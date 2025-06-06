#include <iostream>
#include <fstream>
#include <string>
#include <vector>


class ItemBase {
public:
    std::string name;
    int price;
    int weight;

    virtual void parse(std::string s) {

    }
};

class Food : public ItemBase {
public:
    int calories;
    void parse(std::string s) {
        std::string tmp = "";
        std::vector<std::string> tokens; 
        for (auto el : s) {
            if (el == ' ') {
                tokens.push_back(tmp);
                tmp = "";
            }
            else
                tmp += el;
        }
        tokens.push_back(tmp);
        name = tokens[0];
        price = stoi(tokens[1]);
        calories = stoi(tokens[2]);
        weight = stoi(tokens[3]);
    }
};

class Tech : public ItemBase {
public:
    int consumption;
    void parse(std::string s) {
        std::string tmp = "";
        std::vector<std::string> tokens;
        for (auto el : s) {
            if (el == ' ') {
                tokens.push_back(tmp);
                tmp = "";
            }
            else
                tmp += el;
        }
        tokens.push_back(tmp);
        name = tokens[0];
        price = stoi(tokens[1]);
        consumption = stoi(tokens[2]);
        weight = stoi(tokens[3]);
    }
};

class Wires : public ItemBase {
public:
    int length;
    void parse(std::string s) {
        std::string tmp = "";
        std::vector<std::string> tokens;
        for (auto el : s) {
            if (el == ' ') {
                tokens.push_back(tmp);
                tmp = "";
            }
            else
                tmp += el;
        }
        tokens.push_back(tmp);
        name = tokens[0];
        price = stoi(tokens[1]);
        length = stoi(tokens[2]);
        weight = stoi(tokens[3]);
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
    Shop tech, wires, food;
    std::ifstream in;
    in.open("info.txt");
    std::string line;
    for (int i = 0; i < 5; ++i) {
        getline(in, line);
        Tech item;
        item.parse(line);
        tech.items.push_back(item);
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

    while (true) {
        int com;
        std::cout << "Which store you want to get information about?\n";   
        std::cout << "1) tech store \n";
        std::cout << "2) convenience store \n";
        std::cout << "3) wire store \n";
        std::cin >> com;
        switch (com) {
        case 1:        
            std::cout << "Average price in the store: " << tech.getAveragePrice() << '\n';
            std::cout << "Average weight in the store " << tech.getAverageWeight() << '\n';        
            break;
        case 2:        
            std::cout << "Average price in the convenience store: " << food.getAveragePrice() << '\n';
            std::cout << "Average weight in the convenience store: " << food.getAverageWeight() << '\n';        
            break;
        case 3:        
            std::cout << "Average price in the wire store: " << wires.getAveragePrice() << '\n';
            std::cout << "Average weight in the wire store: " << wires.getAverageWeight() << '\n';        
            break;
        }   
        std::cout << "\n\n";
    }
}