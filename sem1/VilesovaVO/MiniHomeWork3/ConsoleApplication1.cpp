#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <exception>


class ItemBase {
public:
    virtual double getPrice() const = 0;
    virtual double getWeight() const = 0;
    virtual ~ItemBase() = default;
};

class GraphicsCard : public ItemBase {
private:
    std::string name;
    double price;
    double weight;
    double fps; 

public:
    GraphicsCard(const std::string& n, double p, double w, double f) : name(n), price(p), weight(w), fps(f) {}
    double getPrice() const override { return price; }
    double getWeight() const override { return weight; }
};

class Fruit : public ItemBase {
private:
    std::string name;
    double price;
    double weight;
    std::string vitamins; 

public:
    Fruit(const std::string& n, double p, double w, const std::string& v) : name(n), price(p), weight(w), vitamins(v) {}
    double getPrice() const override { return price; }
    double getWeight() const override { return weight; }
};

class Shop {
public:
    std::string name;
    std::vector<ItemBase*> items;

    Shop(const std::string& shopName) : name(shopName) {}


    void addItem(ItemBase* item) { items.push_back(item); }

    double getAveragePrice() const {
        if (items.empty()) return 0.0;
        double sum = 0.0;
        for (const auto& item : items) {
            sum += item->getPrice();
        }
        return sum / items.size();
    }

    double getAverageWeight() const {
        if (items.empty()) return 0.0;
        double sum = 0.0;
        for (const auto& item : items) {
            sum += item->getWeight();
        }
        return sum / items.size();
    }

    ~Shop() {
        for (auto item : items) {
            delete item;
        }
    }
};
Shop* parseFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::string line;
    Shop* currentShop = nullptr;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string keyword;
        ss >> keyword;

        if (keyword == "Shop") {
            std::string shopName;
            ss >> shopName;
            currentShop = new Shop(shopName);
        }
        else if (keyword == "Items") {
            int numItems;
            ss >> numItems;
            for (int i = 0; i < numItems; ++i) {
                std::getline(file, line);
                std::stringstream itemSs(line);
                std::string itemName;
                double price, weight, fps; 
                std::string vitamins;

                itemSs >> itemName;
                if (itemName.find("NVIDIA") != std::string::npos) {
                    itemSs >> price >> weight >> fps;
                    currentShop->addItem(new GraphicsCard(itemName, price, weight, fps));
                }
                else {
                    itemSs >> price >> weight;
                    std::string word;
                    while (itemSs >> word) {
                        vitamins += word + " ";
                    }
                    vitamins.pop_back();
                    currentShop->addItem(new Fruit(itemName, price, weight, vitamins));
                }
            }
            std::cout << "Shop: " << currentShop->name << std::endl;
            std::cout << "Average price: " << currentShop->getAveragePrice() << std::endl;
            std::cout << "Average weight: " << currentShop->getAverageWeight() << std::endl;
        }
    }
    file.close();
    return currentShop;
}
int main() {
    try {
        parseFile("shop_data.txt"); 
       
    }
    catch (const std::runtime_error& error) {
        std::cerr << "Error: " << error.what() << std::endl;
    }

    return 0;
}
