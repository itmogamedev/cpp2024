#include <iostream>

bool checkSyracuse(const int num) {
	int number = num;
	while (number > 1) {
		number = number % 2 == 0 ?
			number / 2
			: number * 3 + 1;
	}
	if (number == 1) {
		return true;
	} 
	else {
		return false;
	}
}

int main() {
	int num;
	std::cout << "Welcome to Syracuse checking program!" << std::endl << std::endl;
	std::cout << "Syracuse says that if you enter any number, " << std::endl << "then perform a sequence of operations" << std::endl << "and repeat it with the result of this sequence," << std::endl << "then eventually it will turn into 1." << std::endl << std::endl;
	std::cout << "Let's check it!" << std::endl; std::cout << "Enter any number:" << std::endl;
	std::cin >> num;
	if (checkSyracuse(num)) {
		std::cout << "Syracuse's hypothesis is correct! Yay!";
	}
	else {
		std::cout << "Syracuse's hypothesis is wrong... :(";
	}
}

