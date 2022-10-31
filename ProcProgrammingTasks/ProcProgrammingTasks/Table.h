#pragma once
#ifndef TABLE_H
#define TABLE_H
#include <iostream>
#include <iomanip>
#include <string>
#include "consolecolors.h"

using namespace std;

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
#endif