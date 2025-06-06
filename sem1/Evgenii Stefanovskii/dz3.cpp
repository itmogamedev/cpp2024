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

class Food : public ItemBase {
public:
    int calories;
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
        calories = stoi(vars[2]);
        weight = stoi(vars[3]);
    }
};

class Technic : public ItemBase {
public:
    int consumption;
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
        consumption = stoi(vars[2]);
        weight = stoi(vars[3]);
    }
};

class Wires : public ItemBase {
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
    Shop technic, wires, food;
    std::ifstream in;
    in.open("data.txt");
    std::string line;
    for (int i = 0; i < 5; ++i) {
        getline(in, line);
        Technic item;
        item.parse(line);
        technic.items.push_back(item);
    }
    for (int i = 0; i < 5; ++i) {
        getline(in, line);
        Food item;
        item.parse(line);
        food.items.push_back(item);
    }
    for (int i = 0; i < 5; ++i) {
        getline(in, line);
        Wires item;
        item.parse(line);
        wires.items.push_back(item);
    }


    std::cout << "Средняя цена в магазине техники: " << technic.getAveragePrice() << '\n';
    std::cout << "Средний вес в магазине техники: " << technic.getAverageWeight() << '\n';
    std::cout << "Средняя цена в продуктовом магазине: " << food.getAveragePrice() << '\n';
    std::cout << "Средний вес в продуктовом магазине: " << food.getAverageWeight() << '\n';
    std::cout << "Средняя цена в магазине проводов: " << wires.getAveragePrice() << '\n';
    std::cout << "Средний вес в магазине проводов: " << wires.getAverageWeight() << '\n';

}