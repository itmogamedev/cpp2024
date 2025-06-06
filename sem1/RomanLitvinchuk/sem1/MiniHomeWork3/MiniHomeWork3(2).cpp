#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

class Item {
public:
    Item(std::string name, double price, double weight)
        : name(name), price(price), weight(weight) {}

    double getPrice() 
    { 
        return price; 
    }
    double getWeight() 
    { 
        return weight; 
    }

private:
    std::string name;
    double price;
    double weight;
};

class ShopBase {
public:
    ShopBase(std::string name) : name(name) {}

    void addItem(Item item) {
        items.push_back(item);
    }

    double averagePrice()
    {
        double totalPrice = 0;
        for (Item item : items) {
            totalPrice += item.getPrice();
        }
        return totalPrice / items.size();
    }

    double averageWeight()
    {
        double totalWeight = 0;
        for (Item item : items) {
            totalWeight += item.getWeight();
        }
        return totalWeight / items.size();
    }

    std::string getName() 
    {
        return name; 
    }

private:
    std::string name;
    std::vector<Item> items;
};

class DrinksShop : public ShopBase {
public:
    DrinksShop() : ShopBase("Drinks") {}
};

class FurnitureShop : public ShopBase {
public:
    FurnitureShop() : ShopBase("Furniture") {}
};

class HardwareShop : public ShopBase {
public:
    HardwareShop() : ShopBase("Hardware") {}
};

int main() {
    std::ifstream file("shops.txt");
    if (!file.is_open()) {
        std::cerr << "Error! File is not opened!";
        return 1;
    }

    DrinksShop drinksShop;
    FurnitureShop furnitureShop;
    HardwareShop hardwareShop;

    std::string shopType;
    std::string ItemsStr;
    int itemCount;

    while (file >> shopType) {
        if (shopType == "Shop") {
            file >> shopType;
            file >> ItemsStr;
            file >> itemCount;

            if (shopType == "Drinks") {
                for (int i = 0; i < itemCount; ++i) {
                    std::string itemName;
                    double price, weight;

                    file >> itemName >> price >> weight;
                    drinksShop.addItem(Item(itemName, price, weight));
                }
            }
            else if (shopType == "Furniture") {
                for (int i = 0; i < itemCount; ++i) {
                    std::string itemName;
                    double price, weight;

                    file >> itemName >> price >> weight;
                    furnitureShop.addItem(Item(itemName, price, weight));
                }
            }
            else if (shopType == "Hardware") {
                for (int i = 0; i < itemCount; ++i) {
                    std::string itemName;
                    double price, weight;

                    file >> itemName >> price >> weight;
                    hardwareShop.addItem(Item(itemName, price, weight));
                }
            }
        }
    }

    std::vector<ShopBase> shops = { drinksShop, furnitureShop, hardwareShop };
    for (auto shop : shops) {
        std::cout << "Shop: " << shop.getName() << std::endl;
        std::cout << "Average Price: " <<  shop.averagePrice() << std::endl;
        std::cout << "Average Weight: " << shop.averageWeight() << std::endl << std::endl;
    }

    return 0;
}