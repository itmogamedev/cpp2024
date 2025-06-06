

#include <iostream>


int main()
{
	int a = 0, b = 1, sum, i, n;
	std::cout << "ENTER THE NUMBER N" << std::endl;
	std::cin >> n;
	
	std::cout << std::endl << "FIBONACCI LIST" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	for (i = 0; i < n; i++) {
		sum = a + b;
		std::cout << sum << std::endl;
		a = b;
		b = sum;

	}
	return 0;

}

