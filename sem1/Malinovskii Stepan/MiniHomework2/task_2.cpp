#include <iostream>
#include <string>

void Cpu(int input)
{
	std::cout << std::to_string(input) + " => ";
	if (input % 2 == 0)
	{
		input /= 2;
	}
	else
	{
		input *= 3;
		input++;
	}
	if (input != 1) { Cpu(input); }
	else { std::cout << input; }
}
int Input()
{
	int input;
	std::cout << "Enter number: ";
	std::cin >> input;
	std::cout << "\n";
	return input;
}
int main()
{
	int input = Input();
	Cpu(input);
}