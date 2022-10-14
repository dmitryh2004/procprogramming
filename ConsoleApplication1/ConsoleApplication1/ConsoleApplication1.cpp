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

using namespace std;

const double pi = 3.14159;
const double e = 2.71828;

string dz_list_names[2][31] = {
	{"1-1", "1-2", "1-3", "1-4", "1-5",
	"2-1", "2-2", "2-3", "2-4", "2-5",
	"3-1", "3-2", "3-3", "3-4", "3-5",
	"4-1", "4-2", "4-3", "4-4", "4-5",
	"4-6", "4-7", "4-8", "4-9",
	"5-1", "5-2", "5-3", "5-4", "5-5", "5-6", "5-7"},
	{"Имя", "Калькулятор", "Уравнение: bx + c = 0", "Уравнение: ax^2 + bx + c = 0", "Лампочка и шторы",
	"Конус", "Разветвление", "Функция z = ln (b - y) * sqrt (b - x)", "Порядок", "Табуляция функции y = (x^2 - 2x + 2) / (x - 1)",
	"Займ", "Процент займа", "Файлы", "Фильтр", "Сортировка",
	"Файл с числами", "Знак числа", "Площадь", "Флаг США", "Синусоида",
	"Римские цифры", "\"Случайные\" числа", "Про продавцов", "Системы счисления",
	"Алгоритм Евклида", "Решето Эратосфена", "Обработка текстовых файлов 1", "Обработка текстовых файлов 2", "Ряды 1", "Ряды 2", "Файлы"}
};

int findplace(string cond, char a)
{
	for (int i = 0; i < cond.size(); i++)
	{
		if (cond[i] == a)
			return i;
	}
	return -1;
}

int num_of_symbols(string str, char ch)
{
	int num = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ch)
			num++;
	}
	return num;
}

void replaceall(string& str, string search, string replace)
{
	int index = 0;
	while (index < str.size())
	{
		size_t s = str.find(search, index);
		if (s == string::npos)
			break;
		else
		{
			str.erase(s, search.length());
			str.insert(s, replace);
			index = s;
		}
	}
}

string reverse(string arg)
{
	int length = arg.size();
	string temp = arg;
	for (int i = 0, j = length - 1; i < j; i++, j--)
	{
		swap(temp[i], temp[j]);
	}
	return temp;
}

void getvar(double& var, string hintMessage, bool Positive)
{
	string check_cond;
	if (Positive)
		check_cond = ",1234567890";
	else
		check_cond = "-,1234567890";
	string varstring = "a";
	bool ok = false;
	while (!ok)
	{
		cout << hintMessage << " -> ";
		cin >> varstring;
		if (varstring.find_first_not_of(check_cond) != string::npos)
		{
			if (Positive)
				cout << "Неверный ввод: найден символ, отличный от цифр или запятой" << endl;
			else
				cout << "Неверный ввод: найден символ, отличный от цифр, минуса или запятой" << endl;
			continue;
		}
		if (num_of_symbols(varstring, '-') > 1)
		{
			cout << "Неверный ввод: число минусов больше 1" << endl;
			continue;
		}
		if (num_of_symbols(varstring, ',') > 1)
		{
			cout << "Неверный ввод: число запятых больше 1" << endl;
			continue;
		}
		if ((findplace(varstring, ',') < findplace(varstring, '-')) && (num_of_symbols(varstring, ',') > 0))
		{
			cout << "Неверный ввод: запятая стоит перед минусом" << endl;
			continue;
		}
		bool ok2 = true;
		for (int i = 0; i < 10; i++)
		{
			if ((findplace(varstring, '-') > findplace(varstring, char(i + 48))) && (num_of_symbols(varstring, char(i + 48)) > 0))
			{
				cout << "Неверный ввод: минус стоит после цифры" << endl;
				ok2 = false;
				break;
			}
		}
		if (!ok2)
			continue;
		ok = !ok;
	}
	var = strtod(varstring.c_str(), nullptr);
}

void getvar(float& var, string hintMessage, bool Positive)
{
	string check_cond;
	if (Positive)
		check_cond = ",1234567890";
	else
		check_cond = "-,1234567890";
	string varstring = "a";
	bool ok = false;
	while (!ok)
	{
		cout << hintMessage << " -> ";
		cin >> varstring;
		if (varstring.find_first_not_of(check_cond) != string::npos)
		{
			if (Positive)
				cout << "Неверный ввод: найден символ, отличный от цифр или запятой" << endl;
			else
				cout << "Неверный ввод: найден символ, отличный от цифр, минуса или запятой" << endl;
			continue;
		}
		if (num_of_symbols(varstring, '-') > 1)
		{
			cout << "Неверный ввод: число минусов больше 1" << endl;
			continue;
		}
		if (num_of_symbols(varstring, ',') > 1)
		{
			cout << "Неверный ввод: число запятых больше 1" << endl;
			continue;
		}
		if ((findplace(varstring, ',') < findplace(varstring, '-')) && (num_of_symbols(varstring, ',') > 0))
		{
			cout << "Неверный ввод: запятая стоит перед минусом" << endl;
			continue;
		}
		bool ok2 = true;
		for (int i = 0; i < 10; i++)
		{
			if ((findplace(varstring, '-') > findplace(varstring, char(i + 48))) && (num_of_symbols(varstring, char(i + 48)) > 0))
			{
				cout << "Неверный ввод: минус стоит после цифры" << endl;
				ok2 = false;
				break;
			}
		}
		if (!ok2)
			continue;
		ok = !ok;
	}
	var = strtof(varstring.c_str(), nullptr);
}

void getvar(int& var, string hintMessage, bool Positive)
{
	string check_cond;
	if (Positive)
		check_cond = "1234567890";
	else
		check_cond = "-1234567890";
	string varstring = "a";
	bool ok = false;
	while (!ok)
	{
		cout << hintMessage << " -> ";
		cin >> varstring;
		if (varstring.find_first_not_of(check_cond) != string::npos)
		{
			if (Positive)
				cout << "Неверный ввод: найден символ, отличный от цифр" << endl;
			else
				cout << "Неверный ввод: найден символ, отличный от цифр или минуса" << endl;
			continue;
		}
		if (num_of_symbols(varstring, '-') > 1)
		{
			cout << "Неверный ввод: число минусов больше 1" << endl;
			continue;
		}
		bool ok2 = true;
		for (int i = 0; i < 10; i++)
		{
			if ((findplace(varstring, '-') > findplace(varstring, char(i + 48))) && (num_of_symbols(varstring, char(i + 48)) > 0))
			{
				cout << "Неверный ввод: минус стоит после цифры" << endl;
				ok2 = false;
				break;
			}
		}
		if (!ok2)
			continue;
		ok = !ok;
	}
	var = int(strtod(varstring.c_str(), nullptr));
}

namespace table {
	const char h_b = '-';
	const char v_b = '|';

