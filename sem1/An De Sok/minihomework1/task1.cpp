#include <iostream>
int square(int a) {
	return a * a;
}
int main()
{
	const int square_length = 5; //������� ��������
	std::cout << "Square: " << square(square_length) << std::endl;
}