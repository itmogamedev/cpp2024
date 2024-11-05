#include <iostream>
#include <fstream>
#include "src/shops.h"
static const std::string DEFAUT_DATABASE_PATH = "shop_data.txt";

shop_base<product>* add_data(std::string const &database_path, std::ostream &os, std::istream &is){

    os << "Welcome to shop creator!\n"
          "1. Press 1 to add basic shop\n"
          "2. Press 2 to add shop with sales\n"
          "3. Press 3 to add shop with hard packaging\n"
          "4. Send anything else for exiting this menu\n";
    std::string x, name;
    std::getline(is, x);
    if (x == "1" || x == "2" || x == "3"){
        os << "Give a name to your shop";
        std::getline(is, name);
    } else {
        return nullptr;
    }
    if (x == "1") {
        return new basic_shop(name);
    } else if (x == "2") {
        auto ss =  static_cast<shop_base<sales_product> *>(new shop_with_sales(name));
        ss->add_product(sales_product("bip", 1, 4, 0.8));
        return reinterpret_cast<shop_base<product> *>(ss); /// arrrghhhssfsef
    } else {
        return reinterpret_cast<shop_base<product> *>(new heavy_package_shop(name));
    }

}
void show_data(std::string const &database_path, std::ostream &os){

}

void print_data(std::string const &database_path, shop_base<product>* new_data){
    std::fstream fb;
    fb.open(database_path, std::ios::out | std::ios::app);
    fb << new_data->present_itself();
    fb.close();
}
void menu(std::string const &database_path, std::ostream &os, std::istream &is) {

    while (true) {
        os << "Welcome to the simple database!\n"
              "1. Press 1 to add new shops\n"
              "2. Press 2 to get your current data presented\n";
        std::string x;
        std::getline(is, x);
        if (x == "1") {
            shop_base<product>* new_data = add_data(database_path, os, is);
            if (new_data != nullptr){
                print_data(database_path, new_data);
                delete new_data;
            }

        } else if (x == "2") {
            show_data(database_path, os);
        }
    }
}

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
    menu(DEFAUT_DATABASE_PATH, std::cout, std::cin);
    /*std::cout << basicShop.present_itself();
    std::cout << shopWithSales.present_itself();
    std::cout << heavyPackageShop.present_itself();*/
    return 0;
}
