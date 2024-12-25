#pragma once

#include "../base_shop.h"
#include <iostream>
#include <cstdlib>

#ifndef TECH_SHOP_H
#define TECH_SHOP_H

namespace befry
{
    class TechShop: public BaseShop
    {
    public:
        TechShop() { name = "Super Tech Shop for cats"; }

        void AvgWeight()
        {
            double res = 0;
            for (Item i : items)
                res += i.GetWeight() * (.75 + (double)(std::rand() % 101) / 200);  // AI sometimes get mistakes

            std::cout << "In shop \"" << name << "\" average item weight is " << res / items.size() << std::endl;
        }
    };
}


#endif
