#include <iostream>

int main()
{ 
	int n, prev1 = 0, prev2 = 1, next;
	std::cout << "Enter the number: ";
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		if (i == 0) {
			std::cout << 0 << "\n";
			continue;
		}
		if (i == 1) {
			std::cout << 1 << "\n";
			continue;
		}
		next = prev1 + prev2;
		prev1 = prev2;
		prev2 = next;
		std::cout << next << "\n";
	}
}