	class Table {
	public:
		const int max_col_num = 5;
		const int max_row_num = 50;
		string name = "Table";
		int col_num;
		int row_num;
		int col_width[5] = { -1, -1, -1, -1, -1 };
		string data[5][50];
		int colors[5][50][2];
		int border_color;

		Table(int cn, int rn, int col_w[5], string n, int bc)
		{
			if ((cn <= max_col_num) && (rn <= max_row_num))
			{
				this->col_num = cn;
				this->row_num = rn;
				for (int i = 0; i < 5; i++)
				{
					this->col_width[i] = col_w[i];
				}
				if (n.c_str() != nullptr)
					this->name = n;
				this->border_color = bc;
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 50; j++)
					{
						this->data[i][j] = " ";
						this->colors[i][j][0] = 0;
						this->colors[i][j][1] = 0;
					}
				}
			}
			else
			{
				cout << "Can not create table " << rn << "x" << cn << endl;
			}
		}

		void set_data(int row, int col, string d, int bg_color, int text_color)
		{
			this->data[col][row] = d;
			this->colors[col][row][0] = bg_color;
			this->colors[col][row][1] = text_color;
		}

		void show()
		{
			cout << this->name << endl;
			int total_width = 1;

			for (int i = 0; i < this->col_num; i++)
			{
				total_width += this->col_width[i] + 1;
			}
			SetColor(0, border_color);
			for (int j = 0; j < total_width; j++)
			{
				cout << h_b;
			}
			cout << endl;
			for (int i = 0; i < this->row_num; i++)
			{
				cout << v_b;
				for (int j = 0; j < this->col_num; j++)
				{
					cout << setw(col_width[j]);
					SetColor(colors[j][i][0], colors[j][i][1]);
					cout << this->data[j][i];
					SetColor(0, border_color);
					cout << v_b;
				}
				cout << endl;
				for (int j = 0; j < total_width; j++)
				{
					cout << h_b;
				}
				cout << endl;
			}
			SetColor(0, 15);
		}
	};
};

void f1_1();
void f1_2();
void f1_3();
void f1_4();
void f1_5();
void f2_1();
void f2_2();
void f2_3();
void f2_4();
void f2_5();
void f3_1();
void f3_2();
void f3_3();
void f3_4();
void f3_5();
void f4_1();
void f4_2();
void f4_3();
void f4_4();
void f4_5();
void f4_6();
void f4_7();
void f4_8();
void f4_9();
void f5_1();
void f5_2();
void f5_3();
void f5_4();
void f5_5();
void f5_6();
void f5_7();

void main_menu()
{

	setlocale(LC_ALL, "Russian");
	string input;
	int widths[5] = { 5, 50, -1, -1, -1 };
	table::Table dz_list(2, 32, widths, "Список заданий:", 14);
	dz_list.set_data(0, 0, "Номер", 0, 13);
	dz_list.set_data(0, 1, "Название задания", 0, 13);
	for (int i = 1; i < 32; i++)
	{
		dz_list.set_data(i, 0, dz_list_names[0][i - 1], 0, 13);
		dz_list.set_data(i, 1, dz_list_names[1][i - 1], 0, 15);
	}
	while (1)
	{
		system("color 0f");
		system("cls");
		SetColor(0, 11);
		cout << "****   ***  ***  ****  *   *  ***  *****       *   * ***** *   * *  ** " << endl;
		cout << "*     *  * *   * *   * *   * *   * *           ** ** *     *   * * *  *" << endl;
		cout << "*     *  * *   * *   * *   * *   * *           * * * *     *   * * *  *" << endl;
		cout << "*     *  * ***** ****  ***** *   * ****        *   * ****  ***** ***  *" << endl;
		cout << "*     *  * *   * *   * *   * *   * *           *   * *     *   * * *  *" << endl;
		cout << "*     *  * *   * *   * *   * *   * *           *   * *     *   * * *  *" << endl;
		cout << "*    **  * *   * ****  *   *  ***  *****       *   * ***** *   * *  ** " << endl;
		SetColor(0, 15);
		cout << "Введите номер задания (например 1-1) или list для вывода списка заданий.\nВведите 0-0 чтобы выйти." << endl;
		SetColor(0, 12);
		cout << "ВАЖНО!";
		SetColor(0, 15);
		cout << " При вводе чисел в программах дробные числа писать через запятую!\n";

		cin >> input;
		if (input == "0-0")
		{
			break;
		}
		else if (input == "1-1")
		{
			f1_1();
		}
		else if (input == "1-2")
		{
			f1_2();
		}
		else if (input == "1-3")
		{
			f1_3();
		}
		else if (input == "1-4")
		{
			f1_4();
		}
		else if (input == "1-5")
		{
			f1_5();
		}
		else if (input == "2-1")
		{
			f2_1();
		}
		else if (input == "2-2")
		{
			f2_2();
		}
		else if (input == "2-3")
		{
			f2_3();
		}
		else if (input == "2-4")
		{
			f2_4();
		}
		else if (input == "2-5")
		{
			f2_5();
		}
		else if (input == "3-1")
		{
			f3_1();
		}
		else if (input == "3-2")
		{
			f3_2();
		}
		else if (input == "3-3")
		{
			f3_3();
		}
		else if (input == "3-4")
		{
			f3_4();
		}
		else if (input == "3-5")
		{
			f3_5();
		}
		else if (input == "4-1")
		{
			f4_1();
		}
		else if (input == "4-2")
		{
			f4_2();
		}
		else if (input == "4-3")
		{
			f4_3();
		}
		else if (input == "4-4")
		{
			f4_4();
		}
		else if (input == "4-5")
		{
			f4_5();
		}
		else if (input == "4-6")
		{
			f4_6();
		}
		else if (input == "4-7")
		{
			f4_7();
		}
		else if (input == "4-8")
		{
			f4_8();
		}
		else if (input == "4-9")
		{
			f4_9();
		}
		else if (input == "5-1")
		{
			f5_1();
		}
		else if (input == "5-2")
		{
			f5_2();
		}
		else if (input == "5-3")
		{
			f5_3();
		}
		else if (input == "5-4")
		{
			f5_4();
		}
		else if (input == "5-5")
		{
			f5_5();
		}
		else if (input == "5-6")
		{
			f5_6();
		}
		else if (input == "5-7")
		{
			f5_7();
		}
		else if (input == "list")
		{
			dz_list.show();
		}
		else {
			cout << "Неверный ввод" << endl;
		}
		system("pause");
	}
}
int main(int argc, char* argv[])
{
	srand(time(NULL));
	main_menu();
	return 0;
}

void f1_1()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 1-1" << endl;
	cout << "-------------------------------" << endl;
	SetColor(0, 15);
	cout << "Hello Дмитрий" << endl;
}

