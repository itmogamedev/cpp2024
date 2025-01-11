#include <iostream>

static void Siracus(int num) {
	int temp = num;
	std::cout << temp;
	while (temp != 1) {
		if (temp % 2 == 0) temp /= 2;
		else temp = (temp * 3 + 1) / 2;
		std::cout << " -> " << temp;
	}
}

int main()
{ 
	int num;
	std::cout << "Enter your number: ";
	std::cin >> num;
	Siracus(num);
}







