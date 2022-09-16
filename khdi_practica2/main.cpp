//�������� �������� ������� ��������, ����-25-22

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <locale.h>
#include <conio.h>
#include <cmath>
#include <string>

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
            cout << "�������� ����" << endl;
        }
    }
    var = strtod(varstring.c_str(), nullptr);
}
//
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
            cout << "�������� ����" << endl;
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
            cout << "�������� ����" << endl;
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

    cout << "�����! ��-�� ������������ ��������� ������� ����� ���������� ������ �����\n�������: �� 0.6, � 0,6!" << endl;
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
    cout << "===============================" << endl;
    cout << "          ������� 1" << endl;
    cout << "-------------------------------" << endl;
    cout << "�����" << endl;
    double h, R, r, l;
    getvar(h, "������� ������ ������", true);
    h = round(h * pow(10, 6)) / pow(10, 6); //���������� �� 5-�� ����� ����� �������

    getvar(R, "������� ������ ������� ��������� ������", true);
    R = round(R * pow(10, 6)) / pow(10, 6); //���������� �� 5-�� ����� ����� �������

    getvar(r, "������� ������ �������� ��������� ������", true);
    r = round(r * pow(10, 6)) / pow(10, 6); //���������� �� 5-�� ����� ����� �������
    double V, S;

    l = sqrt((R - r) * (R - r) + h * h);
    if ((r == R) && (R == 0))
    {
        cout << "������� �������: ����� - 0, ������� ����������� - 0" << endl;
    }
    else if (r == R)
    {
        cout << "������� �������" << endl;
        V = pi * r * r * h;
        S = 2 * pi * r * h + 2 * pi * r * r;
        cout << "����� �������� - " << V << ", ������� ����������� - " << S << endl;
    }
    else if (h == 0)
    {
        cout << "������� ����" << endl;
        R = (R > r) ? R : r;
        S = 2 * pi * R * R;
        cout << "����� ����� - 0, ������� ����������� - " << S << endl;
    }
    else {
        V = (1.0 / 3.0) * pi * h * (R * R + R * r + r * r);
        S = pi * (R * R + (R + r) * l + r * r);
        cout << "����� ���������� ������ - " << V << ", ������� ����������� - " << S << endl;
    }
}

void f2()
{
    cout << "===============================" << endl;
    cout << "          ������� 2" << endl;
    cout << "-------------------------------" << endl;
    cout << "������������" << endl;
    float a, x;
    getvar(a, "������� a", false);
    getvar(x, "������� x", false);
    float w;

    if (abs(x) < 1)
    {
        if (0 == x)
            cout << "�������� w = a * ln|x| �� ���������� �� ��������� �������������� �����" << endl;
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
            cout << "�������� w = sqrt(a - x^2) �� ���������� �� ��������� �������������� �����" << endl;
        }
        else
        {
            w = sqrt(a - x * x);
            cout << "w = sqrt(a - x^2) = " << w << endl;
        }
    }
}

void f3()
{
    cout << "===============================" << endl;
    cout << "          ������� 3" << endl;
    cout << "-------------------------------" << endl;
    cout << "������� z = ln (b - y) * sqrt (b - x)" << endl;
    float b, x, y;
    getvar(b, "������� b", false);
    getvar(x, "������� x", false);
    getvar(y, "������� y", false);

    if (!((b - y) > 0) || ((b - x) < 0))
    {
        cout << "������� ��� ������ b, x, y �� ���������� �� ��������� �������������� �����" << endl;
    }
    else
    {
        float z = log(b - y) * sqrt(b - x);
        cout << "z = " << z << endl;
    }
}

void f4()
{
    cout << "===============================" << endl;
    cout << "          ������� 4" << endl;
    cout << "-------------------------------" << endl;
    cout << "�������" << endl;
    int n = 0;
    while (0 == n)
    {
        getvar(n, "������� ����������� n", true);
        if (0 == n)
        {
            cout << "�������� ����" << endl;
        }
    }

    for (int i = n; i < n + 10; ++i)
    {
        cout << i << " ";
    }
    cout << endl;
}

void f5()
{
    cout << std::fixed << std::setprecision(2);
    cout << "===============================" << endl;
    cout << "          ������� 5" << endl;
    cout << "-------------------------------" << endl;
    cout << "��������� ������� y = (x^2 - 2x + 2) / (x - 1)" << endl;
    for (float i = -4; i <= 4; i += 0.5f)
    {
        if (0 == i - 1)
            cout << "x = " << i << "; ������� �� ����������" << endl;
        else
            cout << "x = " << i << ": y = " << ((i * i - 2 * i + 2) / (i - 1)) << endl;
    }
    cout << "������� �� ���������� �� � = 1" << endl;
}