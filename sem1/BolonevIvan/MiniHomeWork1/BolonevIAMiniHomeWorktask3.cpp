#include <iostream>

void fib2(int a)
{
	int i = 0;
	int r = 0;
	int m = 1;
	int l;

	std::cout << "0" << std::endl;
	std::cout << "1" << std::endl;
	while (i < a)
	{
		i++;
		l = m + r;
		r = m;
		m = l;
		std::cout << l << std::endl;
	}
	
}

int main()
{
	setlocale(LC_ALL, "ru");
	int a;
	std::cout << "Выберите сколько чисел Фибоначи вывести" << std::endl;
	std::cin >> a;
	fib2(a);
}