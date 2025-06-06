#include <iostream>

void back(int a)
{
	
	int c = 10;
	int i = 0;
	int m = 0;
	while (a > 0)
	{
		i = a % 10;
		m = m * 10 + i;
		a = a / 10;

	}
	std::cout << m;
}

int main()
{
	setlocale(LC_ALL, "ru");
	std::cout << "Введите число чтобы развернуть его" << std::endl;
	int a;
	std::cin >> a;
	back(a);

}
