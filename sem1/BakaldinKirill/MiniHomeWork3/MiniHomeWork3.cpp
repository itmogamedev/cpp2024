#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class ItemBase {
public:
    double getPrice() const { return 0.0; };
    double getWeight() const { return 0.0; };
};

class Item : public ItemBase {
private:
    std::string name;
    double price;
    double weight;

public:
    Item(std::string name, double price, double weight)
        : name(name), price(price), weight(weight) {}

    double getPrice() const { return price; }
    double getWeight() const { return weight; }

    std::string getName() const { return name; }
};

class Shop {
private:
    std::string name;
    std::vector<Item> items;

public:
    Shop(std::string name) : name(name) {}

    void addItem(Item item) {
        items.push_back(item);
    }

    double averagePrice() const {
        if (items.empty()) return 0.0;
        double totalPrice = 0.0;
        for (Item item : items) {
            totalPrice += item.getPrice();
        }
        return totalPrice / items.size();
    }

    double averageWeight() const {
        if (items.empty()) return 0.0;
        double totalWeight = 0.0;
        for (Item item : items) {
            totalWeight += item.getWeight();
        }
        return totalWeight / items.size();
    }

    std::string getName() const { return name; }
};

std::vector<Shop> parseShopsFromFile(std::string filename) {
    std::vector<Shop> shops;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file.\n";
        return shops;
    }

    std::string line, shopName;
    int itemCount = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        iss >> word;

        if (word == "Shop") {
            iss >> shopName;
            shops.emplace_back(shopName);
        }
        else if (word == "Items") {
            iss >> itemCount;
        }
        else {
            std::string itemName = word;
            double price, weight;
            iss >> price >> weight;
            Item item(itemName, price, weight);
            shops.back().addItem(item);
        }
    }

    file.close();
    return shops;
}

int main() {
    std::string filename = "shops.txt";
    std::vector<Shop> shops = parseShopsFromFile(filename);

    for (Shop shop : shops) {
        std::cout << "Shop: " << shop.getName() << "\n";
        std::cout << "Average Price: " << shop.averagePrice() << "\n";
        std::cout << "Average Weight: " << shop.averageWeight() << "\n\n";
    }

    return 0;
}
