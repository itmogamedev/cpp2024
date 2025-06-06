//
// Created by Maksim Evdokimov on 01.11.2024.
//

#include <fstream>
#include "utils.cpp"

#include "Implementations/ConstructionShop/construction-shop.cpp"
#include "Implementations/ElectronicsShop/electronics-shop.cpp"
#include "Implementations/GroceryShop/grocery-shop.cpp"

std::vector<Shop*> parseShops(std::ifstream& file) {
    unsigned int shops_count;
    file >> shops_count;

    std::vector<Shop*> shops;
    for (unsigned int i = 0; i < shops_count; i++) {
        std::string shop_type;
        while (shop_type.empty()) {
            std::getline(file, shop_type);
        }

        unsigned int shop_type_hash = hash_string(shop_type.c_str(), shop_type.size());

        switch (shop_type_hash) {
            case hash_string("construction", 12): {
                auto shop = new ConstructionShop();
                shop->parseFromStream(file);
                shops.push_back(shop);
                break;
            }
            case hash_string("electronics", 11): {
                auto shop = new ElectronicsShop();
                shop->parseFromStream(file);
                shops.push_back(shop);
                break;
            }
            case hash_string("grocery", 7): {
                auto shop = new GroceryShop();
                shop->parseFromStream(file);
                shops.push_back(shop);
                break;
            }
            default: {
                throw std::runtime_error("Unknown shop type: " + shop_type);
            }
        }
    }

    return shops;
}

void compute_shop_stats(const Shop& shop, double& avg_price, double& avg_mass) {
    unsigned long int items_count = 0;
    avg_price = 0;
    avg_mass = 0;

    for (auto item : shop.getItems()) {
        avg_price += static_cast<double>(item->getPrice());
        avg_mass += item->getMass();
        items_count++;
    }

    avg_price /= items_count;
    avg_mass /= items_count;
}

int main() {
    std::ifstream file("SampleData/combined-data.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        wait_for_enter();
        return 1;
    }

    std::cout << "Parsing shops..." << std::endl;
    auto shops = parseShops(file);
    std::cout << shops.size() << " shops parsed" << std::endl << std::endl;

    while(true) {
        for(unsigned int i = 0; i < shops.size(); i++) {
            std::cout << i + 1 << ". " << shops[i]->getName() << " (" << shops[i]->getAddress() << ")" << std::endl;
        }

        std::cout << "Enter shop name (or 'exit' to exit, 'stats' to show short stats): ";
        std::string shop_name;
        std::cin >> shop_name;
        std::cout << std::endl << std::endl;

        if (shop_name == "exit") {
            break;
        }

        if (shop_name == "stats") {
            unsigned long int items_count = 0;
            double avg_price = 0;
            double avg_mass = 0;

            for (auto shop : shops) {
                double shop_avg_price;
                double shop_avg_mass;
                compute_shop_stats(*shop, shop_avg_price, shop_avg_mass);

                avg_price += shop_avg_price;
                avg_mass += shop_avg_mass;
                items_count += shop->getItems().size();
            }

            avg_price /= shops.size();
            avg_mass /= shops.size();

            std::cout << "Shops count: " << shops.size() << std::endl;
            std::cout << "Items count: " << items_count << std::endl;
            std::cout << "Average price: " << avg_price << " RUB" << std::endl;
            std::cout << "Average mass: " << avg_mass << " kg" << std::endl;

            wait_for_enter();
            clear_screen();
            continue;
        }

        bool found = false;
        for (auto shop : shops) {
            if (shop->getName() == shop_name) {
                found = true;
                std::cout << "Shop: " << shop->getName() << std::endl;
                std::cout << "Address: " << shop->getAddress() << std::endl << std::endl;

                double avg_price;
                double avg_mass;
                compute_shop_stats(*shop, avg_price, avg_mass);

                std::cout << "Shop stats:" << std::endl;
                std::cout << "Items count: " << shop->getItems().size() << std::endl;
                std::cout << "Average price: " << avg_price << " RUB" << std::endl;
                std::cout << "Average mass: " << avg_mass << " kg" << std::endl << std::endl << std::endl;

                std::cout << "Items:" << std::endl;
                for (auto item : shop->getItems()) {
                    std::cout << item->getDisplayString() << std::endl;
                }
                std::cout << std::endl;
                break;
            }
        }

        if (!found) {
            std::cout << "Shop not found" << std::endl;
        }

        wait_for_enter();
        clear_screen();
    }

    return 0;
}