void f1_2()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 1-2" << endl;
	cout << "-------------------------------" << endl;
	cout << "Калькулятор" << endl << endl;
	SetColor(0, 15);
	float a, b;
	getvar(a, "Введите а", false);
	getvar(b, "Введите b", false);
	cout << "a + b = " << a + b << "\na - b = " << a - b << "\na * b = " << a * b << "\n";
	if (b != 0)
		cout << "a / b = " << a / b << endl;
	else
		cout << "Поделить нельзя :(" << endl;
}

void f1_3()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 1-3" << endl;
	cout << "-------------------------------" << endl;
	cout << "Уравнение: bx + c = 0" << endl << endl;
	SetColor(0, 15);
	float b, c;
	getvar(b, "Введите b", false);
	getvar(c, "Введите c", false);
	if (0 == b)
	{
		if (0 == c)
		{
			cout << "x - любое" << endl;
		}
		else
		{
			cout << "Решений нет" << endl;
		}
	}
	else
	{
		cout << "x = " << (-c / b) << endl;
	}
}

void f1_4()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 1-4" << endl;
	cout << "-------------------------------" << endl;
	cout << "Уравнение: ax^2 + bx + c = 0" << endl << endl;
	SetColor(0, 15);
	float a, b, c;
	getvar(a, "Введите a", false);
	getvar(b, "Введите b", false);
	getvar(c, "Введите c", false);
	if (a == 0)
	{
		if (0 == b)
		{
			if (0 == c)
			{
				cout << "x - любое" << endl;
			}
			else
			{
				cout << "Решений нет" << endl;
			}
		}
		else
		{
			cout << "x = " << (-c / b) << endl;
		}
	}
	else
	{
		float D = b * b - 4 * a * c;
		cout << "Дискриминант = " << D << endl;
		if (D < 0)
		{
			cout << "Решений на действительных числах нет" << endl;
		}
		if (D == 0)
		{
			cout << "x = " << (-b / (2 * a)) << endl;
		}
		if (D > 0)
		{
			cout << "x1 = " << ((-b + sqrt(D)) / (2 * a)) << endl;
			cout << "x2 = " << ((-b - sqrt(D)) / (2 * a)) << endl;
		}
	}
}

void f1_5()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 1-5" << endl;
	cout << "-------------------------------" << endl;
	cout << "Лампочка и шторы" << endl << endl;
	SetColor(0, 15);
	char a[3];
	bool b[3];
	cout << "Лампочка включена? (не 0 - да/0 - нет)" << endl;
	a[0] = _getch();
	b[0] = (a[0] != '0');
	if (b[0])
		cout << "Светло" << endl;
	else
	{
		cout << "Шторы раздвинуты? (не 0 - да/0 - нет)" << endl;
		a[1] = _getch();
		b[1] = (a[1] != '0');
		if (!b[1])
			cout << "Темно" << endl;
		else
		{
			cout << "На улице день? (не 0 - да/0 - нет)" << endl;
			a[2] = _getch();
			b[2] = (a[2] != '0');
			if (b[2])
				cout << "Светло" << endl;
			else
				cout << "Темно" << endl;
		}
	}
}


void f2_1()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 2-1" << endl;
	cout << "-------------------------------" << endl;
	cout << "Конус" << endl;
	SetColor(0, 15);
	double h, R, r, l;
	getvar(h, "Введите высоту конуса", true);
	h = round(h * pow(10, 6)) / pow(10, 6); //округление до 5-го знака после запятой

	getvar(R, "Введите радиус нижнего основания конуса", true);
	R = round(R * pow(10, 6)) / pow(10, 6); //округление до 5-го знака после запятой

	getvar(r, "Введите радиус верхнего основания конуса", true);
	r = round(r * pow(10, 6)) / pow(10, 6); //округление до 5-го знака после запятой
	double V, S;

	l = sqrt((R - r) * (R - r) + h * h);
	if ((r == R) && (R == 0))
	{
		cout << "Получен отрезок: объем - 0, площадь поверхности - 0" << endl;
	}
	else if (r == R)
	{
		cout << "Получен цилиндр" << endl;
		V = pi * r * r * h;
		S = 2 * pi * r * h + 2 * pi * r * r;
		cout << "Объем цилиндра - " << V << ", площадь поверхности - " << S << endl;
	}
	else if (h == 0)
	{
		cout << "Получен диск" << endl;
		R = (R > r) ? R : r;
		S = 2 * pi * R * R;
		cout << "Объем диска - 0, площадь поверхности - " << S << endl;
	}
	else {
		V = (1.0 / 3.0) * pi * h * (R * R + R * r + r * r);
		S = pi * (R * R + (R + r) * l + r * r);
		cout << "Объем усеченного конуса - " << V << ", площадь поверхности - " << S << endl;
	}
}

void f2_2()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 2-2" << endl;
	cout << "-------------------------------" << endl;
	cout << "Разветвление" << endl;
	SetColor(0, 15);
	float a, x;
	getvar(a, "Введите a", false);
	getvar(x, "Введите x", false);
	float w;

	if (abs(x) < 1)
	{
		if (0 == x)
			cout << "Значение w = a * ln|x| не определено на множестве действительных чисел" << endl;
		else
		{
			w = a * log(abs(x));
			cout << "w = a * ln |x| = " << w << endl;
		}
	}
	else
	{
		if (a < x * x)
		{
			cout << "Значение w = sqrt(a - x^2) не определено на множестве действительных чисел" << endl;
		}
		else
		{
			w = sqrt(a - x * x);
			cout << "w = sqrt(a - x^2) = " << w << endl;
		}
	}
}

void f2_3()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 2-3" << endl;
	cout << "-------------------------------" << endl;
	cout << "Функция z = ln (b - y) * sqrt (b - x)" << endl;
	SetColor(0, 15);
	float b, x, y;
	getvar(b, "Введите b", false);
	getvar(x, "Введите x", false);
	getvar(y, "Введите y", false);

	if (!((b - y) > 0) || ((b - x) < 0))
	{
		cout << "Функция при данных b, x, y не определена на множестве действительных чисел" << endl;
	}
	else
	{
		float z = log(b - y) * sqrt(b - x);
		cout << "z = " << z << endl;
	}
}

void f2_4()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 2-4" << endl;
	cout << "-------------------------------" << endl;
	SetColor(0, 15);
	cout << "Порядок" << endl;
	int n;
	getvar(n, "Введите натуральное n", true);
	for (int i = n; i < n + 10; ++i)
	{
		cout << i << " ";
	}
	cout << endl;
}

void f2_5()
{
	system("cls");
	SetColor(0, 14);
	int prec = cout.precision();
	cout << fixed << setprecision(2);
	cout << "===============================" << endl;
	cout << "          Задание 2-5" << endl;
	cout << "-------------------------------" << endl;
	cout << "Табуляция функции y = (x^2 - 2x + 2) / (x - 1)" << endl;
	SetColor(0, 15);
	for (float i = -4; i <= 4; i += 0.5f)
	{
		if (0 == i - 1)
			cout << "x = " << i << "; функция не определена" << endl;
		else
			cout << "x = " << i << ": y = " << ((i * i - 2 * i + 2) / (i - 1)) << endl;
	}
	cout << "Функция не определена на х = 1" << endl;
	cout.unsetf(ios::fixed);
	cout << setprecision(prec);
}

