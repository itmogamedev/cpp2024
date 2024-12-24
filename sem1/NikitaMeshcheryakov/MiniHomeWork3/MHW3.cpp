#include <iostream>
#include <vector>
#include <string>
#include <fstream>

const std::string Path = "Shops.txt";
void SepString(std::string line, char sep, std::vector<std::string>& words);

class Item
{
private:
	std::string Name;
	double Price;
	double Weight;

public:
	Item(std::string name, double price, double weight)
	{
		Name = name;
		Price = price;
		Weight = weight;
	}

	double GetWeight()
	{
		return Weight;
	}

	double GetPrice()
	{
		return Price;
	}
};

class Shop 
{
protected:
	std::string Name;
	std::vector<Item> Goods;

public:

	Shop() {}

	Shop(std::string name)
	{
		Name = name;
	}

	virtual void WriteFromFileToShop()
	{
		std::vector<std::string> stringShopInfo;
		std::string line;
		int pos = 0;
		bool flag = false;

		std::ifstream in;
		in.open(Path);

		if (in.is_open())
		{
			while (std::getline(in, line))
			{
				if (flag)
				{
					pos = line.find("Shop");

					if (pos == 0)
					{
						break;
					}

					stringShopInfo.push_back(line);
				}

				if (line == "Shop " + Name)
				{
					flag = true;
				}
			}
		}
		in.close();

		for (int i = 1; i < stringShopInfo.size(); ++i)
		{
			if (stringShopInfo[i] == "")
			{
				continue;
			}

			std::vector<std::string> words;
			SepString(stringShopInfo[i], ' ', words);
			Item item(words[0], std::stod(words[1]), std::stod(words[2]));
			Goods.push_back(item);
		}
	}

	double CalculateAvgPrice()
	{
		int SumPrice = 0;

		for (int i = 0; i < Goods.size(); ++i)
		{
			SumPrice += Goods[i].GetPrice();
		}

		return SumPrice / Goods.size();
	}

	double CalculateAvgWeight()
	{
		int SumWeight = 0;

		for (int i = 0; i < Goods.size(); ++i)
		{
			SumWeight += Goods[i].GetWeight();
		}

		return SumWeight / Goods.size();
	}

	virtual void ShowInfo()
	{
		std::cout << "Магазин " << Name << std::endl;
		std::cout << "Средняя цена по магазину: " << CalculateAvgPrice() <<" рублей." << std::endl;
		std::cout << "Средний вес по магазину: " << CalculateAvgWeight() << " грамм." << std::endl;
	}
};

class ElectronicShop : public Shop
{
public:
	ElectronicShop(std::string name) : Shop(name) {}

	ElectronicShop() : Shop() {}

	//void WriteFromFileToShop() override
	// {
	//		Переопределение парсинга;
	// }

	//void ShowInfo() override
	// {
	//		Переопределение сводки по магазину;
	// }

};

class VegetablesShop : public Shop
{
public:
	VegetablesShop(std::string name) : Shop(name) {}

	VegetablesShop() : Shop() {}

	//void WriteFromFileToShop() override
	// {
	//		Переопределение парсинга;
	// }

	//void ShowInfo() override
	// {
	//		Переопределение сводки по магазину;
	// }
};

class HouseholdStore : public Shop
{
public:
	HouseholdStore(std::string name) : Shop(name) {}

	HouseholdStore() : Shop() {}

	//void WriteFromFileToShop() override
	// {
	//		Переопределение парсинга;
	// }

	//void ShowInfo() override
	// {
	//		Переопределение сводки по магазину;
	// }
};

class ShopBase 
{
private:
	std::vector<Shop> Shops;
	std::string BasePath;

public:
	ShopBase(std::string basePath)
	{
		BasePath = basePath;
	}

	void DefineTypesOfShops()
	{
		std::string line;
		int pos = 0;

		std::ifstream in;
		in.open(Path);

		if (in.is_open())
		{
			while (std::getline(in, line))
			{
				pos = line.find("Shop");

				if (pos == 0)
				{
					std::string shopName = line.substr(5);
					if (shopName == "MVideo")
					{
						ElectronicShop shop(shopName);
						Shops.push_back(shop);
					}
					else if (shopName == "FruitsAndVegetables")
					{
						VegetablesShop shop(shopName);
						Shops.push_back(shop);
					}
					else if(shopName == "Polaris")
					{
						HouseholdStore shop(shopName);
						Shops.push_back(shop);
					}
					else
					{
						Shop shop(shopName);
						Shops.push_back(shop);
					}
				}
			}
		}
		in.close();
	}

	void DefineShopsStats()
	{
		for(int i = 0; i < Shops.size(); ++i)
		{
			Shops[i].WriteFromFileToShop();
		}
	}

	void ShowAllInfo()
	{
		for (int i = 0; i < Shops.size(); ++i)
		{
			Shops[i].ShowInfo();
			std::cout << std::endl;
		}
	}
};

int main() 
{
	setlocale(LC_ALL, "RU");
	ShopBase shops("Path");

	shops.DefineTypesOfShops();

	shops.DefineShopsStats();

	shops.ShowAllInfo();
}

void SepString(std::string line, char sep, std::vector<std::string>& words)
{
	int i = 0;
	std::string tmp = "";

	while (i <= line.size())
	{
		while (line[i] != sep && i != line.size())
		{
			tmp += line[i];
			++i;
		}

		words.push_back(tmp);
		++i;
		tmp = "";
	}
}




