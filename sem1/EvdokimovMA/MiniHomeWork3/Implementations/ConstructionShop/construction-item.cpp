//
// Created by Maksim Evdokimov on 01.11.2024.
//

#include "../../item.cpp"
#include "fstream"

class ConstructionItem : public Item {
    std::string material;
    std::string dimensions;

public:
    void parseValues(std::ifstream& stream) override {
        std::getline(stream, material);
        std::getline(stream, dimensions);
    }

    std::string getDisplayString() const override {
        std::ostringstream stream;
        stream << "Name: " << getName() << std::endl;
        stream << "Description: " << getDescription() << std::endl;
        stream << "Price: " << getPrice().rubles << " rubles " << (int)getPrice().kopecks << " kopecks" << std::endl;
        stream << "Mass: " << getMass() << "kg" << std::endl;
        stream << "Material: " << material << std::endl;
        stream << "Dimensions: " << dimensions << std::endl;
        return stream.str();
    }
};