void f3_1()
{
	double m = 0, S, n = 0, p = 0;
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание  3-1" << endl;
	cout << "-------------------------------" << endl;
	cout << "Заем" << endl;
	SetColor(0, 15);
	getvar(S, "Введите сумму заема", true);
	getvar(n, "Введите количество лет", true);
	getvar(p, "Введите процент", false);


	p /= 100;
	bool ok = true;
	if (n == 0)
		m = S;
	else if (p == 0)
		m = S / 12 / n;
	else if ((p == -2) && (int(n) == n) && (int(n) % 2 == 0))
	{
		cout << "Месячную выплату посчитать невозможно" << endl;
		ok = false;
	}
	else
	{
		m = S * p * pow(1 + p, n);
		m /= 12 * (pow(1 + p, n) - 1);
	}
	if (ok) cout << "Месячная выплата = " << m << endl;
}

void f3_2()
{
	double m = 0, S, n = 0, p;
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 3-2" << endl;
	cout << "-------------------------------" << endl;
	cout << "Процент займа" << endl;
	SetColor(0, 15);
	getvar(S, "Введите сумму заема", true);
	while (n == 0)
	{
		getvar(n, "Введите количество лет", true);
		if (n == 0)
		{
			cout << "Неверный ввод" << endl;
		}
	}

	while (m == 0)
	{
		getvar(m, "Введите месячную выплату", true);
		if (m == 0)
		{
			cout << "Неверный ввод" << endl;
		}
	}


	double left = -pow(10, 10), right = pow(10, 10), middle = 0;
	while (true)
	{
		middle = (left + right) / 2;
		double r = middle / 100;
		double t;
		if (r == 0)
			t = S / 12 / n;
		else {
			t = S * r * pow(1 + r, n);
			t /= 12 * (pow(1 + r, n) - 1);
		}

		if (abs(t - m) < 0.01)
		{
			break;
		}
		if (t < m)
		{
			left = middle;
		}
		if (t > m)
		{
			right = middle;
		}
	}
	cout << "Процент займа: " << middle << endl;
}

void f3_3()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 3-3" << endl;
	cout << "-------------------------------" << endl;
	cout << "Файлы" << endl;
	SetColor(0, 15);
	std::ifstream inf("files/file3-3.txt");
	if (inf)
	{
		while (!inf.eof())
		{
			string t;
			getline(inf, t);
			cout << t << endl;
		}
	}
	else
	{
		cout << "Исходный файл (files/file3-3.txt) не найден" << endl;
	}
	std::ofstream ouf("files/ofile3-3.txt");
	if (ouf)
	{
		cout << "Вводите текст для записи: ($ - закончить)" << endl;
		string s = "a";
		while (s != "$")
		{
			char buff[200];
			cin.getline(buff, 200);
			s = buff;
			if (s != "$")
				ouf << s << "\n";
		}
	}
	else
	{
		cout << "Выходной файл (files/ofile3-3.txt) не найден" << endl;
	}
	inf.close();
	ouf.close();
}

void f3_4()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 3-4" << endl;
	cout << "-------------------------------" << endl;
	cout << "Фильтр" << endl;
	SetColor(0, 15);
	std::ifstream inf("files/filterfile3-4.txt");
	bool last_ch_is_num = false;
	if (inf)
	{
		while (!inf.eof())
		{
			char t;
			inf >> t;
			switch (t)
			{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				last_ch_is_num = true;
				cout << t;
				break;
			default:
				if (last_ch_is_num)
				{
					cout << " ";
					last_ch_is_num = false;
				}
				break;
			}
		}
	}
	else
	{
		cout << "Исходный файл (files/filterfile3-4.txt) не найден" << endl;
	}
	cout << endl;
}



void f3_5()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	string s = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя"; //Допустимые буквы
	string a = "";
	char last = ' ';
	while (last != '0')
	{
		system("cls");
		SetColor(0, 14);
		cout << "===============================" << endl;
		cout << "          Задание 3-5" << endl;
		cout << "-------------------------------" << endl;
		cout << "Сортировка" << endl;
		SetColor(0, 15);
		cout << "Вводите буквы: (введите 0 чтобы закончить, введено букв: " << n << ") -> " << endl;
		cout << "Текущая строка: " << a << endl;
		cout << "Допустимые буквы: " << s << endl;
		last = _getch();
		if (s.find_first_of(last) != string::npos)
		{
			n++;
			a = a + last;
		}
		if (last == '0')
		{
			system("cls");
			SetColor(0, 14);
			cout << "===============================" << endl;
			cout << "          Задание 5" << endl;
			cout << "-------------------------------" << endl;
			cout << "Сортировка" << endl;
			SetColor(0, 15);
			cout << "Вводите буквы: (введено букв: " << n << ")";
			cout << endl;
		}
	}
	cout << "Исходные буквы: " << a << endl;

	/*for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			if (findplace(s, a[i]) < findplace(s, a[j]))
			{
				std::swap(a[i], a[j]);
			}
		}
	} старый вариант через поиск в строке*/
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < a.size(); j++)
		{
			if (tolower(a[i]) < tolower(a[j]))
			{
				std::swap(a[i], a[j]);
			}
		}
	}
	int c = 0; //предыдущий символ в нижнем регистре
	int pos_c = 0; //позиция этого символа
	for (int i = 0; i < a.size(); i++)
	{
		int b = tolower(a[i]); //текущий символ в НР
		int pos_b = i; //его позиция
		if (b != c)
		{
			for (int j = pos_c; j < pos_b; j++)
			{
				for (int k = pos_c; k < pos_b; k++)
				{
					if (a[j] < a[k])
						std::swap(a[j], a[k]);
				}
			}
			pos_c = pos_b;
		}
		if (pos_b == a.size() - 1)
		{
			for (int j = pos_c; j <= pos_b; j++)
			{
				for (int k = pos_c; k <= pos_b; k++)
				{
					if (a[j] < a[k])
						std::swap(a[j], a[k]);
				}
			}
		}
		c = b;
	}

	cout << "Отсортированные буквы: " << a << endl;
}

void sign(double a)
{
	if (a < 0)
		cout << "Отрицательное число, знак = -1";
	else if (a == 0)
		cout << "Ноль, знак = 0";
	else
		cout << "Положительное число, знак = 1";
}

void circle()
{
	double r;
	getvar(r, "Введите радиус", true);
	double S = pi * r * r;
	cout << "Площадь круга = " << S << endl;
}

void triangle()
{
	double a, b, c;
	getvar(a, "Введите сторону a", true);
	getvar(b, "Введите сторону b", true);
	getvar(c, "Введите сторону c", true);

	if ((a + b < c) || (a + c < b) || (b + c < a))
	{
		cout << "Такой треугольник не существует" << endl;
	}
	else
	{
		double p = (a + b + c) / 2;
		double S;
		S = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "Площадь треугольника = " << S << endl;
	}
}

