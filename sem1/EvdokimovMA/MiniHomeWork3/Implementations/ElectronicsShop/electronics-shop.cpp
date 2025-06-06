//
// Created by Maksim Evdokimov on 01.11.2024.
//

#include <fstream>
#include <iostream>

#include "../../shop.cpp"
#include "../../utils.cpp"

#include "phone-item.cpp"
#include "computer-item.cpp"

class ElectronicsShop : public Shop {
public:
    void parseItems(std::ifstream &stream, unsigned int items_count) override {
        for (unsigned int i = 0; i < items_count; i++) {
            std::string type;
            while (type.empty()) {
                std::getline(stream, type);
            }

            unsigned int type_hash = hash_string(type.c_str(), type.size());

            switch (type_hash) {
                case hash_string("phone", 5): {
                    auto item = new PhoneItem();
                    item->parseFromStream(stream);
                    items.push_back(item);
                    break;
                }
                case hash_string("computer", 8): {
                    auto item = new ComputerItem();
                    item->parseFromStream(stream);
                    items.push_back(item);
                    break;
                }
                default: {
                    throw std::runtime_error("Unknown item type");
                }
            }
        }
    }
};