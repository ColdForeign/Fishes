#include "fish.h"

int main()
{
	srand(unsigned(time(nullptr)));
	size_t rows = 20;
	size_t cols = 40;

	size_t amount, time;
	cout << "Enter count of fishes: ";
	cin >> amount;
	cout << "Enter sleep time: ";
	cin >> time;

	Fish* fishes = new Fish[amount];
	wchar_t** ocean = Fish::CreateWater(rows, cols);
	Fish::HideCursor();
	Fish::GenerateFishs(fishes, amount, rows, cols);
	Fish::GenerateSeaweed(ocean, rows, cols);
	Fish::ShowWater(ocean, amount, fishes, rows, cols);
	size_t goCount = 0;
	do
	{
		system("cls");
		amount = Fish::GetFishCount();
		for (size_t i = 0; i < amount; i++)
			if (fishes[i].getHP() == Fish::DEATH)
				fishes = Fish::DeleteFish(fishes, amount, i);
		if (Fish::GetSeaweedCount() < 120)
			Fish::GenerateSeaweed(ocean, rows, cols);

		Fish::ShowWater(ocean, amount, fishes, rows, cols);
		Sleep(time);
		system("color 0");
		cout << "Fish count: " << Fish::GetFishCount() << endl;
		cout << "Seaweed count: " << Fish::GetSeaweedCount() << endl;

		Fish::FishMove(ocean, fishes, amount,  rows, cols);
		Fish::EatSeaweed(ocean, fishes, amount);
		goCount++;
	} while (amount > 0);

	cout << "Itaration: " << goCount << ", game over\n";
}
