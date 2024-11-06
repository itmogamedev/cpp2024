#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

//Базовый класс для предметов
class ItemBase {
public:
    virtual ~ItemBase() = default;
    virtual double getPrice() const = 0;
    virtual double getWeight() const = 0;
};

//Общий класс Item
class Item : public ItemBase {
protected:
    std::string name;
    double price;
    double weight;

public:
    Item(const std::string& name, double price, double weight)
        : name(name), price(price), weight(weight) {}

    double getPrice() const override { return price; }
    double getWeight() const override { return weight; }

    std::string getName() const { return name; }
};

//Класс для "ForPCs"
class ForPCsItem : public Item {
    std::string spec;
    int performance;

public:
    ForPCsItem(const std::string& name, double price, double weight, const std::string& spec, int performance)
        : Item(name, price, weight), spec(spec), performance(performance) {}
};

//Класс для Fruits"
class FruitItem : public Item {
    std::vector<std::string> vitamins;

public:
    FruitItem(const std::string& name, double price, double weight, const std::vector<std::string>& vitamins)
        : Item(name, price, weight), vitamins(vitamins) {}
};

//Класс для "Books"
class BookItem : public Item {
    std::string genre;
    std::string category;

public:
    BookItem(const std::string& name, double price, double weight, const std::string& genre, const std::string& category)
        : Item(name, price, weight), genre(genre), category(category) {}
};

//Класс для магазина, который содержит предметы
class Shop {
    std::string name;
    std::vector<std::shared_ptr<ItemBase>> items;

public:
    Shop(const std::string& name) : name(name) {}

    void addItem(const std::shared_ptr<ItemBase>& item) {
        items.push_back(item);
    }

    double averagePrice() const {
        double total = 0;
        for (const auto& item : items) {
            total += item->getPrice();
        }
        return items.empty() ? 0 : total / items.size();
    }

    double averageWeight() const {
        double total = 0;
        for (const auto& item : items) {
            total += item->getWeight();
        }
        return items.empty() ? 0 : total / items.size();
    }

    void printShopInfo() const {
        std::cout << "Shop: " << name << "\n"
                  << "Average Price: " << averagePrice() << "\n"
                  << "Average Weight: " << averageWeight() << "\n\n";
    }
};

//Функция для парсинга данных из файла
std::vector<Shop> parseFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<Shop> shops;
    std::string line;

    while (std::getline(file, line)) {
        if (line.rfind("Shop", 0) == 0) {
            std::string shopName = line.substr(5);
            Shop shop(shopName);

            std::getline(file, line);
            int itemCount = std::stoi(line.substr(6));

            for (int i = 0; i < itemCount; ++i) {
                std::getline(file, line);
                std::istringstream itemStream(line);
                std::string name;
                double price, weight;
                std::string attribute1, attribute2;

                itemStream >> name >> price >> weight >> attribute1 >> attribute2;

                if (shopName == "ForPCs") {
                    int performance = std::stoi(attribute2);
                    shop.addItem(std::make_shared<ForPCsItem>(name, price, weight, attribute1, performance));
                } else if (shopName == "Fruits") {
                    std::vector<std::string> vitamins;
                    vitamins.push_back(attribute1);
                    while (itemStream >> attribute2) {
                        vitamins.push_back(attribute2);
                    }
                    shop.addItem(std::make_shared<FruitItem>(name, price, weight, vitamins));
                } else if (shopName == "Books") {
                    shop.addItem(std::make_shared<BookItem>(name, price, weight, attribute1, attribute2));
                }
            }

            shops.push_back(shop);
        }
    }
    return shops;
}

int main() {
    std::vector<Shop> shops = parseFile("shops.txt");

    for (const auto& shop : shops) {
        shop.printShopInfo();
    }

    return 0;
}