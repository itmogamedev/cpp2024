#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <memory> 

class Item
{
public:
	std::string name;
	int cost;
	int weight;

	Item(std::string name, int cost, int weight) : name(name), cost(cost), weight(weight) {}
};

class Shop
{
public:
	std::vector<std::shared_ptr<Item>> items; // Используем shared_ptr для управления памятью
	std::string shop_name;

	Shop(std::string name) : shop_name(name) {} // Конструктор для инициализации имени магазина

	void AddItem(std::shared_ptr<Item> item)
	{
		items.push_back(item);
	}

	float averagePrice() 
	{
		float total = 0;
		for (const auto& item : items) 
		{
			total += item->cost;
		}
		return items.empty() ? 0 : total / items.size();
	}

	float averageWeight() 
	{
		float total = 0;
		for (const auto& item : items) {
			total += item->weight;
		}
		return items.empty() ? 0 : total / items.size();
	}
};

class ClothesItem : public Item
{
public:
	std::string material;
	ClothesItem(std::string name, int cost, int weight, std::string material) : Item(name, cost, weight), material(material) {}
};

class MedicineItem : public Item
{
public:
	std::string application;
	MedicineItem(std::string name, int cost, int weight, std::string application) : Item(name, cost, weight), application(application) {}
};

class ArtItem : public Item
{
public:
	std::string colour;
	ArtItem(std::string name, int cost, int weight, std::string colour) : Item(name, cost, weight), colour(colour) {}
};

int main()
{
	std::ifstream file("List of shops.txt");
	std::string line;
	std::vector<Shop> shops;

	while (std::getline(file, line))
	{
		if (line.find("Shop") != std::string::npos)
		{
			std::string shop_name = line.substr(5);
			shops.emplace_back(shop_name);
		}
		else if (line.find("Items") != std::string::npos)
		{
			int numb_of_products;
			std::istringstream(line.substr(6)) >> numb_of_products;
			for (int i = 0; i < numb_of_products; ++i)
			{
				std::string item_name;
				int cost, weight;
				std::string additional_info;

				std::getline(file, line);
				std::istringstream iss(line);
				iss >> item_name >> cost >> weight >> additional_info;

				if (shops.back().shop_name == "Ostin")
				{
					auto clothesItem = std::make_shared<ClothesItem>(item_name, cost, weight, additional_info);
					shops.back().AddItem(clothesItem);
				}
				if (shops.back().shop_name == "Gorzdrav")
				{
					auto medItem = std::make_shared<MedicineItem>(item_name, cost, weight, additional_info);
					shops.back().AddItem(medItem);
				}
				else if (shops.back().shop_name == "Leonardo")
				{
					auto artItem = std::make_shared<ArtItem>(item_name, cost, weight, additional_info);
					shops.back().AddItem(artItem);
					
				}
			}
		}
	}

	for ( auto& shop : shops)
	{
		std::cout << "Shop:" << shop.shop_name << std::endl;
		std::cout << "Average Price: " << shop.averagePrice() << std::endl;
		std::cout << "Average Weight: " << shop.averageWeight() << std::endl;
		std::cout << std::endl;
	}

	file.close();
	return 0; // Возвращаем 0, чтобы указать, что программа завершилась успешно
}