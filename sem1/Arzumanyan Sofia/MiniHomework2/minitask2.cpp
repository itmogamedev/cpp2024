#include <iostream>

void Sirakuzzzz(int x) {
	while (x != 1) {
		if (x % 2 == 0) {
			x /= 2;
		}
		else {
			x = x * 3 + 1;

		}
		std::cout << x << std::endl;

	}
}
	
		int main() {

			int x;
			std::cout << "Enter natural number"; 
			std::cin >> x;
			if (x <= 0) {
				std::cout << "again.. NATURAL NUMBER";
			}	
			else {
				Sirakuzzzz(x);
			}
			
			return 0;
}
