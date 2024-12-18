#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>


class Item {
public:
	std::string nameItem;
	float priceItem;
	float massItem;

	Item(const std::string& _nameItem, float _priceItem, float _massItem)
		: nameItem(_nameItem), priceItem(_priceItem), massItem(_massItem) {}
};

class ShopBase {
protected:
	std::vector<Item> items;

public:
	int quantityItems;

	float avgPrice() {
		std::cout << std::fixed << std::setprecision(2);
		float generalPrice{};

		for (Item& item : items) generalPrice += item.priceItem;

		return items.empty() ? 0 : generalPrice / items.size();
	}

	float avgMass() {
		std::cout << std::fixed << std::setprecision(2);
		float generalMass{};

		for (Item& item : items) generalMass += item.massItem;

		return items.empty() ? 0 : generalMass / items.size();
	}

	void addItem(const Item& item){
		items.push_back(item);
	}

};

class CustomShop : public ShopBase{
public:
	std::string shopName;

	CustomShop(const std::string& name): shopName(name){}
};

std::vector<CustomShop> parsingFile(const std::string& fileName) {
	std::vector<CustomShop> shops;
	
	std::ifstream file(fileName);
	std::string line;

	while (std::getline(file, line, ' ')) {
		if (line == "Shop") {
			std::getline(file, line);
			CustomShop customShop(line);

			std::getline(file, line, ' ');
			std::getline(file, line);
			customShop.quantityItems = std::stoi(line);

			for (int i = 0; i < customShop.quantityItems; i++) {
				std::getline(file, line);
				std::istringstream iss(line);
				std::string nameItem;
				float priceItem;
				float massItem;

				iss >> nameItem >> priceItem >> massItem;

				customShop.addItem(Item(nameItem, priceItem, massItem));
			}

			shops.push_back(customShop);
		}
		else std::getline(file, line);
	}
	return shops;
}

int main() {
	std::vector<CustomShop> shops = parsingFile("Shopping.txt");
	for (CustomShop shop : shops) {
		std::cout << shop.shopName << " avg mass: " << shop.avgMass() << '\n';
		std::cout << shop.shopName << " avg price: " << shop.avgPrice() << '\n';
	}

	return 0;
}