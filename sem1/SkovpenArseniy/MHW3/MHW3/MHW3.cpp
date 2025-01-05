#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class Item {
public:
    std::string name;
    double price;
    double weight;

    Item(const std::string& n, double p, double w) : name(n), price(p), weight(w) {}
};

class ShopBase {
protected:
    std::vector<Item> items;

public:
    virtual void addItem(const Item& item) {
        items.push_back(item);
    }

    virtual double averagePrice() {
        double total = 0;
        for (const auto& item : items) {
            total += item.price;
        }
        return total / items.size();
    }

    virtual double averageWeight() {
        double total = 0;
        for (const auto& item : items) {
            total += item.weight;
        }
        return total / items.size();
    }
};

class CustomShop : public ShopBase {
public:
    std::string shopName;

    CustomShop(const std::string& name) : shopName(name) {}
};

void parseFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line, shopName;
    int itemCount;

    while (std::getline(file, line)) {
        if (line.find("Shop") != std::string::npos) {
            shopName = line.substr(5);
            CustomShop shop(shopName);
            std::getline(file, line);
            itemCount = std::stoi(line.substr(6));

            for (int i = 0; i < itemCount; ++i) {
                std::getline(file, line);
                std::istringstream iss(line);
                std::string itemName;
                double price, weight;
                iss >> itemName >> price >> weight;
                shop.addItem(Item(itemName, price, weight));
            }

            std::cout << "Shop: " << shopName << "\nAverage Price: "
                << shop.averagePrice() << "\nAverage Weight: "
                << shop.averageWeight() << "\n\n";
        }
    }
}

int main() {
    parseFile("shops.txt");
    return 0;
}
