#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

class shopBase {
public:
    std::string shopName;
    std::string itemName;
    int price;
    int weight;
    void writeToFile(std::ofstream& file) {
        file << itemName << ' ' << price << ' ' << weight << std::endl;
    }
};

class shop : public shopBase {
public:
    std::vector<std::string> shopR = { "MVideo", "Magnit", "SVEL0", "krasnoe_,beloe" };
    std::vector<int> prices;  
    std::vector<int> weights; 

    shop() {
        std::srand(std::time(0));
        int randomIndex = std::rand() % shopR.size();
        shopName = shopR[randomIndex];
    }
    void calculateAverages(std::ofstream& database) {
        int totalPrice = 0, totalWeight = 0;
        for (size_t i = 0; i < prices.size(); ++i) {
            totalPrice += prices[i];
            totalWeight += weights[i];
        }
        double averagePrice = (prices.size() > 0) ? (double)totalPrice / prices.size() : 0;
        double averageWeight = (weights.size() > 0) ? (double)totalWeight / weights.size() : 0;
        database << "Средняя цена магазина " << shopName << ": " << averagePrice << std::endl;
        database << "Средний вес магазина " << shopName << ": " << averageWeight << std::endl;
    }
};

class goods : public shop {
public:
    std::vector<std::string> mvideoGoods = { "TV", "Laptop", "Phone", "Headphones" };
    std::vector<std::string> magnitGoods = { "Kiwi", "Pineapple", "Chips", "Milk" };
    std::vector<std::string> svel0Goods = { "Washing machine", "Refrigerator", "Microwave", "Vacuum cleaner" };
    std::vector<std::string> krasnoeBeloeGoods = { "Wine", "Vodka", "Whiskey", "Beer" };

    goods(std::ofstream& database) {
        shopBase first;
        std::srand(std::time(0));
        database << "Магазин: " << shopName << std::endl;
        for (int i = 0; i < 5; ++i) { //генерация 5-ти товаров
            if (shopName == "MVideo") {
                itemName = mvideoGoods[std::rand() % mvideoGoods.size()];
            }
            else if (shopName == "Magnit") {
                itemName = magnitGoods[std::rand() % magnitGoods.size()];
            }
            else if (shopName == "SVEL0") {
                itemName = svel0Goods[std::rand() % svel0Goods.size()];
            }
            else if (shopName == "krasnoe_,beloe") {
                itemName = krasnoeBeloeGoods[std::rand() % krasnoeBeloeGoods.size()];
            }
            price = std::rand() % 500 + 1; //цена и вес
            weight = std::rand() % 10 + 1;
            prices.push_back(price);
            weights.push_back(weight);
            writeToFile(database);
        }
        calculateAverages(database);
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    std::ofstream database("Database.txt", std::ofstream::app);
    if (!database) {
        std::cout << "Не удалось открыть файл для записи!" << std::endl;
        return 1;
    }
    goods t(database);
    database.close();
    return 0;
}
