#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>

class Item {
public:
	std::string name;
	double price;
	double weight;
	std::string uniqueAttribute;

	Item(std::string name, double price, double weight, std::string uniqueAttribute)
		: name(name), price(price), weight(weight), uniqueAttribute(uniqueAttribute) {}
};

class ShopBase {
public:
	void addItem(Item item) {}

	~ShopBase() {}
};

class CustomShop : public ShopBase {
private:
	std::string shopName;
	std::vector<Item> items;

public:
	CustomShop(std::string name) : shopName(name) {}

	void addItem(Item item) {
		items.push_back(item);
	}

	double calculateAveragePrice() {
		double total = std::accumulate(items.begin(), items.end(), 0.0,
			[](double sum, Item item) { return sum + item.price; });
		return items.size() == 0 ? 0.0 : total / items.size();
	}

	double calculateAverageWeight() {
		double total = std::accumulate(items.begin(), items.end(), 0.0,
			[](double sum, Item item) { return sum + item.weight; });
		return items.size() == 0 ? 0.0 : total / items.size();
	}

	void displayAverages() {
		std::cout << "Shop: " << shopName << std::endl;
		std::cout << "Average Price: " << calculateAveragePrice() << std::endl;
		std::cout << "Average Weight: " << calculateAverageWeight() << std::endl << std::endl;

		for (int i = 0; i < items.size(); ++i) {
			std::cout << "Item: " << items[i].name << ", Price: " << items[i].price
				<< ", Weight: " << items[i].weight
				<< ", Unique Attribute: " << items[i].uniqueAttribute << std::endl;
		}
		std::cout << std::endl;
	}
};

std::vector<CustomShop> parseShopsFromFile(std::string filename) {
	std::ifstream file(filename);
	std::vector<CustomShop> shops;
	std::string line;

	if (!file.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return shops;
	}

	while (std::getline(file, line)) {
		if (line.rfind("Shop", 0) == 0) {
			std::string shopName = line.substr(5);
			if (shopName.empty()) {
				std::cerr << "Error: Missing shop name." << std::endl;
				continue;
			}

			CustomShop shop(shopName);

			if (!std::getline(file, line) || line.rfind("Items", 0) != 0) {
				std::cerr << "Error: Expected 'Items' line after shop name for shop " << shopName << std::endl;
				continue;
			}

			int itemCount;
			try {
				itemCount = std::stoi(line.substr(6));
			}
			catch (...) {
				std::cerr << "Error: Invalid item count for shop " << shopName << std::endl;
				continue;
			}

			for (int i = 0; i < itemCount; ++i) {
				if (!std::getline(file, line)) {
					std::cerr << "Error: Unexpected end of file while reading items for shop " << shopName << ".\n";
					break;
				}

				std::istringstream itemStream(line);
				std::string name, uniqueAttribute;
				double price, weight;

				if (!std::getline(itemStream, name, ',')) {
					std::cerr << "Error: Missing item name in shop " << shopName << ".\n";
					continue;
				}

				if (!(itemStream >> price)) {
					std::cerr << "Error: Invalid price for item " << name << " in shop " << shopName << ".\n";
					continue;
				}

				itemStream.ignore(1);

				if (!(itemStream >> weight)) {
					std::cerr << "Error: Invalid weight for item " << name << " in shop " << shopName << ".\n";
					continue;
				}

				itemStream.ignore(1);

				if (!std::getline(itemStream, uniqueAttribute)) {
					std::cerr << "Error: Missing unique attribute for item " << name << " in shop " << shopName << ".\n";
					continue;
				}

				shop.addItem(Item(name, price, weight, uniqueAttribute));
			}
			shops.push_back(shop);
		}
		else if (!line.empty()) {
			std::cerr << "Error: Unrecognized line format: " << line << "\n";
		}
	}
	return shops;
}

int main() {
	std::string filename = "shops_data.txt";
	std::vector<CustomShop> shops = parseShopsFromFile(filename);

	if (shops.empty()) {
		std::cerr << "Error: No valid shop data found in file.\n";
		return 1;
	}

	for (int i = 0; i < shops.size(); ++i) {
		shops[i].displayAverages();
	}

	return 0;
}