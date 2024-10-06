#include <iostream>

int main()
{
	int num;
	std::cout << "Enter a natural number to test the Syracuse hypothesis: ";
	std::cin >> num;
	while (num > 1)
	{
		if (num % 2 == 0) 
		{
			std::cout << "Number is even,so divide it by 2, we get " << num / 2 << std::endl;
			num = num / 2;
		}
		if (num % 2 == 1)
		{
			std::cout << "Number is odd,so multiply by 3 and plus 1, we get " << num * 3 + 1 << std::endl;
			num = num * 3 + 1;
		}
		if (num == 2)
		{
			std::cout << "Number is even,so divide it by 2" << std::endl;
			num = num / 2;
			std::cout << "Hypothesis is confirmed, get " << num;
		}
			
	}

}