#pragma once

#include <vector>

#include "item.h"

#ifndef BASE_SHOP_H
#define BASE_SHOP_H

namespace befry
{
    class BaseShop
    {
    protected:
        std::string name = "Unknown Shop";
        std::vector<Item> items;
    public:
        void NewItem(Item item);
        void AvgCost();
        void AvgWeight();
    };
}

#endif