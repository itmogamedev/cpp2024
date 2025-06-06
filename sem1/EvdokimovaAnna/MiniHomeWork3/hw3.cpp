#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

class Item 
{
public:
    string name;
    double price;
    double weight;

    Item(const string& n, double p, double w) : name(n), price(p), weight(w) {}
};

class ShopBase 
{
public:
    virtual double averagePrice() const = 0;
    virtual double averageWeight() const = 0;
    virtual string getShopName() const = 0;  
};

class CustomShop : public ShopBase 
{
protected:
    vector<Item> items;
    string shopName; 

public:
    CustomShop(const string& name) : shopName(name) {}

    void addItem(const Item& item) 
    {
        items.push_back(item);
    }

    double averagePrice() const override 
    {
        double totalPrice = 0;
        for (const auto& item : items) 
        {
            totalPrice += item.price;
        }
        return (items.size() > 0) ? totalPrice / items.size() : 0;
    }

    double averageWeight() const override 
    {
        double totalWeight = 0;
        for (const auto& item : items) 
        {
            totalWeight += item.weight;
        }
        return (items.size() > 0) ? totalWeight / items.size() : 0;
    }

    string getShopName() const override 
    {
        return shopName;
    }
};

class ShopFruits : public CustomShop 
{
public:
    ShopFruits() : CustomShop("Fruits") {}
};

class ShopVegetables : public CustomShop 
{
public:
    ShopVegetables() : CustomShop("Vegetables") {}
};

class ShopDrinks : public CustomShop 
{
public:
    ShopDrinks() : CustomShop("Drinks") {}
};

void processFile(const string& filename) 
{
    ifstream file(filename);
    string line;
    CustomShop* currentShop = nullptr;

    while (getline(file, line)) 
    {
        stringstream ss(line);
        string word;
        ss >> word;

        if (word == "Shop") 
        {
            string shopName;
            ss >> shopName;

           
            if (shopName == "Fruits") 
            {
                currentShop = new ShopFruits();
            }
            else if (shopName == "Vegetables") 
            {
                currentShop = new ShopVegetables();
            }
            else if (shopName == "Drinks") 
            {
                currentShop = new ShopDrinks();
            }
        }

        if (word == "Items") 
        {
            int itemCount;
            ss >> itemCount;
            for (int i = 0; i < itemCount; ++i) 
            {
                string itemName;
                double itemPrice, itemWeight;
                getline(file, line);
                stringstream itemStream(line);
                itemStream >> itemName >> itemPrice >> itemWeight;
                Item newItem(itemName, itemPrice, itemWeight);
                currentShop -> addItem(newItem);
            }

           
            cout << "Shop: " << currentShop->getShopName() << endl;
            cout << "Average price: " << fixed << setprecision(2) << currentShop -> averagePrice() << endl;
            cout << "Average weight: " << fixed << setprecision(2) << currentShop -> averageWeight() << endl;
            cout << "-----------------------------" << endl;
        }
    }

    file.close();
}

int main() 
{
    string filename = "shopp.txt";
    processFile(filename);

    return 0;
}