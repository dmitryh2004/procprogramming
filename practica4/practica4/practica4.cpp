#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <locale.h>
#include <conio.h>
#include <cmath>
#include <string>
#include <fstream>
#include <Windows.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const double pi = 3.14159;
const double e = 2.71828;

void getvar(double& var, string hintMessage, bool Positive)
{
	string check_cond;
	if (Positive)
		check_cond = ",1234567890";
	else
		check_cond = "-,1234567890";
	string varstring = "a";
	while (varstring.find_first_not_of(check_cond) != string::npos)
	{
		cout << hintMessage << " -> ";
		getline(cin, varstring);
		if (varstring.find_first_not_of(check_cond) != string::npos)
		{
			cout << "Неверный ввод" << endl;
		}
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
	while (varstring.find_first_not_of(check_cond) != string::npos)
	{
		cout << hintMessage << " -> ";
		getline(cin, varstring);
		if (varstring.find_first_not_of(check_cond) != string::npos)
		{
			cout << "Неверный ввод" << endl;
		}
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
	while (varstring.find_first_not_of(check_cond) != string::npos)
	{
		cout << hintMessage << " -> ";
		getline(cin, varstring);
		if (varstring.find_first_not_of(check_cond) != string::npos)
		{
			cout << "Неверный ввод" << endl;
		}
	}
	var = int(strtof(varstring.c_str(), nullptr));
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

void f1();
void f2();
void f3();
void f4();
void f5();
void f6();
void f7();
void f8();
void f9();

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Важно! Из-за особенностей программы дробные числа необходимо\nписать через запятую: не 0.6, а 0,6!" << endl;
	system("pause");
	system("cls");
	f1();
	system("pause");
	system("cls");
	f2();
	system("pause");
	system("cls");
	f3();
	system("pause");
	system("cls");
	f4();
	system("pause");
	system("cls");
	f5();
	system("pause");
	system("cls");
	f6();
	system("pause");
	system("cls");
	f7();
	system("pause");
	system("cls");
	f8();
	system("pause");
	system("cls");
	f9();
	system("pause");
	system("cls");
}

void f1()
{

	std::ofstream outf("files/file1.txt");
	int n = 0;
	double t = 0;
	while (n != 10)
	{
		cout << "===============================" << endl;
		cout << "          Задание 1" << endl;
		cout << "-------------------------------" << endl;
		cout << "Файл с числами" << endl;
		string hint = "Вводите числа (" + std::to_string(n) + "/10)";
		getvar(t, hint, false);
		outf << t << endl;
		n++;
		system("cls");
	}
	cout << "===============================" << endl;
	cout << "          Задание 1" << endl;
	cout << "-------------------------------" << endl;
	cout << "Файл с числами" << endl;
	cout << "Вводите числа (10/10) -> введено!" << endl;
	outf.close();
	cout << endl << "Файл закрыт" << endl;
	std::ifstream inf("files/file1.txt");
	cout << endl << "Файл открыт" << endl;
	double S = 0;
	while (!inf.eof())
	{
		string temp;
		getline(inf, temp);
		S += strtod(temp.c_str(), nullptr);
	}
	inf.close();
	cout << "Сумма = " << S << endl;
}

void f2()
{
	cout << "===============================" << endl;
	cout << "          Задание 2" << endl;
	cout << "-------------------------------" << endl;
	cout << "Знак числа" << endl;
	double n;
	getvar(n, "Введите число", false);
	sign(n);
	cout << endl;
}

void f3()
{
	cout << "===============================" << endl;
	cout << "          Задание 3" << endl;
	cout << "-------------------------------" << endl;
	cout << "Площадь" << endl;
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

void f4()
{
	cout << "===============================" << endl;
	cout << "          Задание 4" << endl;
	cout << "-------------------------------" << endl;
	cout << "Флаг США" << endl;
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

void f5()
{
	cout << "===============================" << endl;
	cout << "          Задание 5" << endl;
	cout << "-------------------------------" << endl;
	cout << "Синусоида" << endl;
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

int rim_process(int dec, int lastN, int lastDec)
{
	return (lastN > dec) ? (lastDec - dec) : (lastDec + dec);
}

void f6()
{
	cout << "===============================" << endl;
	cout << "          Задание 6" << endl;
	cout << "-------------------------------" << endl;
	cout << "Римские цифры" << endl;
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
		getline(cin, rim);
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

void f7()
{
	cout << "===============================" << endl;
	cout << "          Задание 7" << endl;
	cout << "-------------------------------" << endl;
	cout << "\"Случайные\" числа" << endl;
	int i = 0;
	getvar(i, "Введите число", true);
	int const_m = 30;
	int const_a = 17;
	int const_c = 14;
	cout << "Сгенерировано число " << random(i, const_m, const_a, const_c) << endl;
}
void f8()
{
	cout << "===============================" << endl;
	cout << "          Задание 8" << endl;
	cout << "-------------------------------" << endl;
	cout << "Про продавцов" << endl;
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
	cout << "Таблица А" << endl;
	cout << endl;
	cout << "|" << std::setw(8) << "Продавец" << "|" << std::setw(15) << "    Товары    " << "|" << endl;
	cout << "|        |---|---|---|---|" << endl;
	cout << "|" << std::setw(8) << " " << "|" << std::setw(3) << " 1 " << "|" << std::setw(3) << " 2 " << "|" << std::setw(3) << " 3 " << "|" <<
		std::setw(3) << " 4 " << "|" << endl;
	cout << "|--------|---|---|---|---|" << endl;
	cout << "|" << std::setw(8) << "   1   " << "|" << std::setw(3) << A[0][0] << "|" << std::setw(3) << A[0][1] << "|" 
		<< std::setw(3) << A[0][2] << "|" << std::setw(3) << A[0][3] << "|" << endl;
	cout << "|--------|---|---|---|---|" << endl;
	cout << "|" << std::setw(8) << "   2   " << "|" << std::setw(3) << A[1][0] << "|" << std::setw(3) << A[1][1] << "|"
		<< std::setw(3) << A[1][2] << "|" << std::setw(3) << A[1][3] << "|" << endl;
	cout << "|--------|---|---|---|---|" << endl;
	cout << "|" << std::setw(8) << "   3   " << "|" << std::setw(3) << A[2][0] << "|" << std::setw(3) << A[2][1] << "|"
		<< std::setw(3) << A[2][2] << "|" << std::setw(3) << A[2][3] << "|" << endl;
	cout << "|--------|---|---|---|---|" << endl;
	cout << endl;

	cout << "Таблица B" << endl;
	cout << endl;
	cout << "|" << std::setw(5) << "Товар" << "|" << std::setw(4) << "Цена" << "|" << std::setw(12) << "Комиссионные" << "|" << endl;
	cout << "|-----|----|------------|" << endl;
	cout << "|" << std::setw(5) << "  1  " << "|" << std::setw(4) << B[0][0] << "|" << std::setw(12) << B[0][1] << "|" << endl;
	cout << "|-----|----|------------|" << endl;
	cout << "|" << std::setw(5) << "  2  " << "|" << std::setw(4) << B[1][0] << "|" << std::setw(12) << B[1][1] << "|" << endl;
	cout << "|-----|----|------------|" << endl;
	cout << "|" << std::setw(5) << "  3  " << "|" << std::setw(4) << B[2][0] << "|" << std::setw(12) << B[2][1] << "|" << endl;
	cout << "|-----|----|------------|" << endl;
	cout << "|" << std::setw(5) << "  4  " << "|" << std::setw(4) << B[3][0] << "|" << std::setw(12) << B[3][1] << "|" << endl;
	cout << "|-----|----|------------|" << endl;
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

	cout << "Таблица С" << endl;
	cout << endl;
	cout << "|" << std::setw(8) << "Продавец" << "|" << std::setw(7) << "Выручка" << "|" << std::setw(12) << "Комиссионные" << "|" << endl;
	cout << "|--------|-------|------------|" << endl;
	cout << "|" << std::setw(8) << "   1   " << "|" << std::setw(7) << C[0][0] << "|" << std::setw(12) << C[0][1] << "|" << endl;
	cout << "|--------|-------|------------|" << endl;
	cout << "|" << std::setw(8) << "   2   " << "|" << std::setw(7) << C[1][0] << "|" << std::setw(12) << C[1][1] << "|" << endl;
	cout << "|--------|-------|------------|" << endl;
	cout << "|" << std::setw(8) << "   3   " << "|" << std::setw(7) << C[2][0] << "|" << std::setw(12) << C[2][1] << "|" << endl;
	cout << "|--------|-------|------------|" << endl;
	cout << endl;

	int minn, maxn; float minv = 10000.0f, maxv = 0.0f;
	for (int i = 0; i < 3; i++)
	{
		if (C[i][0] > maxv)
		{
			maxv = C[i][0];
			maxn = i+1;
		}
		if (C[i][0] < minv)
		{
			minv = C[i][0];
			minn = i+1;
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

int findplace(string cond, char a)
{
	for (int i = 0; i < cond.size(); i++)
	{
		if (cond[i] == a)
			return i;
	}
	return -1;
}

void f9()
{
	cout << "===============================" << endl;
	cout << "          Задание 9" << endl;
	cout << "-------------------------------" << endl;
	cout << "Системы счисления" << endl;
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
		getline(cin, num_in);
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
		cout << "Число "<< num_in << " (" << CS_in << "сс) в " << CS_out << "-й СС: ";
		for (int i = num_out.size() - 1; i >= 0; i--)
			cout << num_out[i];
		cout << endl;
	}
}

