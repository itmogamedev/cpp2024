#include <iostream>

int main()
{ 
	int num, select;
	while (true) {
		std::cout << "Enter your decimal: ";
		std::cin >> num;
		std::cout << "Select what to convert to: \n 1 - octal \n 2 - hexadecimal" << std::endl;
		std::cin >> select;
		switch (select) {
			case 1:
				std::cout << std::oct << num << std::endl;
				break;
			case 2: 
				std::cout << std::hex << num << std::endl;
				break;
		}
	}
}







