#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class ItemBase {
public:
    virtual double getPrice() const = 0;
    virtual double getWeight() const = 0;
    virtual ~ItemBase() {}
};

class Item : public ItemBase {
private:
    std::string name;
    double price;
    double weight;

public:
    Item(const std::string name, double price, double weight)
        : name(name), price(price), weight(weight) {}

    double getPrice() const override {
        return price;
    }

    double getWeight() const override {
        return weight;
    }
};

class Shop {
private:
    std::string name;
    std::vector<Item> items; 

public:
    Shop(const std::string name) : name(name) {}

    void addItem(const Item item) {
        items.push_back(item);
    }

    double averagePrice() const {
        if (items.empty()) return 0;
        double total = 0;
        for (const auto item : items) {
            total += item.getPrice();
        }
        return total / items.size();
    }

    double averageWeight() const {
        if (items.empty()) return 0;
        double total = 0.0;
        for (const auto& item : items) {
            total += item.getWeight();
        }
        return total / items.size();
    }

    const std::string& getName() const {
        return name;
    }
};

std::vector<Shop> parseFile(const std::string filePath) {
    std::vector<Shop> shops;
    std::ifstream file(filePath);
    std::string line;

    while (std::getline(file, line)) {
        if (line.find("Shop") == 0) {
            std::string shopName = line.substr(5);
            Shop shop(shopName);

            std::getline(file, line);
            int itemsCount = std::stoi(line.substr(6));

            for (int i = 0; i < itemsCount; ++i) {
                std::getline(file, line);
                std::istringstream iss(line);
                std::string itemName;
                double itemPrice, itemWeight;

                iss >> itemName >> itemPrice >> itemWeight;
                shop.addItem(Item(itemName, itemPrice, itemWeight)); 
            }
            shops.push_back(shop); 
        }
    }
    return shops;
}

int main() {
    std::vector<Shop> shops = parseFile("shops.txt");

    for (const auto shop : shops) {
        double avgPrice = shop.averagePrice();
        double avgWeight = shop.averageWeight();
        std::cout << "Shop: " << shop.getName()
            << ", Average Price: " << avgPrice
            << ", Average Weight: " << avgWeight << std::endl;
    }

    return 0;
}
