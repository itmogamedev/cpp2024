#include <iostream>
#include <fstream>
#include <list>
class Item{
    public:
        Item(int price, int weight, std::string name);
        int GetPrice();
        int GetWeight();
        std::string GetName();
    private:
        int price;
        int weight;
        std::string name;
};
class Shop{
    public:
        Shop(std::string name);
        void addItemsToShop(std::vector<Item>& newItems);
        void showItems();
        std::string GetName();
        void FindMiddlePriceAndWeight();
    private:
        std::vector<Item> items;
        std::string name;
        int itemsCount;
        int shopMiddlePrice;
        int shopMiddleWeight;
};
class TechnicShop : public Shop{
    public:
        TechnicShop(std::string name);
    private:
        std::string name;
};
class ProductShop : public Shop{
     public:
        ProductShop(std::string name);
     private:
        std::string name;
};
class SportShop: public Shop{
     public:
        SportShop(std::string name);
     private:
        std::string name;
};
class TechnicItem : public Item{
    public:
    TechnicItem(int price, int weight, std::string name);
    private:
        int price;
        int weight;
        std::string name;
};
class ProductItem : public Item{
        public:
    ProductItem(int price, int weight, std::string name);
    private:
        int price;
        int weight;
        std::string name;
};
class SportItem: public Item{
        public:
    SportItem(int price, int weight, std::string name);
    private:
        int price;
        int weight;
        std::string name;
};
void Shop::addItemsToShop(std::vector<Item> &newItems)
{
    items = newItems;
}
std::string Shop::GetName(){
    return name;
}
void Shop::showItems(){
    for (Item item : items){
        std::cout << item.GetName() << " " << item.GetPrice()<< " " << item.GetWeight() << " " << GetName() << std::endl;
    }
}
Shop::Shop(std::string name): name(name) {
    shopMiddlePrice = 0;
    shopMiddleWeight = 0;
};
void Shop::FindMiddlePriceAndWeight(){
    for (Item item : items){
        shopMiddlePrice += item.GetPrice();
        shopMiddleWeight += item.GetWeight();
    }
    shopMiddlePrice = shopMiddlePrice / itemsCount;
    shopMiddleWeight = shopMiddleWeight / itemsCount;
    std::cout << "Средняя цена в магазине " << GetName() << " " <<  shopMiddlePrice  << std::endl;
    std::cout << "Средний вес в магазине " << GetName() << " " <<  shopMiddleWeight  << std::endl;
}
SportShop::SportShop(std::string name): Shop(name) {};
ProductShop::ProductShop(std::string name): Shop(name) {};
TechnicShop::TechnicShop(std::string name): Shop(name) {};
std::vector<Shop> getData();
Item::Item(int price, int weight, std::string name): price(price), weight(weight), name(name) {};
SportItem::SportItem(int price, int weight, std::string name): Item(price, weight, name){};
ProductItem::ProductItem(int price, int weight, std::string name):  Item(price, weight, name){};
TechnicItem::TechnicItem(int price, int weight, std::string name):  Item(price, weight, name) {};
int Item::GetPrice(){
    return price;
}
int Item::GetWeight(){
    return weight;
}
std::string Item::GetName(){
    return name;
}
int main() {
    std::vector<Shop> shops;
    shops = getData();
    for (Shop shop : shops){
        shop.showItems();
    }
    for (Shop shop : shops){
        shop.FindMiddlePriceAndWeight();
    }
};
std::vector<Shop> getData(){
std::ifstream file("data.txt", std::ios::in);
if (file.peek() != EOF){
std::string line;
std::string allStudentsLine;
bool isFirstLine = true;
while (std::getline(file, line))
{
     if (isFirstLine) {
            allStudentsLine += line;
            isFirstLine = false;
        } else {
            allStudentsLine += ' ';
            allStudentsLine += line;
        }
}
std::string word;
std::vector<std::string> words;
int i = 0;
while (i < allStudentsLine.length()){
    if (allStudentsLine[i] != ' '){
        word += allStudentsLine[i];
    } else {
        words.push_back(word);
        word = "";
    }
    i++;
}
words.push_back(word);
file.close();
int cycleCount = 0; 
std::string shopName;
int itemsCount;
std::string itemName;
int itemPrice;
int itemWeight;
bool f = true;
std::vector<Shop> shops;
std::vector<Item> items;
int c = 0;
for (std::string word : words)
{
    if (f)
    {
        switch (cycleCount)
        {
        case 0:
        {
            shopName = word;
            break;
        }
        case 2:
        {
            itemsCount = stoi(word);
            break;
        }
        default:
        break;
            }
    if (cycleCount == 2) {
        f = false;
        cycleCount = -1;
    }
        cycleCount++;
    }
    else
    {
        switch (cycleCount)
        {
        case 0:
        {
            itemName = word;
            break;
        }
        case 1:
        {
            itemPrice = stoi(word);
            break;
        }
        case 2:
        {
            itemWeight = stoi(word);
            break;
        }
        default:
        break;
            }
    if (cycleCount == 2 && (c == itemsCount-1)) {
        if (shopName == "Sportmaster"){
        items.push_back(SportItem(itemPrice, itemWeight, itemName));
        f = true;
        cycleCount = -1;
        SportShop shop = SportShop(shopName);
        shop.addItemsToShop(items);
        shops.push_back(shop);
        shopName = "";
        items.clear();
        itemsCount = 0;
        c = 0;

        } else if (shopName == "Eldorado"){
        items.push_back(TechnicItem(itemPrice, itemWeight, itemName));
        f = true;
        cycleCount = -1;
        TechnicShop shop = TechnicShop(shopName);
        shop.addItemsToShop(items);
        shops.push_back(shop);
        shopName = "";
        items.clear();
        itemsCount = 0;
        c = 0;

        } else if (shopName == "Semishagov"){
         items.push_back(ProductItem(itemPrice, itemWeight, itemName));
        f = true;
        cycleCount = -1;
        ProductShop shop = ProductShop(shopName);
        shop.addItemsToShop(items);
        shops.push_back(shop);
        shopName = "";
        items.clear();
        itemsCount = 0;
        c = 0;
        }
    } else if (cycleCount == 2 && c != itemsCount){
        if (shopName == "Eldorado"){
        items.push_back(TechnicItem(itemPrice, itemWeight, itemName));
        itemPrice = 0;
        itemWeight = 0;
        itemName = "";
        cycleCount = -1;
        c++;
        } else if (shopName == "Semishagov"){
        items.push_back(ProductItem(itemPrice, itemWeight, itemName));
        itemPrice = 0;
        itemWeight = 0;
        itemName = "";
        cycleCount = -1;
        c++;
        } else if (shopName == "Sportmaster"){
        items.push_back(SportItem(itemPrice, itemWeight, itemName));
        itemPrice = 0;
        itemWeight = 0;
        itemName = "";
        cycleCount = -1;
        c++;
        }
    }
    cycleCount++;
    }
}
return shops;
}
}
