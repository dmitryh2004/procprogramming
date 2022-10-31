#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <string>
using namespace std;
#include "consolecolors.h"

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


//conditions for check in input_processing
//one-parameter check functions
bool equals_1v(double n, double a)
{
	return (n == a);
}

bool not_equal_1v(double n, double a)
{
	return (n != a);
}

bool less_1v(double n, double a)
{
	return (n < a);
}

bool greater_1v(double n, double a)
{
	return (n > a);
}

bool greater_or_equals_1v(double n, double a)
{
	return (equals_1v(n, a) || greater_1v(n, a));
}

bool less_or_equals_1v(double n, double a)
{
	return (equals_1v(n, a) || less_1v(n, a));
}

//two-parameters checking functions
bool is_in_or_equal(double n, double a, double b)
{
	return ((n >= a) && (n <= b));
}

bool is_in_or_equal_a(double n, double a, double b)
{
	return ((n >= a) && (n < b));
}

bool is_in_or_equal_b(double n, double a, double b)
{
	return ((n > a) && (n <= b));
}

bool is_in(double n, double a, double b)
{
	return ((n > a) && (n < b));
}

bool is_out_or_equal(double n, double a, double b)
{
	return ((n <= a) || (n >= b));
}

bool is_out_or_equal_a(double n, double a, double b)
{
	return ((n <= a) || (n > b));
}

bool is_out_or_equal_b(double n, double a, double b)
{
	return ((n < a) || (n >= b));
}

bool is_out(double n, double a, double b)
{
	return ((n < a) || (n > b));
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