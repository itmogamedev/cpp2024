#include <iostream>
int main()
{
	int x;
	std::cout << "enter a number" << std::endl;
	std::cin >> x;
	while (x != 1) {
		if (x % 2 == 0) {
			x = x /= 2;
		}
		else {
			x = ((x * 3) + 1);
		}

	}
	if (x == 1) {
		std::cout << "confirmed";
}
}