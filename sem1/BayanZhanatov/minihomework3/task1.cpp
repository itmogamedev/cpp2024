#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class ItemBase {
public:
    virtual ~ItemBase() {}
    virtual double getPrice() const = 0;
    virtual double getWeight() const = 0;
};

class Item : public ItemBase {
    std::string name;
    double price;
    double weight;

public:
    Item(const std::string& name, double price, double weight)
        : name(name), price(price), weight(weight) {}

    double getPrice() const override {
        return price;
    }

    double getWeight() const override {
        return weight;
    }
};

class Shop {
    std::string name;
    std::vector<Item> items;

public:
    Shop(const std::string& name) : name(name) {}

    void addItem(const Item& item) {
        items.push_back(item);
    }

    double calculateAveragePrice() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.getPrice();
        }
        return items.empty() ? 0 : total / items.size();
    }

    double calculateAverageWeight() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.getWeight();
        }
        return items.empty() ? 0 : total / items.size();
    }

    std::string getName() const {
        return name;
    }
};

std::vector<Shop> parseFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::vector<Shop> shops;

    while (getline(file, line)) {
        std::istringstream ss(line);
        std::string shopHeader, shopName;
        ss >> shopHeader >> shopName;

        if (shopHeader == "Shop") {
            Shop shop(shopName);

            getline(file, line);
            ss.clear();
            ss.str(line);
            std::string itemsHeader;
            int itemCount;
            ss >> itemsHeader >> itemCount;

            for (int i = 0; i < itemCount; ++i) {
                getline(file, line);
                ss.clear();
                ss.str(line);
                std::string itemName;
                double price, weight;
                ss >> itemName >> price >> weight;
                Item item(itemName, price, weight);
                shop.addItem(item);
            }
            shops.push_back(shop);
        }
    }
    return shops;
}

int main() {
    std::string filename = "shops.txt";
    auto shops = parseFile(filename);

    for (const auto& shop : shops) {
        std::cout << "Shop: " << shop.getName() << std::endl;
        std::cout << "Average Price: " << shop.calculateAveragePrice() << std::endl;
        std::cout << "Average Weight: " << shop.calculateAverageWeight() << std::endl;
    }

    return 0;
}
