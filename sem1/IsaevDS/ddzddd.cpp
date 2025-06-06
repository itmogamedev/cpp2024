#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

class ItemBase {
protected:
    std::string name;
    double price;
    double weight;
public:
    ItemBase(const std::string& name, double price, double weight)
        : name(name), price(price), weight(weight) {}

    virtual ~ItemBase() = default;

    double getPrice() { return price; }
    double getWeight() { return weight; }
};

class MilkItem : public ItemBase {
public:
    MilkItem(const std::string& name, double price, double weight)
        : ItemBase(name, price, weight) {}
};
class GameItem : public ItemBase {
public:
    GameItem(const std::string& name, double price, double weight)
        : ItemBase(name, price, weight) {}
};
class PCItem : public ItemBase {
public:
    PCItem(const std::string& name, double price, double weight)
        : ItemBase(name, price, weight) {}
};
class Shop {
private:
    std::string name;
    std::vector<ItemBase*> items;  // Храним указатели на предметы
public:
    Shop(const std::string& name) : name(name) {}

    ~Shop() {
        
    }

    void addItem(ItemBase* item) {
        items.push_back(item);
    }

    double calculateAveragePrice() const {
        if (items.empty()) return 0.0;
        double totalPrice = 0.0;
        for (const auto& item : items) {
            totalPrice += item->getPrice();
        }
        return totalPrice / items.size();
    }

    double calculateAverageWeight() const {
        if (items.empty()) return 0.0;
        double totalWeight = 0.0;
        for (const auto& item : items) {
            totalWeight += item->getWeight();
        }
        return totalWeight / items.size();
    }

    void printStatistics() const {
        std::cout << "Shop: " << name << '\n';
        std::cout << "Average Price: " << calculateAveragePrice() << '\n';
        std::cout << "Average Weight: " << calculateAverageWeight() << '\n';
    }
};

void parseFile(std::vector<Shop>& shops) {
    std::fstream file("shops.txt");
    if (!file.is_open()) {
        std::cout << "sss" << '\n';
        return;
    }

    std::string line;
    Shop* currentShop = nullptr;
    std::string shopName;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string word;
        
        int itemCount = 0;
        ss >> word;

        if (word == "Shop") {

            ss >> shopName;
            shops.emplace_back(shopName);
            currentShop = &shops.back();
        }
        else if (word == "Items" && currentShop != nullptr) {
            ss >> itemCount;
            for (int i = 0; i < itemCount; i++)
            {
                getline(file, line);
                std::stringstream ss(line);
                ss >> word;
                std::string itemName = word;
                double price, weight;
                ss >> price >> weight;
                if (shopName == "Milkshop")
                {
                    currentShop->addItem(new MilkItem(itemName, price, weight));
                }
                else if (shopName == "Peckarnya")
                {
                    currentShop->addItem(new PCItem(itemName, price, weight));
                }
                else if (shopName == "Gamesi")
                {
                    currentShop->addItem(new GameItem(itemName, price, weight));
                }
            }
        }
    }

    file.close();
}

int main() {
    std::vector<Shop> shops;
    parseFile(shops);

    for (const auto& shop : shops) {
        shop.printStatistics();
        std::cout << std::endl;
    }

    return 0;
}