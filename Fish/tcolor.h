#pragma once
#include <windows.h>

enum class ConsoleColor {
	Black = 0,
	Blue,
	Green,
	Cyan,
	Red,
	Purple,
	Brown,
	LightGray,
	DarkGray,
	LightBlue,
	LightGreen,
	LightCyan,
	LightRed,
	LightPurple,
	Yellow,
	White = 15
};

// in () write ConsloleColor::YourColor
inline void SetColor(ConsoleColor color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, WORD(color));
}