



#include <iostream>



int main()
{
	
	int a = 0;
	int b = 1;
	int c;
	int n;
	std::cout << "Enter the number of elements: ";
	std::cin >> n;
	std::cout << 0 << " " << 1 << " ";
	for (int i = 0; i < n - 2; i = i + 1) {
		c = a + b;
		a = b;
		b = c;
		std::cout << c << " ";
	}
}

