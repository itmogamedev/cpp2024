



#include <iostream>


int main()
{
	
	int a;
	int b = 0;
	std::cin >> a;
	
	while (a > 0) {
		b *= 10;
		b += a % 10;
		a /= 10;
	}

	
	
	if (a % 10 == 0) {
		std::cout << "0" << b;
	}
	else {
		std::cout << b;
	}
}

