#pragma once
#ifndef INPUT_PROC_H
#define INPUT_PROC_H

void getvar(double& var, string hintMessage, bool Positive, bool(*cond1var)(double, double), bool(*cond2var)(double, double, double),
	bool(*cond3var)(double, double, double, double), double a1, double a2, double b2, double a3, double b3, double c3);
void getvar(float& var, string hintMessage, bool Positive, bool(*cond1var)(double, double), bool(*cond2var)(double, double, double),
	bool(*cond3var)(double, double, double, double), double a1, double a2, double b2, double a3, double b3, double c3);
void getvar(int& var, string hintMessage, bool Positive, bool(*cond1var)(double, double), bool(*cond2var)(double, double, double),
	bool(*cond3var)(double, double, double, double), double a1, double a2, double b2, double a3, double b3, double c3);
void getvar(int64_t& var, string hintMessage, bool Positive, bool(*cond1var)(double, double), bool(*cond2var)(double, double, double),
	bool(*cond3var)(double, double, double, double), double a1, double a2, double b2, double a3, double b3, double c3);

void getvar(double& var, string hintMessage, bool Positive, bool(*cond1var)(double, double)=NULL, bool(*cond2var)(double, double, double) = NULL,
	bool(*cond3var)(double, double, double, double) = NULL, double a1=0, double a2=0, double b2=0, double a3=0, double b3=0, double c3=0)
{
	string check_cond;
	if (Positive)
		check_cond = ",1234567890";
	else
		check_cond = "-,1234567890";
	string varstring = "a";
	bool ok = false;
	double temp;
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
		temp = strtod(varstring.c_str(), nullptr);
		if (cond1var)
		{
			if (!cond1var(temp, a1))
			{
				cout << "Неверный ввод" << endl;
				continue;
			}	
		}
		if (cond2var)
		{
			if (!cond2var(temp, a2, b2))
			{
				cout << "Неверный ввод" << endl;
				continue;
			}
		}
		if (cond3var)
		{
			if (!cond3var(temp, a3, b3, c3))
			{
				cout << "Неверный ввод" << endl;
				continue;
			}
		}
		ok = !ok;
	}
	var = temp;
}

void getvar(float& var, string hintMessage, bool Positive, bool(*cond1var)(double, double) = NULL, bool(*cond2var)(double, double, double) = NULL,
	bool(*cond3var)(double, double, double, double) = NULL, double a1 = 0, double a2 = 0, double b2 = 0, double a3 = 0, double b3 = 0, double c3 = 0)
{
	string check_cond;
	if (Positive)
		check_cond = ",1234567890";
	else
		check_cond = "-,1234567890";
	string varstring = "a";
	bool ok = false;
	float temp = 0;
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
		temp = strtof(varstring.c_str(), nullptr);
		if (cond1var)
		{
			if (!cond1var(temp, a1))
			{
				cout << "Неверный ввод" << endl;
				continue;
			}
		}
		if (cond2var)
		{
			if (!cond2var(temp, a2, b2))
			{
				cout << "Неверный ввод" << endl;
				continue;
			}
		}
		if (cond3var)
		{
			if (!cond3var(temp, a3, b3, c3))
			{
				cout << "Неверный ввод" << endl;
				continue;
			}
		}
		ok = !ok;
	}
	var = temp;
}

void getvar(int& var, string hintMessage, bool Positive, bool(*cond1var)(double, double) = NULL, bool(*cond2var)(double, double, double) = NULL,
	bool(*cond3var)(double, double, double, double) = NULL, double a1 = 0, double a2 = 0, double b2 = 0, double a3 = 0, double b3 = 0, double c3 = 0)
{
	string check_cond;
	if (Positive)
		check_cond = "1234567890";
	else
		check_cond = "-1234567890";
	string varstring = "a";
	bool ok = false;
	int temp = 0;
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
		temp = strtol(varstring.c_str(), nullptr, 0);
		if (cond1var)
		{
			if (!cond1var(temp, a1))
			{
				cout << "Неверный ввод" << endl;
				continue;
			}
		}
		if (cond2var)
		{
			if (!cond2var(temp, a2, b2))
			{
				cout << "Неверный ввод" << endl;
				continue;
			}
		}
		if (cond3var)
		{
			if (!cond3var(temp, a3, b3, c3))
			{
				cout << "Неверный ввод" << endl;
				continue;
			}
		}
		ok = !ok;
	}
	var = temp;
}

void getvar(int64_t& var, string hintMessage, bool Positive, bool(*cond1var)(double, double) = NULL, bool(*cond2var)(double, double, double) = NULL,
	bool(*cond3var)(double, double, double, double) = NULL, double a1 = 0, double a2 = 0, double b2 = 0, double a3 = 0, double b3 = 0, double c3 = 0)
{
	string check_cond;
	if (Positive)
		check_cond = "1234567890";
	else
		check_cond = "-1234567890";
	string varstring = "a";
	bool ok = false;
	int power = 0;
	int64_t temp = 0;
	while (!ok)
	{
		temp = 0;
		power = 0;
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
		for (int i = varstring.size() - 1; i >= 0; i--)
		{
			if (varstring[i] == '-')
			{
				temp = -temp;
			}
			else
			{
				temp += pow(10, power) * (varstring.c_str()[i] - 48);
			}
			power++;
		}
		if (cond1var)
		{
			if (!cond1var(temp, a1))
			{
				cout << "Неверный ввод" << endl;
				continue;
			}
		}
		if (cond2var)
		{
			if (!cond2var(temp, a2, b2))
			{
				cout << "Неверный ввод" << endl;
				continue;
			}
		}
		if (cond3var)
		{
			if (!cond3var(temp, a3, b3, c3))
			{
				cout << "Неверный ввод" << endl;
				continue;
			}
		}
		ok = !ok;
	}
	var = temp;
}
#endif
