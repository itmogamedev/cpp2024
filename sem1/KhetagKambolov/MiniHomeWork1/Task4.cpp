#include <iostream>

int main()
{ 
	int n, reversed = 0;
	std::cout << "Enter the number: ";
	std::cin >> n;
	while (n != 0) {
		int remain = n % 10;
		if (remain == 0) std::cout << 0;
		reversed = reversed * 10 + remain;
		n /= 10;
	}
	std::cout << reversed;
}







