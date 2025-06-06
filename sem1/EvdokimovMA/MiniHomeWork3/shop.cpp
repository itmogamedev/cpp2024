//
// Created by Maksim Evdokimov on 01.11.2024.
//

#pragma once

#include "string"
#include "item.cpp"
#include <sstream>
#include <fstream>
#include <vector>

class Shop {
    std::string name;
    std::string address;

protected:
    std::vector<Item*> items;

public:
    Shop() {
        name = "Unnamed shop";
        address = "No address";
        items = std::vector<Item*>();
    }
    ~Shop() {
        for (auto item : items) {
            delete item;
        }
    }

    void parseFromStream(std::ifstream& stream) {
        // Parse shop data
        parseShopData(stream);

        // Parse items count
        std::string items_count_str;
        std::getline(stream, items_count_str);
        unsigned int items_count = std::stoi(items_count_str);

        // Parse items
        items.reserve(items_count);
        parseItems(stream, items_count);
    }

    virtual void parseShopData(std::ifstream& stream) {
        std::getline(stream, name);
        std::getline(stream, address);
    }
    virtual void parseItems(std::ifstream& stream, unsigned int items_count) {
        throw std::runtime_error("Not implemented");
    }

    std::string getName() {
        return name;
    }
    std::string getAddress() {
        return address;
    }
    const std::vector<Item*>& getItems() const {
        return items;
    }
};