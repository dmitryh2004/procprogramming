#pragma once
#ifndef COLOR_H
#define COLOR_H
#include <windows.h>
enum ConsoleColor
{
	Black = 0, Blue = 1,
	Green = 2, Cyan = 3,
	Red = 4, Magenta = 5,
	Brown = 6, LightGray = 7,
	DarkGray = 8, LightBlue = 9,
	LightGreen = 10, LightCyan = 11,
	LightRed = 12, LightMagenta = 13,
	Yellow = 14, White = 15
};

void SetColor(int bg, int t)
{
	HANDLE h1 = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h1, (WORD)((bg << 4) | t));
}

void SetToDef()
{
	SetColor(0, 15);
}
#endif