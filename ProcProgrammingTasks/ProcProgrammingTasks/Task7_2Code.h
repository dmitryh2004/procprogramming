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

using namespace std;

//используемые типы
enum cargo_type {sand, water, container};

//параметры моделирования
int arrangement_of_arrive = 11 * 24; //отклонение от расписания в часах
int arrive_offset = -2 * 24; //смещение отклонения от расписания в часах

int arrangement_of_unload = 12 * 24; //отклонение от нормального времени разгрузки в часах
int unload_offset = 0; //смещение отклонения от разгрузки

int unload_speed[3] = { 1000, 800, 1500 }; //в час (для cargo_type в порядке их объявления)

bool can_be_storm = true; //может ли начаться шторм
int average_storm_duration = 12; //сколько в среднем длится шторм
int arrangement_of_storm_duration = 4; //разброс в длительности шторма
int storm_duration_offset = -2; //смещение разброса в длительности шторма

int storm_ver = 100; //вероятность возникновения шторма (считается как 1 / величина)
double storm_debuff = 0.5; //в шторм разгрузка на 50% медленнее

//погодные условия
bool is_storm = false;
int storm_time_remained = 0; //оставшееся время шторма

int MODELLING_TIME = 0; //текущее время
int modelling_step = 24; //период вывода моделирования на экран в часах. По умолчанию - раз в 24 часа

//ДЛЯ СТАТИСТИКИ
int payment = 0; //текущий штраф
int payment_for_hour = 100; //за каждый час простоя выписывается штраф на 100 у.е. (за день - 2400)

int queue_iterations = 0; //сколько раз рассчитывалась очередь
double average_queue_length = 0;
double average_queue_time = 0; //среднее время в очереди
double average_unload_time = 0; //среднее время разгрузки

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
	int arrive_time = 0; //фактическое время прибытия в часах, отсчитывается от начала моделирования
	int unload_start_time = 0; //время начала разгрузки в часах, отсчитывается от начала моделирования
	int unload_end_time = 0; //время окончания разгрузки в часах, отсчитывается от начала моделирования
	int crane_num = 0; //на каком кране обслуживается корабль
	int delay = 0; //время задержки в часах
	bool is_at_crane = false; //находится ли сейчас в процессе разгрузки
	bool has_arrived = false; //прибыл ли корабль
	bool unloaded = false; //разгружен ли корабль
};

int total_ships = 0; //общее количество кораблей
int total_cranes = 0; //общее количество кранов

schedule_label *schedule = NULL; //расписание
ship *ships = NULL; //список кораблей

class crane
{
public:
	int id = 0; //номер крана
	cargo_type cargo; //тип груза, на который рассчитан кран
	int current_ship = -1; //номер текущего корабля в расписании
	double weight_remain = 0; //оставшийся вес текущего судна
	double crane_unload_speed = 0; //скорость разгрузки: считается в начале разгрузки с учетом задержек
	double start_ships_weight = 0; //изначальный вес груза: нужен в расчетах процента разгрузки
	int unload_current_time = 0; //сколько времени разгружается текущий корабль

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
			{ //если корабль прибыл, но не разгружен/разгружается и его тип груза совпадает с типом крана
				current_ship = i;
				start_ships_weight = ships[i].schedule_position.weight;
				ships[i].unload_start_time = MODELLING_TIME;
				weight_remain = start_ships_weight;
				int random_delay_time = rand() % arrangement_of_unload + unload_offset;
				crane_unload_speed = weight_remain / (random_delay_time + ships[i].schedule_position.estimate_unload_time);
				ships[i].is_at_crane = true;
				ships[i].crane_num = id;
				return;
			}
		}
		current_ship = -1;
	}

	void update()
	{
		if (current_ship != -1)
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
				ships[current_ship].unload_end_time = MODELLING_TIME;
				ships[current_ship].unloaded = true;
				int delay_time = unload_current_time - ships[current_ship].schedule_position.estimate_unload_time;
				find_next_ship_to_unload(current_ship);
			}
		}
		else
		{
			find_next_ship_to_unload(current_ship);
		}
	}
};

crane *cranes = NULL; //указатель на массив кранов, находящихся в порту

void cleanup_dynamic_data()
{
	delete[] cranes;
	delete[] schedule;
	delete[] ships;
}

