#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class ItemBase {
protected:
    std::string Name;
    int price, weight;
public:
    void set_data(std::string Name1, int price1, int weight1) {
        Name = Name1;
        price = price1;
        weight = weight1;
    }
    std::string getName() {
        return Name;
    }
    int getPrice() {
        return price;
    }
    int getWeight() {
        return weight;
    }
};

class VideoCard: public ItemBase{
protected:
    std::string Memory, Energy;
public:
    void set_data(std::string Name1, int price1, int weight1, std::string Memory1, std::string Energy1) {
        Name = Name1;
        price = price1;
        weight = weight1;
        Memory = Memory1;
        Energy = Energy1;
    }
    std::string getMemory() {
        return Memory;
    }
    std::string getEnergy() {
        return Energy;
    }
};

class CPU : public ItemBase {
protected:
    std::string Energy;
    int core;
public:
    void set_data(std::string Name1, int price1, int weight1, std::string Energy1, int core1) {
        Name = Name1;
        price = price1;
        weight = weight1;
        Energy = Energy1;
        core = core1;
    }
    std::string getEnergy() {
        return Energy;
    }
    int getCore() {
        return core;
    }
};

class HardDrive : public ItemBase {
protected:
    std::string Connection, Volume;
public:
    void set_data(std::string Name1, int price1, int weight1, std::string Connection1, std::string Volume1) {
        Name = Name1;
        price = price1;
        weight = weight1;
        Volume = Volume1;
        Connection = Connection1;
    }
    std::string getConnection() {
        return Connection;
    }
    std::string getVolume() {
        return Volume;
    }
};




int main()
{

    std::string Shop, x, y;
    std::ifstream in("Base.txt");
    std::vector<VideoCard> videocard;
    std::vector<CPU> cpu;
    std::vector<HardDrive> harddrive;
    while (in >> x >> y) {
        if (x == "Shop") {
            Shop = y;
        }
        else {
            for (int i = 0; i < std::stoi(y); i++) {
                if (Shop == "Videocards") {
                    std::string a1, a4, a5;
                    int a2, a3;
                    VideoCard copy;
                    in >> a1 >> a2 >> a3 >> a4 >> a5;
                    copy.set_data(a1, a2, a3, a4, a5);
                    videocard.push_back(copy);

                }
                else if (Shop == "CPUs") {
                    std::string a1, a4;
                    int a2, a3, a5;
                    CPU copy;
                    in >> a1 >> a2 >> a3 >> a4 >> a5;
                    copy.set_data(a1, a2, a3, a4, a5);
                    cpu.push_back(copy);
                }
                else if (Shop == "HDD/SSD") {
                    std::string a1, a4, a5;
                    int a2, a3;
                    HardDrive copy;
                    in >> a1 >> a2 >> a3 >> a4 >> a5;
                    copy.set_data(a1, a2, a3, a4, a5);
                    harddrive.push_back(copy);
                }
            }
        }
    }
    float price1 = 0.0, price2 = 0.0, price3 = 0.0, weight1 = 0.0, weight2 = 0.0, weight3 = 0.0;
    for (int i = 0; i < size(videocard)-1; i++) {
        VideoCard example1;
        example1 = videocard[i];
        price1 += example1.getPrice() / 5.0;
        weight1 += example1.getWeight() / 5.0;
    }
    std::cout << "Average price in Shop Video cards: " << price1 << "\t" << "Average weight: " << weight1 << "\n";
    for (int i = 0; i < size(cpu) - 1; i++) {
        CPU example1;
        example1 = cpu[i];
        price2 += example1.getPrice() / 5.0;
        weight2 += example1.getWeight() / 5.0;
    }
    std::cout << "Average price in CPU Video cards: " << price2 << "\t" << "Average weight: " << weight2 << "\n";
    for (int i = 0; i < size(harddrive) - 1; i++) {
        HardDrive example1;
        example1 = harddrive[i];
        price3 += example1.getPrice() / 5.0;
        weight3 += example1.getWeight() / 5.0;
    }
    std::cout << "Average price in Shop HDD/SSD cards: " << price3 << "\t" << "Average weight: " << weight3 << "\n";
}