void pryamougolnik()
{
	double a, b;
	getvar(a, "Введите сторону a", true);
	getvar(b, "Введите сторону b", true);

	cout << "Площадь = " << a * b << endl;
}

void f4_1()
{
	std::ofstream outf("files/file4-1.txt");
	int n = 0;
	double t = 0;
	while (n != 10)
	{
		system("cls");
		SetColor(0, 14);
		cout << "===============================" << endl;
		cout << "          Задание 4-1" << endl;
		cout << "-------------------------------" << endl;
		cout << "Файл с числами" << endl;
		SetColor(0, 15);
		string hint = "Вводите числа (" + std::to_string(n) + "/10)";
		getvar(t, hint, false);
		outf << t << endl;
		n++;
		system("cls");
	}
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 4-1" << endl;
	cout << "-------------------------------" << endl;
	cout << "Файл с числами" << endl;
	SetColor(0, 15);
	cout << "Вводите числа (10/10) -> введено!" << endl;
	outf.close();
	cout << endl << "Файл закрыт" << endl;
	std::ifstream inf("files/file4-1.txt");
	if (inf)
	{
		cout << endl << "Файл открыт" << endl;
		double S = 0;
		while (!inf.eof())
		{
			double temp;
			inf >> temp;
			S += temp;
		}
		inf.close();
		cout << "Сумма = " << S << endl;
	}
	else {
		cout << "Не удалось открыть файл" << endl;
	}
}

void f4_2()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 4-2" << endl;
	cout << "-------------------------------" << endl;
	cout << "Знак числа" << endl;
	SetColor(0, 15);
	double n;
	getvar(n, "Введите число", false);
	sign(n);
	cout << endl;
}

void f4_3()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 4-3" << endl;
	cout << "-------------------------------" << endl;
	cout << "Площадь" << endl;
	SetColor(0, 15);
	cout << "Выберите фигуру: прямоугольник = P, треугольник = T, круг = C";
	char c = '0';
	while (!((c == 'C') || (c == 'c') || (c == 'T') || (c == 't') || (c == 'P') || (c == 'p')))
	{
		c = _getch();
	}
	cout << endl;
	switch (c)
	{
	case 'c':
	case 'C':
		circle();
		break;
	case 'T':
	case 't':
		triangle();
		break;
	case 'P':
	case 'p':
		pryamougolnik();
		break;
	default:
		break;
	}
}

void f4_4()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 4-4" << endl;
	cout << "-------------------------------" << endl;
	cout << "Флаг США" << endl;
	SetColor(0, 15);
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if ((i < 6) && (j < 8))
			{
				cout << "*";
			}
			else
			{
				cout << "_";
			}
		}
		cout << endl;
	}
}

void f4_5()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 4-5" << endl;
	cout << "-------------------------------" << endl;
	cout << "Синусоида" << endl;
	SetColor(0, 15);
	cout << "                                                  ^ y" << endl;
	char g[101][21];
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			if (j == 10)
				g[i][j] = '-';
			else if (i == 50)
				g[i][j] = '|';
			else
				g[i][j] = ' ';
		}
	}
	for (float x = -5.0f; x < 5.0f; x += 0.1f)
	{
		float y = sin(x);
		g[int(x * 10) + 50][-int(y * 10) - 10] = '*';
	}
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			cout << g[j][i];
		}
		if (i == 10)
			cout << "> x";
		cout << endl;
	}
}

/*int rim_process(int dec, int lastN, int lastDec)
{
	return (lastN > dec) ? (lastDec - dec) : (lastDec + dec);
}

void f4_6() //ПЕРЕДЕЛАТЬ!!!
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 4-6" << endl;
	cout << "-------------------------------" << endl;
	cout << "Римские цифры" << endl;
	SetColor(0, 15);
	string rim = "a";
	string nums = "IVXLCDM";
	while ((rim.find_first_not_of(nums) != string::npos) ||
		(rim.find("IIV") != string::npos) ||
		(rim.find("IIX") != string::npos) ||
		(rim.find("IIL") != string::npos) ||
		(rim.find("IIC") != string::npos) ||
		(rim.find("IID") != string::npos) ||
		(rim.find("IIM") != string::npos) ||
		(rim.find("VVX") != string::npos) ||
		(rim.find("VVL") != string::npos) ||
		(rim.find("VVC") != string::npos) ||
		(rim.find("VVD") != string::npos) ||
		(rim.find("VVM") != string::npos) ||
		(rim.find("XXL") != string::npos) ||
		(rim.find("XXC") != string::npos) ||
		(rim.find("XXD") != string::npos) ||
		(rim.find("XXM") != string::npos) ||
		(rim.find("LLC") != string::npos) ||
		(rim.find("LLD") != string::npos) ||
		(rim.find("LLM") != string::npos) ||
		(rim.find("CCD") != string::npos) ||
		(rim.find("CCM") != string::npos) ||
		(rim.find("DDM") != string::npos))
	{
		cout << "Введите положительное число в римской системе счисления \n(возможные символы: IVXLCDM) -> ";
		cin >> rim;
		if ((rim.find_first_not_of(nums) != string::npos) ||
			(rim.find("IIV") != string::npos) ||
			(rim.find("IIX") != string::npos) ||
			(rim.find("IIL") != string::npos) ||
			(rim.find("IIC") != string::npos) ||
			(rim.find("IID") != string::npos) ||
			(rim.find("IIM") != string::npos) ||
			(rim.find("VVX") != string::npos) ||
			(rim.find("VVL") != string::npos) ||
			(rim.find("VVC") != string::npos) ||
			(rim.find("VVD") != string::npos) ||
			(rim.find("VVM") != string::npos) ||
			(rim.find("XXL") != string::npos) ||
			(rim.find("XXC") != string::npos) ||
			(rim.find("XXD") != string::npos) ||
			(rim.find("XXM") != string::npos) ||
			(rim.find("LLC") != string::npos) ||
			(rim.find("LLD") != string::npos) ||
			(rim.find("LLM") != string::npos) ||
			(rim.find("CCD") != string::npos) ||
			(rim.find("CCM") != string::npos) ||
			(rim.find("DDM") != string::npos))
		{
			cout << "Неверный ввод" << endl;
		}
	}
	int num = 0, last_num = 0;
	for (int i = rim.size() - 1; i >= 0; i--)
	{
		switch (rim[i])
		{
		case 'M':
			num = rim_process(1000, last_num, num);
			last_num = 1000;
			break;
		case 'D':
			num = rim_process(500, last_num, num);
			last_num = 500;
			break;
		case 'C':
			num = rim_process(100, last_num, num);
			last_num = 100;
			break;
		case 'L':
			num = rim_process(50, last_num, num);
			last_num = 50;
			break;
		case 'X':
			num = rim_process(10, last_num, num);
			last_num = 10;
			break;
		case 'V':
			num = rim_process(5, last_num, num);
			last_num = 5;
			break;
		case 'I':
			num = rim_process(1, last_num, num);
			last_num = 1;
			break;
		}
	}

	cout << "Число в арабской системе - " << num << endl;
}*/

