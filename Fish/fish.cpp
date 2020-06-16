#include "fish.h"

int Fish::count = 0; 
int Fish::countSeaWeed = 0;
Fish::Fish()
{
	this->x = 0;
	this->y = 0;
	this->healthPoints = 100;
	count++;
}

Fish::Fish(size_t x, size_t y, size_t healthPoints)
{
	this->setCoords(x, y);
	this->setHP(healthPoints);
	count++;
}

void Fish::print()
{
	SetColor(ConsoleColor::LightCyan);
	cout << this->getX() << "||" << this->getY() << endl;
	cout << this->getHP() << endl;
}

void Fish::setX(size_t x)
{
	this->x = x;
}

void Fish::setY(size_t y)
{
	this->y = y;
}

size_t Fish::getX() const
{
	return this->x;
}

size_t Fish::getY() const
{
	return this->y;
}

size_t Fish::getHP() const
{
	return this->healthPoints;
}

void Fish::setHP(size_t healthPoints)
{
	this->healthPoints = healthPoints;
}

void Fish::setCoords(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
}

size_t Fish::GetFishCount()
{
	return count;
}

size_t Fish::GetSeaweedCount()
{
	return countSeaWeed;
}

void Fish::HideCursor()
{
	GET_HANDLE(hConsole);
	CONSOLE_CURSOR_INFO consoleCursor;
	GetConsoleCursorInfo(hConsole, &consoleCursor);
	consoleCursor.bVisible = false;
	SetConsoleCursorInfo(hConsole, &consoleCursor);
}

wchar_t** Fish::CreateWater(size_t rows, size_t cols)
{
	wchar_t** water = new wchar_t* [rows];
	for (size_t i = 0; i < rows; i++)
		water[i] = new wchar_t[cols];

	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; j++)
			water[i][j] = ' ';
	return water;
}

void Fish::GenerateSeaweed(wchar_t** water, size_t rows, size_t cols)
{
	size_t tempX, tempY;
	for (size_t i = 0; i < rand() % 31 + 50; i++)
	{
		countSeaWeed++;
		tempX = rand() % rows;
		tempY = rand() % cols;
		water[tempX][tempY] = L'░';
	}

	for (size_t i = 0; i < rand() % 21 + 30; i++)
	{
		countSeaWeed++;
		do
		{
			
			tempX = rand() % rows;
			tempY = rand() % cols;
		} while (water[tempX][tempY] != ' ');

		water[tempX][tempY] = L'▒';
	}

	for (size_t i = 0; i < rand() % 11 + 15; i++)
	{
		countSeaWeed++;
		do
		{
			
			tempX = rand() % rows;
			tempY = rand() % cols;
		} while (water[tempX][tempY] != ' ');

		water[tempX][tempY] = L'▓';
	}

	for (size_t i = 0; i < rand() % 10 + 1 ; i++)
	{
		countSeaWeed++;
		do
		{
			tempX = rand() % rows;
			tempY = rand() % cols;
		} while (water[tempX][tempY] != ' ');

		water[tempX][tempY] = L'█';
	}
}

void Fish::ShowWater(const wchar_t* const* water, size_t amount, Fish* fishes, size_t rows, size_t cols)
{
	GET_HANDLE(hConsole);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			bool temp = false;
			OUTPUT_MODE_UNICODE;
			for (size_t k = 0; k < amount; k++)
				if (fishes[k].getX() == i && fishes[k].getY() == j)
				{
					SetConsoleTextAttribute(hConsole, WORD((11 << 4) | 4));
					wcout << L"■";
					temp = true;
					break;
				}

			if (!temp)
			{
				if (water[i][j] == ' ')
					SetConsoleTextAttribute(hConsole, WORD((11 << 4) | 4));
				else
					SetConsoleTextAttribute(hConsole, WORD((11 << 4) | 2));
				wcout << water[i][j];
			}
		}
		OUTPUT_MODE_TEXT;
		cout << endl;
	}
}

void Fish::GenerateFishs(Fish* fishes, size_t amount, size_t rows, size_t cols)
{
	for (size_t i = 0; i < amount; i++)
	{
		fishes[i].setCoords((rand() % rows), (rand() % cols));
	}
}

void Fish::FishMove(const wchar_t* const*, Fish* fishes, const size_t amount, const size_t rows, const size_t cols)
{
	const size_t maxMove = 3;
	size_t moveWay, move;
	for (size_t i = 0; i < amount; i++)
	{
		size_t tempX = fishes[i].getX();
		size_t tempY = fishes[i].getY();
		move = rand() % maxMove + 1;
		moveWay = rand() % 4 + 1;
		switch (moveWay)
		{
		case UP:
			if (int(tempY - move) <= 0)
				fishes[i].setY(cols - move);
			else
				fishes[i].setY(tempY - move);
			break;

		case DOWN:
			if (tempY + move >= cols - 1)
				fishes[i].setY(move);
			else
				fishes[i].setY(tempY + move);
			break;

		case LEFT:
			if (int(tempX - move) <= 0)
				fishes[i].setX(rows - move);
			else
				fishes[i].setX(tempX - move);
			break;

		case RIGHT:
			if (tempX + move >= rows - 1)
				fishes[i].setX(move);
			else
				fishes[i].setX(tempX + move);
			break;
		}

		if (fishes[i].getHP() != 0)
			fishes[i].setHP(fishes[i].getHP() - 1);
		
	}
}

void Fish::EatSeaweed(wchar_t** water, Fish* fishes, const size_t amount)
{
	size_t tempX, tempY;
	for (size_t i = 0; i < amount; i++)
	{
		size_t tempX = fishes[i].getX();
		size_t tempY = fishes[i].getY();

		if (water[tempX][tempY] == L' ' || fishes[i].getHP() == MAX_HP)
			continue;
		if (water[tempX][tempY] == L'█')
		{
			fishes[i].setHP(MAX_HP);
			water[tempX][tempY] = ' ';
			countSeaWeed--;
			return;
		}

		if ((water[tempX][tempY] != ' ')
			&& (fishes[i].getHP() + LOW >= MAX_HP
				|| fishes[i].getHP() + MIDDLE >= MAX_HP
				|| fishes[i].getHP() + HIGHT >= MAX_HP))
		{
			fishes[i].setHP(MAX_HP);
			countSeaWeed--;
			water[tempX][tempY] = ' ';
		}
		else if (water[tempX][tempY] != L'░')
		{
			countSeaWeed--;
			fishes[i].setHP(fishes[i].getHP() + LOW);
			water[tempX][tempY] = ' ';
		}
		else if (water[tempX][tempY] != L'▒')
		{
			countSeaWeed--;
			fishes[i].setHP(fishes[i].getHP() + MIDDLE);
			water[tempX][tempY] = ' ';
		}
		else if (water[tempX][tempY] != L'▓')
		{
			countSeaWeed--;
			fishes[i].setHP(fishes[i].getHP() + HIGHT);
			water[tempX][tempY] = ' ';
		}
	}
}

Fish* Fish::DeleteFish(Fish* fishes, size_t& amount, size_t index)
{
	if (amount > 0)
	{
		amount--;
		Fish* tempFishes = new Fish[amount];

		for (size_t i = 0, j = 0; i < amount + 1; i++)
			if (i != index)
				tempFishes[j++] = fishes[i];

		delete[] fishes;
		fishes = nullptr;

		return tempFishes;
	}
	else
		return fishes;
}

Fish::~Fish()
{
	this->healthPoints = 0;
	this->x = 0;
	this->y = 0;
	count--;
}