#pragma once
#ifndef Task7_2Code_H
#define Task7_2Code_H
#include <iostream>
#include <iomanip>
#include <locale.h>
#include <string>
#include <Windows.h>
#include <cstdlib>
#include <conio.h>
#include <cmath>
#include <fstream>
#include <ctime>

#include "consolecolors.h"
#include "Table_v2.h"
#include "functions.h"
#include "input_processing.h"

//используемые типы
enum cargo_type {sand, water, container};

//параметры моделировани¤
int arrangement_of_arrive = 11 * 24; //отклонение от расписани¤ в часах
int arrive_offset = -2 * 24; //смещение отклонени¤ от расписани¤ в часах

int arrangement_of_unload = 12 * 24; //отклонение от нормального времени разгрузки в часах
int unload_offset = 0; //смещение отклонени¤ от разгрузки

int unload_speed[3] = { 1000, 800, 1500 }; //в час (дл¤ cargo_type в пор¤дке их объ¤влени¤)

bool can_be_storm = true; //может ли начатьс¤ шторм
int average_storm_duration = 12; //сколько в среднем длитс¤ шторм
int arrangement_of_storm_duration = 4; //разброс в длительности шторма
int storm_duration_offset = 2; //смещение разброса в длительности шторма

double storm_debuff = 0.5; //в шторм разгрузка на 50% медленнее

//погодные услови¤
bool is_storm = false;
int storm_time_remained = 0; //оставшеес¤ врем¤ шторма

int MODELLING_TIME = 0; //текущее врем¤

int payment = 0; //текущий штраф
int payment_for_hour = 100; //за каждый час просто¤ выписываетс¤ штраф на 100 у.е. (за день - 2400)

struct schedule_label {
	int id; //номер строки в расписании
	int day;//1-31
	int hour;//0-23
	string name;
	cargo_type cargo;
	double weight;
	int estimate_unload_time; //в часах
};

struct ship {
	schedule_label schedule_position;
	int arrive_time = 0; //фактическое врем¤ прибыти¤ в часах, отсчитываетс¤ от начала моделировани¤
	int delay = 0; //врем¤ задержки в часах
	bool is_at_crane = false; //находитс¤ ли сейчас в процессе разгрузки
	bool has_arrived = false; //прибыл ли корабль
	bool unloaded = false; //разгружен ли корабль
};

int total_ships = 0; //общее количество кораблей
schedule_label *schedule = NULL; //расписание
ship *ships = NULL; //список кораблей

class crane
{
public:
	cargo_type cargo; //тип груза, на который рассчитан кран
	int current_ship = -1; //номер текущего корабл¤ в расписании
	double weight_remain = 0; //оставшийс¤ вес текущего судна
	double crane_unload_speed = 0; //скорость разгрузки: считаетс¤ в начале разгрузки с учетом задержек
	double start_ships_weight = 0; //изначальный вес груза: нужен в расчетах процента разгрузки
	int unload_current_time = 0; //сколько времени разгружаетс¤ текущий корабль

	crane()
	{

	}

	crane(cargo_type c)
	{
		cargo = c;
	}

	void find_next_ship_to_unload(int start_index)
	{
		for (int i = start_index + 1; i < total_ships; i++)
		{
			if ((ships[i].has_arrived) && (!ships[i].is_at_crane) && (!ships[i].unloaded) && (ships[i].schedule_position.cargo == cargo))
			{ //если корабль прибыл, но не разгружен/разгружаетс¤ и его тип груза совпадает с типом крана
				current_ship = i;
				start_ships_weight = ships[i].schedule_position.weight;
				weight_remain = start_ships_weight;
				int random_delay_time = rand() % arrangement_of_unload + unload_offset;
				crane_unload_speed = weight_remain / (random_delay_time + ships[i].schedule_position.estimate_unload_time);
				ships[i].is_at_crane = true;
				return;
			}
		}
		current_ship = -1;
	}

	void update()
	{
		unload_current_time++;
		if (unload_current_time > ships[current_ship].schedule_position.estimate_unload_time)
		{
			ships[current_ship].delay++;
			payment += payment_for_hour;
		}
		weight_remain -= crane_unload_speed - is_storm * storm_debuff;
		if (weight_remain <= 0)
		{
			ships[current_ship].unloaded = true;
			find_next_ship_to_unload(current_ship);
		}
	}
};

crane *cranes = NULL; //указатель на массив кранов, наход¤щихс¤ в порту

void cleanup_dynamic_data()
{
	delete[] cranes;
	delete[] schedule;
	delete[] ships;
}

void download_data(const char* schedule_path, const char* crane_path)
{
	fstream crane_file(crane_path), ships_file(schedule_path);
	if ((!crane_file) || (!ships_file))
	{
		cout << "Невозможно открыть исходные файлы" << schedule_path << " и " << crane_path << endl;
	}
	else
	{
		string crane_temp = "", schedule_temp = "";
		int crane_count = 0, schedule_labels_count = 0;
		//заполн¤ем объекты кранов
		while (!crane_file.eof())
		{
			getline(crane_file, crane_temp);
			crane_count++;
		}
		cranes = new crane[crane_count];
		crane_file.seekg(0);
		int i = 0;
		while (!crane_file.eof())
		{
			getline(crane_file, crane_temp);
			int type = strtol(crane_temp.c_str(), nullptr, 0);
			switch (type)
			{
			case 0:
				cranes[i] = crane(cargo_type::sand);
				break;
			case 1:
				cranes[i] = crane(cargo_type::water);
				break;
			case 2:
				cranes[i] = crane(cargo_type::container);
				break;
			default:
				SetColor(0, 12);
				cout << "Обнаружен несуществующий тип крана в строке " << i+1 << " файла " << crane_path << endl;
				cout << "Загрузка данных остановлена" << endl;
				SetColor(0, 15);
				cleanup_dynamic_data();
				return;
			}
			i++;
		}
		//заполн¤ем расписание
		while (!ships_file.eof())
		{
			getline(ships_file, schedule_temp);
			schedule_labels_count++;
		}
		schedule = new schedule_label[schedule_labels_count];
		ships_file.seekg(0);
		i = 0;
		while (!ships_file.eof())
		{
			getline(ships_file, schedule_temp);

			/*int type = strtol(crane_temp.c_str(), nullptr, 0);
			switch (type)
			{
			case 0:
				cranes[i] = crane(cargo_type::sand);
				break;
			case 1:
				cranes[i] = crane(cargo_type::water);
				break;
			case 2:
				cranes[i] = crane(cargo_type::container);
				break;
			default:
				SetColor(0, 12);
				cout << "ќбнаружен несуществующий тип крана в строке " << i + 1 << "файла " << crane_path << endl;
				cout << "«агрузка данных остановлена" << endl;
				SetColor(0, 15);
				cleanup_dynamic_data();
				return;
			}*/
			i++;
		}
	}
	crane_file.close();
	ships_file.close();
}

void start_modelling()
{
	MODELLING_TIME = 0;

}
#endif