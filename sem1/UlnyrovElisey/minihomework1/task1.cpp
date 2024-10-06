#include <iostream>
int AreaOfSquare(int SideOfSquare)
{
	return SideOfSquare * SideOfSquare;
}

int main()
{
	int x = 0;
	std::cout << "x = ";
	std::cin >> x;
	int S = AreaOfSquare(x);
	std::cout << "S = ";
	std::cout << S;
	return 0;
}