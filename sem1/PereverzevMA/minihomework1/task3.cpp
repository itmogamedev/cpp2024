#include <iostream>
int main()
{
	int a = 0;
	int b = 1;
	int c;
	int N;
	std::cout << "number of elements" << std::endl;
	std::cin >> N;
	std::cout << 1 << " ";
	for (int i = 0; i < N - 1; ++i) {
		c = a + b;
		a = b;
		b = c;
		std::cout << c << " ";
	}
}