void f4_6()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 4-6" << endl;
	cout << "-------------------------------" << endl;
	cout << "Римские цифры" << endl;
	SetColor(0, 15);
	string rim = "a";
	char poss[] = { //Возможные символы
		'I', 'A', 'V', 'B', 'X', 'E', 'L', 'F', 'C', 'G', 'D', 'H', 'M'
		//I  IV   V     IX   X   XL   L    XC    C   CD    D   CM    M
	}; //пояснение: здесь введены другие символы для комбинаций из 2 "классических" римских символов.
	// Это сделано для упрощения кода программы, так как 2 символа считается за один.
	// Для каждого нового символа приведена "старая" комбинация.
	int equals[] = { //Значения в десятичной системе, которым эквивалентны возможные символы
		1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000
	};
	int out = 0;
	while (rim.find_first_not_of("IVXLCDM") != string::npos) //ввод числа. При этом исключаются 
															 //все не относящиеся к римским цифрам символы
	{
		cout << "Введите положительное число в римской системе счисления \nВозможные символы: IVXLCDM -> ";
		cin >> rim;
		if (rim.find_first_not_of("IVXLCDM") != string::npos)
		{
			cout << "Неверный ввод" << endl;
		}
	}
	string rim2 = reverse(rim); //сохраняем число, записанное наоборот, в другую строку
	replaceall(rim, "IV", "A"); //замена комбинаций из 2 символов на 1 символ
	replaceall(rim, "IX", "B");
	replaceall(rim, "XL", "E");
	replaceall(rim, "XC", "F");
	replaceall(rim, "CD", "G");
	replaceall(rim, "CM", "H");

	replaceall(rim2, "MC", "H"); //то же самое, но в обратном порядке
	replaceall(rim2, "DC", "G");
	replaceall(rim2, "CX", "F");
	replaceall(rim2, "LX", "E");
	replaceall(rim2, "XI", "B");
	replaceall(rim2, "VI", "A");

	rim2 = reverse(rim2);

	bool ok = true;
	if (rim != rim2)
		//если есть разночтения типа IXL, связанные с разным порядком просмотра записи, то такого числа у римлян не было
	{
		//cout << "Дебаг: строки не равны" << endl;
		ok = !ok;
	}

	string rim3 = rim;

	for (int i = 0; i < rim3.size(); i++)
	{
		for (int j = 0; j < rim3.size(); j++)
		{
			if (findplace("IAVBXELFCGDHM", rim3[i]) > findplace("IAVBXELFCGDHM", rim3[j]))
			{
				swap(rim3[i], rim3[j]);
			}
		}
	}

	if (ok && (rim3 != rim))
	{
		ok = !ok;
	}

	if (ok && ((num_of_symbols(rim, 'A') > 1) || (num_of_symbols(rim, 'B') > 1) || (num_of_symbols(rim, 'E') > 1) ||
		(num_of_symbols(rim, 'F') > 1) || (num_of_symbols(rim, 'G') > 1) || (num_of_symbols(rim, 'H') > 1)))
		//если есть 2 одинаковых "составных" символа
	{
		//cout << "Дебаг: есть два однаковых составных символа" << endl;
		ok = !ok;
	}

	if (ok && ((num_of_symbols(rim, 'A') + num_of_symbols(rim, 'B')) > 1 || (num_of_symbols(rim, 'E') +
		num_of_symbols(rim, 'F')) > 1 || (num_of_symbols(rim, 'G') + num_of_symbols(rim, 'H')) > 1))
		//если одновременно есть оба "составных" символа, отвечающих за один и тот же разряд
	{
		//cout << "Дебаг: есть два составных символа отвечающих за 1 разряд" << endl;
		ok = !ok;
	}

	if (ok && //проверка на разночтения в записи типа IVI
		(
		(rim.find("IA") != string::npos) || //IIV
			(rim.find("AI") != string::npos) || //IVI
			(rim.find("IB") != string::npos) || //IIX
			(rim.find("BI") != string::npos) || //IXI
			(rim.find("XE") != string::npos) || //XXL
			(rim.find("EX") != string::npos) || //XLX
			(rim.find("XF") != string::npos) || //XXC
			(rim.find("FX") != string::npos) || //XCX
			(rim.find("CG") != string::npos) || //CCD
			(rim.find("GC") != string::npos) || //CDC
			(rim.find("CH") != string::npos) || //CCM
			(rim.find("HC") != string::npos) || //CMC
			(rim.find("VV") != string::npos) || //VV
			(rim.find("LL") != string::npos) || //LL
			(rim.find("DD") != string::npos) //DD
			)
		)
	{
		//cout << "Дебаг: есть запрещенные комбинации" << endl;
		ok = !ok;
	}

	if (ok) //проверка на 4 и более одинаковых символа подряд
	{
		int count = 1;
		char last = ' ';
		for (int i = 0; i < rim.size(); i++)
		{
			if (rim[i] == last)
			{
				count++;
			}
			else
			{
				count = 1;
			}
			if (count > 3)
			{
				ok = !ok;
				break;
			}
			last = rim[i];
		}
	}

	if (ok) //если такое число все-таки могло быть записано римлянами, то переводим его
	{
		for (int i = 0; i < rim.size(); i++)
		{
			for (int j = 0; j < 13; j++)
			{
				if (rim[i] == poss[j])
				{
					out += equals[j];
				}
			}
		}
		cout << "Число в арабской системе - " << out << endl;
	}
	else //если нет, то оповещаем пользователя об этом
		cout << "Введенное число не существует в римской системе" << endl;

}

const int s0 = 1;

int random(int i, int m, int a, int c)
{
	if (i == 0)
	{
		return s0;
	}
	else
	{
		return (a * random(i - 1, m, a, c) + c) % m;
	}
}

