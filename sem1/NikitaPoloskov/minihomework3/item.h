#pragma once

#include <string>

#ifndef ITEM_H
#define ITEM_H

namespace befry
{
    class Item
    {
    private:
        std::string name;
        double weight;
        double cost;
    public:
        Item(std::string n, double c, double w);

        std::string GetName();
        double GetWeight();
        double GetCost();
    };
}

#endif //ITEM_H
