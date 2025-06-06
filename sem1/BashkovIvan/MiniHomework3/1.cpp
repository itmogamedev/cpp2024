#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class ItemBase {
public:
    std::string name;
    unsigned int price;
    unsigned int mass;

    ItemBase(std::string name1, unsigned int price1, unsigned int mass1) {
        name = name1;
        price = price1;
        mass = mass1;
    }
};

class Electronics : public ItemBase {
public:
    unsigned int fps;

    Electronics(std::string name, unsigned int price, unsigned int mass, unsigned int fps1) : ItemBase(name, price, mass) {
        fps = fps1;
    }
};

class Book : public ItemBase {
public:
    unsigned int pageCount;

    Book(std::string name, unsigned int price, unsigned int mass, unsigned int pageCount1) : ItemBase(name, price, mass) {
        pageCount = pageCount1;
    }
};

class VinylRecord : public ItemBase {
public:
    unsigned int duration;

    VinylRecord(std::string name, unsigned int price, unsigned int mass, unsigned int duration1) : ItemBase(name, price, mass) {
        duration = duration1;
    }
};

class Shop {
public:
    std::string name;
    std::vector<ItemBase*> items;

    Shop(std::string name1) {
        name = name1;
    }

    void addItem(ItemBase* item) {
        items.push_back(item);
    }

    int averagePrice() {
        int sum = 0;
        for (auto item : items) {
            sum += item->price;
        }
        return sum / items.size();
    }

    int averageMass() {
        int sum = 0;
        for (auto item : items) {
            sum += item->mass;
        }
        return sum / items.size();
    }

};

std::vector<Shop> parseFile(std::string filename) {
    std::vector<Shop> shops;
    std::ifstream file(filename);
    std::string line;
    Shop* currentShop = nullptr;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string word;
        ss >> word;
        if (word == "Shop") {
            std::string shopName;
            ss >> shopName;
            shops.emplace_back(shopName);
            currentShop = &shops.back();
        }
        else if (word == "Items" && currentShop) {
            int itemCount;
            ss >> itemCount;
            for (int i = 0; i < itemCount; ++i) {
                std::getline(file, line);
                std::istringstream itemStream(line);
                std::string itemName;
                unsigned int price, mass, additional;
                itemStream >> itemName >> price >> mass >> additional;

                if (currentShop->name == "TechStore") {
                    currentShop->addItem(new Electronics(itemName, price, mass, additional));
                }
                else if (currentShop->name == "BookStore") {
                    currentShop->addItem(new Book(itemName, price, mass, additional));
                }
                else {
                    currentShop->addItem(new VinylRecord(itemName, price, mass, additional));
                }
            }
        }
    }

    file.close();
    return shops;
}

int main() {
    std::vector<Shop> shops = parseFile("data.txt");

    for (Shop shop : shops) {
        std::cout << "Shop: " << shop.name << "\n";
        std::cout << "Average Price: " << shop.averagePrice() << "\n";
        std::cout << "Average Mass: " << shop.averageMass() << "\n\n";
    }
}