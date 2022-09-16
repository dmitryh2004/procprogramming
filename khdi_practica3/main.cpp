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

void f1();
void f2();
void f3();
void f4();
void f5();

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Важно! Из-за особенностей программы дробные числа необходимо писать через\nзапятую: не 0.6, а 0,6!" << endl;
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
}

void f1()
{
    double m, S, n = 0, p = 0;
    cout << "===============================" << endl;
    cout << "          Задание 1" << endl;
    cout << "-------------------------------" << endl;
    cout << "Займ" << endl;
    getvar(S, "Введите сумму займа", true);
    while (n == 0)
    {
        getvar(n, "Введите количество лет", true);
        if (n == 0)
        {
            cout << "Неверный ввод" << endl;
        }
    }

    while (p == 0)
    {
        getvar(p, "Введите процент", true);
        if (p == 0)
        {
            cout << "Неверный ввод" << endl;
        }
    }


    p /= 100;

    m = S * p * pow(1 + p, n);
    m /= 12 * (pow(1 + p, n) - 1);
    cout << "Месячная выплата = " << m << endl;
}

void f2()
{
    double m = 0, S, n = 0, p;
    cout << "===============================" << endl;
    cout << "          Задание 2" << endl;
    cout << "-------------------------------" << endl;
    cout << "Процент займа" << endl;
    getvar(S, "Введите сумму займа", true);
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

    for (p = 0;; p += 0.1)
    {
        double r = p / 100;

        double t = S * r * pow(1 + r, n);
        t /= 12 * (pow(1 + r, n) - 1);
        if (t >= m)
        {
            cout << "Процент займа в пределах [" << p - 0.1 << "; " << p << "]" << endl;
            break;
        }
    }
}

void f3()
{
    cout << "===============================" << endl;
    cout << "          Задание 3" << endl;
    cout << "-------------------------------" << endl;
    cout << "Файлы" << endl;
    std::ifstream inf("files/file.txt");
    while (!inf.eof())
    {
        string t;
        getline(inf, t);
        cout << t << endl;
    }

    std::ofstream ouf("files/ofile.txt");
    ouf << "Bla bla bla" << endl << "Bla BlA" << endl;
    inf.close();
    ouf.close();
}

void f4()
{
    cout << "===============================" << endl;
    cout << "          Задание 4" << endl;
    cout << "-------------------------------" << endl;
    cout << "Фильтр" << endl;
    std::ifstream inf("files/filterfile.txt");
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
            cout << t;
            break;
        default:
            break;
        }
    }
    cout << endl;
}

void f5()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n = 0;
    char c[30];
    string cond = "абвгдеёжзийклмнопрстуфхцчшщъыьэюяabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯABCDEFGHIJKLMNOPQRSTUVWXYZ";
    while (n < 30)
    {
        system("cls");
        cout << "===============================" << endl;
        cout << "          Задание 5" << endl;
        cout << "-------------------------------" << endl;
        cout << "Сортировка" << endl;
        cout << "Вводите буквы: (" << n << "/30) -> ";
        c[n] = _getch();
        if (cond.find_first_of(c[n]) != string::npos)
        {
            n++;
        }
        if (n == 30)
        {
            system("cls");
            cout << "===============================" << endl;
            cout << "          Задание 5" << endl;
            cout << "-------------------------------" << endl;
            cout << "Сортировка" << endl;
            cout << "Вводите буквы: (30/30) -> введено!";
            cout << endl;
        }
    }
    cout << "Исходные буквы: ";
    for (int i = 0; i < 30; i++)
        cout << c[i];
    cout << endl;

    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            if (c[i] < c[j])
            {
                std::swap(c[i], c[j]);
            }
        }
    }

    cout << "Отсортированные буквы: ";
    for (int i = 0; i < 30; i++)
        cout << c[i];
    cout << endl;
}
