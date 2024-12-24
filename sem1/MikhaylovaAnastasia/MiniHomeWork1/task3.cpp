

#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int current = 1;
	int last = 0;
	std::cout << current << " ";
	for (int i = 1; i < n; i++) {
		std::cout << current + last << " ";
		int temp = last;
		last = current;
		current += temp;
	}
}

