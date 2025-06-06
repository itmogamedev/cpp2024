#include <iostream>
#include <fstream>
#include "src/shops.h"
#include "src/StringUtils.h"

void get_middle(std::string file_name, std::ostream &ostream, std::istream &istream,
                std::vector<shop_base<product> *> cache);

void add_product(std::string file_name, std::ostream &ostream, std::istream &istream,
                 std::vector<shop_base<product> *> cache);

void add_shop(std::string &database_path, std::ostream &os, std::istream &is) {
    os << "Welcome to shop creator!\n"
          "1. Press 1 to create basic shop\n"
          "2. Press 2 to create shop with sales\n"
          "3. Press 3 to create shop with heavy packaging\n"
          "4. Send anything else to exit\n";
    std::string x, name;
    std::getline(is, x);
    if (x != "1" && x != "2" && x != "3") {
        return;
    }
    os << "Enter a name for your new shop\n";
    std::getline(is, name);
    std::fstream fb;
    fb.open(database_path, std::ios::out | std::ios::app);

    if (x == "1") {
        auto shop = basic_shop(name);
        fb << shop.present_itself();
    }
    if (x == "2") {
        auto shop = shop_with_sales(name);
        fb << shop.present_itself();
    }
    if (x == "3") {
        fb << heavy_package_shop(name).present_itself();
    }
    fb.close();
}


void cache_data(std::string &database_path, std::vector<shop_base<product> *> &data) {
    std::vector<std::string> shop_data;
    std::string line;
    std::ifstream is(database_path);
    while (std::getline(is, line)) {
        trim(line);
        if (!line.empty()) {
            split_line(line, ' ', shop_data);
            std::string class_name, name;
            class_name = shop_data[0];
            name = shop_data[1];
            if (class_name == basic_shop::class_name()) {
                auto *shop = new basic_shop(name);
                data.push_back(shop);
            } else if (class_name == shop_with_sales::class_name()) {
                data.push_back(reinterpret_cast<shop_base<product> *>(new shop_with_sales(name)));
            } else if (class_name == heavy_package_shop::class_name()) {
                data.push_back(reinterpret_cast<shop_base<product> *>(new heavy_package_shop(name)));
            }
            //data.push_back();
        }
        std::getline(is, line);
        trim(line);
        split_line(line, ' ', shop_data);
        int how_much = std::stoi(shop_data[1]);
        for (int i = 0; i < how_much; ++i) {
            std::getline(is, line);
            trim(line);
            data.back()->parse_new_product(line);
        }
    }
    is.close();
}

void show_data(std::string &database_path,
               std::ostream &os, std::istream &is, std::vector<shop_base<product> *> &data) {
    data.clear();
    cache_data(database_path, data);
    for (auto &i: data) {
        os << i->present_itself() << '\n';
    }
}

void menu(std::string database_path, std::ostream &os, std::istream &is) {
    std::vector<shop_base<product> *> cache;
    //cache_data(database_path, cache);
    while (true) {
        std::cout << "Welcome to the simple shop database!\n"
                     "1. Press 1 to add new shops\n"
                     "2. Press 2 to get your current data presented\n"
                     "3. Press 3 to get middle cost/weight in shop\n"
                     "4. Press 4 to add new products\n";
        std::string x;
        //is >> x;
        std::getline(is, x);
        trim(x);
        if (x == "1") {
            add_shop(database_path, os, is);
        } else if (x == "2") {
            show_data(database_path, os, is, cache);
        } else if (x == "3") {
            get_middle(database_path, os, is, cache);
        } else if (x == "4") {
            add_product(database_path, os, is, cache);
        } else if (x.empty()) {
            break;
        }
    }
}

void add_product(std::string file_name, std::ostream &ostream, std::istream &istream,
                 std::vector<shop_base<product> *> cache) {
    cache_data(file_name, cache);
    int i = -2;
    while (true) {
        ostream << "Enter number of your shop of interest, or 0 to exit this menu \n";
        std::string output;
        std::getline(istream, output);
        trim(output);
        if (!output.empty()) {
            i = std::stoi(output);
            i--;
            if (i == -1) {
                break;
            }
            shop_base<product> *shop = cache[i];
            ostream << "Enter your product in format of: " + shop->ask_for_product() + '\n';
            std::string product;
            std::getline(istream, product);
            shop->parse_new_product(product);
        }
    }
    std::ofstream out;          // поток для записи
    out.open(file_name);
    for (auto k: cache) {
        out << k->present_itself();
    }
    out.close();

}

void get_middle(std::string file_name, std::ostream &ostream, std::istream &istream,
                std::vector<shop_base<product> *> cache) {
    cache_data(file_name, cache);
    ostream << "Enter number of your shop of interest\n";
    int i;
    std::string input;
    std::getline(istream, input);
    i = std::stoi(input);
    i--;
    auto shop = cache[i];
    ostream << shop->present_itself();
    ostream << "middle cost " << shop->middle_cost() << '\n';
    ostream << "middle weight " << shop->middle_weight() << '\n';
}

int main() {
    enum random_stuff {
        CARROT,
        MILK,
        CHOCOLATE,
        APPLES
    };
    basic_shop basicShop("baba");
    shop_with_sales shopWithSales("beba");
    heavy_package_shop heavyPackageShop("buba");

    basicShop.add_product(product("bip", 1, 4));
    basicShop.add_product(product("bop", 1, 4));
    shopWithSales.add_product(sales_product("bip", 1, 4, 0.8));


    //std::cout << basicShop.present_itself();
//    std::cout << shopWithSales.present_itself();
//    std::cout << heavyPackageShop.present_itself();
    menu("shops.txt", std::cout, std::cin);
    return 0;
}
