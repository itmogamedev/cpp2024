#include <iostream>

void fibonacci(int a, int b, int c, int d);

void fibonacci(int count)
{
	fibonacci(0, 1, 0, count);
}

void fibonacci(int second, int first, int iteration,int count)
{
	if (iteration == count) return;
	int result = second + first;
	std::cout << result<< std::endl;
	fibonacci(first, result, ++iteration,count);
}

int main()
{
	setlocale(LC_ALL, "");

	int inputCount = 0;
	std::cout << "¬ведите кол-во чисел ‘ибоначи: ";
	std::cin >> inputCount;

	fibonacci(inputCount);

	return 0;
}

