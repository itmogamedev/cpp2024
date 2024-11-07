#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

class ItemBase {
public:
    virtual ~ItemBase() = default;
    virtual double getPrice() const = 0;
    virtual double getWeight() const = 0;
};

class Item : public ItemBase {
private:
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
private:
    std::string name;
    std::vector<std::unique_ptr<ItemBase>> items;

public:
    Shop(const std::string& name) : name(name) {}

    void addItem(std::unique_ptr<ItemBase> item) {
        items.push_back(std::move(item));
    }

    double averagePrice() const {
        if (items.empty()) return 0.0;

        double totalPrice = 0.0;
        for (const auto& item : items) {
            totalPrice += item->getPrice();
        }
        return totalPrice / items.size();
    }

    double averageWeight() const {
        if (items.empty()) return 0.0;

        double totalWeight = 0.0;
        for (const auto& item : items) {
            totalWeight += item->getWeight();
        }
        return totalWeight / items.size();
    }

    const std::string& getName() const {
        return name;
    }
};

void processShopData(const std::string& data, std::vector<Shop>& shops) {
    std::istringstream stream(data);
    std::string line;

    while (std::getline(stream, line)) {
        if (line.find("Shop") != std::string::npos) {
            std::string shopName = line.substr(5);
            Shop shop(shopName);

            std::getline(stream, line); // Read "Items X"
            int numItems = std::stoi(line.substr(6));

            for (int i = 0; i < numItems; ++i) {
                std::getline(stream, line);
                std::istringstream itemStream(line);
                std::string itemName;
                double price, weight;
                itemStream >> itemName >> price >> weight;

                // Добавляем предмет в магазин
                shop.addItem(std::make_unique<Item>(itemName, price, weight));
            }

            shops.push_back(std::move(shop));
        }
    }
}

int main() {
    std::string data = R"(
Shop PCBrutal
Items 5
KCAS600W 10 6
RYZEN7 15 1
ASEROCK-A320 13 5
RTX4060 40 7
DDR5-6000 18 2
Shop BestTables
Items 6
Oak-desk 52 187
Birch-bench 46 190
Glass-table 43 78
Green-chair 29 55
Dark-closet 64 199
Double-bed 58 165
Shop Underwater-water
Items 5
Salt-water 2 5
Rose-flavored-water 4 5
Fish-water 3 5
Iron-water 7 5
BIG-water 100 250
)";

    std::vector<Shop> shops;
    processShopData(data, shops);

    for (const auto& shop : shops) {
        std::cout << "Shop: " << shop.getName() << "\n";
        std::cout << "Average Price: " << shop.averagePrice() << "\n";
        std::cout << "Average Weight: " << shop.averageWeight() << "\n";
    }

    return 0;
}
