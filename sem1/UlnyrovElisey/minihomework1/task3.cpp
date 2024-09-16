#include <iostream>
int main() {
	int N = 0;
	int first = 0;
	int second = 1;
	int next = 0;
	int count = 2;
	
	std::cout << "N = ";
	std::cin >> N;	
	
	if (N <= 0)
	{
		std::cout << "";
	}
	else if (N == 1)
	{
		std::cout << first;
	}
	else
	{
		std::cout << first << " " << second;
	}
	
		while (count < N)
	{
			next = first + second;
			first = second;
			second = next;
			count++;
			std::cout << " " << next;
	}
		return 0;
}