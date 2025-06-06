//
// Created by Maksim Evdokimov on 01.11.2024.
//

#pragma once

#include "string"
#include "price.cpp"
#include <sstream>
#include <fstream>

class Item {
    std::string name;
    std::string description;
    Price price;
    double mass;

public:
    Item() {
        name = "Unnamed item";
        description = "No description";
        price = Price();
    }

    void parseFromStream(std::ifstream& stream) {
        // Read item data
        parseItemData(stream);

        // Read values
        parseValues(stream);
    }
    void parseItemData(std::ifstream& stream) {
        // Read name
        std::getline(stream, name);

        // Read description
        std::string line;
        std::getline(stream, line);
        description = line;

        // Read price
        std::string price_str;
        std::getline(stream, price_str);
        price = Price::parseFromString(price_str);

        // Read mass
        std::string mass_str;
        std::getline(stream, mass_str);
        mass = std::stod(mass_str);
    }
    virtual void parseValues(std::ifstream& stream) { }

    std::string getName() const {
        return name;
    }
    std::string getDescription() const {
        return description;
    }
    Price getPrice() const {
        return price;
    }
    double getMass() const {
        return mass;
    }

    virtual std::string getDisplayString() const {
        std::ostringstream stream;
        stream << "Name: " << name << std::endl;
        stream << "Description: " << description << std::endl;
        stream << "Price: " << price.rubles << " rubles " << (int)price.kopecks << " kopecks" << std::endl;
        stream << "Mass: " << mass << " kg" << std::endl;
        return stream.str();
    }
};