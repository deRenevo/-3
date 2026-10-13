#include <iostream>
#include <Windows.h>
#include <locale>
#include <random>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>

void Start();
static int ReadIntRange(int min, int max);

static void CreateFruitJuice(std::vector<std::string>& names, std::vector<int>& prices)
{
	names.clear();
	prices.clear();

	names.push_back("Яблочный сок");
	prices.push_back(100);

	names.push_back("Апельсиновый сок");
	prices.push_back(100);

	names.push_back("Абрикосовый сок");
	prices.push_back(100);

	names.push_back("Грушевый сок");
	prices.push_back(100);
}

static void CreateVegetableJuice(std::vector<std::string>& names, std::vector<int>& prices)
{
	names.clear();
	prices.clear();

	names.push_back("Томатный сок");
	prices.push_back(100);

	names.push_back("Луковый сок");
	prices.push_back(200);

	names.push_back("Огуречный сок");
	prices.push_back(100);
}

static void CreateTea(std::vector<std::string>& names, std::vector<int>& prices)
{
	names.clear();
	prices.clear();

	names.push_back("Чесночный чай");
	prices.push_back(100);

	names.push_back("Петрушковый чай");
	prices.push_back(200);
}

static void CreateTincture(std::vector<std::string>& names, std::vector<int>& prices)
{
	names.clear();
	prices.clear();

	names.push_back("Боярышник");
	prices.push_back(100);
}

static void ShopPage(std::vector<std::string>& nameList, std::vector<int>& pricesList, std::vector<int>& countList, const std::vector<std::string>& showcaseName, const std::vector<int>& showcasePrices);

static void RemoveHawthorn(std::vector<std::string>& names, std::vector<int>& prices, std::vector<int>& counts)
{
	while (true)
	{
		auto it = std::find(names.begin(), names.end(), "Боярышник");
        
		if (it == names.end())
		{
			break;
		}

		int I = static_cast<int>(it - names.begin());

		names.erase(names.begin() + I);
		prices.erase(prices.begin() + I);
		counts.erase(counts.begin() + I);
	}
}

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	/*srand(time(NULL));
	{
	int Capcha = rand() % 10000;
	std::cout << "КАПЧА: " << Capcha << std::endl;
	int Inp;
	std::cout << "ВВЕДИТЕ: ";
	std::cin >> Inp;

	if (Capcha != Inp)
	{
		std::cout << "НЕТ ВЫ РОБОТ" << std::endl;
		return 0;
	}
	}*/

	system("cls");
	
	bool bIsRunning = true;

	while (bIsRunning)
	{
		system("cls");
		int Inp;
		std::cout << "Выборк" << std::endl;
		std::cout << "0.Выход" << std::endl;
		std::cout << "1.Вход" << std::endl;

		std::cin >> Inp;

		switch (Inp)
		{
		case 0:
			bIsRunning = false;
			break;

		case 1:
			Start();
			int i;
			std::cout << "Продолжить тык" << std::endl;
			std::cin >> i;
			break;

		default:
			std::cout << "Ошибка" << std::endl;
		}
	}
	

	return 0;
}

