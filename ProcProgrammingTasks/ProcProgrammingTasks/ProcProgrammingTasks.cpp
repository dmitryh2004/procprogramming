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
#include "Table.h"
#include "functions.h"
#include "input_processing.h"
#include "Task7_2Code.h"

using namespace std;

const double pi = 3.14159;
const double e = 2.71828;

string dz_list_names[2][37] = {
	{"1-1", "1-2", "1-3", "1-4", "1-5",
	"2-1", "2-2", "2-3", "2-4", "2-5",
	"3-1", "3-2", "3-3", "3-4", "3-5",
	"4-1", "4-2", "4-3", "4-4", "4-5",
	"4-6", "4-7", "4-8", "4-9",
	"5-1", "5-2", "5-3", "5-4", "5-5", "5-6", "5-7",
	"6-1",
	"7-1", "7-2", "7-3", "7-4", "7-5"},
	{"Имя", "Калькулятор", "Уравнение: bx + c = 0", "Уравнение: ax^2 + bx + c = 0", "Лампочка и шторы",
	"Конус", "Разветвление", "Функция z = ln (b - y) * sqrt (b - x)", "Порядок", "Табуляция функции y = (x^2 - 2x + 2) / (x - 1)",
	"Займ", "Процент займа", "Файлы", "Фильтр", "Сортировка",
	"Файл с числами", "Знак числа", "Площадь", "Флаг США", "Синусоида",
	"Римские цифры", "\"Случайные\" числа", "Про продавцов", "Системы счисления",
	"Алгоритм Евклида", "Решето Эратосфена", "Обработка текстовых файлов 1", "Обработка текстовых файлов 2", "Ряды 1", "Ряды 2", "Файлы",
	"Шарики",
	"Монахи", "Порт (на автомат)", "Точки", "Проверка скобочных выражений", "Цифровой корень"}
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
void f6_1();
void f7_1();
void f7_2_Avtomat();
void f7_3();
void f7_4();
void f7_5();

void main_menu()
{
	setlocale(LC_ALL, "Russian");
	string input;
	int widths[5] = { 5, 50, -1, -1, -1 };
	table::Table dz_list(2, 38, widths, "Список заданий:", 14);
	dz_list.set_data(0, 0, "Номер", 0, 13);
	dz_list.set_data(0, 1, "Название задания", 0, 13);
	for (int i = 1; i < 38; i++)
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
		else if (input == "6-1")
		{
			f6_1();
		}
		else if (input == "7-1")
		{
			f7_1();
		}
		else if (input == "7-2")
		{
			f7_2_Avtomat();
		}
		else if (input == "7-3")
		{
			f7_3();
		}
		else if (input == "7-4")
		{
			f7_4();
		}
		else if (input == "7-5")
		{
			f7_5();
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
	show_title(dz_list_names[0][0], dz_list_names[1][0]);
	cout << "Hello Дмитрий" << endl;
}

void f1_2()
{
	show_title(dz_list_names[0][1], dz_list_names[1][1]);
	float a, b;
	getvar(a, "Введите а", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(b, "Введите b", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
	cout << "a + b = " << a + b << "\na - b = " << a - b << "\na * b = " << a * b << "\n";
	if (b != 0)
		cout << "a / b = " << a / b << endl;
	else
		cout << "Поделить нельзя :(" << endl;
}

void f1_3()
{
	show_title(dz_list_names[0][2], dz_list_names[1][2]);
	float b, c;
	getvar(b, "Введите b", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(c, "Введите c", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
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
	show_title(dz_list_names[0][3], dz_list_names[1][3]);
	float a, b, c;
	getvar(a, "Введите a", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(b, "Введите b", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(c, "Введите c", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
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
	show_title(dz_list_names[0][4], dz_list_names[1][4]);
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
	show_title(dz_list_names[0][5], dz_list_names[1][5]);
	double h, R, r, l;
	getvar(h, "Введите высоту конуса", true, *greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	h = round(h * pow(10, 6)) / pow(10, 6); //округление до 5-го знака после запятой

	getvar(R, "Введите радиус нижнего основания конуса", true, *greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	R = round(R * pow(10, 6)) / pow(10, 6); //округление до 5-го знака после запятой

	getvar(r, "Введите радиус верхнего основания конуса", true, *greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
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
	show_title(dz_list_names[0][6], dz_list_names[1][6]);
	float a, x;
	getvar(a, "Введите a", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(x, "Введите x", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
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
	show_title(dz_list_names[0][7], dz_list_names[1][7]);
	float b, x, y;
	getvar(b, "Введите b", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(x, "Введите x", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(y, "Введите y", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);

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
	show_title(dz_list_names[0][8], dz_list_names[1][8]);
	int n;
	getvar(n, "Введите натуральное n", true, *greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	for (int i = n; i < n + 10; ++i)
	{
		cout << i << " ";
	}
	cout << endl;
}

void f2_5()
{
	int prec = cout.precision();
	cout << fixed << setprecision(2);
	show_title(dz_list_names[0][9], dz_list_names[1][9]);
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
	show_title(dz_list_names[0][10], dz_list_names[1][10]);
	getvar(S, "Введите сумму заема", true, *greater_or_equals_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(n, "Введите количество лет", true, *greater_or_equals_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(p, "Введите процент", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);


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
	double m = 0, S, n = 0;
	show_title(dz_list_names[0][11], dz_list_names[1][11]);
	getvar(S, "Введите сумму заема", true, *greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(n, "Введите количество лет", true, *greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(m, "Введите месячную выплату", true, *greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);


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
	show_title(dz_list_names[0][12], dz_list_names[1][12]);
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
	show_title(dz_list_names[0][13], dz_list_names[1][13]);
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
	int n = 0;
	string s = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"; //Допустимые буквы
	string a = "";
	char last = ' ';
	while (last != '0')
	{
		show_title(dz_list_names[0][14], dz_list_names[1][14]);
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
			show_title(dz_list_names[0][14], dz_list_names[1][14]);
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
	getvar(r, "Введите радиус", true, *greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	double S = pi * r * r;
	cout << "Площадь круга = " << S << endl;
}

void triangle()
{
	double a, b, c;
	getvar(a, "Введите сторону a", true, *greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(b, "Введите сторону b", true, *greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(c, "Введите сторону c", true, *greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);

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
	getvar(a, "Введите сторону a", true, *greater_or_equals_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(b, "Введите сторону b", true, *greater_or_equals_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);

	cout << "Площадь = " << a * b << endl;
}

void f4_1()
{
	std::ofstream outf("files/file4-1.txt");
	int n = 0;
	double t = 0;
	while (n != 10)
	{
		show_title(dz_list_names[0][15], dz_list_names[1][15]);
		string hint = "Вводите числа (" + std::to_string(n) + "/10)";
		getvar(t, hint, false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
		outf << t << endl;
		n++;
		system("cls");
	}
	show_title(dz_list_names[0][15], dz_list_names[1][15]);
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
	show_title(dz_list_names[0][16], dz_list_names[1][16]);
	double n;
	getvar(n, "Введите число", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
	sign(n);
	cout << endl;
}

void f4_3()
{
	show_title(dz_list_names[0][17], dz_list_names[1][17]);
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
	show_title(dz_list_names[0][18], dz_list_names[1][18]);
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if ((i < 6) && (j < 8))
			{
				SetColor(9, 15);
				cout << "*";
				SetColor(0, 15);
			}
			else
			{
				SetColor(12, 15);
				cout << "_";
				SetColor(0, 15);
			}
		}
		cout << endl;
	}
}

void f4_5()
{
	show_title(dz_list_names[0][19], dz_list_names[1][19]);
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
	show_title(dz_list_names[0][20], dz_list_names[1][20]);
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
	show_title(dz_list_names[0][21], dz_list_names[1][21]);
	int i = 0;
	getvar(i, "Введите число", true, *greater_or_equals_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
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
	show_title(dz_list_names[0][22], dz_list_names[1][22]);
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
		TableA.set_data(i, 1, to_string(A[i - 1][0]).erase(to_string(A[i - 1][0]).find(",") + 3), 0, 15);
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
	show_title(dz_list_names[0][23], dz_list_names[1][23]);
	string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int max_CS = 36; //max counting system - максимальная система счисления
	int min_CS = 2; //аналогично max_CS
	int CS_in = 0, CS_out = 0; //входная СС и выходная СС
	string num_in = "a", num_out = "", num_out_float = ""; //входное и выходное число

	getvar(CS_in, "Введите исходную СС (2-36)", true, NULL, *is_in_or_equal, NULL, 0, 2, 36, 0, 0, 0);

	getvar(CS_out, "Введите конечную СС (2-36)", true, NULL, *is_in_or_equal, NULL, 0, 2, 36, 0, 0, 0);

	while ((num_in.find_first_not_of(alphabet + ",-") != string::npos) || (num_in.size() > 25))
	{
		cout << "Введите число в " << CS_in << "-й СС (максимум 25 знаков): ";
		cin >> num_in;
		if ((num_in.find_first_not_of(alphabet + ",-") != string::npos) || (num_in.size() > 25))
			cout << "Неверный ввод" << endl;
	}

	bool ok = true;
	bool is_float = false;
	bool is_negative = false;
	//проверка на существование заданного числа в CS_in-й СС
	for (int i = 0; i < num_in.size(); i++)
	{
		if (num_in[i] == '-')
		{
			if (is_negative)
			{
				cout << "Ошибка в записи числа: обнаружен лишний минус" << endl;
				ok = false;
				break;
			}
			is_negative = true;
			continue;
		}
		if (num_in[i] == ',')
		{
			if (is_float)
			{
				cout << "Ошибка в записи числа: обнаружена лишняя запятая" << endl;
				ok = false;
				break;
			}
			is_float = true;
			continue;
		}
		if (findplace(alphabet, num_in[i]) > findplace(alphabet, alphabet[CS_in - 1]))
		{
			cout << "Число " << num_in << " не существует в " << CS_in << "-й СС" << endl;
			ok = false;
			break;
		}
	}

	int64_t decimal = 0;
	long double float_decimal = 0.0f;
	int power = 0;
	if (ok)
	{
		if (is_float)
		{
			//целая часть
			for (int i = num_in.find(',') - 1; i >= 0; i--) //переводим целую часть в десятичную систему
			{
				if (num_in[i] == '-')
				{
					continue;
				}
				decimal += findplace(alphabet, num_in[i]) * pow(CS_in, power);
				power++;
			}
			while (decimal > 0) //а потом в выходную систему
			{
				num_out += alphabet[decimal % CS_out];
				decimal /= CS_out;
			}
			num_out = reverse(num_out);
			//дробная часть
			power = 0;
			for (int i = num_in.find(',') + 1; i < num_in.size(); i++) //переводим дробную часть в десятичную систему
			{
				power--;
				float_decimal += findplace(alphabet, num_in[i]) * pow(CS_in, power);
			}
			if (power < -15)
			{
				SetColor(0, 14);
				cout << "Внимание: возможна потеря точности при переводе" << endl;
				SetColor(0, 15);
			}
			//определяем количество разрядов после запятой, достаточных для перевода без потери точности
			double L = 0;
			L = -log(pow(10, power) / 2) / log(CS_out);
			int L_int = int(L) + 1;
			bool need_round = true;
			for (int i = 1; i <= L_int; i++) //переводим дробную часть в систему CS_out
			{
				num_out_float += alphabet[min(int(float_decimal * CS_out), CS_out - 1)];
				float_decimal *= CS_out;
				float_decimal -= int(float_decimal);
				if (float_decimal == 0) //если число переведено, то заканчиваем перевод, округление не требуется
				{
					need_round = false;
					break;
				}
			}
			if (need_round)
			{
				int last_index = findplace(alphabet, num_out_float[num_out_float.size() - 1]); //смотрим последнюю цифру числа
				if (last_index / double(CS_out) >= 0.5) //если ее значение больше половины значения самой большой цифры в выходной СС
				{
					bool done = false;
					int count = -1;
					while (!done)
					{
						count++; //увеличиваем номер разряда
						if (count == num_out_float.size()) //если мы прошли всю дробную часть, то переходим к целой части
						{
							int count_int = -1;
							while (1)
							{
								count_int++; //увеличиваем номер разряда
								if (count_int == num_out.size()) //если мы прошли и всю целую часть
								{
									num_out.insert(0, 1, '1'); //то добавляем единицу в начало
									done = true; //выходим из цикла округления
									break;
								}
								num_out[num_out.size() - (count_int + 1)] = //увеличиваем очередной разряд на 1
									alphabet[findplace(alphabet, num_out[num_out.size() - (count_int + 1)])];
								if (findplace(alphabet, num_out[num_out.size() - (count_int + 1)]) + 1 < CS_out) //если он в рамках
									//выходной системы, то прекращаем
									break;
								else {
									num_out[num_out.size() - (count_int + 1)] = '0'; //разряд обнулился, возникла единица переноса
								}
							}
							is_float = false;
							done = true;
							if (done)
								break;
						}
						num_out_float[num_out_float.size() - (count + 1)] = //увеличиваем очередной разряд на 1
							alphabet[findplace(alphabet, num_out_float[num_out_float.size() - (count + 1)])];
						if (findplace(alphabet, num_out_float[num_out_float.size() - (count + 1)]) + 1 < CS_out) //если он в рамках
							//выходной системы, то прекращаем
							break;
						else {
							num_out_float[num_out_float.size() - (count + 1)] = '0'; //разряд обнулился, возникла единица переноса
						}
					}

				}
			}
			for (int i = num_out_float.size() - 1; i >= 0; i--) //удаляем незначащие нули в дробной части
				if (num_out_float[i] == '0')
					num_out_float.erase(i);
				else
					break;
		}
		else
		{
			for (int i = num_in.size() - 1; i >= 0; i--) //переводим число в десятичную систему
			{
				if (num_in[i] == '-')
				{
					continue;
				}
				decimal += findplace(alphabet, num_in[i]) * pow(CS_in, power);
				power++;
			}
			while (decimal > 0) //а потом в выходную систему
			{
				num_out += alphabet[decimal % CS_out];
				decimal /= CS_out;
			}
			num_out = reverse(num_out);
		}
		cout << "Число " << num_in << " (" << CS_in << "сс) в " << CS_out << "-й СС: ";
		if (is_negative)
			cout << "-";
		if (num_out == "")
			cout << 0;
		else
			cout << num_out;
		if (is_float)
			cout << "," << num_out_float;
		cout << endl;
	}
}

void f5_1()
{
	show_title(dz_list_names[0][24], dz_list_names[1][24]);
	int a = 0, b = 0;
	getvar(a, "Введите положительное целое число а", true, *greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(b, "Введите положительное целое число b", true, *greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);

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
	show_title(dz_list_names[0][25], dz_list_names[1][25]);

	int64_t a = 0;
	getvar(a, "Введите целое число, большее или равное 2", true, *greater_or_equals_1v, NULL, NULL, 2, 0, 0, 0, 0, 0);
	int k = 0, n = 1;
	for (int64_t i = 3; i <= a; i++)
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
			n++;
		}
	}
	cout << "Всего простых чисел от 2 до " << a << ": " << n << endl;
	cout << "Нажмите \"s\", чтобы показать найденные простые числа ";
	SetColor(0, 12);
	cout << "(может занять долгое время)" << endl;
	SetColor(0, 15);
	if (tolower(_getch()) == 's')
	{
		cout << "Простые числа от 2 до " << a << ": " << endl << 2;
		for (int64_t i = 3; i <= a; i++)
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
				cout << ",\t";
				k++;
				if (k == 10)
				{
					cout << endl;
					k = 0;
				}
				cout << i;
			}
		}
		cout << endl;
	}
}

void f5_3()
{ //посимвольная сортировка
	show_title(dz_list_names[0][26], dz_list_names[1][26]);
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
	show_title(dz_list_names[0][27], dz_list_names[1][27]);
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
	show_title(dz_list_names[0][28], dz_list_names[1][28]);
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
		string temp = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (!((s[i] == ' ') && (s[i - 1] == ' ')))
				temp += s[i];
		}
		size_t spaces[5] = { 0, 0, 0, 0, 0 };
		int index = 0;
		for (int i = 0; i < 5; i++)
		{
			spaces[i] = temp.find(' ', index);
			if (spaces[i] == string::npos)
				break;
			index = spaces[i] + 1;
		}
		string s1 = "";
		if (spaces[3] && spaces[4])
		{
			spaces[4] = min(spaces[4], temp.size());
			for (int i = spaces[3] + 1; i < spaces[4]; i++)
			{
				s1 += temp[i];
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
	show_title(dz_list_names[0][29], dz_list_names[1][29]);
	SetColor(0, 11);
	cout << "Что происходит: в случайно сгенерированном массиве ищется введенное с клавиатуры число и, если оно есть,\n на экран выводятся все позиции, на которых это число находится" << endl;
	SetColor(0, 15);
	int a; int b;
	int n = 0;
	SetColor(0, 14);
	cout << "Часть 1: настройка массива" << endl;
	SetColor(0, 15);

	getvar(a, "Введите нижнюю границу диапазона", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(b, "Введите верхнюю границу диапазона", false, greater_or_equals_1v, NULL, NULL, a, 0, 0, 0, 0, 0);

	getvar(n, "Введите количество чисел в массиве (в диапазоне 0 - 50 000 000)", true, NULL, is_in_or_equal, NULL, 0, 0, 50000000, 0, 0, 0);

	int* N = new int[n];
	int* found = new int[n];
	for (int i = 0; i < n; i++)
	{
		N[i] = rand() % (abs(a - b) + 1) + a;
	}

	SetColor(0, 14);
	cout << "Часть 2: поиск числа" << endl;
	SetColor(0, 15);
	int search = 0;
	getvar(search, "Введите искомое число", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);

	if (!is_in_or_equal(search, a, b))
	{
		cout << "Число " << search << " не найдено ни разу" << endl;
	}
	else
	{
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (N[i] == search)
			{
				found[count] = i;
				count++;
			}
		}
		cout << endl << "Всего найдено чисел " << search << ": " << count << endl;
		if (count)
		{
			cout << "Вывести позиции, на которых находится число?";
			SetColor(0, 12);
			cout << " (может занять долгое время)";
			SetColor(0, 15);
			cout << endl << "Нажмите y, если да, и любую другую клавишу, если нет" << endl;
			char act = _getch();
			if (act == 'y')
			{
				cout << "Число " << search << " найдено на следующих позициях:";
				for (int i = 0; i < count; i++)
				{
					if (i % 10 == 0)
						cout << endl;
					cout << setw(11) << found[i];
				}
				cout << endl;
			}
		}
	}
	delete[] found;
	delete[] N;
}

void f5_7()
{ //номер зачетки, фио, список из 5 предметов с оценками.
	//Подсчитать среднюю успеваемость группы, вывести список всех студентов, у которых успеваемость выше средней
	show_title(dz_list_names[0][30], dz_list_names[1][30]);
	fstream inf("files/file5-7.txt", ios::in);
	if (inf)
	{
		string temp = "";
		bool ok = true;
		float average = 0.0f;
		int count = 0;
		while (!inf.eof())
		{
			temp = "";
			getline(inf, temp);
			if (num_of_symbols(temp, ' ') != 6)
			{
				cout << "Файл не отформатирован по следующей схеме:\n\
номер зачетки - фамилия студента - оценка 1, 2, 3, 4, 5" << endl;
				return;
			}
			size_t spaces[] = { 0, 0, 0, 0, 0, 0 };
			int index = 0;
			for (int i = 0; i < 6; i++)
			{
				spaces[i] = temp.find(' ', index);
				index = spaces[i] + 1;
			}
			for (int i = 2; i < 6; i++)
			{
				if ((spaces[i] - spaces[i - 1] != 2))
				{
					cout << "Файл не отформатирован по следующей схеме:\n\
номер зачетки - фамилия студента - оценка 1, 2, 3, 4, 5" << endl;
					return;
				}
			}
			count += 5;
			average += (int(temp[spaces[2] + 1]) + int(temp[spaces[3] + 1]) + int(temp[spaces[4] + 1]) + int(temp[spaces[5] + 1]) + int(temp[spaces[1] + 1]) - 48 * 5);
		}
		if (ok)
		{
			average /= count;
			cout << "Средняя успеваемость = " << average << endl;
			cout << "Студенты, имеющие успеваемость выше средней: " << endl;
			inf.seekg(0);
			float average1;
			while (!inf.eof())
			{
				temp = "";
				getline(inf, temp);
				size_t spaces[] = { 0, 0, 0, 0, 0, 0 };
				int index = 0;
				for (int i = 0; i < 6; i++)
				{
					spaces[i] = temp.find(' ', index);
					index = spaces[i] + 1;
				}
				average1 = (int(temp[spaces[2] + 1]) + int(temp[spaces[3] + 1]) + int(temp[spaces[4] + 1]) + int(temp[spaces[5] + 1]) + int(temp[spaces[1] + 1]) - 48 * 5) / 5.0f;
				if (average1 > average)
				{
					cout << temp << endl;
				}
			}
		}

	}
	else
	{
		cout << "Исходный файл files/file5-7.txt не найден" << endl;
	}
}

void f6_1()
{
	show_title(dz_list_names[0][31], dz_list_names[1][31]);
	int n = 0;
	cout << "Максимальное количество шариков, при котором возможно напечатать все перестановки - 21" << endl;
	cout << "Максимальное количество шариков, для которого можно рассчитать примерное число перестановок - 170" << endl;
	getvar(n, "Введите количество шариков", true, greater_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	if (n > 170)
	{
		cout << "При вычислениях получен слишком большой результат (больше, чем 10^307)" << endl;
	}
	else
	{
		double Q = 0; //число ситуаций, при которых номер ни одного шарика не совпадет с порядком вынимания

		//Формула для расчета: P = n! - (n! * sum((-1)^k / k!)), где k = 0,1,...,n

		double all = fact(n);

		Q = all;

		double tempQ = 0;
		for (int k = 0; k <= n; k++)
		{
			double temp = pow(-1, k);
			temp /= fact(k);
			tempQ += temp;
		}
		Q *= tempQ;

		int prec = cout.precision();
		double P = 0; //число ситуаций, обратных ситуациям Q, т.е. хотя бы у 1 шарика его номер совпал с порядком
		P = all - Q;
		SetColor(0, 10);
		cout << "Количество перестановок, при которых номер хотя бы 1 шарика совпадет с порядком\nвынимания этих шариков: ";
		SetColor(0, 15);
		if (P > pow(10, 10))
			cout << "примерно ";
		cout << P;
		SetColor(0, 15);
		cout << endl;

		double p = P / all * 100;
		SetColor(0, 14);
		if ((n % 10 == 1) && (n % 100 != 11))
			cout << "\nВсего перестановок из " << n << " шарика: ";
		else
			cout << "\nВсего перестановок из " << n << " шариков: ";
		SetColor(0, 15);
		if (all > pow(10, 10))
			cout << "примерно ";
		cout << all;
		SetColor(0, 15);
		cout << endl;
		SetColor(0, 11);
		cout << "\nКоличество подходящих перестановок: ";
		SetColor(0, 15);
		cout << p << "% от общего количества" << endl;

		if (n <= 21)
		{
			cout << "Вывести перестановки, удовлетворяющие условиям? ";
			SetColor(0, 12);
			cout << "(может занять долгое время)" << endl;
			SetColor(0, 15);
			cout << "(y - да/другой символ - нет)" << endl;
			if (tolower(_getch()) == 'y')
			{
				unsigned long long num = 1;
				int* permutations = new int[n];
				for (int i = 0; i < n; i++)
				{
					permutations[i] = i + 1;
				}
				print_permutation(permutations, n, num);
				while (nextSet(permutations, n))
				{
					num++;
					bool ok = false;
					for (int i = 0; i < n; i++)
					{
						if (permutations[i] == i + 1)
						{
							ok = true;
							break;
						}
					}
					if (ok) print_permutation(permutations, n, num);
				}
				delete[] permutations;
			}
		}
	}
}

//база заданий - задания:
//тема         номер и название
//базы данных  110 (монахи)
//автомат      150 (порт)
//сортировка   42 (точки)
//разное       138 (check функция)
//разное       146 (цифровой корень)

void find_monach(int monach, int** table, int rows)
{
	bool was = false;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < 4; j++)
			if (table[i][j] == monach)
				was = true;
	if (was)
	{
		cout << monach << " - монах" << endl;
		cout << "Его учителя: ";
		int cur_monach = monach;
		for (int i = rows - 1; i >= 0; i--)
		{
			for (int j = 3; j > 0; j--)
			{
				if (table[i][j] == cur_monach)
				{
					if (cur_monach != monach)
					{
						cout << ", ";
					}
					cout << table[i][0];
					cur_monach = table[i][0];
					if (cur_monach == 1)
					{
						break;
					}
				}
			}
			if (cur_monach == 1)
			{
				break;
			}
		}
		cout << endl;
	}
	else
	{
		cout << monach << " - не монах" << endl;
		return;
	}
}

void find_nearest_teacher(int monach1, int monach2, int** table, int rows)
{
	bool was1 = false;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < 4; j++)
			if (table[i][j] == monach1)
				was1 = true;
	bool was2 = false;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < 4; j++)
			if (table[i][j] == monach2)
				was2 = true;
	if (!was1)
	{
		cout << monach1 << " - не монах" << endl;
	}
	if (!was2)
	{
		cout << monach2 << " - не монах" << endl;
	}
	if (was1 && was2)
	{
		string teachers1 = "";
		int cur_monach = monach1;
		for (int i = rows - 1; i >= 0; i--)
		{
			for (int j = 3; j > 0; j--)
			{
				if (table[i][j] == cur_monach)
				{
					if (cur_monach != monach1)
					{
						teachers1 += " ";
					}
					teachers1 += to_string(table[i][0]);
					cur_monach = table[i][0];
					if (cur_monach == 1)
					{
						break;
					}
				}
			}
			if (cur_monach == 1)
			{
				break;
			}
		}

		string teachers2 = "";
		cur_monach = monach2;
		for (int i = rows - 1; i >= 0; i--)
		{
			for (int j = 3; j > 0; j--)
			{
				if (table[i][j] == cur_monach)
				{
					if (cur_monach != monach2)
					{
						teachers2 += " ";
					}
					teachers2 += to_string(table[i][0]);
					cur_monach = table[i][0];
					if (cur_monach == 1)
					{
						break;
					}
				}
			}
			if (cur_monach == 1)
			{
				break;
			}
		}

		if (teachers2.size() == 1)
			teachers2 += " ";
		int index = 0;
		while (index < teachers1.size())
		{
			int space_temp = index + 1;
			if (teachers1.find(' ', index) != string::npos)
			{
				space_temp = teachers1.find(' ', index);
			}

			string t = "";
			for (int i = index; i < space_temp; i++)
			{
				t += teachers1[i];
			}
			if (teachers2.find(t + " ") != string::npos)
			{
				cout << "Общий учитель: " << t << endl;
				break;
			}

			index = space_temp + 1;
		}
	}
}

void f7_1()
{
	show_title(dz_list_names[0][32], dz_list_names[1][32]);
	fstream f("files/file7-1.txt");
	if (!f)
	{
		cout << "Не удалось открыть исходный файл files/file7-1.txt" << endl;
		return;
	}
	int n = 0;
	string temp = "";
	while (!f.eof())
	{
		getline(f, temp);
		n++;
	}
	//выделение памяти под монахов
	//указатель на массив указателей
	int** monach_table = new int* [n];
	for (int i = 0; i < n; i++)
	{
		//указатель на массив данных
		monach_table[i] = new int[4];
	}
	///////////////////////////////
	f.seekg(0);
	int row = 0;
	while (!f.eof())
	{
		getline(f, temp);
		size_t spaces[] = { 0, 0, 0, 0 };
		bool ok = true;
		int index = 0;
		for (int i = 0; i < 4; i++)
		{
			spaces[i] = temp.find(' ', index);
			index = spaces[i] + 1;
		}
		if (spaces[3] != string::npos)
		{
			cout << "Файл не отформатирован по схеме: \"номер монаха - номер ученика 1 - номер ученика 2 - номер ученика 3\"" << endl;
			row = -1;
			break;
		}
		string t[4] = { "", "", "", "" };
		for (int i = 0; i < temp.size(); i++)
		{
			if (is_in_or_equal(i, 0, spaces[0] - 1))
			{
				t[0] += temp[i];
			}
			if (is_in_or_equal(i, spaces[0] + 1, spaces[1] - 1))
			{
				t[1] += temp[i];
			}
			if (is_in_or_equal(i, spaces[1] + 1, spaces[2] - 1))
			{
				t[2] += temp[i];
			}
			if (is_in_or_equal(i, spaces[2] + 1, temp.size() - 1))
			{
				t[3] += temp[i];
			}
		}
		int ti[4] = {strtol(t[0].c_str(), nullptr, 0), strtol(t[1].c_str(), nullptr, 0), strtol(t[2].c_str(), nullptr, 0), strtol(t[3].c_str(), nullptr, 0) };
		if (((ti[0] >= ti[1]) && ti[1]) || ((ti[0] >= ti[2]) && ti[2]) || ((ti[0] >= ti[3]) && ti[3])) //если номер ученика меньше номера учителя
		{
			SetColor(0, 12);
			cout << "Номер ученика меньше номера учителя в строке " << row + 1 << endl;
			SetColor(0, 15);
			ok = false;
		}
		if (!ti[1] && !ti[2] && !ti[3])
		{
			SetColor(0, 14);
			cout << "Предупреждение: в строке " << row+1 << " у учителя нет ни одного ученика; данная строка смысла не имеет" << endl;
			SetColor(0, 15);
		}
		//если один и тот же монах встречается в качестве учителя повторно
		for (int i = 0; i < row; i++)
		{
			if (monach_table[i][0] == ti[0])
			{
				SetColor(0, 12);
				cout << "Учитель в строке " << i + 1 << " объявлен более 1 раза" << endl;
				SetColor(0, 15);
				ok = false;
			}
		}
		//если один и тот же монах фигурирует в качестве ученика повторно
		for (int i = 0; i < row; i++)
		{
			for (int j = 1; j < 4; j++)
			{
				for (int k = 1; k < 4; k++)
				{
					if ((monach_table[i][j] == ti[k]) && ti[k])
					{
						SetColor(0, 12);
						cout << "Монах " << ti[k] << " в строке " << i + 1 << " уже объявлен как ученик" << endl;
						ok = false;
						SetColor(0, 15);
					}
				}
			}
			
		}
		if (!ok)
		{
			row = -1;
			break;
		}
			
		for (int i = 0; i < 4; i++)
		{
			monach_table[row][i] = strtol(t[i].c_str(), nullptr, 0);
		}
		
		row++;
	}

	if (row != -1)
	{
		string input = "";
		getline(cin, input); //холостое чтение
		while (input != "0")
		{
			cout << "Введите команду или help для вывода списка команд" << endl;
			getline(cin, input);
			if (input == "help")
			{
				cout << "0 - выход из функции, реализующей это задание" << endl;
				cout << "1 x - поиск монаха по номеру x" << endl;
				cout << "2 x y - поиск ближайшего общего учителя монахов x и y" << endl;
			}
			else if (input == "0")
			{

			}
			else
			{
				size_t spaces1[3] = { 0, string::npos, string::npos };
				int index = 0;
				for (int i = 0; i < 3; i++)
				{
					spaces1[i] = input.find(' ', index);
					if (spaces1[i] != string::npos)
						index = spaces1[i] + 1;
					else
						break;
				}
				if (spaces1[2] != string::npos)
				{
					cout << "Неверный ввод команды" << endl;
				}
				else
				{
					string t[3] = { "", "", "" };
					if (spaces1[1] == string::npos)
						spaces1[1]--;
					if (spaces1[2] == string::npos)
						spaces1[2]--;
					for (int i = 0; i < input.size(); i++)
					{
						if (is_in_or_equal(i, 0, spaces1[0] - 1))
						{
							t[0] += input[i];
						}
						if (is_in_or_equal(i, spaces1[0] + 1, spaces1[1] - 1))
						{
							t[1] += input[i];
						}
						if (is_in_or_equal(i, spaces1[1] + 1, spaces1[2] - 1))
						{
							t[2] += input[i];
						}
					}
					if ((t[0] == "1") && (t[1] != "") && (t[2] == ""))
					{
						if (strtol(t[1].c_str(), nullptr, 0) != 0)
						{
							find_monach(strtol(t[1].c_str(), nullptr, 0), monach_table, n);
						}
						else
						{
							cout << "Неверный ввод команды" << endl;
						}
					}
					else if ((t[0] == "2") && (t[1] != "") && (t[2] != ""))
					{
						if ((strtol(t[1].c_str(), nullptr, 0) == 0) || (strtol(t[2].c_str(), nullptr, 0) == 0))
						{
							cout << "Неверный ввод команды" << endl;
						}
						else
							find_nearest_teacher(strtol(t[1].c_str(), nullptr, 0), strtol(t[2].c_str(), nullptr, 0), monach_table, n);
					}
					else
					{
						cout << "Такой команды не существует" << endl;
					}
				}
			}
			cout << endl;
		}
	}
	//удаление памяти под монахов
	f.close();
	for (int i = 0; i < n; i++)
	{
		//удаление указателя на массив данных
		delete[] monach_table[i];
	}
	//удаление указателя на массив указателей
	delete[] monach_table;
	///////////////////////////////

}

void f7_2_Avtomat()
{
	show_title(dz_list_names[0][33], dz_list_names[1][33]);
	port_modelling_menu();
}
void f7_3()
{
	show_title(dz_list_names[0][34], dz_list_names[1][34]);
	typedef struct p { double x; double y; } point;
	point A;
	getvar(A.x, "Введите координату х точки А", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
	getvar(A.y, "Введите координату y точки А", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
	int n = 0;
	getvar(n, "Введите количество точек В (в диапазоне 0 - 10 000 000)", true, NULL, is_in_or_equal, NULL, 0, 0, 10000000, 0, 0, 0);
	point* B = new point[n];
	cout << "Как вы хотите задать точки В? (вручную - H/случайно - любой другой символ)" << endl;
	char act = _getch();
	if (tolower(act) == 'h')
	{
		SetColor(0, 11);
		cout << "Выбран ручной способ ввода" << endl;
		SetColor(0, 15);
		for (int i = 0; i < n; i++)
		{
			getvar(B[i].x, "Введите координату х точки B #" + to_string(i + 1), false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
			getvar(B[i].y, "Введите координату y точки B #" + to_string(i + 1), false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
		}
	}
	else
	{
		SetColor(0, 11);
		cout << "Выбран случайный способ ввода: необходимо задать диапазон для генерации случайных координат" << endl;
		SetColor(0, 15);
		double x_min = 0, x_max = 0, y_min = 0, y_max = 0;
		getvar(x_min, "Введите нижнюю границу диапазона для х", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
		x_max = x_min - 1;
		while (x_max < x_min)
		{
			getvar(x_max, "Введите верхнюю границу диапазона для х", false, *greater_or_equals_1v, NULL, NULL, x_min, 0, 0, 0, 0, 0);
			if (x_max < x_min)
			{
				cout << "Неверный ввод" << endl;
			}
		}
		getvar(y_min, "Введите нижнюю границу диапазона для y", false, NULL, NULL, NULL, 0, 0, 0, 0, 0, 0);
		y_max = y_min - 1;
		while (y_max < y_min)
		{
			getvar(y_max, "Введите верхнюю границу диапазона для y", false, *greater_or_equals_1v, NULL, NULL, y_min, 0, 0, 0, 0, 0);
			if (y_max < y_min)
			{
				cout << "Неверный ввод" << endl;
			}
		}
		for (int i = 0; i < n; i++)
		{
			B[i].x = double(rand() % (abs(int(x_min - x_max)) + 1)) + x_min;
			B[i].y = double(rand() % (abs(int(y_min - y_max)) + 1)) + y_min;
		}
	}
	int c = 0;
	double min_range = -1;
	for (int i = 0; i < n; i++)
	{
		double range = pow(B[i].x - A.x, 2) + pow(B[i].y - A.y, 2);
		if (min_range == -1)
		{
			min_range = range;
			c = i;
		}
		else
		{
			if (min_range > range)
			{
				c = i;
				min_range = range;
			}
		}
	}
	cout << "Ближе всего к точке А (" << A.x << ", " << A.y << ") находится точка В #" << c + 1 << " с координатами (" << B[c].x << ", " << B[c].y << ") (расстояние: " << sqrt(min_range) << ")" << endl;
	if (tolower(act) != 'h')
	{
		cout << "Вывести сгенерированные точки? (y - да, другой символ - нет)" << endl;
		if (_getch() == 'y')
		{
			for (int i = 0; i < n; i++)
			{
				cout << "B #" << i + 1 << ": " << B[i].x << " " << B[i].y << endl;
			}
		}
	}
	delete[] B;
}

int check(string str) //функция для 7-4
{
	string temp = str;
	string bounds = "()[]{}";
	string temp2 = "";
	int iterations = 0;
	for (int i = 0; i < temp.size(); i++) //убираем пробелы
	{
		if (findplace(bounds, temp[i]) != -1)
		{
			temp2 += temp[i];
		}
	}
	temp = temp2;
	if ((num_of_symbols(temp, '(') != num_of_symbols(temp, ')')) ||
		(num_of_symbols(temp, '[') != num_of_symbols(temp, ']')) ||
		(num_of_symbols(temp, '{') != num_of_symbols(temp, '}'))) //если число открывающих скобок не равно числу закрывающих скобок,
		//дальнейшая проверка смысла не имеет
		return 1;
	while (1)
	{
		iterations++;
		if (temp.find("()") == string::npos)
		{
			if (temp.find("[]") == string::npos)
			{
				if (temp.find("{}") == string::npos)
				{
					if (temp != "")
						return 2;
					else break;
				}
				else
				{
					replaceall(temp, "{}", "");
				}
			}
			else
			{
				replaceall(temp, "[]", "");
			}
		}
		else
		{
			replaceall(temp, "()", "");
		}
		if (iterations > 4000)
			return -1;
	}
	return 0;
}

void f7_4()
{
	show_title(dz_list_names[0][35], dz_list_names[1][35]);
	string str = "";
	cout << "Введите скобочное выражение для проверки: -> ";
	getline(cin, str); //чтение "вхолостую", чтобы сбросить "пустой" буфер в cin
	getline(cin, str);
	int check_str = check(str);
	switch (check_str)
	{
	case 0:
		SetColor(0, 10);
		cout << "Ошибок не найдено" << endl;
		SetColor(0, 15);
		break;
	case 1:
		SetColor(0, 12);
		cout << "Обнаружены непарные скобки" << endl;
		SetColor(0, 15);
		break;
	case 2:
		SetColor(0, 12);
		cout << "Скобки расположены в порядке, не позволяющем их убрать (например: ";
		SetColor(0, 14);
		cout << "[{]}";
		SetColor(0, 12);
		cout << ")" << endl;
		SetColor(0, 15);
		break;
	default:
		SetColor(0, 14);
		cout << "Возникла ошибка при проверке строки - результат неизвестен" << endl;
		SetColor(0, 15);
	}

}

void digital_root(int64_t num)
{
	string temp = to_string(num);
	int64_t dr = 0;
	string digit;
	for (int i = 0; i < temp.size(); i++)
	{
		digit = temp[i];
		dr += int(_strtoi64(digit.c_str(), nullptr, 0));
	}
	if (dr < 10)
	{
		SetColor(0, 14);
		cout << dr;
		SetColor(0, 15);
	}
	else
	{
		cout << dr << " -> ";
		digital_root(dr);
	}
}

void digital_root_output(int64_t num)
{
	cout << "Цифровой корень числа " << num << ": " << num << " -> ";
	digital_root(num);
	cout << endl;
}

void f7_5()
{
	show_title(dz_list_names[0][36], dz_list_names[1][36]);
	int64_t a = 0;
	getvar(a, "Введите положительное целое число", true, greater_or_equals_1v, NULL, NULL, 0, 0, 0, 0, 0, 0);
	digital_root_output(a);
}
