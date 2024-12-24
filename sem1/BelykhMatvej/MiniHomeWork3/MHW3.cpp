#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <map>
#include <Windows.h>

class Color {
public:
    explicit Color(int colorCode) : colorCode(colorCode) {}

    friend std::ostream& operator<<(std::ostream& os, const Color& color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color.colorCode);
        return os;
    }

private:
    int colorCode;
};

class Item {
public:
    std::string name;
    float price;
    float weight;

    Item(const std::string& name, float price, float weight)
        : name(name), price(price), weight(weight) {}
};

class ShopBase {
public:
    virtual float AvePrice() const = 0;
    virtual float AveWeight() const = 0;
};

class CustomShop : public ShopBase {
protected:
    std::vector<Item> items;

public:
    void addItem(const Item& item) {
        items.push_back(item);
    }

    float AvePrice() const override {
        float total = 0;
        for (size_t i = 0; i < items.size(); ++i) {
            total += items[i].price;
        }
        return total / items.size();
    }

    float AveWeight() const override {
        float total = 0;
        for (size_t i = 0; i < items.size(); ++i) {
            total += items[i].weight;
        }
        return total / items.size();
    }
};

class ITMOMerch : public CustomShop {
public:
    std::string shopType = "Merchandise";
};

class ITMOTableGames : public CustomShop {
public:
    std::string gameCategory = "Board Games";
};

class GraphicsCards : public CustomShop {
public:
    std::string graphicsType = "Graphics Processing Units";
};

std::map<std::string, std::unique_ptr<CustomShop>> Parser() {
    std::ifstream file("shops.txt");
    std::string line;
    std::map<std::string, std::unique_ptr<CustomShop>> shops;

    std::unique_ptr<CustomShop> currentShop = nullptr;
    std::string shopName;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        iss >> word;

        if (word == "Shop") {
            if (currentShop != nullptr) {
                shops[shopName] = std::move(currentShop);
            }
            iss >> shopName;

            if (shopName == "ITMOMerch") {
                currentShop = std::make_unique<ITMOMerch>();
            }
            else if (shopName == "ITMOTableGames") {
                currentShop = std::make_unique<ITMOTableGames>();
            }
            else if (shopName == "GraphicsCards") {
                currentShop = std::make_unique<GraphicsCards>();
            }
        }
        else if (word == "Items") {
            continue;
        }
        else if (currentShop != nullptr) {
            std::string name = word;
            float price, weight;
            iss >> price >> weight;
            std::string additionalInfo;
            std::getline(iss, additionalInfo);
            currentShop->addItem(Item(name, price, weight));
        }
    }

    if (currentShop != nullptr) {
        shops[shopName] = std::move(currentShop);
    }

    return shops;
}

int main() {
    std::map<std::string, std::unique_ptr<CustomShop>> shops = Parser();

    for (std::map<std::string, std::unique_ptr<CustomShop>>::iterator i = shops.begin(); i != shops.end(); ++i) {
        std::cout << Color(2) << "Shop: " << i->first << std::endl;
        std::cout << Color(7) << "Average Price: " << i->second->AvePrice() << std::endl;
        std::cout << "Average Weight: " << i->second->AveWeight() << std::endl;
    }

    return 0;
}
