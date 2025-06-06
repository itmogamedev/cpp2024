#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class ItemBase {
public:
    std::string NameItem = "RTX6090";
    int Weight = 5;
    int Count = 3;
    ItemBase() {}
    ~ItemBase() {}
    ItemBase(std::string NameItem_, int Weight_, int Count_) {
        NameItem = NameItem_;
        Weight = Weight_;
        Count = Count_;
    }
    void Info() {
        std::cout << NameItem << " " << Weight << " " << Count << "\n";
    }
};

class Item : public ItemBase {
private:
public:
    Item() {
    }
    ~Item() {
    }

    Item(std::string NameItem_, int Weight_, int Count_) {
        NameItem = NameItem_;
        Weight = Weight_;
        Count = Count_;
    }
    void SetAll(std::string NameItem_, int Weight_, int Count_) {
        NameItem = NameItem_;
        Weight = Weight_;
        Count = Count_;
    }
    void inf() {
        Info();
    }
    int GetWeight() {
        return Weight;
    }
    int GetCount() {
        return Count;
    }
};

class ShopBase {
private:
    int ItemsCount;
    std::string ShopName = "Shop";
    std::vector <Item> Shop;
public:
    ShopBase() {
    }
    ~ShopBase() {
    }
    ShopBase(std::string Shop_, int ItemsCount_) {
        ShopName = Shop_;
        ItemsCount = ItemsCount_;
        Shop.resize(ItemsCount);
    }
    void Info() {
        std::cout << ShopName << " " << ItemsCount << "\n";
    }
    void InfoShop() {
        for (int i = 0; i < ItemsCount; i++) {
            Shop[i].Info();
        }
    }
    double midlCount() {
        double Midl = 0, count = ItemsCount;
        for (int i = 0; i < ItemsCount; i++) {
            Midl += Shop[i].GetCount();
        }
        Midl = Midl / count;
        return Midl;
    }
    double midlWeight() {
        double Midl = 0, count = ItemsCount;
        for (int i = 0; i < ItemsCount; i++) {
            Midl += Shop[i].GetWeight();
        }
        Midl = Midl / count;
        return Midl;
    }
    std::vector<Item> GetVector() {
        return Shop;
    }
    void Push_back(Item item, int i) {
        Shop[i] = item;
    }

};

int main()
{
    /*std::ofstream out;
    out.open("ShopBase.txt", std::ios::app);
    std::string line;
    for (int i = 0; i < 21; i++) {
        getline(std::cin, line);
        if (out.is_open()) {
            out << line << "\n";
        }
    }
    out.close();*/
    int countShop;
    std::string ShopName;
    int CountItems;
    std::vector <ShopBase> ShopBases;
    int count, f, g, j = 1;
    std::ifstream in("ShopBase.txt");
    if (in.is_open()) {
        std::string ShopName, fg;
        while (in >> ShopName) {
            in >> fg;
            in >> count;
            ShopBase Shop(ShopName, count);
            for (int k = 0; k < count; k++) {
                std::string ItemName;
                int countItem, Weight;
                in >> ItemName >> countItem >> Weight;
                Item item;
                item.SetAll(ItemName, Weight, countItem);
                Shop.Push_back(item, k);
            }

            ShopBases.push_back(Shop);
            j++;
        }
    }
    for (int i = 0; i < j - 1; i++) {
        ShopBases[i].Info();
        ShopBases[i].InfoShop();
        std::cout << ShopBases[i].midlCount() << "\n";
        std::cout << ShopBases[i].midlWeight() << "\n";
        std::cout << "\n";
    }
    in.close();
}