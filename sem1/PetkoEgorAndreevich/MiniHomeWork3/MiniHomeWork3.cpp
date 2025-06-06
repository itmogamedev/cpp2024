#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;
using std::stringstream;
using std::getline;

class ItemBase {
protected:
    string category;
public:
    ItemBase(string category) : category(category) {}
    virtual ~ItemBase() {}
    string getCategory() const { return category; }
};

class Item : public ItemBase {
private:
    string name;
    float price;
    float weight;

public:
    Item(string name, float price, float weight, string category)
        : ItemBase(category), name(name), price(price), weight(weight) {}

    string getName() const { return name; }
    float getPrice() const { return price; }
    float getWeight() const { return weight; }
};

class Shop {
private:
    string name;
    vector<Item> items;

public:
    Shop(string name) : name(name) {}

    void addItem(const Item& item) {
        items.push_back(item);
    }

    float averagePrice() const {
        if (items.empty()) return 0;
        float totalPrice = 0;
        for (const auto& item : items) {
            totalPrice += item.getPrice();
        }
        return totalPrice / items.size();
    }

    float averageWeight() const {
        if (items.empty()) return 0;
        float totalWeight = 0;
        for (const auto& item : items) {
            totalWeight += item.getWeight();
        }
        return totalWeight / items.size();
    }

    void printShopInfo() const {
        cout << "Shop: " << name << ", Average price: " << averagePrice()
            << ", Average weight: " << averageWeight() << endl;
    }
};

void loadShopsFromFile(const string& filename, vector<Shop>& shops) {
    ifstream file(filename);

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string shopName;
        ss >> shopName;

        if (shopName == "Shop") {
            string shopTitle;
            ss >> shopTitle;
            Shop shop(shopTitle);

            getline(file, line);
            stringstream ssItems(line);
            string itemsLabel;
            int itemCount;
            ssItems >> itemsLabel >> itemCount;

            for (int i = 0; i < itemCount; ++i) {
                string name, category;
                float price, weight;
                string extra;

                getline(file, line);
                stringstream itemStream(line);
                itemStream >> name >> price >> weight >> category;

                if (itemStream >> extra) {
                    category += " " + extra;
                }

                Item item(name, price, weight, category);
                shop.addItem(item);
            }

            shops.push_back(shop);
        }
    }
}

int main() {
    vector<Shop> shops;

    loadShopsFromFile("WhatICanBuy.txt", shops);

    for (const auto& shop : shops) {
        shop.printShopInfo();
    }

    return 0;
}