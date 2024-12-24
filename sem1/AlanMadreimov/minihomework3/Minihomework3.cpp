#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class ItemBase {
private:
	double price;
	double weight;
	std::string name;


public:

	ItemBase(double price, double weight, std::string name) {
		this->price = price;
		this->weight = weight;
		this->name = name;
	}
	ItemBase() {

	}

	void print_item_data() {
		std::cout << "Item: " << name << " Price: " << price << "$" << " Weight: " << weight << "kg";
	}

	double get_price() {
		return price;
	}

	double get_weight() {
		return weight;
	}
};

class shop {
private:
	std::string name;
	std::vector <ItemBase> items;

public:
	double AVweight;
	double AVprice;


	shop() {

	}
	shop(std::string name) {
		this->name = name;
	}
	virtual void add_items() {
	}

	void print_name() {
		std::cout << "Shop: " << name << "\n";
	}

	void print_stat() {
		std::cout << "Average price: " << AVprice << "$ Average weight of goods: " << AVweight << "kg" << "\n";
	}

	void print_all_items() {
		for (int i = 0; i < items.size(); i++) {
			items[i].print_item_data();
			std::cout << "\n";
		}
	}

	

};

class Item_PC : public ItemBase {
private:
	double infn;
	std::string info;
public:
	Item_PC(double price, double weight, std::string name, std::string info, double infn)
		: ItemBase(price, weight, name)
	{
		this->infn = infn;
		this->info = info;
	}
	void print_item_data()
	{
		if (info == "FPS") {
			ItemBase::print_item_data();
			std::cout << " FPS: " << infn;
		}
		else if (info == "GHz") {
			ItemBase::print_item_data();
			std::cout << " Processor frequency: " << infn << "GHz";
		}
		else {
			ItemBase::print_item_data();
			std::cout << " Memory " << infn << " GB";
		}
	}
};

class pc_shop : public shop {
private:
	std::vector <Item_PC> items;
public:
	using shop::shop;

	void print_all_items() {
		pc_shop::print_name();
		for (int i = 0; i < items.size(); i++) {
			items[i].print_item_data();
			std::cout << "\n";
		}
	}
	void add_items(std::vector <Item_PC> items) {
		double t_price = 0;
		double t_weight = 0;
		short int cnt = 0;
		for (int i = 0; i < items.size(); i++) {
			this->items.push_back(items[i]);
			t_price += items[i].get_price();
			t_weight += items[i].get_weight();
			cnt++;
		}
		AVprice = t_price / cnt;
		AVweight = t_weight / cnt;
		

	}
};

class Item_Book : public ItemBase {
private:
	int year;
	std::string writer;
public:
	Item_Book(double price, double weight, std::string name, std::string writer, int year)
		: ItemBase(price, weight, name)
	{
		this->year = year;
		this->writer = writer;
	}
	void print_item_data()
	{
		ItemBase::print_item_data();
		std::cout << " Writer: " << writer << " Year of creation: " << year;
			
	}
};

class book_shop : public shop {
private:
	std::vector <Item_Book> items;
public:
	using shop::shop;

	void print_all_items() {
		book_shop::print_name();
		for (int i = 0; i < items.size(); i++) {
			items[i].print_item_data();
			std::cout << "\n";
		}
	}
	void add_items(std::vector <Item_Book> items) {
		double t_price = 0;
		double t_weight = 0;
		short int cnt = 0;
		for (int i = 0; i < items.size(); i++) {
			this->items.push_back(items[i]);
			t_price += items[i].get_price();
			t_weight += items[i].get_weight();
			cnt++;
		}
		AVprice = t_price / cnt;
		AVweight = t_weight / cnt;


	}
};

class Item_Fruit : public ItemBase {
private:
	std::string vit1;
	std::string vit2;
public:
	Item_Fruit(double price, double weight, std::string name, std::string vit1, std::string vit2)
		: ItemBase(price, weight, name)
	{
		this->vit1 = vit1;
		this->vit2 = vit2;
	}
	void print_item_data()
	{
		ItemBase::print_item_data();
		std::cout << " Vitamins: " << vit1 << " " << vit2;

	}
};

class fruit_shop : public shop {
private:
	std::vector <Item_Fruit> items;
public:
	using shop::shop;

	void print_all_items() {
		fruit_shop::print_name();
		for (int i = 0; i < items.size(); i++) {
			items[i].print_item_data();
			std::cout << "\n";
		}
	}
	void add_items(std::vector <Item_Fruit> items) {
		double t_price = 0;
		double t_weight = 0;
		short int cnt = 0;
		for (int i = 0; i < items.size(); i++) {
			this->items.push_back(items[i]);
			t_price += items[i].get_price();
			t_weight += items[i].get_weight();
			cnt++;
		}
		AVprice = t_price / cnt;
		AVweight = t_weight / cnt;


	}
};

int main() {
	setlocale(LC_ALL, "Russian");
	std::ifstream in("D:\\C++Projects\\Minihomework3\\shops.txt");
	std::string str;

	std::string i_name;
	double price;
	double weight;
	std::string inf;
	std::string dop_inf;
	double dop;

	std::vector <Item_PC> pc;
	std::vector <Item_Book> books;
	std::vector <Item_Fruit> fruits;

	std::getline(in, str);
	pc_shop pcstore(str);

	for (int i = 0; i < 5;i++) {
		std::getline(in, str);
		std::stringstream ss(str);
		ss >> i_name;
		ss >> price;
		ss >> weight;
		ss >> inf;
		ss >> dop;
		Item_PC n(price,weight,i_name,inf,dop);
		pc.push_back(n);
	}
	pcstore.add_items(pc);

	std::getline(in, str);
	fruit_shop frstore(str);

	for (int i = 0; i < 5; i++) {
		std::getline(in, str);
		std::stringstream ss(str);
		ss >> i_name;
		ss >> price;
		ss >> weight;
		ss >> inf;
		ss >> dop;
		Item_Fruit n(price,weight,i_name,inf,dop_inf);
		fruits.push_back(n);
	}
	frstore.add_items(fruits);

	std::getline(in, str);
	book_shop bkstore(str);

	for (int i = 0; i < 5; i++) {
		std::getline(in, str);
		std::stringstream ss(str);
		ss >> i_name;
		ss >> price;
		ss >> weight;
		ss >> inf;
		ss >> dop;
		Item_Book n(price,weight,i_name,inf,dop);
		books.push_back(n);
	}
	bkstore.add_items(books);
	
	pcstore.print_all_items();
	pcstore.print_stat();

	frstore.print_all_items();
	frstore.print_stat();

	bkstore.print_all_items();
	bkstore.print_stat();


	return 0;
}