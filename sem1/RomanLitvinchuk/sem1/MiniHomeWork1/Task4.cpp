# include <iostream>
# include <math.h>

int main()
{
	int number = 0;
	int ZeroCount = 0;
	int ReverseNumber = 0;
	int digit = -1;
	std::cout << "Number?" << std::endl;
	std::cin >> number;
	int storage = number;
	while (storage % 10 == 0) {
		ZeroCount += 1;
		storage /= 10;

	}
	storage = number;
	while (storage != 0) {
		storage = storage / 10;
		digit += 1;
	}
	while (number != 0) {
		ReverseNumber += number % 10 * pow(10, digit);
		number = number / 10;
		digit -= 1;
	}
	std::cout << "Reverse Number = ";
	for (; ZeroCount > 0; --ZeroCount) {
		std::cout << '0';
	}
	std::cout << ReverseNumber;
	return 0;
}