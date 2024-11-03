#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class Item {
public:
    std::string name;
    float price;
    float weight;

    Item(const std::string& name, float price, float weight)
        : name(name), price(price), weight(weight) {}
};

class ShopBase {
protected:
    std::string name;
    std::vector<Item> items;

public:
    ShopBase(const std::string& name) : name(name) {}
    virtual ~ShopBase() = default;

    void addItem(const Item& item) {
        items.push_back(item);
    }

    virtual float getAveragePrice() const = 0;
    virtual float getAverageWeight() const = 0;

    void displayAverages() const {
        std::cout << "Shop: " << name << std::endl;
        std::cout << "Average Price: " << getAveragePrice() << std::endl;
        std::cout << "Average Weight: " << getAverageWeight() << std::endl;
    }
};

class CustomShop : public ShopBase {
public:
    CustomShop(const std::string& name) : ShopBase(name) {}

    float getAveragePrice() const override {
        float totalPrice = 0;
        for (const auto& item : items) {
            totalPrice += item.price;
        }
        return totalPrice / items.size();
    }

    float getAverageWeight() const override {
        float totalWeight = 0;
        for (const auto& item : items) {
            totalWeight += item.weight;
        }
        return totalWeight / items.size();
    }
};

void ParsedFile(std::vector<ShopBase*>& shops) {
    std::ifstream file("shops.txt");
    std::string line, word;
    CustomShop* currentShop = nullptr;

    while (std::getline(file, line)) {
        std::istringstream load(line);
        load >> word;

        if (word == "Shop") {
            if (currentShop) {
                shops.push_back(currentShop); 
            }

            std::string shopName;
            load >> shopName;
            currentShop = new CustomShop(shopName); 
        }
        else if (word == "Items" && currentShop) {
            int itemCount;
            load >> itemCount;

            for (int i = 0; i < itemCount; ++i) {
                std::getline(file, line);
                std::istringstream itemLoad(line);
                std::string itemName;
                float price, weight;

                itemLoad >> itemName >> price >> weight;
                currentShop->addItem(Item(itemName, price, weight));
            }
        }
    }

    if (currentShop) {
        shops.push_back(currentShop);
    }

    file.close();
}

int main() {
    std::vector<ShopBase*> shops;
    ParsedFile(shops);

    for (const auto& shop : shops) {
        shop->displayAverages();
        std::cout << std::endl;
    }
}
