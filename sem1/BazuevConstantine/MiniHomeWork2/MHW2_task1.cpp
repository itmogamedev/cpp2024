#include "iostream"
#include "string"

std::string Convert(int num, int sys);

int main()
{
	int number;
	int sys_num;

	std::cout << "Enter a number: ";
	std::cin >> number;
	std::cout << "Enter a calculus system (1 for 16-based, 2 for 8-based. default is 16-based): ";
	std::cin >> sys_num;

	while (sys_num != 1 and sys_num != 2)
	{
		std::cout << "Enter a valid number for system (1 for 16-based, 2 for 8-based. default is 16-based):";
		std::cin >> sys_num;
	}

	std::cout << "Number in " << ((sys_num == 2) ? "8-based" : "16-based") << " is " << Convert(number, sys_num);

}

std::string Convert(int num, int sys)
{
	if (num == 0)
	{
		return "0";
	}

	char nums[] = { '0', '1', '2', '3' ,'4' , '5', '6' ,'7' , '8' ,'9', 'A', 'B' , 'C' , 'D', 'E', 'F' };

	std::string text = "";

	switch (sys)
	{
	case(1):
		
		while (num > 0)
		{
			text = nums[num % 16] + text;
			num /= 16;
		}
		break;

	case(2):
		
		while (num > 0)
		{
			text = nums[num % 8] + text;
			num /= 8;
		}
		break;
	}
	return text;
}