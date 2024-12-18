#include <iostream>


int main()
{
	unsigned int quantity = 0;
	unsigned int storage = 0;
	std::cout << "How many elements?" << std::endl;
	std::cin >> quantity;
	unsigned int FirstNumber = 1;
	unsigned int SecondNumber = 1;
	if (quantity >= 2) {
		std::cout << FirstNumber << " ";
		std::cout << SecondNumber << " ";
		quantity -= 2;
	}
	else {
		if (quantity == 1) {
			std::cout << FirstNumber;
			--quantity;
		}
		else {
			if (quantity == 0) {
				std::cout << "Nothing";
			}
		}
		
	}
	while (quantity > 0) {
		std::cout << FirstNumber + SecondNumber << " ";
		storage = FirstNumber;
		FirstNumber = SecondNumber;
		SecondNumber += storage;
		--quantity;

	}


}