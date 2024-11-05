#include <iostream>
#include "src/shops.h"


int main() {
    enum random_stuff{
        CARROT,
        MILK,
        CHOCOLATE,
        APPLES
    };
    basic_shop basicShop("baba");
    shop_with_sales shopWithSales("beba");
    heavy_package_shop heavyPackageShop ("buba");

    basicShop.add_product(product("bip", 1, 4));
    basicShop.add_product(product("bop", 1, 4));
    shopWithSales.add_product(sales_product("bip", 1, 4, 0.8));

    std::cout << basicShop.present_itself();
    std::cout << shopWithSales.present_itself();
    std::cout << heavyPackageShop.present_itself();
    return 0;
}
