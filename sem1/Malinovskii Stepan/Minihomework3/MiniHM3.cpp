	#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

enum Enum
{
	dnsShop, patorochkaShop, avtoShop,
	bottel, egg, car, bike, gpu, cpu
};

class BaseShop;
std::map <std::string, Enum> mapping;
std::vector<BaseShop> shops;

class BaseItem
{
public:
	int price;
	int weight;
	std::string name;

	BaseItem(int _price, int _weight, std::string _name)
	{
		price = _price;
		weight = _weight;
		name = _name;
	}

	virtual void show—haracter()
	{
		std::cout << "Name: " + name + " " + "Price: " + std::to_string(price) + "Weight: " + std::to_string(weight) << std::endl;
	}
};

class BaseShop
{
public:
	std::string name;
	std::vector<BaseItem*> productList;

	void addNewProduct(BaseItem *item)
	{
		productList.push_back(item);
	}

	void midleWeight()
	{
		std::cout << name << std::endl;
		float sum = 0;
		for (auto i : productList)
		{
			sum += i->weight;
		}
		std::string result = std::to_string(roundf((float)sum / productList.size()*100)/100);
		std::cout << "Weight: "+result.substr(0,result.find('.')+2) << std::endl;
	}

	void midlePrice()
	{
		std::cout << name << std::endl;
		float sum = 0;
		for (auto i : productList)
		{
			sum += i->price;
		}
		std::string result = std::to_string(roundf((float)sum / productList.size() * 100) / 100);
		std::cout<< "Price: " +result.substr(0, result.find('.') + 2) << std::endl;
	}

	void showProduct() 
	{
		std::cout << name << std::endl;
		for (auto i: productList)
		{
			i->show—haracter();
		}
	}
};

class GPU : public  BaseItem
{
public:
	int power;

	GPU(int _price, int _weight, int _power, std::string _name) : BaseItem(_price, _weight, _name)
	{
		power = _power;
	}

	void show—haracter() 
	{
		std::cout << "Name: " + name + " |||" + " Power: " + std::to_string(power) + " |||" + " Price: " + std::to_string(price) + " |||" + " Weight: " + std::to_string(weight) << std::endl;
	}
};
class CPU : public BaseItem
{
public:
	int countCores;

	CPU(int _price, int _weight, int _countCores, std::string _name) : BaseItem(_price, _weight, _name)
	{
		countCores = _countCores;
	}

	void show—haracter() 
	{
		std::cout << "Name: " + name + " |||" + " Number of cores: " + std::to_string(countCores) + " |||" + " Price: " + std::to_string(price) + " |||" + " Weight: " + std::to_string(weight) << std::endl;
	}
};

class DnsShop : public BaseShop
{
public:
	DnsShop()
	{
		name = "DnsShop";
	}
};

class Bottel : public BaseItem
{
public:
	int volume;

	Bottel(int _price, int _weight, int _volume, std::string _name) : BaseItem(_price, _weight, _name)
	{
		volume = _volume;
	}

	void show—haracter() 
	{
		std::cout << "Name: " + name + " |||" + " Volume: " + std::to_string(volume) + " |||" + " Price: " + std::to_string(price) + " |||" + " Weight: " + std::to_string(weight) << std::endl;
	}
};

class Egg : public BaseItem
{
public:
	int count;

	Egg(int _price, int _weight, int _count, std::string _name) : BaseItem(_price, _weight, _name)
	{
		count = _count;
	}

	void show—haracter() 
	{
		std::cout << "Name: " + name + " |||" + " Count eggs: " + std::to_string(count) + " |||" + " Price: " + std::to_string(price) + " |||" + " Weight: " + std::to_string(weight) << std::endl;
	}
};

class PatorochkaShop : public BaseShop
{
public:
	PatorochkaShop()
	{
		name = "PatorochkaShop";
	}
};

class Bike : public BaseItem
{
public:
	int power;

	Bike(int _price, int _weight, int _power, std::string _name) : BaseItem(_price, _weight, _name)
	{
		power = _power;
	}

	void show—haracter() 
	{
		std::cout << "Name: " + name + " |||" + " Power: " + std::to_string(power) + " |||" + " Price: " + std::to_string(price) + " |||" + " Weight: " + std::to_string(weight) << std::endl;
	}
};

class Car : public BaseItem
{
public:
	std::string color;

	Car(int _price, int _weight, std::string _color, std::string _name) : BaseItem(_price, _weight, _name)
	{
		color = _color;
	}

	void show—haracter() 
	{
		std::cout << "Name: " + name + " |||" + " Color: " + color + " |||" + " Price: " + std::to_string(price) + " |||" + " Weight: " + std::to_string(weight) << std::endl;
	}
};

class AvtoShop : public BaseShop
{
public:
	AvtoShop()
	{
		name = "AvtoShop";
	}
};

void divide(std::string line, std::vector<std::string>* sLine)
{
	int l = 0;
	for (int i = 0;i < line.size();i++)
	{
		while (line[i] == ' ' )
		{
			sLine->push_back(line.substr(l, i - l));
			l = i + 1;
			break;
		}
		if (i + 1 == line.size()) sLine->push_back(line.substr(l, i - l+1));
	}
}


