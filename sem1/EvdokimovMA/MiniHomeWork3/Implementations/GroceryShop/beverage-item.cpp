//
// Created by Maksim Evdokimov on 01.11.2024.
//

#include "../../item.cpp"

class BeverageItem : public Item {
    double volume;
    std::string brand;

public:
    void parseValues(std::ifstream& stream) override {
        std::string line;
        std::getline(stream, line);
        volume = std::stod(line);

        std::getline(stream, brand);
    }

    std::string getDisplayString() const override {
        std::ostringstream stream;
        stream << "Name: " << getName() << std::endl;
        stream << "Description: " << getDescription() << std::endl;
        stream << "Price: " << getPrice().rubles << " rubles " << (int)getPrice().kopecks << " kopecks" << std::endl;
        stream << "Volume: " << volume << std::endl;
        stream << "Brand: " << brand << std::endl;
        return stream.str();
    }
};