#include "Lake.h"

static int countWater = 0;
Water::Water()
{
	this->name = "NoName";
	this->lenght = 0;
	this->widht = 0;
	this->maxDeep = 0;
	this->type = Water::WaterTypes::NONE;
}

Water::Water(string name, size_t lenght, size_t widht, size_t deep, WaterTypes type)
{
	this->setName(name);
	this->setLenght(lenght);
	this->setWidth(widht);
	this->setMaxDeep(deep);
	this->setWaterType(type);
	this->setArea(lenght, widht);
	this->setSpace(lenght, widht, deep);
}

void Water::setName(string name)
{
	int tempLenght = 0;
	size_t nameLenght = name.length();
	for (size_t i = 0; i < nameLenght; i++)
	{
		if ((name[i] >= 65 && name[i] <= 90) || (name[i] >= 97 && name[i] <= 122) || name[i] >= ' ')
		{
			tempLenght++;
		}
		if (nameLenght == tempLenght)
			this->name = name;
	}
}

void Water::setLenght(size_t lenght)
{
	if (lenght > MIN_LENGHT || lenght < MAX_LENGHT)
	{
		this->lenght = lenght;
	}
}

void Water::setWidth(size_t widht)
{
	if (widht > MIN_WIDHT || widht < MAX_WIDHT)
	{
		this->widht = widht;
	}
}

void Water::setMaxDeep(size_t deep)
{
	if (deep > MIN_DEEP || deep < MAX_DEEP)
	{
		this->maxDeep = deep;
	}
}

void Water::setArea(size_t lenght, size_t widht)
{

	if (widht * lenght <= 165200000) //Площа найбільшого океану(тихого) в км2
	{
		this->area = widht * lenght;
	}
}

void Water::setArea(size_t area)
{
	if (area <= 165200000) //Площа найбільшого океану(тихого) в км2
	{
		this->area = area;
	}
}

void Water::setSpace(size_t lenght, size_t widht, size_t deep)
{
	if (lenght* widht* deep <= 710000000) //Максимальни об'єм води найбільшого океану(тихого) в км3
	{
		this->space = lenght * widht * deep;
	}
}

void Water::setSpace(size_t space)
{
	if (space <= 710000000) //Максимальни об'єм води найбільшого океану(тихого) в км3
	{
		this->space = space;
	}
}

void Water::setWaterType(WaterTypes type)
{
	if (type >= WaterTypes::NONE && type <= WaterTypes::POOL)
	{
		this->type = type;
	}
}

bool Water::cmpType(const Water& objectPtr1, const Water& objectPtr2)
{	
	if (objectPtr1.getWaterType() == objectPtr2.getWaterType())
	{
		return true;
	}
	else
		return 0;
}

int Water::cmpArea(const Water& objectPtr1, const Water& objectPtr2)
{
	if (objectPtr1.getArea() > objectPtr2.getArea())
		return 1;
	else if (objectPtr1.getArea() < objectPtr2.getArea())
		return -1;
	else
		return 0;
}

bool Water::cmpType(const Water& objectPtr1, const Water& objectPtr2)
{
	if (objectPtr1.getWaterType() == objectPtr2.getWaterType())
	{
		return true;
	}
	else
		return false;
}

size_t Water::findMostArea(Water* waters, size_t size, string type)
{
	size_t max = waters[0].getArea();
	size_t index = 0;

	for (size_t i = 1; i < size; i++)
		if (waters[i].getWaterType() == type)
			if (max < waters[i].getArea())
			{
				max = waters[i].getArea();
				index = i;
			}

	return index;
}

string Water::getName() const
{
	return this->name;
}

size_t Water::getLenght() const
{
	return this->lenght;
}

size_t Water::getWidht() const
{
	return this->widht;
}

size_t Water::getMaxDeep() const
{
	return this->maxDeep;
}

size_t Water::getArea() const
{
	return this->area;
}

size_t Water::getSpace() const
{
	return this->space;
}

string Water::getWaterType() const
{
	switch (this->type)
	{
	case WaterTypes::NONE:
		return "NONE";
		break;
	case WaterTypes::LAKE:
		return "LAKE";
		break;
	case WaterTypes::OCEAN:
		return "OCEAN";
		break;
	case WaterTypes::SEA:
		return "SEA";
		break;
	case WaterTypes::SWAMP:
		return "SWAMP";
		break;
	case WaterTypes::RESERVOIR:
		return "RESERVOIR";
		break;
	case WaterTypes::POOL:
		return "POOL";
		break;
	}
}


void Water::print()
{
	cout << "Water name: " << getName() << endl;
	cout << "Water lenght: " << getLenght() << endl;
	cout << "Water widht: " << getWidht() << endl;
	cout << "Water maximum deep: " << getMaxDeep() << endl;
	cout << "Water area: " << getArea() << endl;
	cout << "Water space: " << getSpace() << endl;
	cout << "Water type: " << getWaterType() << endl;
}

Water::~Water()
{
}
