#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class ShopBase
{
public:
    int all_items = 0;
    std::string name;

    void set_name(std::string n) { name = n; };
    void set_all_items(int i) { all_items = i; };
};
class CustomShop : public ShopBase
{
public:
    int full_cost = 0;
    int full_weight = 0;

    void set_full_cost(int fc) { full_cost = full_cost + fc; };
    void set_full_weight(int fw) { full_weight = full_weight + fw; };
    void print() const
    {
        std::cout << "Name: " << name << ", items: " << all_items << std::endl;
    }
};
std::vector<CustomShop> shops;
class Item
{
public:
    std::string shop_name;
    std::string name;
    std::string cost;
    std::string weight;

    void set_shop_name(std::string s) { shop_name = s; }
    void set_name(std::string n) { name = n; }
    void set_cost(std::string c) { cost = c; }
    void set_weight(std::string w) { weight = w; }
    void print() const
    {
        std::cout << "Shop name: " << shop_name << ", name: " << name << ", cost: " << cost << ", weight: " << weight << std::endl;
    }
};
std::vector<Item> items;

void pull();
void mid();

int main()
{
    pull();
    mid();
}

void pull()
{
    std::string line;
    std::ifstream file("shops.txt");

    if (file.is_open())
    {
        short int number = -1;
        while (std::getline(file, line))
        {
            if (line.substr(0, 4) == "shop")
            {
                CustomShop shop;
                shop.set_name(line.substr(4));
                shops.push_back(shop);
                number += 1;
            }
            if (line.substr(0, 5) == "items")
            {
                shops[number].set_all_items(std::stoi(line.substr(5)));
            }
            if (line.substr(0, 4) != "shop" and line.substr(0, 5) != "items")
            {
                Item item;

                for (int i = 0, cursor = 0; i < line.length(); i++)
                {
                    if (line[i] == ' ' and cursor != 0 and item.cost == "")
                    {
                        item.set_cost(line.substr(cursor, i - cursor -1));
                        item.set_weight(line.substr(i));
                    }
                    if (line[i] == ' ' and cursor == 0)
                    {
                        cursor = i;
                        item.set_name(line.substr(0, cursor));
                    }
                }
                item.set_shop_name(shops[number].name);
                items.push_back(item);
            }
        }
    }
}
void mid()
{
    for (int i = 0; i < shops.size(); i++)
    {
        for (int j = 0; j < items.size(); j++)
        {
            if (items[j].shop_name == shops[i].name)
            {
                shops[i].set_full_cost(stoi(items[j].cost));
                shops[i].set_full_weight(stoi(items[j].weight));
            }
        }
    }

    for (int i = 0; i < shops.size(); i++)
    {
        std::cout << "Shop" << shops[i].name << std::endl;
        std::cout << "Mid cost = " << shops[i].full_cost / shops[i].all_items << std::endl;
        std::cout << "Mid weight = " << shops[i].full_weight / shops[i].all_items << std::endl;
    }
}