#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class ItemBase
{
protected:
	std::string name;
	double price;
	double mass;
	std::string distributorType;

public:
	ItemBase(std::string name, double price, double mass)
	{
		this->name = name;
		this->price = price;
		this->mass = mass;
	}

	std::string GetDistrubitorType()
	{
		return this->distributorType;
	}

	double GetPrice()
	{
		return this->price;
	}

	double GetMass()
	{
		return this->mass;
	}
};

class Electronics : public ItemBase
{
public:
	Electronics(std::string name, double price, double mass) : ItemBase(name, price, mass)
	{
		this->distributorType = "ForPCs";
	}
};

class Groceries : public ItemBase
{
public:
	Groceries(std::string name, double price, double mass) : ItemBase(name, price, mass)
	{
		this->distributorType = "Groceries";
	}
};

class Clothes : public ItemBase
{
public:
	Clothes(std::string name, double price, double mass) : ItemBase(name, price, mass)
	{
		this->distributorType = "Clothes";
	}
};

class Shop
{
private:
	std::string type;
	std::vector<ItemBase> itemsList;

public:
	int numberOfItems;

	Shop(std::string type)
	{
		this->type = type;
	}

	void AddItem(ItemBase item)
	{
		this->itemsList.push_back(item);
	}

	std::string GetType()
	{
		return this->type;
	}

	double GetAvrgPrice()
	{
		double avrgPrice = 0;

		for (int i = 0; i < this->itemsList.size(); i++)
		{
			avrgPrice += itemsList[i].GetPrice();
		}

		avrgPrice /= numberOfItems;

		return avrgPrice;
	}

	double GetAvrgMass()
	{
		double avrgMass = 0;

		for (int i = 0; i < this->itemsList.size(); i++)
		{
			avrgMass += itemsList[i].GetMass();
		}

		avrgMass /= numberOfItems;

		return avrgMass;
	}

	void GetInfo()
	{
		std::cout << "В магазине " << GetType() << " средняя стоимость товаров: " << GetAvrgPrice() << ", а их средняя масса: " << GetAvrgMass() << std::endl;
	}
};

void Initialize(std::vector<Shop>& shoplist);

int main()
{
	setlocale(LC_ALL, "Russian");
	std::vector<Shop> shoplist;

	Initialize(shoplist);

	for (int i = 0; i < shoplist.size(); i++)
	{
		shoplist[i].GetInfo();
	}
}

void Initialize(std::vector<Shop>& shoplist)
{
	std::ifstream in("shoplist.txt");
	std::string line;

	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			if (line.find("Shop") != std::string::npos)
			{
				Shop shop(line.substr(line.find(" ")+1, line.size()));
				shoplist.push_back(shop);
			}
			else if (line.find("Item") != std::string::npos)
			{
				shoplist[shoplist.size()-1].numberOfItems = stoi(line.substr(line.find(" ") + 1, line.size()));
			}
			else
			{
				double mass = stod(line.substr(line.rfind(" ")+1, line.size()));
				line.erase(line.rfind(" "), line.size());
				double price = stod(line.substr(line.rfind(" ")+1, line.size()));
				line.erase(line.rfind(" "), line.size());
				std::string name = line;

				if (shoplist[shoplist.size() - 1].GetType() == "ForPCs")
				{
					Electronics item(name, price, mass);
					shoplist[shoplist.size() - 1].AddItem(item);
				}
				else if (shoplist[shoplist.size() - 1].GetType() == "Groceries")
				{
					Electronics item(name, price, mass);
					shoplist[shoplist.size() - 1].AddItem(item);
				}
				else if(shoplist[shoplist.size() - 1].GetType() == "Clothes")
				{
					Electronics item(name, price, mass);
					shoplist[shoplist.size() - 1].AddItem(item);
				}
			}
		}
	}

	in.close();
}