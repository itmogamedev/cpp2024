#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

string path = "Shops.txt";

class Item {
	public:
		string name;
		double price;
		double weight;

		Item() {
			name = "";
			price = 0;
			weight = 0;
		}

		Item(string name, double price, double weight) {
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

		Knife(string name, double price, double weight, double length) {
			this->name = name;
			this->price = price;
			this->weight = weight;
			this->length = length;
		}
};

class Cloth : public Item {
public:
	string size;

	Cloth() {
		size = "S";
	}

	Cloth(string name, double price, double weight, string size) {
		this->name = name;
		this->price = price;
		this->weight = weight;
		this->size = size;
	}
};

class Paint : public Item {
public:
	string type;

	Paint() {
		type = "glossy";
	}

	Paint(string name, double price, double weight, string type) {
		this->name = name;
		this->price = price;
		this->weight = weight;
		this->type = type;
	}
};

class Shop {
	vector <Item> items;
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
		vector <Knife> knifes;
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
		vector <Cloth> clothes;
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
		vector <Paint> paints;
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
	ifstream in;
	in.open(path);
	if (in.is_open()) {
		string str;
		string strSplit[5];
		for (int i = 0; getline(in, str); i++)
		{
			stringstream s(str);
			int j = 0;
			while (s.good() && j < 4) {				
				s >> strSplit[j];		
				cout << strSplit[j] << " ";
				j++;
			}
			if (strSplit[0] == "Butterfly") {
				knifeShop.knifes.push_back(Knife(strSplit[0], stod(strSplit[1]), stod(strSplit[2]), stod(strSplit[3])));
			}
			cout << endl;
			
		}
	}
	in.close();
}

int main() 
{
	ReadFromFile();
}





