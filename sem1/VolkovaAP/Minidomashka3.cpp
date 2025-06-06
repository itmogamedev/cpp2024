#include <iostream>
#include <string>
#include <fstream>

class ItemBase
{
protected:
    std::string name;
    int price;
    int weight;
};

class Iphone : public ItemBase
{
protected:
    std::string color;
    int memory;

public:
    Iphone(std::string name, std::string color, int memory, int price, int weight)
    {
        this->name = name;
        this->color = color;
        this->memory = memory;
        this->price = price;
        this->weight = weight;
    }
};

class Book : public ItemBase
{
protected:
    std::string genre;
    int number_of_pages;

public:
    Book(std::string name, std::string genre, int number_of_pages, int price, int weight)
    {
        this->name = name;
        this->genre = genre;
        this->number_of_pages = number_of_pages;
        this->price = price;
        this->weight = weight;
    }
};

class Sport_item : public ItemBase
{
protected:
    std::string type;
    std::string kind_of_sport;

public:
    Sport_item(std::string name, std::string type, std::string kind_of_sport, int price, int weight)
    {
        this->name = name;
        this->type = type;
        this->kind_of_sport = kind_of_sport;
        this->price = price;
        this->weight = weight;
    }
};

class Item
{
public:
    void New_iphone()
    {
        Iphone iphone("iphone 13", "black", 256, 77990, 173);
    }

    void New_book()
    {
        Book book("Kolobok", "skazka", 10, 250, 100);
    }

    void New_sport_item()
    {
        Sport_item sport_item("ski", "equipment", "alpine skiing", 6800, 3200); 
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");

    std::string path = "database.txt";

    std::ifstream fin(path);
    std::string str;

    int sum_price = 0;
    int sum_weight = 0;

    while (getline(fin, str))
    {
        if (str == "iphonestore" or str == "bookstore" or str == "sportmaster" or str == "items 5")
        {
            if (str == "iphonestore")
            {
                std::cout << "iphonestore" << std::endl;
            }

            if (str == "bookstore")
            {
                std::cout << "Средняя цена: " << (float)sum_price / 5 << "\t" << "Средний вес: " << (float)sum_weight / 5 << std::endl << std::endl;
                sum_price = 0;
                sum_weight = 0;
                std::cout << "bookstore" << std::endl;
            }

            if (str == "sportmaster")
            {
                std::cout << "Средняя цена: " << (float)sum_price / 5 << "\t" << "Средний вес: " << (float)sum_weight / 5 << std::endl << std::endl;
                sum_price = 0;
                sum_weight = 0;
                std::cout << "sportmaster" << std::endl;
            }

            if (str == "items 5")
            {
                std::cout << "items 5" << std::endl;
            }
        }

        else {
            int pos1 = 0;
            for (int i = 1; i < 4; ++i)
            {
                pos1 = str.find(",", pos1) + 2;
            }
            int endpos1 = str.find(",", pos1);
            std::string str_price = str.substr(pos1, endpos1 - pos1);
            int price = stoi(str_price);
            sum_price += price;

            int pos2 = endpos1 + 2;
            int endpos2 = str.find(",", pos2);
            std::string str_weight = str.substr(pos2, endpos2 - pos2);
            int weight = stoi(str_weight);
            sum_weight += weight;

            //std::cout << "Цена: " << price << "\t" << "Вес: " << weight << std::endl;
        }
    }

    fin.close();

    std::cout << "Средняя цена: " << (float)sum_price / 5 << "\t" << "Средний вес: " << (float)sum_weight / 5 << std::endl << std::endl;
}