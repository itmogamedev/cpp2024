#include <iostream>

int main()
{
	int s, a, b, h;
	std::cout << "Enter top and bottom \n";
	std::cin >> a >> b;
	std::cout << "Enter height \n";
	std::cin >> h;
	s = (a + b) / 2 * h;
	std::cout << "Square " << s << std::endl;
}