#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

class ItemBase
{
public:
    std::string name;
    int price;
    int weight;

    void setItem(const std::string& itemData)
    {
        std::istringstream iss(itemData);
        iss >> name >> price >> weight;
    }

    // Метод для чтения данных о товарах из файла
    void readShopData(std::ifstream& file, std::string& store_name, std::vector<ItemBase>& items)
    {
        std::string line;

        while (std::getline(file, line))
        {
            if (line.substr(0, 4) == "Shop")
            {
                store_name = line.substr(4);
            }
            else if (line.substr(0, 5) == "items")
            {
                int val = std::stoi(line.substr(5));
                for (int i = 0; i < val; ++i)
                {
                    if (std::getline(file, line))
                    {
                        ItemBase item;
                        item.setItem(line);
                        items.push_back(item); // Добавление товара в вектор
                    }
                }
                break; // Прекращаем чтение после обработки всех товаров
            }
        }
    }
};

class Shop
{
protected:
    std::string store_name;
    std::vector<ItemBase> items;
    double average_price = 0.0; // Переменная для средней цены
    double average_weight = 0.0; // Переменная для среднего веса

public:
    void addItem(const ItemBase& item)
    {
        items.push_back(item);
        calculateAverage(); // Вычисляем средние значения при добавлении товара
    }

    void calculateAverage()
    {
        if (items.empty()) return; // Проверка на пустой вектор

        double total_price = 0;
        double total_weight = 0;

        for (const auto& item : items)
        {
            total_price += item.price;
            total_weight += item.weight;
        }

        average_price = total_price / items.size();
        average_weight = total_weight / items.size();
    }

    void displayAverage() const
    {
        std::cout << "Название магазина: " << store_name << std::endl;
        std::cout << "Средняя цена: " << average_price << std::endl;
        std::cout << "Средний вес: " << average_weight << std::endl;
    }

    void setStoreName(const std::string& name)
    {
        store_name = name;
    }
};

class Shop_Vegetables : public Shop
{
public:
    void readShopData(std::ifstream& file)
    {
        ItemBase item;
        item.readShopData(file, store_name, items); // Чтение данных о товарах из файла
        calculateAverage(); // Вычисляем средние значения после добавления всех товаров
    }
};

class Shop_Coffee : public Shop
{
public:
    void readShopData(std::ifstream& file)
    {
        ItemBase item;
        item.readShopData(file, store_name, items); // Чтение данных о товарах из файла
        calculateAverage(); // Вычисляем средние значения после добавления всех товаров
    }
};

class Shop_TableGame : public Shop
{
public:
    void readShopData(std::ifstream& file)
    {
        ItemBase item;
        item.readShopData(file, store_name, items); // Чтение данных о товарах из файла
        calculateAverage(); // Вычисляем средние значения после добавления всех товаров
    }
};

int main()
{
    setlocale(0, "");
    // Открываем файл один раз.
    std::ifstream file("C:/Users/Makas/OneDrive/Рабочий стол/Магазины.txt");

    if (!file.is_open())
    {
        std::cerr << "Ошибка открытия файла!" << std::endl;
        return 1; // Завершаем программу при ошибке открытия файла.
    }

    Shop_Vegetables vegetableShop;
    vegetableShop.readShopData(file); // Читаем данные для овощного магазина

    Shop_Coffee coffeeShop;
    coffeeShop.readShopData(file); // Читаем данные для кофейного магазина

    Shop_TableGame tableGameShop;
    tableGameShop.readShopData(file); // Читаем данные для магазина настольных игр

    file.close(); // Закрываем файл после обработки всех магазинов.

    // Отображаем средние значения для каждого магазина
    vegetableShop.displayAverage();
    coffeeShop.displayAverage();
    tableGameShop.displayAverage();

    return 0;
}