bool download_data(const char* schedule_path, const char* crane_path)
{
	fstream crane_file(crane_path), ships_file(schedule_path);
	if ((!crane_file) || (!ships_file))
	{
		cout << "Невозможно открыть исходные файлы" << schedule_path << " и " << crane_path << endl;
		return false;
	}
	else
	{
		string crane_temp = "", schedule_temp = "";
		int crane_count = 0, schedule_labels_count = 0;
		//заполняем объекты кранов
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
				cout << "Обнаружен несуществующий тип крана в строке " << i+1 << " файла " << crane_path << "(" << crane_temp << ")" << endl;
				cout << "Загрузка данных остановлена" << endl;
				SetColor(0, 15);
				delete[] cranes;
				total_ships = 0;
				total_cranes = 0;
				return false;
			}
			cranes[i].id = i+1;
			i++;
		}
		//заполняем расписание
		while (!ships_file.eof())
		{
			getline(ships_file, schedule_temp);
			schedule_labels_count++;
		}
		schedule = new schedule_label[schedule_labels_count];
		ships = new ship[schedule_labels_count];
		total_ships = schedule_labels_count;
		total_cranes = crane_count;
		ships_file.seekg(0);
		i = 0;
		while (!ships_file.eof())
		{
			getline(ships_file, schedule_temp);
			string schedule_temp_words[6] = { "" };
			if (num_of_symbols(schedule_temp, ' ') != 5)
			{
				SetColor(0, 12);
				cout << "Файл " << schedule_path << " не отформатирован по схеме: ";
				cout << "\n" << "ID записи - дата прибытия - час прибытия - название корабля - тип груза - вес груза\n";
				cout << "(строка файла " << i + 1 << ")" << endl;
				cout << "Загрузка данных остановлена" << endl;
				SetColor(0, 15);
				delete[] cranes;
				delete[] schedule;
				delete[] ships;
				total_ships = 0;
				total_cranes = 0;
				return false;
			}
			for (int j = 0; j < 6; j++)
			{
				size_t space_pos = schedule_temp.find(' ');
				string schedule_temp_temp = "";
				for (int k = 0; k < min(space_pos, schedule_temp.size()); k++)
				{
					schedule_temp_words[j] += schedule_temp[k];
				}
				for (int k = space_pos+1; k < schedule_temp.size(); k++)
				{
					schedule_temp_temp += schedule_temp[k];
				}
				swap(schedule_temp, schedule_temp_temp);
			}
			schedule[i].id = strtol(schedule_temp_words[0].c_str(), nullptr, 0);
			schedule[i].day = strtol(schedule_temp_words[1].c_str(), nullptr, 0);
			if (is_out(schedule[i].day, 0, 30))
			{
				SetColor(0, 12);
				cout << "В строке файла " << i + 1 << " обнаружен недопустимый день (" << schedule[i].day << ")" << endl;
				cout << "День должен лежать в диапазоне [0; 30]" << endl;
				cout << "Загрузка данных остановлена" << endl;
				SetColor(0, 15);
				delete[] cranes;
				delete[] schedule;
				delete[] ships;
				total_ships = 0;
				total_cranes = 0;
				return false;
			}
			schedule[i].hour = strtol(schedule_temp_words[2].c_str(), nullptr, 0);
			if (is_out(schedule[i].hour, 0, 23))
			{
				SetColor(0, 12);
				cout << "В строке файла " << i + 1 << " обнаружен недопустимый час (" << schedule[i].hour << ")" << endl;
				cout << "Час должен лежать в диапазоне [0; 23]" << endl;
				cout << "Загрузка данных остановлена" << endl;
				SetColor(0, 15);
				delete[] cranes;
				delete[] schedule;
				delete[] ships;
				total_ships = 0;
				total_cranes = 0;
				return false;
			}
			schedule[i].name = schedule_temp_words[3];
			int current_cargo_type = strtol(schedule_temp_words[4].c_str(), nullptr, 0);
			switch (current_cargo_type)
			{
			case 0:
				schedule[i].cargo = sand;
				break;
			case 1:
				schedule[i].cargo = water;
				break;
			case 2:
				schedule[i].cargo = container;
				break;
			default:
				SetColor(0, 12);
				cout << "Строка файла " << i + 1 << " содержит недопустимый тип груза " << current_cargo_type << endl;
				cout << "Загрузка данных остановлена" << endl;
				SetColor(0, 15);
				delete[] cranes;
				delete[] schedule;
				delete[] ships;
				total_ships = 0;
				total_cranes = 0;
				return false;
			}
			schedule[i].weight = strtod(schedule_temp_words[5].c_str(), nullptr);
			if (less_or_equals_1v(schedule[i].weight, 0))
			{
				SetColor(0, 12);
				cout << "В строке файла " << i + 1 << " обнаружен недопустимый вес (" << schedule[i].weight << ")" << endl;
				cout << "Вес должен быть положительным значением." << endl;
				cout << "Загрузка данных остановлена" << endl;
				SetColor(0, 15);
				delete[] cranes;
				delete[] schedule;
				delete[] ships;
				total_ships = 0;
				total_cranes = 0;
				return false;
			}
			schedule[i].estimate_unload_time = int(schedule[i].weight) / int(unload_speed[current_cargo_type]);

			ships[i].schedule_position = schedule[i];
			ships[i].arrive_time = max(1, (schedule[i].hour + schedule[i].day * 24) + (rand() / arrangement_of_arrive + arrive_offset));
			i++;
		}
	}
	crane_file.close();
	ships_file.close();
}

