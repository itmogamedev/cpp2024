#include <iostream>
#include <string>
#include <fstream>
//items are stored in a doubly linked list
class item {
public:
	int price;
	int mass;
	int characteristic; // any other characteristic what exactly is this depends on type of shop
	item* next;
	item* prev;
	item(int price, int mass, int characteristic) {
		this->price = price;
		this-> mass = mass;
		this->characteristic = characteristic;
		next = nullptr;
		prev = nullptr;
	}
};
void add(item*& head, int price, int mass, int characteristic) {
	item* newitem = new item(price, mass, characteristic);
	if (head == nullptr) {
		head = newitem;
		return;
	}
	item* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newitem;
	newitem->prev = temp;
};
class shopbase {
public:
	item* itemZero = new item(0,0,0);// make first item for all shops, so i don't have to make an exception for the first item
	int massAll;
	int priceAll;
	int countMass(int itemamount) {
		item* current = itemZero;
		for (int i=-1; i < itemamount; i++) {
			massAll += current->mass;
			current = current->next;

		}
		return massAll;
	}
	int countprice(int itemamount) {
		item* current = itemZero;
		for (int i= -1; i < itemamount; i++) {
			priceAll += current->price;
			current = current->next;
		}
		return priceAll;
	}
};

class CARshop:public shopbase {
public:
	int Allmaxspeed = 1;
	float findMaxspeed(int itemamount) {
		item* current = itemZero;
		for (int i= -1; i < itemamount; i++) {
			if (current->characteristic > Allmaxspeed){
				Allmaxspeed = current->characteristic;
			}
			current = current->next;
		}
		return Allmaxspeed;
	}
};
class ROCKSshop :public shopbase {
public:
	int densitySum = 0;
	float meandensity(int itemamount) {
		item* current = itemZero;
		for (int i= -1; i < itemamount; i++) {
			if (current->characteristic!=0){
				densitySum += (current->mass / (current->characteristic));
			}
			current = current->next;
		}
		
		return densitySum/itemamount;
	}
};
class PCshop :public shopbase {
public:
	int fpsAll = 0;
	int meanfps(int itemamount) {
		item* current = itemZero;
		for (int i= -1; i < itemamount; i++) {
			fpsAll += current->characteristic;
			current = current->next;
		}
		return fpsAll / itemamount;
	}

};
int main() {
	CARshop carshop;
	int carsAmount;
	ROCKSshop rocksshop;
	int rocksAmount;
	PCshop pcshop;
	int pcsAmount;
	// making a list in file
	std::remove("shops.txt");
	std::ofstream out;
	out.open("shops.txt", std::ios::app);
	if (out.is_open()) {
		out << "PCshop" << '\n' << "items 5" << '\n' << "pc1 1 1 fps 1" << '\n' << "pc2 2 2 fps 2" << '\n' << "pc3 3 3 fps 3" << '\n' << "pc4 4 4 fps 4" << '\n' << "pc5 5 5 fps 5" << '\n';
		out << "ROCKSshop" << '\n' << "items 5" << '\n' << "rock1 1 1 volume 1" << '\n' << "rock2 2 2 volume 2" << '\n' << "rock3 3 3 volume 3" << '\n' << "rock4 4 4 volume 4" << '\n' << "rock5 5 5 volume 5" << '\n';
		out << "CARshop" << '\n' << "items 5" << '\n' << "car1 1 1 speed 1" << '\n' << "car2 2 2 speed 2" << '\n' << "car3 3 3 speed 3" << '\n' << "car4 4 4 speed 4" << '\n' << "car5 5 5 speed 5" << '\n';
	}
	out.close();

	//parsing it
	std::string line;
	std::ifstream in("shops.txt");
	if (in.is_open())
	{	// 3 times to do all 3 shops
		for (int i = 0; i < 3; i++) {
			//depending on which shop first creating it
			std::getline(in, line);
			if (line == "PCshop") {
				// extracting amount of items
				std::getline(in, line);
				pcsAmount = std::stoi(line.substr(line.find(" ") + 1, line.length()));
				for (int i = 0; i < pcsAmount; i++) {
					// extracting mass, price and characteristic
					std::getline(in, line);
					std::string itemarray[5] = {" ", " ", " ", " ", " "};
					int ind = 0;
					int prev = 0;
					for (int i = 0; i < line.length(); i++) {
						if (line[i] == ' ') {
							itemarray[ind] = line.substr(prev, i - prev);
							prev = i + 1;
							ind++;
						}
					}
					itemarray[ind] = line.substr(prev, line.length());
					// adding an item
					add(pcshop.itemZero, std::stoi(itemarray[1]), std::stoi(itemarray[2]), std::stoi(itemarray[4]));
				}
			}
			// all the same for two other shops
			else if (line == "ROCKSshop") {
				std::getline(in, line);
				rocksAmount = std::stoi(line.substr(line.find(" ") + 1, line.length()));
				for (int i = 0; i < rocksAmount; i++) {
					std::getline(in, line);
					std::string itemarray[5] = { " ", " ", " ", " ", " " };
					int ind = 0;
					int prev = 0;
					for (int i = 0; i < line.length(); i++) {
						if (line[i] == ' ') {
							itemarray[ind] = line.substr(prev, i - prev);
							prev = i + 1;
							ind++;
						}
					}
					itemarray[ind] = line.substr(prev, line.length());
					add(rocksshop.itemZero, std::stoi(itemarray[1]), std::stoi(itemarray[2]), std::stoi(itemarray[4]));
				}
			}
			else{
				std::getline(in, line);
				carsAmount = std::stoi(line.substr(line.find(" ") + 1, line.length()));
				for (int i = 0; i < carsAmount; i++) {
					std::getline(in, line);
					std::string itemarray[5] = { " ", " ", " ", " ", " " };
					int ind = 0;
					int prev = 0;
					for (int i = 0; i < line.length(); i++) {
						if (line[i] == ' ') {
							itemarray[ind] = line.substr(prev, i - prev);
							prev = i + 1;
							ind++;
						}
					}
					itemarray[ind] = line.substr(prev, line.length());
					add(carshop.itemZero, std::stoi(itemarray[1]), std::stoi(itemarray[2]), std::stoi(itemarray[4]));
				}
			}
		}
	}
	in.close();
	std::cout << "cars mass:" << carshop.countMass(carsAmount)<<'\n';
	std::cout << "cars price:" << carshop.countprice(carsAmount) << '\n';
	std::cout << "pcs mass:" << pcshop.countMass(pcsAmount) << '\n';
	std::cout << "pcs price:" << pcshop.countprice(pcsAmount) << '\n';
	std::cout << "rocks mass:" << rocksshop.countMass(rocksAmount) << '\n';
	std::cout << "rocks price:" << rocksshop.countprice(rocksAmount) << '\n';
	std::cout << "cars max speed:" << carshop.findMaxspeed(carsAmount) << '\n';
	std::cout << "pcs mean fps:" << pcshop.meanfps(pcsAmount) << '\n';
	std::cout << "rocks mean density:" << rocksshop.meandensity(rocksAmount) << '\n';
/**/
	return 0;

}