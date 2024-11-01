//
// Created by Maksim Evdokimov on 01.11.2024.
//

#include "../../item.cpp"
#include "fstream"

class GroceryItem : public Item {
    std::string expirationDate;
    std::string ingredients;
    std::string brand;

public:
    void parseValues(std::ifstream& stream) override {
        std::getline(stream, expirationDate);
        std::getline(stream, ingredients);
        std::getline(stream, brand);
    }

    std::string getDisplayString() const override {
        std::ostringstream stream;
        stream << "Name: " << getName() << std::endl;
        stream << "Description: " << getDescription() << std::endl;
        stream << "Price: " << getPrice().rubles << " rubles " << (int)getPrice().kopecks << " kopecks" << std::endl;
        stream << "Mass: " << getMass() << "kg" << std::endl;
        stream << "Expiration date: " << expirationDate << std::endl;
        stream << "Ingredients: " << ingredients << std::endl;
        stream << "Brand: " << brand << std::endl;
        return stream.str();
    }
};