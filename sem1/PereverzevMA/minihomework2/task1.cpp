#include <iostream>;
int main()
{
	int x;
	std::cout << "enter the number to convert to 16 and 8 system";
	std::cin >> x;
	std::cout << std::hex << x << std::endl;
	std::cout << std::oct << x << std::endl;
	return 0;

}
