#include <iostream>

int main()
{
	unsigned int num;
	std::cout << "Enter a natural number:";
	std::cin >> num;
	std::cout << num<< std::endl;
	while (num!=1) {


		if (num % 2 == 0) {
			num = num / 2;
			std::cout << num << std::endl;
		}
		else {
			num = (num * 3 + 1) / 2;
			std::cout << num << std::endl;
		}
	}
	std::cout << "The hypothesis is correct";
	return 0;
}

