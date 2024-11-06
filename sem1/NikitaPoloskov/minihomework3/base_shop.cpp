#include "base_shop.h"

#include <iostream>

void befry::BaseShop::NewItem(Item item) { items.push_back(item); }

void befry::BaseShop::AvgCost()
{
    double res = 0;
    for (Item i : items)
        res += i.GetCost();

    std::cout << "In shop \"" << name << "\" average item cost is " << res / items.size() << std::endl;
}

void befry::BaseShop::AvgWeight()
{
    double res = 0;
    for (Item i : items)
        res += i.GetWeight();

    std::cout << "In shop \"" << name << "\" average item weight is " << res / items.size() << std::endl;
}
