#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class ItemBase {

public:
    std::string name;
    int price;
    int weight;


    void parse(std::string s) {

    }
};

class Guns : public ItemBase {

public:
    int size;
    void parse(std::string s) {
        std::string tmp = "";
        std::vector<std::string> vars;
        for (auto el : s) {
            if (el == ' ') {
                vars.push_back(tmp);
                tmp = "";
            }
            else
                tmp += el;
        }
        vars.push_back(tmp);
        name = vars[0];
        price = stoi(vars[1]);
        size = stoi(vars[2]);
        weight = stoi(vars[3]);
    }
};

class Bullets : public ItemBase {

public:
    int quantity;
    void parse(std::string s) {
        std::string tmp = "";
        std::vector<std::string> vars;
        for (auto el : s) {
            if (el == ' ') {
                vars.push_back(tmp);
                tmp = "";
            }
            else
                tmp += el;
        }
        vars.push_back(tmp);
        name = vars[0];
        price = stoi(vars[1]);
        quantity = stoi(vars[2]);
        weight = stoi(vars[3]);
    }
};

class  Knifes : public ItemBase {

public:
    int length;
    void parse(std::string s) {
        std::string tmp = "";
        std::vector<std::string> vars;
        for (auto el : s) {
            if (el == ' ') {
                vars.push_back(tmp);
                tmp = "";
            }
            else
                tmp += el;
        }
        vars.push_back(tmp);
        name = vars[0];
        price = stoi(vars[1]);
        length = stoi(vars[2]);
        weight = stoi(vars[3]);
    }
};

class Shop {

public:
    std::vector<ItemBase> items;

    int getAveragePrice() {
        int result = 0;
        if (items.empty())
            return 0;
        for (auto item : items)
            result += item.price;
        return result / items.size();
    }
    int getAverageWeight() {
        int result = 0;
        if (items.empty())
            return 0;
        for (auto item : items)
            result += item.weight;
        return result / items.size();
    }
};
int main() {
    setlocale(LC_ALL, "ru");
    Shop Gunsshop, Knifesshop, Bulletsshop;
    std::ifstream in;
    in.open("shops.txt");
    std::string line;
    for (int i = 0; i < 5; ++i) {
        getline(in, line);
        Guns item;
        item.parse(line);
        Gunsshop.items.push_back(item);
    }
    for (int i = 0; i < 5; ++i) {
        getline(in, line);
        Bullets item;
        item.parse(line);
        Bulletsshop.items.push_back(item);
    }
    for (int i = 0; i < 5; ++i) {
        getline(in, line);
        Knifes item;
        item.parse(line);
        Knifesshop.items.push_back(item);
    }

    std::cout << "Shop: Guns";
    std::cout << "Average price: " << Gunsshop.getAveragePrice() << '\n';
    std::cout << "Average weight: " << Gunsshop.getAverageWeight() << '\n';
    std::cout << "Shop: Bullets";
    std::cout << "Average price: " << Bulletsshop.getAveragePrice() << '\n';
    std::cout << "Average weight: " << Bulletsshop.getAverageWeight() << '\n';
    std::cout << "Shop: Knifes ";
    std::cout << "Average price: " << Knifesshop.getAveragePrice() << '\n';
    std::cout << "Average weight: " << Knifesshop.getAverageWeight() << '\n';
}