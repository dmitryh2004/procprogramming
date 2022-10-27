#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
using namespace std;

//some funcs
double fact(int n)
{
	if (n == 0)
		return 1.0;
	else
		return n * fact(n - 1);
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
//input functions
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
				cout << "Неверный ввод: цифра стоит перед минусом" << endl;
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
				cout << "Неверный ввод: цифра стоит перед минусом" << endl;
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
				cout << "Неверный ввод: цифра стоит перед минусом" << endl;
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

void show_title(string title, string name)
{
	system("cls");
	SetColor(0, 14);
	cout << "===============================" << endl;
	cout << "          Задание " << title << endl;
	cout << "-------------------------------" << endl;
	cout << name << endl;
	SetColor(0, 15);
}
#endif