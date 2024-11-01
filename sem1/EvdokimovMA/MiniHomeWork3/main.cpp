//
// Created by Maksim Evdokimov on 01.11.2024.
//

#include <fstream>
#include "utils.cpp"

#include "Implementations/ConstructionShop/construction-shop.cpp"
#include "Implementations/ElectronicsShop/electronics-shop.cpp"
#include "Implementations/GroceryShop/grocery-shop.cpp"

std::vector<Shop*> parseShops(std::ifstream& file) {
    std::string line;

    std::getline(file, line);
    unsigned int shops_count = std::stoi(line);

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

int main() {
    std::ifstream file("SampleData/combined-data.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
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

            Price max_price;
            double max_mass = 0;

            for (auto shop : shops) {
                items_count += shop->getItems().size();
                for (auto item : shop->getItems()) {
                    avg_price += static_cast<double>(item->getPrice());
                    avg_mass += item->getMass();

                    if (item->getPrice() > max_price) {
                        max_price = item->getPrice();
                    }
                    if (item->getMass() > max_mass) {
                        max_mass = item->getMass();
                    }
                }
            }

            avg_price /= items_count;
            avg_mass /= items_count;

            std::cout << "Shops count: " << shops.size() << std::endl;
            std::cout << "Items count: " << items_count << std::endl;
            std::cout << "Average price: " << avg_price << " RUB" << std::endl;
            std::cout << "Average mass: " << avg_mass << " kg" << std::endl;
            std::cout << "Max price: " << max_price.toString() << " RUB" << std::endl;
            std::cout << "Max mass: " << max_mass << " kg" << std::endl << std::endl;

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