void f4_7()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 4-7" << endl;
	cout << "-------------------------------" << endl;
	cout << "\"Случайные\" числа" << endl;
	SetColor(0, 15);
	int i = 0;
	getvar(i, "Введите число", true);
	int const_m = 31;
	int const_a = 12;
	int const_c = 15;
	if (i > 4480)
	{
		cout << "Число слишком большое: сгенерировать число невозможно (иначе может быть stack overflow)" << endl << "Максимально допустимое число: 4480" << endl;
	}
	else
	{
		cout << "Сгенерировано число " << random(i, const_m, const_a, const_c) << endl;
	}
}
void f4_8()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 4-8" << endl;
	cout << "-------------------------------" << endl;
	cout << "Про продавцов" << endl;
	SetColor(0, 15);
	float A[3][4];
	float B[4][2];
	float C[3][2];
	//init
	A[0][0] = 5.0f;
	A[0][1] = 2.0f;
	A[0][2] = 0.0f;
	A[0][3] = 10.0f;
	A[1][0] = 3.0f;
	A[1][1] = 5.0f;
	A[1][2] = 2.0f;
	A[1][3] = 5.0f;
	A[2][0] = 20.0f;
	A[2][1] = 0.0f;
	A[2][2] = 0.0f;
	A[2][3] = 0.0f;

	B[0][0] = 1.2f;
	B[0][1] = 0.5f;
	B[1][0] = 2.8f;
	B[1][1] = 0.4f;
	B[2][0] = 5.0f;
	B[2][1] = 1.0f;
	B[3][0] = 2.0f;
	B[3][1] = 1.5f;

	int TableAColWidth[5] = { 8, 11, 11, 11, 11 };
	table::Table TableA(5, 4, TableAColWidth, "Таблица А", 14);
	TableA.set_data(0, 0, "Продавец", 0, 13);
	TableA.set_data(0, 1, "Товары", 0, 13);
	for (int i = 1; i < 4; i++)
	{
		TableA.set_data(i, 0, to_string(i), 0, 13);
		TableA.set_data(i, 1, to_string(A[i - 1][0]).erase(to_string(A[i-1][0]).find(",") + 3), 0, 15);
		TableA.set_data(i, 2, to_string(A[i - 1][1]).erase(to_string(A[i - 1][1]).find(",") + 3), 0, 15);
		TableA.set_data(i, 3, to_string(A[i - 1][2]).erase(to_string(A[i - 1][2]).find(",") + 3), 0, 15);
		TableA.set_data(i, 4, to_string(A[i - 1][3]).erase(to_string(A[i - 1][3]).find(",") + 3), 0, 15);
	}
	TableA.show();
	cout << endl;

	int TableBColWidth[5] = { 8, 11, 12, -1, -1 };
	table::Table TableB(3, 5, TableBColWidth, "Таблица B", 14);
	TableB.set_data(0, 0, "Продавец", 0, 13);
	TableB.set_data(0, 1, "Цена", 0, 13);
	TableB.set_data(0, 2, "Комиссионные", 0, 13);
	for (int i = 1; i < 5; i++)
	{
		TableB.set_data(i, 0, to_string(i), 0, 13);
		TableB.set_data(i, 1, to_string(B[i - 1][0]).erase(to_string(B[i - 1][0]).find(",") + 3), 0, 15);
		TableB.set_data(i, 2, to_string(B[i - 1][1]).erase(to_string(B[i - 1][1]).find(",") + 3), 0, 15);
	}
	TableB.show();
	cout << endl;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 2; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}

	int TableCColWidth[5] = { 8, 11, 12, -1, -1 };
	table::Table TableC(3, 4, TableCColWidth, "Таблица C", 14);
	TableC.set_data(0, 0, "Продавец", 0, 13);
	TableC.set_data(0, 1, "Выручка", 0, 13);
	TableC.set_data(0, 2, "Комиссионные", 0, 13);
	for (int i = 1; i < 5; i++)
	{
		TableC.set_data(i, 0, to_string(i), 0, 13);
		TableC.set_data(i, 1, to_string(C[i - 1][0]).erase(to_string(C[i - 1][0]).find(",") + 3), 0, 15);
		TableC.set_data(i, 2, to_string(C[i - 1][1]).erase(to_string(C[i - 1][1]).find(",") + 3), 0, 15);
	}
	TableC.show();
	cout << endl;

	int minn, maxn; float minv = 10000.0f, maxv = 0.0f;
	for (int i = 0; i < 3; i++)
	{
		if (C[i][0] > maxv)
		{
			maxv = C[i][0];
			maxn = i + 1;
		}
		if (C[i][0] < minv)
		{
			minv = C[i][0];
			minn = i + 1;
		}
	}

	cout << "Больше всего выручил продавец " << maxn << ", меньше всего - " << minn << endl;
	minv = 10000.0f; maxv = 0.0f;
	for (int i = 0; i < 3; i++)
	{
		if (C[i][1] > maxv)
		{
			maxv = C[i][1];
			maxn = i + 1;
		}
		if (C[i][1] < minv)
		{
			minv = C[i][1];
			minn = i + 1;
		}
	}
	cout << "Больше всего комиссионных получил продавец " << maxn << ", меньше всего - " << minn << endl;
	cout << "Общая выручка - " << C[0][0] + C[1][0] + C[2][0] << endl;
	cout << "Общие комиссионные - " << C[0][1] + C[1][1] + C[2][1] << endl;
	cout << "Через продавцов прошло " << C[0][0] + C[1][0] + C[2][0] + C[0][1] + C[1][1] + C[2][1] << " рублей" << endl;
}

void f4_9()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 4-9" << endl;
	cout << "-------------------------------" << endl;
	cout << "Системы счисления" << endl;
	SetColor(0, 15);
	string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int max_CS = 36; //max counting system - максимальная система счисления
	int min_CS = 2; //аналогично max_CS
	int CS_in = 0, CS_out = 0; //входная СС и выходная СС
	string num_in = "a", num_out; //входное и выходное число
	while ((CS_in < 2) || (CS_in > 36))
	{
		getvar(CS_in, "Введите исходную СС (2-36)", true);
		if ((CS_in < 2) || (CS_in > 36))
			cout << "Неверный ввод" << endl;
	}

	while ((CS_out < 2) || (CS_out > 36))
	{
		getvar(CS_out, "Введите конечную СС (2-36)", true);
		if ((CS_out < 2) || (CS_out > 36))
			cout << "Неверный ввод" << endl;
	}

	while ((num_in.find_first_not_of(alphabet) != string::npos) || (num_in.size() > 20))
	{
		cout << "Введите число в " << CS_in << "-й СС (максимум 20 знаков): ";
		cin >> num_in;
		if ((num_in.find_first_not_of(alphabet) != string::npos) || (num_in.size() > 20))
			cout << "Неверный ввод" << endl;
	}

	bool ok = true;
	//проверка на существование заданного числа в CS_in-й СС
	for (int i = 0; i < num_in.size(); i++)
	{
		if (findplace(alphabet, num_in[i]) > findplace(alphabet, alphabet[CS_in - 1]))
		{
			cout << "Число " << num_in << " не существует в " << CS_in << "-й СС" << endl;
			ok = false;
			break;
		}
	}

	int64_t decimal = 0;
	int power = 0;
	if (ok)
	{
		for (int i = num_in.size() - 1; i >= 0; i--)
		{
			decimal += findplace(alphabet, num_in[i]) * pow(CS_in, power);
			power++;
		}
		while (decimal > 0)
		{
			num_out += alphabet[decimal % CS_out];
			decimal /= CS_out;
		}
		cout << "Число " << num_in << " (" << CS_in << "сс) в " << CS_out << "-й СС: ";
		for (int i = num_out.size() - 1; i >= 0; i--)
			cout << num_out[i];
		cout << endl;
	}
}

