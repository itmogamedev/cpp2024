//
// Created by Maksim Evdokimov on 01.11.2024.
//

#include "../../item.cpp"
#include "fstream"

class ComputerItem : public Item {
    std::string cpu;
    std::string gpu;
    std::string ram;
    std::string storage;
    std::string os;

public:
    void parseValues(std::ifstream& stream) override {
        std::getline(stream, cpu);
        std::getline(stream, gpu);
        std::getline(stream, ram);
        std::getline(stream, storage);
        std::getline(stream, os);
    }

    std::string getDisplayString() const override {
        std::ostringstream stream;
        stream << "Name: " << getName() << std::endl;
        stream << "Description: " << getDescription() << std::endl;
        stream << "Price: " << getPrice().rubles << " rubles " << (int)getPrice().kopecks << " kopecks" << std::endl;
        stream << "Mass: " << getMass() << "kg" << std::endl;
        stream << "CPU: " << cpu << std::endl;
        stream << "GPU: " << gpu << std::endl;
        stream << "RAM: " << ram << std::endl;
        stream << "Storage: " << storage << std::endl;
        stream << "OS: " << os << std::endl;
        return stream.str();
    }
};