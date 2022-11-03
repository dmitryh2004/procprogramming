#pragma once
#ifndef Table_v2_H
#define Table_v2_H

#include <iostream>
#include <iomanip>
#include <string>
#include "consolecolors.h"

using namespace std;

namespace Table_v2_n {
	enum align_y { up, center_y, down };
	enum align_x { left, center_x, right };
	class Table_v2 {
	private:
		int cols = 0;
		int rows = 0;
		int border_color = 0;
		int* col_width = NULL;
		int* row_height = NULL;
		int total_width = 1;
		string name;
		align_y* aligns_y = NULL;
		align_x* aligns_x = NULL;
		string* data = NULL;
		int* bg_colors = NULL;
		int* t_colors = NULL;
	public:
		Table_v2(int c, int r, int* cw, int* rh, string n, int bc)
		{
			this->name = n;
			this->cols = c;
			this->rows = r;
			this->border_color = bc;
			this->col_width = cw;
			this->row_height = rh;
			
			data = new string[cols * rows];
			bg_colors = new int[cols * rows];
			t_colors = new int[cols * rows];
			aligns_y = new align_y[cols * rows];
			aligns_x = new align_x[cols * rows];

			for (int i = 0; i < cols; i++)
			{
				total_width += 1 + col_width[i];
			}
		}

		void set_data(int row, int col, string d, int bg, int t, align_y ay, align_x ax)
		{
			this->data[row*cols + col] = d;
			this->bg_colors[row*cols + col] = bg;
			this->t_colors[row*cols + col] = t;
			this->aligns_y[row*cols + col] = ay;
			this->aligns_x[row*cols + col] = ax;
		}

		void show_table()
		{
			cout << name << endl;
			SetColor(0, border_color);
			for (int i = 0; i < total_width; i++)
			{
				cout << "-";
			}
			cout << endl;
			for (int cur_row = 0; cur_row < rows; cur_row++)
			{
				int this_row_height = row_height[cur_row];
				int this_row_down_position = this_row_height - 1;
				int this_row_center_position = this_row_height / 2;
				for (int i = 0; i < this_row_height; i++)
				{
					SetColor(0, border_color);
					cout << "|";
					for (int cur_col = 0; cur_col < cols; cur_col++)
					{
						align_x ax = aligns_x[cur_row*cols + cur_col];
						align_y ay = aligns_y[cur_row*cols + cur_col];
						switch (ay)
						{
						case up:
							if (i != 0)
							{
								SetColor(bg_colors[cur_row*cols + cur_col], t_colors[cur_row*cols + cur_col]);
								for (int j = 0; j < col_width[cur_col]; j++)
								{
									cout << " ";
								}
								SetColor(0, border_color);
								cout << "|";
								continue;
							}	
							break;
						case center_y:
							if (i != this_row_center_position)
							{
								SetColor(bg_colors[cur_row*cols + cur_col], t_colors[cur_row*cols + cur_col]);
								for (int j = 0; j < col_width[cur_col]; j++)
								{
									cout << " ";
								}
								SetColor(0, border_color);
								cout << "|";
								continue;
							}
							break;
						case down:
							if (i != this_row_down_position)
							{
								SetColor(bg_colors[cur_row*cols + cur_col], t_colors[cur_row*cols + cur_col]);
								for (int j = 0; j < col_width[cur_col]; j++)
								{
									cout << " ";
								}
								SetColor(0, border_color);
								cout << "|";
								continue;
							}
							break;
						}
						int offset = 0;
						SetColor(bg_colors[cur_row*cols + cur_col], t_colors[cur_row*cols + cur_col]);
						switch (ax)
						{
						case left:
							cout.setf(ios::left);
							cout << setw(col_width[cur_col]);
							break;
						case center_x:
							cout.setf(ios::left);
							offset = (col_width[cur_col] - data[cur_row*cols + cur_col].size()) / 2;
							for (int j = 0; j < offset; j++)
							{
								cout << " ";
							}
							cout << setw(col_width[cur_col] - offset);
							break;
						case right:
							cout.unsetf(ios::left);
							cout << setw(col_width[cur_col]);
							break;
						}
						
						
						cout << data[cur_row*cols + cur_col];
						SetColor(0, border_color);
						cout << "|";
					}
					cout << endl;
				}

				SetColor(0, border_color);
				for (int i = 0; i < total_width; i++)
				{
					cout << "-";
				}
				cout << endl;
			}
			cout << endl;
			SetColor(0, 15);
		}
		~Table_v2()
		{
			delete[] data;
			delete[] bg_colors;
			delete[] t_colors;
			delete[] aligns_y;
			delete[] aligns_x;
#ifdef DEBUG 
			cout << "All data deleted from the table" << name << endl;
#endif
		}
	};
};

#endif