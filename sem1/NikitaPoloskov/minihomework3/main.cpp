#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <map>

#include "item.h"
#include "base_shop.h"
#include "custom_shops/galya_shop.h"
#include "custom_shops/tech_shop.h"
#include "custom_shops/random_shop.h"

std::vector<befry::BaseShop> shops;

enum SHOP_NAME {Galya, Tech, Random};
std::map<std::string, int> shop_names = {{"Galya", Galya}, {"Tech", Tech}, {"Random", Random}};

void create_shop(std::string name)
{
    switch (shop_names[name])
    {
        case Galya: shops.push_back(befry::GalyaShop()); break;
        case Tech: shops.push_back(befry::TechShop()); break;
        case Random: shops.push_back(befry::RandomShop()); break;
        default: shops.push_back(befry::BaseShop()); break;
    }
}

void read_items(std::ifstream& ins, int count)
{
    std::string tmp;
    std::string name;
    double cost, weight;
    for (int i = 0; i < count; i++)
    {
        std::getline(ins, tmp);
        name = strtok(tmp.data(), " ");
        cost = std::atof(strtok(nullptr, " "));
        weight = std::atof(strtok(nullptr, " "));
        shops.back().NewItem(befry::Item(name, cost, weight));
    }
}

int main() {
    std::srand(std::time(0));

    std::cout << "Welcome to shopping center! Now, we analyze shops." << std::endl;

    std::ifstream fin("shops");
    std::string tmp;
    std::string cmd, name;

    while (fin)
    {
        if (fin.eof()) break;
        std::getline(fin, tmp);
        cmd = strtok(tmp.data(), " ");
        name = strtok(nullptr, " ");

        if (cmd == "Shop") create_shop(name);
        if (cmd == "Items") read_items(fin, std::atoi(name.c_str()));
    }
    fin.close();

    for (befry::BaseShop shop : shops)
    {
        shop.AvgCost();
        shop.AvgWeight();
    }
}
