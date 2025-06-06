#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <string>
#include <map>
#include <iomanip>

class ItemBase {
public:
    virtual ~ItemBase() = default;
    virtual double getPrice() const = 0;
    virtual double getWeight() const = 0;
    virtual std::string getInfo() const = 0;
    virtual std::string getName() const = 0;
};

class Item : public ItemBase {
protected:
    std::string name;
    double price;
    double weight;
    std::string info;

public:
    Item(const std::string& name, double price, double weight, std::string info)
        : name(name), price(price), weight(weight), info(info) {}

    double getPrice() const override { return price; }
    double getWeight() const override { return weight; }
    std::string getName() const { return name; }
    std::string getInfo() const override { return info; }
};

class ForPCs : public Item {
public:
    ForPCs(const std::string& name, double price, double weight, std::string fps)
        : Item(name, price, weight, fps) {}
};

class Fruits : public Item {
public:
    Fruits(const std::string& name, double price, double weight, std::string vitamins)
        : Item(name, price, weight, vitamins) {}
};

class Clothes : public Item {
public:
    Clothes(const std::string& name, double price, double weight, std::string size)
        : Item(name, price, weight, size) {}
};

class Shop {
    std::string name;
    std::vector<std::shared_ptr<ItemBase>> items;

public:
    Shop(const std::string& name) : name(name) {}

    void addItem(std::shared_ptr<ItemBase> item) {
        items.push_back(item);
    }

    double avgPrice() const {
        if (items.empty())
            return 0.0;
        double total = 0.0;
        for (auto& item : items) {
            total += item->getPrice();
        }
        return total / items.size();
    }

    double avgWeight() const {
        if (items.empty())
            return 0.0;
        double total = 0.0;
        for (auto& item : items) {
            total += item->getWeight();
        }
        return total / items.size();
    }

    void printItemsInfo() const {
        std::cout << "Shop: " << name << ":\n";
        for (auto& item : items) {
            std::cout << "Item: " << item->getName()
                << ", Price: " << item->getPrice()
                << ", Weight: " << item->getWeight()
                << ", Info: " << item->getInfo() << std::endl;
        }
    }
};

std::vector<Shop> getFromFile(const std::string& path) {
    std::ifstream file(path);
    std::vector<Shop> shops;
    std::string line, word;
    Shop* currentShop = nullptr;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        iss >> word;

        if (line.rfind("Shop", 0) == 0) {  // Проверка на начало строки "Shop"
            std::string shopName = line.substr(5);  // Извлекаем имя магазина после "Shop"
            Shop shop(shopName);

            // Читаем строку с количеством товаров
            std::getline(file, line);
            int itemCount;
            iss.clear();
            iss.str(line);
            iss >> word >> itemCount;

            // Чтение каждого товара в магазине
            for (int i = 0; i < itemCount; i++) {
                std::getline(file, line);
                std::istringstream itemStream(line);
                std::string name, info;
                double price, weight;

                itemStream >> name >> price >> weight;
                std::getline(itemStream, info);  // Ожидаем, что остальная строка — это информация о товаре

                if (shopName == "ForPCs") {
                    shop.addItem(std::make_shared<ForPCs>(name, price, weight, info));
                }
                else if (shopName == "Fruits") {
                    shop.addItem(std::make_shared<Fruits>(name, price, weight, info));
                }
                else if (shopName == "Clothes") {
                    shop.addItem(std::make_shared<Clothes>(name, price, weight, info));
                }
            }

            shops.push_back(shop);
        }
    }
    return shops;
}

int main() {
    std::vector<Shop> shops = getFromFile("list.txt");

    // Печать информации о каждом магазине и его товарах
    for (const auto& shop : shops) {
        shop.printItemsInfo();
    }

    return 0;
}
