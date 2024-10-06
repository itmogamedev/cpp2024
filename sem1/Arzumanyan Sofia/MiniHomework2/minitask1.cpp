#include <iostream>
#include <iomanip>

void intTOoct() {
	int x;
	std::cin >> x;
	std::cout << std::setbase(8) << x << std::endl;

	return;
}

void intTOhex() {
	int x;
	std::cin >> x;
	std::cout << "0x" << std::hex << x << std::endl;

	return;
}


int main() {
	
	int choice;
	
	std::cout << "Choose func" << std::endl;
	std::cout << "1. Oct" << std::endl;
	std::cout << "2. Hex" << std::endl;
	std::cout << "exit" << std::endl;
	
	if (choice == 1) {
		intTOoct();
	}
	else if (choice == 2) {
		intTOhex();
	}
	else {
		std::cout << "error:(" << std::endl;
	}
    
	return 0;
}