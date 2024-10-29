#include <iostream>
#include <string>
#include <algorithm>
#include<vector>
#include <chrono>
#include <thread>
//задание 2
void print(std::vector<int> todayslist) {
	std::cout << "[";
	for (int i = 0; i < todayslist.size(); i++) {
		std::cout << todayslist[i] << " ";
	}
	std::cout << "]"<<'\n';
}
int randint(int start, int fin) {
	return (rand() % (fin+1 - start)) + start;
}
int answerToInt(char answer) {
	if (answer == 'y'){
		return 1;
	}
	else if (answer == 'n') {
		return 0;
	}
	else {
		return -1;
	}
}
// doubly linked list
class client {
public:
	std::vector<int> products;
	bool right;
	client* next;
	client* prev;
	client(int prodAmount, std::vector<int> todayslist) {
		//creating a list of products for a client
		products.resize(prodAmount, 0);
		for (int i = 0; i < products.size(); i++) {
			products[i] = randint(0, 14);
		}
		// checking if this client should be allowed
		for (int i = 0; i < prodAmount; i++) {
			if (std::find(todayslist.begin(), todayslist.end(), products[i]) == todayslist.end()) {
				right = 0;
			}
		}
		if (right != 0) {
			right = 1;
		}
		next = nullptr;
		prev = nullptr;
	}
};
void add(client*& head, int prodamount,std::vector<int> todayslist) {
	client* newclient = new client(prodamount, todayslist);
	if (head == nullptr) {
		head = newclient;
		return;
	}
	client* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = newclient;
	newclient->prev = temp;
};
void deleteclient(client*& head) {
	if (head == nullptr) {
		return;
	}
	client* temp = head;
	head = head->next;
	if (head != nullptr) {
		head->prev = nullptr;
	}
	delete temp;
};

//game
class game{
private:
	char answer = ' ';
	int score = 0;
	std::string productlist[15] = {"apple juice","orange juice","carrot","pepper","salt","sugar","beef","pork","chiken","cookies","candies","milk", "coffee","tea","butter"};
public:	
	game(int clientAmount, int checkoutAmount) {
		//creating a list of products for today
		std::vector<int> todayslist;
		todayslist.resize(randint(1, 15), 0);
		for (int i = 0; i < todayslist.size(); i++) {
			todayslist[i] = randint(0, 14);
		}
		//removing non- unique values from it;
		std::sort(begin(todayslist), end(todayslist));
		todayslist.erase(std::unique(begin(todayslist), end(todayslist)), end(todayslist));

		//making an str of it to show the player
		std::string todaysliststr = productlist[todayslist[0]];
		for (int i = 1; i < todayslist.size(); i++) {
				todaysliststr += ", " + productlist[todayslist[i]];
		}


		todaysliststr = todaysliststr + '\n' + '\n';
		//asssembling a doubly linked list
		client* clientZero = new client(randint(0, 14),todayslist);
		for (int i = 1; i < clientAmount; i++) {
			add(clientZero, randint(0, 14),todayslist);
		}
		client* current = clientZero;
		std::cout << "are you ready to start?(input y/n)" << '\n';
		char ready = 'a';// 'a' is a random char i chose, cause if i leave it '' an error occurs
		std::cin >> ready;
		while (ready != 'y') {
			if (ready == 'n') {
				std::cout << "input 'y' when you are" << '\n';
			}
			else{
			std::cout << "invalid input, try again" << '\n';
			}
			std::cin.clear();
			std::cin.ignore(1000000000000, '\n');
			std::cin >> ready;
			
		}
		//tutorial
		std::cout << "good, but first a quick explanation" << '\n';
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "here's your list of items for today:" << '\n';
		std::cout << todaysliststr << '\n';
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "don't allow any of the clients with any other products!" << '\n';
		std::cout << "You only have 3 seconds on each of them!" << '\n';
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << "type 'y' to allow client and 'n' to decline" << '\n';
		std::this_thread::sleep_for(std::chrono::seconds(2));
		std::cout << "The first one is coming!" << '\n';
		std::this_thread::sleep_for(std::chrono::seconds(1));
		for (int i = 0; i < clientAmount; i++) {
			// making a string list of clients products
			std::vector<int> clientList = current->products;
			std::string clientListStr = productlist[clientList[0]];
			for (int i = 1; i < clientList.size(); i++) {
				clientListStr += ", " + productlist[clientList[i]];
			}
			std::thread t1([&]() {
				std::cout << "client brought:" << clientListStr << '\n';
				std::cout << "right:" << current->right << '\n';
				answer = ' ';
				std::cin.clear();
				std::cin.ignore(1000000000000, '\n');
				std::cin >> answer;
				});
			std::this_thread::sleep_for(std::chrono::seconds(3));
			t1.detach();
			int answerInt = answerToInt(answer);
			if (answerInt==current->right){
				score++;
				if (i == clientAmount - 1) {
					std::cout << "Correct! You won!" << '\n';
				}
				else{
				std::cout << "Correct! next one:" << '\n';
				std::this_thread::sleep_for(std::chrono::seconds(2));
				}
			}
			else if (answerInt != current->right and answer != ' ') {
				if (i == clientAmount - 1) {
					std::cout << "This one is wrong! but you still won! " << '\n';
				}
				else{
					std::cout << "Wrong!("<<checkoutAmount<<" checkouts left) next one : " << '\n';
					std::this_thread::sleep_for(std::chrono::seconds(2));
					checkoutAmount--;
				}
			}else {
				if (i == clientAmount - 1) {
					std::cout << "Times up! but you still won!" << '\n';
				}
				else{
				std::cout << "Times up!(" << checkoutAmount << " checkouts left) next one:" << '\n';
				std::this_thread::sleep_for(std::chrono::seconds(2));
				checkoutAmount--;
				}
			}
			current = current->next;
			deleteclient(clientZero);
			clientZero = current;
			if (checkoutAmount == 0){
				score = 0;
				std::cout << "You've lost!" << '\n';
				break;
			}
		}
		std::cout << "Final score:" <<score<< '\n';

	};
	
};
int inputHandler() {
	int varToHandle=0;

	try {
		std::cin >> varToHandle;
		std::cout << "var:" << varToHandle << '\n';
		
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100,'\n');
			throw 1;
		}
	}
	catch(int error){
		if (error == 1) {
			error = 0;
			varToHandle = randint(1, 15);
		}
	}
	return varToHandle;
}
int main() {
	srand(time(NULL));
	int clientAmount;
	int checkoutAmount=0;
	std::cout << "please input an amount of clients, any non integer value will be interpritated as a random number" << '\n';
	clientAmount=inputHandler();
	std::cout << "now the amount of checkouts:" << '\n';
	checkoutAmount = inputHandler();
	game game(clientAmount, checkoutAmount);
	return 0;
}