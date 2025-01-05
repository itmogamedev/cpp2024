#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>


std::vector<std::string> split(std::string str_in, std::string str_to_split_by) {

    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;

    while ((pos = str_in.find(str_to_split_by)) != std::string::npos) {
        token = str_in.substr(0, pos);
        tokens.push_back(token);
        str_in.erase(0, pos + str_to_split_by.length());
    }

    tokens.push_back(str_in);

    return tokens;
}


class Item {
public:
    std::string name;
    float price;
    float wait;
    
    Item(std::vector<std::string> arr) {

        name = arr[0];
        price = stof(arr[1]);
        wait = stof(arr[2]);
    }
};

class ShopBase {
public:
    std::string name;
    std::vector<Item> items;


    ShopBase(std::vector<std::string> lines_list) {

        name = lines_list[0];

        for (std::string str : lines_list) {
            std::vector<std::string> item_vec = split(str, " ");
            if (item_vec.size() == 3) {
                items.push_back(Item(item_vec));
            }
        }
    }

};


class CustomShop : public ShopBase {
public:
    CustomShop(std::vector<std::string> lines_list) : ShopBase(lines_list) {}

    float mid_price() {

        float mid_price = 0;
        for (Item item : items) {
            mid_price += item.price;
        }

        mid_price /= items.size();

        return mid_price;
    }

    float mid_wait() {

        float mid_wait = 0;
        for (Item item : items) {
            mid_wait += item.wait;
        }

        mid_wait /= items.size();

        return mid_wait;
    }
};

int main() {
    std::ifstream file;
    std::vector<std::string> stors_strs_list;

    file.open("stors_file.txt");

    std::string file_text;
    std::string line;
    while (std::getline(file, line)) {
        file_text += (line + "|");
    }

    file.close();

    stors_strs_list = split(file_text, "Store ");

    std::vector<CustomShop> stors;
    for (std::string str : stors_strs_list) {
        std::vector<std::string> lines_list = split(str, "|");
        if (lines_list.size() >= 2) {
            stors.push_back(CustomShop(lines_list));
        }
    }

    for (CustomShop shop : stors) {

        std::cout << "for a shop " << shop.name << " awerege price is " << shop.mid_price() << " and awerege weight is " << shop.mid_price() << '\n';
        
    }

    return 0;
}