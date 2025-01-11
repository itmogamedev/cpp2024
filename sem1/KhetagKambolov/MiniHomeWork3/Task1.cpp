#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::string path = "Shops.txt";

class Item {
	public:
		std::string name;
		double price;
		double weight;

		Item() {
			name = "";
			price = 0;
			weight = 0;
		}

		Item(std::string name, double price, double weight) {
			this->name = name;
			this->price = price;
			this->weight = weight;
		}
};

class Knife : public Item {
	public:
		double length;

		Knife() {
			length = 0;
		}

		Knife(std::string name, double price, double weight, double length) {
			this->name = name;
			this->price = price;
			this->weight = weight;
			this->length = length;
		}
};

class Cloth : public Item {
public:
	std::string size;

	Cloth() {
		size = "S";
	}

	Cloth(std::string name, double price, double weight, std::string size) {
		this->name = name;
		this->price = price;
		this->weight = weight;
		this->size = size;
	}
};

class Paint : public Item {
public:
	std::string type;

	Paint() {
		type = "glossy";
	}

	Paint(std::string name, double price, double weight, std::string type) {
		this->name = name;
		this->price = price;
		this->weight = weight;
		this->type = type;
	}
};

class Shop {
	std::vector <Item> items;
	public:	
		virtual double GetAvgPrice() {
			double sum = 0;
			for (Item item : items)
			{
				sum += item.price;
			}
			return sum / 5;			
		}

		virtual double GetAvgWeight() {
			double sum = 0;
			for (Item item : items)
			{
				sum += item.weight;
			}
			return sum / 5;
		}
};

class KnifeShop : public Shop {
	public:		
		std::vector <Knife> knifes;
		double GetAvgPrice() {
			double sum = 0;
			for (Item knife : knifes)
			{
				sum += knife.price;
			}
			return sum / 5;			
		}

		double GetAvgWeight() {
			double sum = 0;
			for (Item knife : knifes)
			{
				sum += knife.weight;
			}
			return sum / 5;
		}
};

class ClothShop : public Shop {
	public:		
		std::vector <Cloth> clothes;
		double GetAvgPrice() {
			double sum = 0;
			for (Item Cloth : clothes)
			{
				sum += Cloth.price;
			}
			return sum / 5;			
		}

		double GetAvgWeight() {
			double sum = 0;
			for (Item Cloth : clothes)
			{
				sum += Cloth.weight;
			}
			return sum / 5;
		}
};

class PaintShop : public Shop {
	public:		
		std::vector <Paint> paints;
		double GetAvgPrice() {
			double sum = 0;
			for (Item Paint : paints)
			{
				sum += Paint.price;
			}
			return sum / 5;			
		}

		double GetAvgWeight() {
			double sum = 0;
			for (Item Paint : paints)
			{
				sum += Paint.weight;
			}
			return sum / 5;
		}
};

KnifeShop knifeShop;
ClothShop clothShop;
PaintShop paintShop;

void ReadFromFile() {
	bool readKnifes, readClothes, readPaints;
	readKnifes = readClothes = readPaints = false;
	std::ifstream in;
	in.open(path);
	if (in.is_open()) {
		std::string str;
		std::string strSplit[5];
		for (int i = 0; getline(in, str); i++)
		{
			std::stringstream s(str);
			int j = 0;
			while (s.good() && j < 4) {				
				s >> strSplit[j];		
				j++;
			}
			
			if (strSplit[1] == "Knifes") {
				readKnifes = true;
				readClothes = false;
				readPaints = false;
				continue;
			}

			if (strSplit[1] == "Clothes") {
				readKnifes = false;
				readClothes = true;
				readPaints = false;
				continue;
			}

			if (strSplit[1] == "Paints") {
				readKnifes = false;
				readClothes = false;
				readPaints = true;
				continue;
			}			

			if (readKnifes) {
				knifeShop.knifes.push_back(Knife(strSplit[0], stod(strSplit[1]), stod(strSplit[2]), stod(strSplit[3])));
			}

			if (readClothes) {
				clothShop.clothes.push_back(Cloth(strSplit[0], stod(strSplit[1]), stod(strSplit[2]), strSplit[3]));
			}

			if (readPaints) {
				paintShop.paints.push_back(Paint(strSplit[0], stod(strSplit[1]), stod(strSplit[2]), strSplit[3]));
			}
		}
	}
	in.close();
}

int main() 
{
	ReadFromFile();
	std::cout << "Knifes average price: " << knifeShop.GetAvgPrice() << std::endl;
	std::cout << "Knifes average weight: " << knifeShop.GetAvgWeight() << std::endl;
	std::cout << "Clothes average price: " << clothShop.GetAvgPrice() << std::endl;
	std::cout << "Clothes average weight: " << clothShop.GetAvgWeight() << std::endl;
	std::cout << "Paints average price: " << paintShop.GetAvgPrice() << std::endl;
	std::cout << "Paints average weight: " << paintShop.GetAvgWeight() << std::endl;
}