void Start()
{
	bool bIsRunning = true;
	
	std::vector<std::string> NameFruitJuice;
	std::vector<int> PriceFruitJuice;
	CreateFruitJuice(NameFruitJuice, PriceFruitJuice);
	
	std::vector<std::string> NameVegetableJuice;
	std::vector<int> PriceVegetableJuice;
	CreateVegetableJuice(NameVegetableJuice, PriceVegetableJuice);
	
	std::vector<std::string> NameTea;
	std::vector<int> PriceTea;
	CreateTea(NameTea, PriceTea);
	
	std::vector<std::string> NameTincture;
	std::vector<int> PriceTincture;
	CreateTincture(NameTincture, PriceTincture);
	
	std::vector<std::string> NameList;
	std::vector<int> PriceList;
	std::vector<int> CountList;
	
	bool bIsHawthorn = false;
	
	while (bIsRunning)
	{
		system("cls");
		std::cout << "Соки севы" << std::endl;
		std::cout << "===Menu===" << std::endl;
		std::cout << "1.Фруктовые соки" << std::endl;
		std::cout << "2.Овощные соки" << std::endl;
		std::cout << "3.Чаи" << std::endl;
		std::cout << "4.Настойки" << std::endl;
		std::cout << "0.Выйти" << std::endl;


		std::cout << std::endl << "Input Action" << std::endl;
		size_t OldSize;
		int Inp;
		while (true)
		{
			if (std::cin >> Inp)
			{
				if (Inp >= 0 && Inp <= 4)
				{
					break;
				}
			}
			
			std::cin.clear();
			std::cin.ignore(10000, '\n');

			std::cout << "error" << std::endl << std::endl;
		}

		switch (Inp)
		{
		case 0:
			bIsRunning = false;
			break;
		case 1:
			OldSize = NameList.size();
			ShopPage(NameList, PriceList, CountList, NameFruitJuice, PriceFruitJuice);
			if (NameList.size() > OldSize)
			{
				bIsHawthorn = true;
				RemoveHawthorn(NameList, PriceList, CountList);
				std::cout << "Ну все без настойки(\n";
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				std::cin.sync();
				std::cin.get();
			}
			break;
		case 2:
			ShopPage(NameList, PriceList, CountList, NameVegetableJuice, PriceVegetableJuice);
			break;
		case 3:
			ShopPage(NameList, PriceList, CountList, NameTea, PriceTea);
			break;
		case 4:
			if (bIsHawthorn)
			{
				std::cout << "Не не без настоек сегодня\n";
				std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
				std::cin.sync();
				std::cin.get();
				break;
			}
			ShopPage(NameList, PriceList, CountList, NameTincture, PriceTincture);
			break;
		default: 
			break;
		}
	}

	int Sum = 0;
	int TotalDisc = 0;
	int GiftOnionCount;

	for (size_t i = 0; i < NameList.size(); ++i)
	{
		Sum += PriceList[i] * CountList[i];
		std::cout << NameList[i] << "\tЦена: " << PriceList[i] << " Количество: " << CountList[i] << std::endl;
	}

	{
		int OnionCost = 0;
		int Count = 0;
		for (int i = 0; i < NameList.size(); ++i)
		{
			if (NameList[i] == "Луковый сок")
			{
				OnionCost = PriceList[i];
				Count += CountList[i];
			}
		}

		GiftOnionCount = Count / 4;
		int OnionDiscount = GiftOnionCount * OnionCost;
		
		Sum -= OnionDiscount;
		TotalDisc += OnionDiscount;
	}

	{
		int Count = 0;
		int Cost = 0;
		for (size_t i = 0; i < NameList.size(); ++i)
		{
			if (NameList[i] == "Петрушковый чай")
			{
				Cost = PriceList[i];
				Count += CountList[i];
			}
		}

		if (Count == 3)
		{
			int Disc = (Cost * Count) * 5 / 100;
			Sum -= Disc;
			TotalDisc += Disc;
		}
	}

	constexpr int Limit = 1000;
	if (Sum > Limit)
	{
		int Disc = Sum * 13 / 100;
		Sum -= Disc;
		TotalDisc += Disc;
	}

	std::cout << "Sum: " << Sum << std::endl;
	std::cout << "Луковый сок в подарок: " << GiftOnionCount << std::endl;
	std::cout << "Скидка: " << TotalDisc << std::endl;
}

static void ShopPage(std::vector<std::string>& nameList, std::vector<int>& price_list, std::vector<int>& countList, const std::vector<std::string>& showcaseName, const std::vector<int>& showcasePrice)
{
	if (showcaseName.empty() || showcasePrice.empty())
	{
		std::cout << "Error" << '\n';
		return;
	}
	
	while (true)
	{
		std::cout << "====СОКИ--СЕВЫ====" << '\n';
		std::cout << "ВЫБЕРЕТЕ КАТЕГРОИЮ" << '\n';
		for (int i = 0; i < showcaseName.size(); ++i)
		{
			std::cout << i + 1 << ". " << showcaseName[i] << " (" << showcasePrice[i] << " не_руб.)" << '\n';
		}
		std::cout << "0. Вернуться назад" << '\n';
		
		std::cout << "Выберети товар: \n";
		const int Inp = ReadIntRange(0, static_cast<int>(showcaseName.size()));
		
		if (Inp == 0)
		{
			break;
		}
		
		std::cout << "Выберети количество: \n";
		const int InpCount = ReadIntRange(1, (std::numeric_limits<int>::max)());
		nameList.push_back(showcaseName[Inp - 1]);
		price_list.push_back(showcasePrice[Inp - 1]);
		countList.push_back(InpCount);
		std::cout << "Добавленно.\n";
	}
}

static int ReadIntRange(int min, int max)
{
	int X;

	while (true)
	{
		if (std::cin >> X)
		{
			if (X >= min && X <= max)
			{
				return X;
			}
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}

		std::cout << "Ошибка" << '\n';
	}
}