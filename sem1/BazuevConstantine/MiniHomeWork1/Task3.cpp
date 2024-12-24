#include "iostream"
#include "string"

std::string Fs(int lenght);

int main()
{
	int len;

	std::cout << "Enter a lenght of Fibonacci sequence: ";
	std::cin >> len;
	std::cout << "Fibonacci sequence: " << Fs(len);

}

std::string Fs(int lenght)
{
	std::string text;
	long long int first = 0, second = 1, result;
	text.append(std::to_string(first) + " ");
	text.append(std::to_string(second) + " ");

	for (int counter = 0; counter < lenght - 2; counter++)
	{
		result = first + second;
		text.append(std::to_string(result) + " ");
		first = second;
		second = result;
	}

	return text;
}