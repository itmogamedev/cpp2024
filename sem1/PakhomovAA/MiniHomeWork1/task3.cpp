#include <iostream>

int calcualteFibonacciNumbers(int index) {
	
	if (index == 1 || index == 2)
	{
		return 1;
	}
	else{
		return calcualteFibonacciNumbers(index - 1) + calcualteFibonacciNumbers(index - 2);
	}
}

void printFibonacciSequence() {
	int index = 0;
	std::cout << "Enter fibonacci row index to stop at (inclusive): ";
	std::cin >> index;
	for (int i = 1; i <= index; i++)
	{
		std::cout << calcualteFibonacciNumbers(i) << " ";
	}
	std::cout << std::endl;
}