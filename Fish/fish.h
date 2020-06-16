#pragma once
#include <iostream>
#include "tcolor.h"
#include <ctime>
#include <io.h>
#include <fcntl.h>
using namespace std;

#define OUTPUT_MODE_UNICODE _setmode(_fileno(stdout), _O_U8TEXT)
#define OUTPUT_MODE_TEXT _setmode(_fileno(stdout), _O_TEXT)
#define GET_HANDLE(name) HANDLE (name) = GetStdHandle(STD_OUTPUT_HANDLE)
class Fish
{
public:
	enum Way
	{
		UP = 1,
		DOWN,
		LEFT,
		RIGHT
	};
	enum Limits
	{
		MIN_HP = 1,
		DEATH = 0,
		MAX_HP = 100,
	};
	enum Seaweeds
	{
		LOW = 1,
		MIDDLE = 2,
		HIGHT = 3,
		ULTRA = 100
	};
	Fish();
	Fish(size_t x, size_t y, size_t healthPoints);
	void print();
	void setX(size_t x);
	void setY(size_t y);
	size_t getX() const;
	size_t getY() const;
	size_t getHP() const;
	void setHP(size_t healthPoints);
	void setCoords(size_t x, size_t y);
	static size_t GetFishCount();
	static size_t GetSeaweedCount();
	static void HideCursor();
	static wchar_t** CreateWater(size_t rows, size_t cols);
	static void GenerateSeaweed(wchar_t** water, size_t rows, size_t cols);
	static void ShowWater(const wchar_t* const* water, size_t amount, Fish* fishes, size_t rows, size_t cols);
	static void GenerateFishs(Fish* fishes, size_t amount, size_t rows, size_t cols);
	static void FishMove(const wchar_t* const* water, Fish* fishes, const size_t amount, const size_t rows, const size_t cols);
	static void EatSeaweed(wchar_t** water, Fish* fishes, const size_t amount);
	static Fish* DeleteFish(Fish* fishes, size_t& amount, size_t index);
	~Fish();

private:
	size_t x;
	size_t y;
	size_t healthPoints;
	static int count;
	static int countSeaWeed;
};