void show_unload_table()
{
	string titles[] = { "Название корабля","Время прибытия", "Время ожидания", "Начало разгрузки", "Продолжительность разгрузки" };
	int max_name_size = titles[0].size();
	for (int i = 0; i < total_ships; i++)
	{
		max_name_size = max(max_name_size, ships[i].schedule_position.name.size());
	}
	int col_w[5] = { max_name_size+2, titles[1].size()+2, titles[2].size()+2, titles[3].size()+2, titles[4].size()+2 };
	int *row_height = new int[total_ships+1];
	for (int i = 0; i < total_ships+1; i++)
	{
		row_height[i] = 1;
	}
	Table_v2_n::Table_v2 UnloadTable(5, total_ships+1, col_w, row_height, "Таблица разгрузок", 7);
	UnloadTable.set_data(0, 0, "Название корабля", 0, 14, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	UnloadTable.set_data(0, 1, "Время прибытия", 0, 14, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	UnloadTable.set_data(0, 2, "Время ожидания", 0, 14, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	UnloadTable.set_data(0, 3, "Начало разгрузки", 0, 14, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	UnloadTable.set_data(0, 4, "Продолжительность разгрузки", 0, 14, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	for (int i = 0; i < total_ships; i++)
	{
		int temp_arrive_time = ships[i].arrive_time;
		int temp_queue_time = ships[i].unload_start_time - ships[i].arrive_time;
		int temp_begin_time = ships[i].unload_start_time;
		int temp_duration = ships[i].unload_end_time - ships[i].unload_start_time;
		string tat = "День " + to_string(temp_arrive_time / 24 + 1) + ", " +
			to_string(temp_arrive_time % 24) + ":00";
		string tqt = to_string(temp_queue_time / 24) + " дней и " +
			to_string(temp_queue_time % 24) + " ч";
		string tbt = "День " + to_string(temp_begin_time / 24 + 1) + ", " +
			to_string(temp_begin_time % 24) + ":00";
		string td = to_string(temp_duration / 24) + " дней и " +
			to_string(temp_duration % 24) + " ч";
		UnloadTable.set_data(1+i, 0, ships[i].schedule_position.name, 0, 15, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
		if (temp_arrive_time <= MODELLING_TIME)
		{
			UnloadTable.set_data(1 + i, 1, tat, 0, 15, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
			if (temp_queue_time >= 0)
			{
				UnloadTable.set_data(1 + i, 2, tqt, 0, 15, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
				if (temp_begin_time <= MODELLING_TIME)
				{
					UnloadTable.set_data(1 + i, 3, tbt, 0, 15, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
					if (temp_duration >= 0)
					{
						UnloadTable.set_data(1 + i, 4, td, 0, 15, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
					}
					else
					{
						UnloadTable.set_data(1 + i, 4, "Разгружается", 0, 14, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
					}
				}
				else
				{
					UnloadTable.set_data(1 + i, 3, "Не принят", 0, 12, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
					UnloadTable.set_data(1 + i, 4, "Не принят", 0, 4, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
				}
			}
			else
			{
				UnloadTable.set_data(1 + i, 2, "В очереди", 0, 12, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
				UnloadTable.set_data(1 + i, 3, "В очереди", 0, 4, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
				UnloadTable.set_data(1 + i, 4, "В очереди", 0, 4, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
			}
		}
		else
		{
			UnloadTable.set_data(1 + i, 1, "Не прибыл", 0, 12, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
			UnloadTable.set_data(1 + i, 2, "Не прибыл", 0, 4, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
			UnloadTable.set_data(1 + i, 3, "Не прибыл", 0, 4, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
			UnloadTable.set_data(1 + i, 4, "Не прибыл", 0, 4, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
		}
		
	}
	UnloadTable.show_table();
	delete[] row_height;
}

void show_statistics()
{
	int col_width[2] = {50, 20};
	int row_height[6] = { 1,1,1,1,1,1 };
	Table_v2_n::Table_v2 StatisticsTable(2, 6, col_width, row_height, "Итоговая статистика", 7);
	StatisticsTable.set_data(0, 0, "Число разгруженных кораблей", 0, 14, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	StatisticsTable.set_data(1, 0, "Средняя длина очереди", 0, 14, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	StatisticsTable.set_data(2, 0, "Среднее время в очереди в часах", 0, 14, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	StatisticsTable.set_data(3, 0, "Максимальная задержка разгрузки в часах", 0, 14, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	StatisticsTable.set_data(4, 0, "Средняя задержка разгрузки в часах", 0, 14, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	StatisticsTable.set_data(5, 0, "Общая сумма выплаченного штрафа", 0, 14, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	//собираем данные для правой части таблицы
	int unloaded_ships = 0;
	int max_delay_time = 0;
	int average_unload_delay = 0;
	average_queue_length /= queue_iterations;
	
	for (int i = 0; i < total_ships; i++)
	{
		if (ships[i].unloaded)
		{
			unloaded_ships++;
			average_unload_delay += (ships[i].unload_end_time - ships[i].unload_start_time) - ships[i].schedule_position.estimate_unload_time;
		}	
		average_queue_time += max(0, ships[i].unload_start_time - ships[i].arrive_time);
		max_delay_time = max(max_delay_time, ships[i].delay);
	}
	average_queue_time /= total_ships;
	average_unload_delay /= unloaded_ships;
	string col1_table[6] = { "", "", "", "", "", "" };
	col1_table[0] = to_string(unloaded_ships);
	col1_table[1] = to_string(average_queue_length);
	col1_table[2] = to_string(average_queue_time);
	col1_table[3] = to_string(max_delay_time);
	col1_table[4] = to_string(average_unload_delay);
	col1_table[5] = to_string(payment);
	StatisticsTable.set_data(0, 1, col1_table[0], 0, 15, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	StatisticsTable.set_data(1, 1, col1_table[1], 0, 15, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	StatisticsTable.set_data(2, 1, col1_table[2], 0, 15, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	StatisticsTable.set_data(3, 1, col1_table[3], 0, 15, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	StatisticsTable.set_data(4, 1, col1_table[4], 0, 15, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	StatisticsTable.set_data(5, 1, col1_table[5], 0, 15, Table_v2_n::align_y::up, Table_v2_n::align_x::center_x);
	StatisticsTable.show_table();
}

void show_crane_info()
{
	int crane_number = 0;
	getvar(crane_number, "Введите номер крана", true, NULL, is_in_or_equal, NULL, 0, 1, total_cranes, 0, 0, 0);
	SetColor(0, 14);
	cout << "Кран №" << crane_number << endl;
	SetColor(0, 15);
	crane_number--;
	cout << "Тип крана - ";
	switch (cranes[crane_number].cargo)
	{
	case sand:
		SetColor(0, 6);
		cout << "сыпучие грузы" << endl;
		break;
	case water:
		SetColor(0, 3);
		cout << "жидкие грузы" << endl;
		break;
	case container:
		SetColor(0, 2);
		cout << "контейнеры" << endl;
		break;
	}
	SetColor(0, 15);
	if (cranes[crane_number].current_ship == -1)
	{
		cout << "Сейчас на этом кране не обслуживается никакой корабль." << endl;
	}
	else
	{
		string time_of_begin = "", estimate_end_time = "";
		time_of_begin = "день " + to_string(ships[cranes[crane_number].current_ship].unload_start_time / 24 + 1) + ", " + 
			to_string(ships[cranes[crane_number].current_ship].unload_start_time % 24) + ":00";
		estimate_end_time = "день " + to_string((ships[cranes[crane_number].current_ship].unload_start_time + 
			ships[cranes[crane_number].current_ship].schedule_position.estimate_unload_time) / 24 + 1) + ", " +
			to_string((ships[cranes[crane_number].current_ship].unload_start_time +
				ships[cranes[crane_number].current_ship].schedule_position.estimate_unload_time) % 24) + ":00";
		int percent = 100 - (cranes[crane_number].weight_remain / cranes[crane_number].start_ships_weight) * 100;
		cout << "Сейчас на этом кране обслуживается корабль " << ships[cranes[crane_number].current_ship].schedule_position.name << endl;
		cout << "Вес груза этого корабля - " << ships[cranes[crane_number].current_ship].schedule_position.weight << " кг" << endl;
		cout << "Осталось разгрузить " << cranes[crane_number].weight_remain << " кг" << endl;
		cout << "Процент разгрузки - " << percent << endl;
		cout << endl << "Время начала разгрузки - " << time_of_begin << endl;
		cout << "Планируемое время окончания разгрузки - " << estimate_end_time << endl;
		int estimate_end_time_int = ships[cranes[crane_number].current_ship].unload_start_time +
			ships[cranes[crane_number].current_ship].schedule_position.estimate_unload_time;
		int difference = MODELLING_TIME - estimate_end_time_int;
		if (difference > 0)
		{
			cout << "Текущее отставание от графика - " << difference << " часов";
			cout << "(" << difference / 24 << " дней и " << difference % 24 << " часов)" << endl;
		}
		else
		{
			cout << "Задержек нет" << endl;
		}
	}
}

void show_ship_info()
{
	int ship_number = 0;
	getvar(ship_number, "Введите номер корабля", true, NULL, is_in_or_equal, NULL, 0, 1, total_ships, 0, 0, 0);
	SetColor(0, 14);
	cout << "Корабль №" << ship_number << endl;
	SetColor(0, 15);
	ship_number--;
	cout << "Название - " << ships[ship_number].schedule_position.name << endl;
	cout << "Тип груза - ";
	switch (ships[ship_number].schedule_position.cargo)
	{
	case sand:
		SetColor(0, 6);
		cout << "сыпучие грузы" << endl;
		break;
	case water:
		SetColor(0, 3);
		cout << "жидкие грузы" << endl;
		break;
	case container:
		SetColor(0, 2);
		cout << "контейнеры" << endl;
		break;
	}
	SetColor(0, 15);
	if (ships[ship_number].has_arrived)
	{
		cout << "Корабль прибыл в день " << ships[ship_number].arrive_time / 24 + 1 << ", в " << ships[ship_number].arrive_time % 24
			<< ":00" << endl;
		cout << "Время прибытия по расписанию - день " << ships[ship_number].schedule_position.day + 1 << ", " <<
			ships[ship_number].schedule_position.hour << ":00" << endl;
	}
	else
	{
		cout << "Корабль не прибыл, ожидаемое время прибытия - день " << ships[ship_number].schedule_position.day + 1 << ", " <<
			ships[ship_number].schedule_position.hour << ":00" << endl;
		return;
	}
	if (ships[ship_number].is_at_crane)
	{
		cout << "Время начала разгрузки - день " << ships[ship_number].unload_start_time / 24 + 1 <<
			", " << ships[ship_number].unload_start_time % 24 << ":00" << endl;
	}
	else
	{
		cout << "Корабль еще не принят на разгрузку" << endl;
		return;
	}
	if (ships[ship_number].unloaded)
	{
		cout << "Время окончания разгрузки - день " << ships[ship_number].unload_end_time / 24 + 1 <<
			", " << ships[ship_number].unload_end_time % 24 << ":00" << endl;
	}
	else
	{
		cout << "Корабль разгружается краном №" << ships[ship_number].crane_num << endl;
	}
}

void show_common_data()
{
	SetColor(0, 14);
	int arrived = 0, at_crane = 0, unloaded = 0;
	int max_name_size = 0;
	cout << endl;
	string titles[3] = {"Прибыли", "Разгружаются", "Разгружены"};
	for (int i = 0; i < total_ships; i++)
	{
		if ((ships[i].has_arrived) && !(ships[i].is_at_crane) && !(ships[i].unloaded))
		{
			arrived++;
		}
		else if ((ships[i].has_arrived) && (ships[i].is_at_crane) && !(ships[i].unloaded))
		{
			at_crane++;
		}
		else if ((ships[i].has_arrived) && (ships[i].is_at_crane) && (ships[i].unloaded))
		{
			unloaded++;
		}
		max_name_size = max(max_name_size, ships[i].schedule_position.name.size());
	}
	max_name_size += 10;
	max_name_size = max(max_name_size, titles[0].size());
	max_name_size = max(max_name_size, titles[1].size());
	max_name_size = max(max_name_size, titles[2].size());
	int col_width[] = {max_name_size, max_name_size, max_name_size};
	int rows = max(arrived, max(at_crane, unloaded));
	int *row_height = new int[rows + 1];
	for (int i = 0; i < rows + 1; i ++ )
	{
		row_height[i] = 1;
	}
	Table_v2_n::Table_v2 CommonTable(3, rows+1, col_width, row_height, "Общие сведения о кораблях в порту", 7);
	
	arrived = 0; at_crane = 0; unloaded = 0;
	for (int i = 0; i < rows + 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			CommonTable.set_data(i, j, " ", 0, 15, Table_v2_n::align_y::center_y, Table_v2_n::align_x::center_x);
		}
	}
	CommonTable.set_data(0, 0, titles[0], 0, 12, Table_v2_n::align_y::center_y, Table_v2_n::align_x::center_x);
	CommonTable.set_data(0, 1, titles[1], 0, 14, Table_v2_n::align_y::center_y, Table_v2_n::align_x::center_x);
	CommonTable.set_data(0, 2, titles[2], 0, 10, Table_v2_n::align_y::center_y, Table_v2_n::align_x::center_x);
	for (int i = 0; i < total_ships; i++)
	{
		string table_data = ships[i].schedule_position.name;
		table_data += " (ID:" + to_string(ships[i].schedule_position.id + 1) + ")";
		int cargo_color = 0;
		switch (ships[i].schedule_position.cargo)
		{
		case sand:
			cargo_color = 6;
			break;
		case water:
			cargo_color = 3;
			break;
		case container:
			cargo_color = 2;
			break;
		}
		if ((ships[i].has_arrived) && !(ships[i].is_at_crane) && !(ships[i].unloaded))
		{
			CommonTable.set_data(arrived + 1, 0, table_data, 0, cargo_color, Table_v2_n::align_y::center_y, Table_v2_n::align_x::center_x);
			arrived++;
		}
		else if ((ships[i].has_arrived) && (ships[i].is_at_crane) && !(ships[i].unloaded))
		{
			CommonTable.set_data(at_crane + 1, 1, table_data, 0, cargo_color, Table_v2_n::align_y::center_y, Table_v2_n::align_x::center_x);
			at_crane++;
		}
		else if ((ships[i].has_arrived) && (ships[i].is_at_crane) && (ships[i].unloaded))
		{
			CommonTable.set_data(unloaded + 1, 2, table_data, 0, cargo_color, Table_v2_n::align_y::center_y, Table_v2_n::align_x::center_x);
			unloaded++;
		}
	}
	CommonTable.show_table();
	cout << endl << "Цвета названий кораблей в зависимости от типа груза:" << endl;
	SetColor(0, 6);
	cout << "Сыпучие грузы" << endl;
	SetColor(0, 3);
	cout << "Жидкие грузы" << endl;
	SetColor(0, 2);
	cout << "Контейнеры" << endl;
	SetColor(0, 15);
	delete[] row_height;
	cout << endl << "Текущая сумма выплаченного штрафа: " << payment << endl;
}

bool update()
{
	storm_time_remained = max(0, storm_time_remained - 1);
	if (!storm_time_remained)
	{
		is_storm = false;
		if (!(rand() % storm_ver) && (can_be_storm))
		{
			is_storm = true;
			storm_time_remained = average_storm_duration + (rand() % arrangement_of_storm_duration + storm_duration_offset);
		}
	}
	for (int i = 0; i < total_ships; i++)
	{
		if (MODELLING_TIME == ships[i].arrive_time)
		{
			ships[i].has_arrived = true;
		}
		else if ((MODELLING_TIME > ships[i].arrive_time) && (!ships[i].is_at_crane))
		{
			ships[i].delay++;
			payment += payment_for_hour;
		}
	}
	int crane_types[3] = { 0 };
	for (int i = 0; i < total_cranes; i++)
	{
		cranes[i].update();
		crane_types[cranes[i].cargo]++;
	}
	double queue[3] = { 0 };
	for (int i = 0; i < total_ships; i++)
	{
		if ((ships[i].has_arrived) && !(ships[i].is_at_crane) && (ships[i].arrive_time < MODELLING_TIME))
		{
			queue[ships[i].schedule_position.cargo] ++;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		queue[i] /= crane_types[i];
		if (queue[i] > 0)
		{
			average_queue_length += queue[i];
			queue_iterations++;
		}
	}
	if (MODELLING_TIME % modelling_step == 0)
	{
		while (1)
		{
			system("cls");
			char act = ' ';
			SetColor(0, 14);
			cout << "Моделирование порта: день " << MODELLING_TIME / 24 + 1 << ", время: " << MODELLING_TIME % 24 << ":00" << endl;
			SetColor(0, 15);
			cout << "Шторм ";
			if (is_storm)
			{
				SetColor(0, 12);
				cout << "наблюдается" << endl;
			}
			else
			{
				SetColor(0, 10);
				cout << "не наблюдается" << endl;
			}
			SetColor(0, 15);
			cout << "Выберите действие:" << endl << "O - показать общее состояние порта" << endl;
			cout << "C - показать информацию о кране" << endl;
			cout << "S - показать информацию о корабле" << endl;
			cout << "N - продолжить моделирование" << endl;
			cout << "Q - завершить моделирование" << endl;
			bool ok = false;
			while (!ok)
			{
				act = _getch();
				switch (tolower(act))
				{
				case 'o':
					show_common_data();
					ok = true;
					break;
				case 'c':
					ok = true;
					show_crane_info();
					break;
				case 's':
					ok = true;
					show_ship_info();
					break;
				case 'n':
					return true;
				case 'q':
					return false;
				default:
					cout << "Неверный ввод" << endl;
				}
			}
			_getch();
		}
		
	}
	return true;
}

void start_modelling()
{
	MODELLING_TIME = 0;
	payment = 0;
	queue_iterations = 0;
	average_queue_length = 0;
	average_queue_time = 0;
	average_unload_time = 0;
	for (MODELLING_TIME = 0; MODELLING_TIME < 24 * 31; MODELLING_TIME++)
	{
		if (!update())
			break;
	}
	SetColor(0, 10);
	cout << "Моделирование завершено" << endl;
	SetColor(0, 15);
	show_unload_table();
	system("pause");
	system("cls");
	show_statistics();
	system("pause");
	system("cls");
	cleanup_dynamic_data();
}

void change_settings()
{
	char setting = ' ';
	while (tolower(setting) != 'q')
	{
		system("cls");
		cout << "Нажмите Q, чтобы закончить настройку." << endl;
		cout << "Нажмите R, чтобы сбросить настройки на настройки по умолчанию." << endl;
		cout << "Выберите, какую настройку вы хотите изменить:" << endl;
		cout << "[0] Шаг моделирования в часах ";
		SetColor(0, 14);
		cout << "(текущее значение : " << modelling_step << ")" << endl;
		SetColor(0, 15);
		cout << "[1] Скорость разгрузки кораблей с сыпучими грузами в час ";
		SetColor(0, 14);
		cout << "(текущее значение : " << unload_speed[0] << ")" << endl;
		SetColor(0, 15);
		cout << "[2] Скорость разгрузки кораблей с жидкими грузами в час ";
		SetColor(0, 14);
		cout << "(текущее значение : " << unload_speed[1] << ")" << endl;
		SetColor(0, 15);
		cout << "[3] Скорость разгрузки кораблей с контейнерами в час ";
		SetColor(0, 14);
		cout << "(текущее значение : " << unload_speed[2] << ")" << endl;
		SetColor(0, 15);
		cout << "[4] Отклонение судов от заданного времени прибытия в часах ";
		SetColor(0, 14);
		cout << "(текущее значение : " << arrangement_of_arrive << ")" << endl;
		SetColor(0, 15);
		cout << "[5] Смещение параметра [4] ";
		SetColor(0, 14);
		cout << "(текущее значение : " << arrive_offset << ")" << endl;
		SetColor(0, 15);
		cout << "[6] Возможная максимальная задержка разгрузки в часах ";
		SetColor(0, 14);
		cout << "(текущее значение : " << arrangement_of_unload << ")" << endl;
		SetColor(0, 15);
		cout << "[7] Смещение параметра [6] ";
		SetColor(0, 14);
		cout << "(текущее значение : " << unload_offset << ")" << endl;
		SetColor(0, 15);
		cout << "[8] Может ли начаться шторм ";
		SetColor(0, 14);
		cout << "(текущее значение : " << can_be_storm << ")" << endl;
		SetColor(0, 8 + can_be_storm * 7);
		cout << "[9] Средняя продолжительность шторма ";
		SetColor(0, 6 + can_be_storm * 8);
		cout << "(текущее значение : " << average_storm_duration << ")" << endl;
		SetColor(0, 8 + can_be_storm * 7);
		cout << "[A] Отклонение от средней продолжительности шторма ";
		SetColor(0, 6 + can_be_storm * 8);
		cout << "(текущее значение : " << arrangement_of_storm_duration << ")" << endl;
		SetColor(0, 8 + can_be_storm * 7);
		cout << "[B] Смещение параметра [A] ";
		SetColor(0, 6 + can_be_storm * 8);
		cout << "(текущее значение : " << storm_duration_offset << ")" << endl;
		SetColor(0, 8 + can_be_storm * 7);
		cout << "[C] Вероятность возникновения шторма (считается как 1 / [C]) ";
		SetColor(0, 6 + can_be_storm * 8);
		cout << "(текущее значение : " << storm_ver << ")" << endl;
		SetColor(0, 8 + can_be_storm * 7);
		cout << "[D] Влияние шторма на разгрузку (0 - никак не влияет, 1 - разгрузка останавливается полностью) ";
		SetColor(0, 6 + can_be_storm * 8);
		cout << "(текущее значение : " << storm_debuff << ")" << endl;
		SetColor(0, 15);
		cout << "[E] Штраф за час простоя корабля ";
		SetColor(0, 14);
		cout << "(текущее значение : " << payment_for_hour << ")" << endl;
		SetColor(0, 15);
		setting = _getch();
		int temp = 0;
		switch (tolower(setting))
		{
		case '0':
			getvar(modelling_step, "Введите новое значение параметра [0]", true, greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
			break;
		case '1':
			getvar(unload_speed[0], "Введите новое значение параметра [1]", true, greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
			break;
		case '2':
			getvar(unload_speed[1], "Введите новое значение параметра [2]", true, greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
			break;
		case '3':
			getvar(unload_speed[2], "Введите новое значение параметра [3]", true, greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
			break;
		case '4':
			getvar(arrangement_of_arrive, "Введите новое значение параметра [4]", true, greater_or_equals_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
			break;
		case '5':
			getvar(arrive_offset, "Введите новое значение параметра [5]", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
			break;
		case '6':
			getvar(arrangement_of_unload, "Введите новое значение параметра [6]", true, greater_or_equals_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
			break;
		case '7':
			getvar(unload_offset, "Введите новое значение параметра [7]", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
			break;
		case '8':
			getvar(temp, "Введите новое значение параметра [8]", false, NULL, is_in_or_equal, NULL, 0, 0, 1, 0, 0, 0);
			can_be_storm = temp;
			break;
		case '9':
			getvar(average_storm_duration, "Введите новое значение параметра [9]", true, greater_or_equals_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
			break;
		case 'a':
			getvar(arrangement_of_storm_duration, "Введите новое значение параметра [A]", true, greater_or_equals_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
			break;
		case 'b':
			getvar(storm_duration_offset, "Введите новое значение параметра [B]", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
			break;
		case 'c':
			getvar(storm_ver, "Введите новое значение параметра [C]", true, greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
			break;
		case 'd':
			getvar(storm_debuff, "Введите новое значение параметра [D]", false, NULL, is_in_or_equal, NULL, 0, 0.0, 1.0, 0, 0, 0);
			break;
		case 'e':
			getvar(payment_for_hour, "Введите новое значение параметра [E]", true, greater_or_equals_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
			break;
		case 'r':
			modelling_step = 24;
			unload_speed[0] = 1000;
			unload_speed[1] = 800;
			unload_speed[2] = 1500;
			arrangement_of_arrive = 11 * 24;
			arrive_offset = -48;
			arrangement_of_unload = 12 * 24;
			unload_offset = 0;
			can_be_storm = true;
			average_storm_duration = 12;
			arrangement_of_storm_duration = 4;
			storm_duration_offset = -2;
			storm_ver = 100;
			storm_debuff = 0.5;
			payment_for_hour = 100;
			break;
		case 'q':
			break;
		default:
			cout << "Неверный ввод параметра" << endl;
		}
	}
}

void port_modelling_menu()
{
	system("cls");
	
	string crane_p, schedule_p;
	bool downloaded = false;
	while (1)
	{
		system("cls");
		char ch = ' ';
		
		SetColor(0, 13);
		cout << "Моделирование порта (задание на автомат)" << endl;
		SetColor(0, 15);
		cout << "Выберите действие:" << endl;
		cout << "S - начать моделирование" << endl;
		cout << "D - загрузить исходные данные" << endl;
		cout << "E - изменить настройки моделирования" << endl;
		cout << "Q - выйти из программы" << endl;
		ch = _getch();
		switch (tolower(ch))
		{
		case 's':
			if (downloaded) 
			{ 
				start_modelling(); 
				downloaded = false;
			}
			else
			{
				SetColor(0, 14);
				cout << "Моделирование начать невозможно: не загружены исходные данные" << endl;
				SetColor(0, 15);
			}
			break;
		case 'e':
			change_settings();
			break;
		case 'd':
			cout << "Введите относительный путь до файла с исходными данными о кранах (не рекомендуется использовать пробелы)" << endl;
			cin >> crane_p;
			cout << "Введите относительный путь до файла с исходным расписанием (не рекомендуется использовать пробелы)" << endl;
			cin >> schedule_p;
			if (download_data(schedule_p.c_str(), crane_p.c_str()))
			{
				downloaded = true;
				cout << "Данные успешно загружены" << endl;
			}
			else
			{
				downloaded = false;
			}
			break;
		case 'q':
			return;
		default:
			cout << "Неверный ввод" << endl;
			break;
		}
	}
	
}
#endif