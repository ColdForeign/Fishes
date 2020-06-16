#pragma once
#include <iostream>
using namespace std;

class Water
{
public:
	enum class WaterTypes
	{
		NONE,
		LAKE,
		OCEAN,
		SEA,
		SWAMP,
		RESERVOIR,
		POOL
	};
	enum Limits
	{
		MAX_LENGHT = 16000,
		MAX_WIDHT = 20000,
		MAX_DEEP = 11000,
		MIN_LENGHT = 0,
		MIN_WIDHT = 0,
		MIN_DEEP = 0
	};

	Water();
	Water(string name, size_t lenght, size_t widht, size_t deep, WaterTypes type);
	Water(const Water& objectPtr1);

	void setName(string name);
	void setLenght(size_t lenght);
	void setWidth(size_t widht);
	void setMaxDeep(size_t deep);
	void setArea(size_t lenght, size_t widht);
	void setArea(size_t area);
	void setSpace(size_t lenght, size_t widht, size_t deep);
	void setSpace(size_t space);
	void setWaterType(WaterTypes type);
	
	string getName() const;
	size_t getLenght() const;
	size_t getWidht() const;
	size_t getMaxDeep() const;
	size_t getArea() const;
	size_t getSpace() const;
	string getWaterType() const;

	static bool cmpType(const Water& objectPtr1, const Water& objectPtr2);
	size_t findMostArea(Water* waters, size_t size, string type);
	static int cmpArea(const Water& objectPtr1, const Water& objectPtr2);

	void print();

	~Water();

private:
	string name;
	size_t lenght;
	size_t widht;
	size_t maxDeep;
	size_t area;
	size_t space;
	WaterTypes type;
	
};