void reader()
{
	std::string line;
	std::vector<std::string> sLine;
	std::ifstream file("Data.txt");
	while (std::getline(file, line))
	{
		divide(line, &sLine);
		if (sLine[0] == "Shop")
		{
			switch (mapping[sLine[1]])
			{
				case (dnsShop):
				{
					DnsShop shop = DnsShop();
					std::getline(file, line);
					sLine.clear();
					divide(line, &sLine);
					int n = std::stoi(sLine[1]);
					for (int i = 0; i < n;i++)
					{
						std::getline(file, line);
						sLine.clear();
						divide(line, &sLine);
						switch (mapping[sLine[0]])
						{
							case(cpu):
							{
								int nn = std::stoi(sLine[1]);
								for (int j = 0;j < nn;j++)
								{
									std::getline(file, line);
									sLine.clear();
									divide(line, &sLine);
									CPU *cpu = new CPU(std::stof(sLine[2]), std::stof(sLine[3]), std::stof(sLine[1]), sLine[0]);
									shop.addNewProduct(cpu);
								}
								break;
							}
							case(gpu):
							{
								int nn = std::stoi(sLine[1]);
								for (int j = 0;j < nn;j++)
								{
									std::getline(file, line);
									sLine.clear();
									divide(line, &sLine);
									GPU *gpu = new GPU(std::stof(sLine[2]), std::stof(sLine[3]), std::stof(sLine[1]), sLine[0]);
									shop.addNewProduct(gpu);
								}
								break;
							}
						}
					}
					shops.push_back(shop);
					break;
				}
				case (avtoShop):
				{
					AvtoShop shop = AvtoShop();
					std::getline(file, line);
					sLine.clear();
					divide(line, &sLine);
					int n = std::stoi(sLine[1]);
					for (int i = 0; i < n;i++)
					{
						std::getline(file, line);
						sLine.clear();
						divide(line, &sLine);
						switch (mapping[sLine[0]])
						{
							case(bike):
							{
								int nn = std::stoi(sLine[1]);
								for (int j = 0;j < nn;j++)
								{
									std::getline(file, line);
									sLine.clear();
									divide(line, &sLine);
									Bike *bike = new Bike(std::stof(sLine[2]), std::stof(sLine[3]), std::stof(sLine[1]), sLine[0]);
									shop.addNewProduct(bike);
								}
								break;
							}
							case(car):
							{
								int nn = std::stoi(sLine[1]);
								for (int j = 0;j < nn;j++)
								{
									std::getline(file, line);
									sLine.clear();
									divide(line, &sLine);
									Car *car = new Car(std::stof(sLine[2]), std::stof(sLine[3]), sLine[1], sLine[0]);
									shop.addNewProduct(car);
								}
								break;
							}
						}
					}
					shops.push_back(shop);
					break;
				}
				case (patorochkaShop):
				{
					PatorochkaShop shop = PatorochkaShop();
					std::getline(file, line);
					sLine.clear();
					divide(line, &sLine);
					int n = std::stoi(sLine[1]);
					for (int i = 0; i < n;i++)
					{
						std::getline(file, line);
						sLine.clear();
						divide(line, &sLine);
						switch (mapping[sLine[0]])
						{
							case(egg):
							{
								int nn = std::stoi(sLine[1]);
								for (int j = 0;j < nn;j++)
								{
									std::getline(file, line);
									sLine.clear();
									divide(line, &sLine);
									Egg *egg = new Egg(std::stof(sLine[2]), std::stof(sLine[3]), std::stof(sLine[1]), sLine[0]);
									shop.addNewProduct(egg);
								}
								break;
							}
							case(bottel):
							{
								int nn = std::stoi(sLine[1]);
								for (int j = 0;j < nn;j++)
								{
									std::getline(file, line);
									sLine.clear();
									divide(line, &sLine);
									Bottel *bottel = new Bottel(std::stof(sLine[2]), std::stof(sLine[3]), std::stof(sLine[1]), sLine[0]);
									shop.addNewProduct(bottel);
								}
								break;
							}
						}
					}
					shops.push_back(shop);
					break;
				}
			}
		}
		sLine.clear();
	}
	file.close();
};

void menu()
{
	while (true)
	{
		int selected;
		std::cout << "Menu+\n1 - Show assortment of stores3\n2 - Show midle weight\n3 - Show midle price\n4 - exit\n";
		std::cout << "Select option: ";
		std::cin >> selected;
		system("cls");
		switch (selected)
		{
		case(1):
			for (auto i : shops)
				i.showProduct();
			break;
		case(2):
			for (auto i : shops)
				i.midleWeight();
			break;
		case(3):
			for (auto i : shops)
				i.midlePrice();
			break;
		case(4):
			exit(5);
			break;
		}
		system("pause");
		system("cls");
	}
}

void start()
{
	mapping["gpu"] = gpu;
	mapping["cpu"] = cpu;
	mapping["dnsShop"] = dnsShop;

	mapping["egg"] = egg;
	mapping["bottel"] = bottel;
	mapping["patorochkaShop"] = patorochkaShop;

	mapping["car"] = car;
	mapping["bike"] = bike;
	mapping["avtoShop"] = avtoShop;

	reader();
	menu();
}

int main()
{
	start();
}