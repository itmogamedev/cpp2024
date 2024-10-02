#include <iostream>

int main() {
	setlocale(LC_ALL, "RU");
	int num, reverse_num=0;
	std::cout << "Введите число:";
	std::cin >> num;
	while (num > 0)
	{
		reverse_num = reverse_num*10 + num % 10;
		num /= 10;

	}
	std::cout <<"Перевернутое число:"<< reverse_num;

	return 0;
}
