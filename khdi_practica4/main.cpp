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
            cout << "�������� ����" << endl;
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

void sign(double a)
{
    if (a < 0)
        cout << "������������� �����, ���� = -1";
    else if (a == 0)
        cout << "����, ���� = 0";
    else
        cout << "������������� �����, ���� = 1";
}

void circle()
{
    double r;
    getvar(r, "������� ������", true);
    double S = pi * r * r;
    cout << "������� ����� = " << S << endl;
}

void triangle()
{
    double a, b, c;
    getvar(a, "������� ������� �", true);
    getvar(b, "������� ������� b", true);
    getvar(c, "������� ������� �", true);

    if ((a + b < c) || (a + c < b) || (b + c < a))
    {
        cout << "����� ����������� �� ����������" << endl;
    }
    else
    {
        double p = (a + b + c) / 2;
        double S;
        S = sqrt(p * (p - a) * (p - b) * (p - c));
        cout << "������� ������������ = " << S << endl;
    }
}

void pryamougolnik()
{
    double a,b;
    getvar(a, "������� ������� �", true);
    getvar(b, "������� ������� b", true);

    cout << "������� = " << a * b << endl;
}

void f1();
void f2();
void f3();
void f4();
void f5();

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
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

    std::ofstream outf("files/file1.txt");
    int n = 0;
    double t = 0;
    while (n != 10)
    {
        cout << "===============================" << endl;
        cout << "          ������� 1" << endl;
        cout << "-------------------------------" << endl;
        cout << "���� � �������" << endl;
        string hint = "������� ����� (" + std::to_string(n) + "/10)";
        getvar(t, hint, false);
        outf << t << endl;
        n++;
        system("cls");
    }
    cout << "===============================" << endl;
    cout << "          ������� 1" << endl;
    cout << "-------------------------------" << endl;
    cout << "���� � �������" << endl;
    cout << "������� ����� (10/10) -> �������!" << endl;
    outf.close();
    cout << endl << "���� ������" << endl;
    std::ifstream inf("files/file1.txt");
    cout << endl << "���� ������" << endl;
    double S = 0;
    while (!inf.eof())
    {
        string temp;
        getline(inf, temp);
        S += strtod(temp.c_str(), nullptr);
    }
    inf.close();
    cout << "����� = " << S << endl;
}

void f2()
{
    cout << "===============================" << endl;
    cout << "          ������� 2" << endl;
    cout << "-------------------------------" << endl;
    cout << "���� �����" << endl;
    double n;
    getvar(n, "������� �����", false);
    sign(n);
    cout << endl;
}

void f3()
{
    cout << "===============================" << endl;
    cout << "          ������� 3" << endl;
    cout << "-------------------------------" << endl;
    cout << "�������" << endl;
    cout << "�������� ������: ������������� = P, ����������� = T, ���� = C";
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
    cout << "          ������� 4" << endl;
    cout << "-------------------------------" << endl;
    cout << "���� ���" << endl;
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
    cout << "          ������� 5" << endl;
    cout << "-------------------------------" << endl;
    cout << "���������" << endl;
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
        g[int(x*10) + 50][-int(y*10)-10] = '*';
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
