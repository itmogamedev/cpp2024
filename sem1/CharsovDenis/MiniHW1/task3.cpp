#include <iostream>

int main()
{
	int currentNum{};
	int nextNum{ 1 };
	int temp{};

	std::cout << "How many fibonacci numbers to output: ";
	int numOfNums{};
	std::cin >> numOfNums;

	std::cout << "The Fibonacci numbers:\n";

	for (int i = 0; i < numOfNums; i++) {
		std::cout << currentNum << " ";

		temp = currentNum;
		currentNum = nextNum;
		nextNum += temp;
	}

}
