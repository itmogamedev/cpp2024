#pragma once

#include "../base_shop.h"
#include <iostream>

#ifndef GALYA_SHOP_H
#define GALYA_SHOP_H

namespace befry
{
    class GalyaShop: public BaseShop
    {
    public:
        GalyaShop() { name = "Galya's Shop"; }

        void AvgCost()
        {
            double res = 0;
            for (Item i : items)
                res += i.GetCost() * .8;  // Galya always give you discount :)

            std::cout << "In shop \"" << name << "\" average item cost is " << res / items.size() << std::endl;
        }
    };
}

#endif
