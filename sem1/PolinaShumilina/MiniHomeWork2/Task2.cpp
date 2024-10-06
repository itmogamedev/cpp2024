#include <iostream>

int main()
{
	int n;
	std::cout << "Enter the number - ";
	std::cin >> n;
	if (n > 0) {
		while (n != 1) {
			if (n % 2 == 0) {
				n = n / 2;
			}
			else {
				n = ((n * 3) + 1) / 2;
			}
		}
		std::cout << "The resulting number - " << n << std::endl;
		std::cout << "Syracuse's hypothesis verified!";
	}
	else {
		std::cout << "You entered a non-natural number";
	}
}