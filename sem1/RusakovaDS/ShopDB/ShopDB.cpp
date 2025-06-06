#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Item {
	string name;
	float price;
	float weight;
};

using Items = vector<Item>;

struct Shop {
	string name;
	int itemCount;
	Items items;
};

using Shops = vector<Shop>;


class ShopDB
{
public:
	string getFileName()
	{
		return fileName;
	}

	void readFromFile() {
		ifstream file;
		string line, word;
		vector<string> row;
		Items items;
		string name = "";
		int count = 0;
		int itemCount = 0;
		bool isShop = true;

		file.open(getFileName());

		if (file.is_open())
		{
			shops.clear();

			while (getline(file, line))
			{
				row.clear();

				stringstream s(line);

				while (getline(s, word, ';'))
				{
					row.push_back(word);
				}

				if (isShop) 
				{
					if (items.size() > 0)
					{
						shops.push_back(Shop{ name, itemCount, items });
						items.clear();
						name = "";
						itemCount = 0;
					}

					isShop = false;
					count = 0;
					name = row[0];
					itemCount = stoi(row[1]);
				}
				else 
				{
					string name = row[0];
					float weigth = stof(row[1]);
					float price = stof(row[2]);
					items.push_back(Item{ name, price, weigth });
					count++;
					if (count == itemCount) {
						isShop = true;
					}
				}
			}
			if (items.size() > 0)
			{
				shops.push_back(Shop{ name, itemCount, items });
				items.clear();
				name = "";
				itemCount = 0;
			}
		}
		file.close();
	}

	void printAllShops()
	{
		for (Shop shop : shops)
		{
			printShop(shop);
		}
	}

	void printShop(Shop shop)
	{
		float weightSum = 0;
		float priceSum = 0;

		cout << "Name: "
			<< shop.name
			<< "\tcount: "
			<< shop.itemCount
			<< endl;

		for (Item item : shop.items)
		{
			cout << "\tName: "
				<< item.name
				<< "\t\tweight: "
				<< item.weight
				<< "\tprice: "
				<< item.price
				<< endl;
			weightSum += item.weight;
			priceSum += item.price;
		}
		cout << "\t\t\t"
			<< "average weight: "
			<< weightSum / shop.itemCount
			<< "\taverage price: "
			<< priceSum / shop.itemCount
			<< endl;
		cout << "====================="
			<< endl;
	}

private:
	const string fileName = "shops.csv";

	Shops shops;


};



int main()
{
	ShopDB shopDB;
	shopDB.readFromFile();
	shopDB.printAllShops();

	cout << "FileName: " << shopDB.getFileName() << endl;
}