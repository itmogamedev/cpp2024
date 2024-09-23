#include <iostream>


void fibonachi() {
	int last_numb;
	std::cin >> last_numb;
	int rememb_numbers[3]{ 0, 1, 1 };
	for (int i = 0; i < last_numb; i++) {
		std::cout << rememb_numbers[0] << ' ';
		rememb_numbers[2] = rememb_numbers[1];
		rememb_numbers[1] = rememb_numbers[0] + rememb_numbers[1];
		rememb_numbers[0] = rememb_numbers[2];
	}
}
