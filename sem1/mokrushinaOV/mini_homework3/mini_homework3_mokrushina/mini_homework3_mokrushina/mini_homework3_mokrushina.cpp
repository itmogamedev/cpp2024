#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

std::vector<std::string> split(std::string str_in, std::string str_to_split_by) {

    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;

    while ((pos = str_in.find(str_to_split_by)) != std::string::npos) {
        token = str_in.substr(0, pos);
        tokens.push_back(token);
        str_in.erase(0, pos + 1);
    }
    tokens.push_back(str_in);

    return tokens;
}

class Item {
public:
    std::string name;
    float price;
    float wait;

    //Item(std::string in_name, float in_price, float in_wait) : name(in_name), price(in_price), wait(in_wait) {}
    
    Item(std::string str) {

        std::vector<std::string> arr = split(str, " ");

        name = arr[0];
        price = stof(arr[1]);
        wait = stof(arr[2]);
    }
};

class ShopBase {
public:
    std::string name;
    std::vector<Item> items;


    ShopBase(std::string str) {
        std::vector<std::string> lines_list;

        lines_list = split(str, "\n");

        name = split(lines_list[0], " ")[0];
        lines_list.erase(std::next(lines_list.begin(), 0), std::next(lines_list.begin(), 1));

        for (std::string str : lines_list) {
            items.emplace_back(str);
        }
    }

};


class CustomShop : public ShopBase {
public:
    CustomShop(const std::string& str) : ShopBase(str) {}

    void wright_mid_price() {

        float mid_price = 0;
        for (Item item : items) {
            mid_price += item.price;
        }

        mid_price /= items.size();
        std::cout << mid_price;
    }
};

int main() {
    std::ifstream file;
    std::vector<std::string> stors_strs_list;

    file.open("stors_file.txt");
    std::string file_text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    stors_strs_list = split(file_text, "Store");

    std::vector<CustomShop> stors;
    for (std::string str : stors_strs_list) {
        stors.emplace_back(str);
    }

    for (CustomShop shop : stors) {
        shop.wright_mid_price();
    }

    return 0;
}