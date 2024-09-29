#include <iostream>
#include <string>

bool isNumber(const std::string s)
{
	return !s.empty() && (s.find_first_not_of("0123456789") == s.npos);
}
void TranslatorToOct(int input,std::string sing)
{
	std::string result;
	while (input)
	{
		result += std::to_string(input % 8);
		input /= 8;
	}
	std::reverse(result.begin(), result.end());
	std::cout << "Result is: ";
	std::cout << sing + result << std::endl;
}
void TranslatorToHex(int input, std::string sing)
{
	std::string result;
	while (input)
	{
		int temp;
		temp = (input % 16);
		input /= 16;
		if (temp <= 9)
		{
			result += std::to_string(temp);
		}
		else
		{
			switch (temp)
			{
			case(10):
				result += "A";
				break;
			case(11):
				result += "B";
				break;
			case(12):
				result += "C";
				break;
			case(13):
				result += "D";
				break;
			case(14):
				result += "E";
				break;
			case(15):
				result += "F";
				break;
			}
		}
	}
	std::reverse(result.begin(), result.end());
	std::cout << "Result is: ";
	std::cout << sing + result << std::endl;
}
void Distribution(int op)
{
	std::string input;
	std::string sing="";
	int number = 0;
	std::cout << "Enter number: ";
	std::cin >> input;
	if (input[0] == '-') 
	{
		sing = "-";
		input = input.substr(1, input.size());
	}
	if (isNumber(input))
	{
		number = std::stoi(input);
	}
	else
	{
		std::cout << "Not a number entered" << std::endl;
		exit(0);
	}
	switch (op)
	{
		case(1):
			TranslatorToOct(number,sing);
			break;
		case(2):
			TranslatorToHex(number,sing);
			break;
	}
}
void CheckInput(std::string op)
{
	if (op == "1" || op == "2")
	{
		std::cout << "The entered data is correct\n";
		Distribution(std::stoi(op));
	}
	else
	{
		std::cout << "The entered data is incorrect\n";
	}
}
int main()
{
	bool isStart = true;
	while (isStart)
	{
		std::string option;
		std::cout << "\nSelect option: \n1 - Dec to Oct \n2 - Dec to Hex\n3 - Exit\n";
		std::cout << "Your choice - ";
		std::cin >> option;
		if (option == "3")
		{
			isStart = false;
			break;
		}
		CheckInput(option);
	}
	return 0;
}