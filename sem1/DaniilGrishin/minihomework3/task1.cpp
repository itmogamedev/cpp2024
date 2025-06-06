#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>


class ItemBase {
public:
    std::string name;   
    double price;       
    double weight;      

    ItemBase(std::string n, double p, double w) : name(n), price(p), weight(w) {}
};


class GPUItem : public ItemBase {
public:
    int fps; 

    GPUItem(std::string n, double p, double w, int f) : ItemBase(n, p, w), fps(f) {}
};

class FruitItem : public ItemBase {
public:
    std::string vitamins;

    FruitItem(std::string n, double p, double w, std::string v) : ItemBase(n, p, w), vitamins(v) {}
};

class BookItem : public ItemBase {
public:
    int pages;

    BookItem(std::string n, double p, double w, int pg) : ItemBase(n, p, w), pages(pg) {}
};

class Shop {
public:
    std::string name;                
    std::vector<ItemBase*> items;       

    Shop(std::string n) : name(n) {}

    // Метод для добавления товара в магазин
    void addItem(ItemBase* item) {
        items.push_back(item);
    }

    // Метод для вычисления средней цены товаров в магазине
    double averagePrice() {
        double total = 0;
        for (auto& item : items) {
            total += item->price;
        }
        return items.empty() ? 0 : total / items.size();
    }

    // Метод для вычисления среднего веса товаров в магазине
    double averageWeight() {
        double total = 0;
        for (auto& item : items) {
            total += item->weight;
        }
        return items.empty() ? 0 : total / items.size();
    }
};

int main() {
    std::ifstream file("shops.txt"); 
    std::string line;               
    std::vector<Shop> shops;        

    while (std::getline(file, line)) {
        if (line.find("Shop") != std::string::npos) {
            std::string shopName = line.substr(5); 
            shops.emplace_back(shopName);           
        }

        // Чтение количества предметов
        else if (line.find("Items") != std::string::npos) {
            int itemCount;
            std::istringstream(line.substr(6)) >> itemCount; // Получаем количество предметов

            for (int i = 0; i < itemCount; ++i) {
                std::getline(file, line); // Читаем строку с предметом

                std::istringstream iss(line);
                std::string itemName;
                double price, weight;

                
                iss >> itemName >> price >> weight;

                // Проверяем тип предмета по имени магазина
                if (shops.back().name == "ForPCs") {
                    int fps;
                    iss >> fps;
                    GPUItem* gpuItem = new GPUItem(itemName, price, weight, fps);
                    shops.back().addItem(gpuItem);
                }
                else if (shops.back().name == "Fruits") {
                    std::string vitamins;
                    iss >> vitamins;
                    FruitItem* fruitItem = new FruitItem(itemName, price, weight, vitamins);
                    shops.back().addItem(fruitItem);
                }
                else if (shops.back().name == "Books") {
                    int pages;
                    iss >> pages;
                    BookItem* bookItem = new BookItem(itemName, price, weight, pages);
                    shops.back().addItem(bookItem);
                }
            }
        }
    }

    for (auto& shop : shops) {
        std::cout << "Shop: " << shop.name << std::endl;
        std::cout << "Average Price: " << shop.averagePrice() << std::endl;
        std::cout << "Average Weight: " << shop.averageWeight() << std::endl;
        std::cout << std::endl;
    }

    file.close();
    return 0;
}