void f5_1()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 5-1" << endl;
	cout << "-------------------------------" << endl;
	cout << "Алгоритм Евклида" << endl;
	SetColor(0, 15);
	int a = 0, b = 0;
	while (a == 0)
	{
		getvar(a, "Введите положительное целое число а", true);
		if (a == 0)
		{
			cout << "Неверный ввод" << endl;
		}
	}
	while (b == 0)
	{
		getvar(b, "Введите положительное целое число b", true);
		if (b == 0)
		{
			cout << "Неверный ввод" << endl;
		}
	}

	int nod = 1;
	for (int i = 1; i <= min(a, b); i++)
	{
		if ((a % i == 0) && (b % i == 0))
			nod = i;
	}
	cout << "Наибольший общий делитель этих чисел = " << nod << endl;
}

void f5_2()
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 5-2" << endl;
	cout << "-------------------------------" << endl;
	cout << "Решето Эратосфена" << endl;
	SetColor(0, 15);

	int a = 0;
	while (a < 2)
	{
		getvar(a, "Введите целое число, большее или равное 2", true);
		if (a < 2)
			cout << "Неверный ввод" << endl;
	}

	cout << "Простые числа от 2 до " << a << ": " << endl << setw(7) << 2;
	int k = 0;
	for (int i = 3; i <= a; i++)
	{
		bool simple = true;
		for (int j = 2; j < (i / 2 + 1); j++)
		{
			if (i % j == 0)
			{
				simple = false;
			}
		}
		if (simple)
		{
			cout << ", ";
			k++;
			if (k == 10)
			{
				cout << endl;
				k = 0;
			}
			cout << setw(7) << i;
		}
			
	}
	cout << endl;
}

void f5_3()
{ //посимвольная сортировка
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 5-3" << endl;
	cout << "-------------------------------" << endl;
	cout << "Обработка текстовых файлов 1" << endl;
	SetColor(0, 15);
	SetColor(0, 11);
	cout << "Что происходит: посимвольная сортировка" << endl;
	SetColor(0, 15);
	fstream inf("files/file5-3.txt", ios::in);
	if (inf)
	{
		string a;
		inf >> a;
		cout << "Исходная строка: " << a << endl;
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < a.size(); j++)
			{
				if (a[i] < a[j])
					swap(a[i], a[j]);
			}
		}
		cout << "Отсортированная строка: " << a << endl;
	}
	else
	{
		cout << "Невозможно открыть исходный файл files/file5-3.txt" << endl;
	}
	inf.close();
}

void f5_4()
{ //чтение текста из текстового файла
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 5-4" << endl;
	cout << "-------------------------------" << endl;
	cout << "Обработка текстовых файлов 2" << endl;
	SetColor(0, 15);
	SetColor(0, 11);
	cout << "Что происходит: чтение текста из файла" << endl;
	SetColor(0, 15);
	fstream inf("files/file5-4.txt", ios::in);
	if (inf)
	{
		string i;
		while (!inf.eof())
		{
			getline(inf, i);
			cout << i << endl;
		}
	}
	else
	{
		cout << "Невозможно открыть исходный файл files/file5-4.txt" << endl;
	}
	inf.close();
}

void f5_5()
{ //в строке символов записать наоборот пятое слово, если оно есть
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 5-5" << endl;
	cout << "-------------------------------" << endl;
	cout << "Ряды 1" << endl;
	SetColor(0, 15);
	SetColor(0, 11);
	cout << "Что происходит: в строке символов ищется пятое слово и, если оно есть, выводится в обратном порядке на экран" << endl;
	SetColor(0, 15);
	char ch = ' ';
	bool ok = true;
	string relativepath = "a";
	string s;
	cout << "Как вы хотите задать строку? (f - через файл, любой другой символ - вручную)\n";
	ch = _getch();
	getline(cin, s);
	if (ch == 'f')
	{
		cout << "Задайте относительный путь (от файла программы до исходного файла):" << endl;
		cin >> relativepath;
		fstream inf(relativepath, ios::in);
		if (inf)
		{
			getline(inf, s);
		}
		else
		{
			cout << "По данному пути файл не найден" << endl;
			ok = false;
		}
		inf.close();
	}
	else {
		cout << "Введите строку: " << endl;
		getline(cin, s);
	}

	if (ok)
	{
		cout << "Исходная строка: " << s << endl;
		size_t spaces[5] = {0, 0, 0, 0, 0};
		int index = 0;
		for (int i = 0; i < 5; i++)
		{
			spaces[i] = s.find(' ', index);
			if (spaces[i] == string::npos)
				break;
			index = spaces[i] + 1;
		}
		string s1 = "";
		if (spaces[3] && spaces[4])
		{
			for (int i = spaces[3] + 1; i < spaces[4]; i++)
			{
				s1 += s[i];
			}
			cout << "Пятое слово в строке наоборот: " << reverse(s1) << endl;
		}
		else
		{
			cout << "Пятое слово в строке не найдено" << endl;
		}
	}
}

void f5_6()
{ //сколько раз введенное с клавиатуры число встречается в массиве и на каких позициях
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание 5-6" << endl;
	cout << "-------------------------------" << endl;
	cout << "Ряды 2" << endl;
	SetColor(0, 15);
	SetColor(0, 11);
	cout << "Что происходит: в случайно сгенерированном массиве ищется введенное с клавиатуры число и, если оно есть,\n на экран выводятся все позиции, на которых это число находится" << endl;
	SetColor(0, 15);
	int a; int b;
	int n = 0;
	SetColor(0, 14);
	cout << "Часть 1: настройка массива" << endl;
	SetColor(0, 15);

	getvar(a, "Введите нижнюю границу диапазона", false);
	b = a - 1;
	while (b < a)
	{
		getvar(b, "Введите верхнюю границу диапазона", false);
		if (b < a)
			cout << "Неверный ввод" << endl;
	}

	while (n == 0)
	{
		getvar(n, "Введите количество чисел в массиве > 0", true);
		if (n == 0)
		{
			cout << "Неверный ввод" << endl;
		}
	}

	int* N = new int[n];
	for (int i = 0; i < n; i++)
	{
		N[i] = rand() % (abs(a - b) + 1) + a;
	}

	SetColor(0, 14);
	cout << "Часть 2: поиск числа" << endl;
	SetColor(0, 15);
	int search = 0;
	getvar(search, "Введите искомое число", false);

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (N[i] == search)
		{
			count++;
			cout << "Число найдено на позиции " << i+1 << endl;
		}
	}
	if (count)
	{
		cout << "Всего найдено чисел " << search << ": " << count << endl;
	}
	else
	{
		cout << "Число " << search << " не найдено ни разу" << endl;
	}
	delete[] N;
}

void f5_7()
{ //номер зачетки, фио, список из 5 предметов с оценками.
	//Подсчитать среднюю успеваемость группы, вывести список всех студентов, у которых успеваемость выше средней

}
