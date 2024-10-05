

#include <iostream>

int main()
{
	int num;
	std::cin >> num;
	int rev = 0;
	while (num > 0) {
		rev *= 10;
		rev += num % 10;
		num /= 10;

	}
	std::cout << rev;

}


