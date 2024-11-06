#pragma once

#include "../base_shop.h"
#include <iostream>
#include <cstdlib>

#ifndef RANDOM_SHOP_H
#define RANDOM_SHOP_H

namespace befry
{
    class RandomShop: public BaseShop
    {
    public:
        RandomShop() { name = "Very Random Shop"; }

        void AvgCost()
        {
            double res = 0;
            for (Item i : items)
                res += i.GetCost() * (double)(std::rand() % 201) / 100;  // Very random cost

            std::cout << "In shop \"" << name << "\" average item cost is " << res / items.size() << std::endl;
        }

        void AvgWeight()
        {
            double res = 0;
            for (Item i : items)
                res += i.GetWeight() * (double)(std::rand() % 201) / 100;  // Very random weight

            std::cout << "In shop \"" << name << "\" average item weight is " << res / items.size() << std::endl;
        }
    };
}

#endif
