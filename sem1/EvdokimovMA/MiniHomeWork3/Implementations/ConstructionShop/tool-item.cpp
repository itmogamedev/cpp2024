//
// Created by Maksim Evdokimov on 01.11.2024.
//

#include "../../item.cpp"

class ToolItem : public Item {
    std::string type;
    std::string power;
    std::string brand;

public:
    void parseValues(std::ifstream& stream) override {
        std::getline(stream, type);
        std::getline(stream, power);
        std::getline(stream, brand);
    }

    std::string getDisplayString() const override {
        std::ostringstream stream;
        stream << "Name: " << getName() << std::endl;
        stream << "Description: " << getDescription() << std::endl;
        stream << "Price: " << getPrice().rubles << " rubles " << (int)getPrice().kopecks << " kopecks" << std::endl;
        stream << "Mass: " << getMass() << "kg" << std::endl;
        stream << "Type: " << type << std::endl;
        stream << "Power: " << power << std::endl;
        stream << "Brand: " << brand << std::endl;
        return stream.str();
    }
};