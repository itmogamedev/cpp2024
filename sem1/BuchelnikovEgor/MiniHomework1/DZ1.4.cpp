#include<iostream>
int main() {
	setlocale(LC_ALL, "Russian");
	int number, chislo=0;
	std::cout << "Введите число ";
	std::cin >> number;
	while (number > 0) {
		chislo = chislo * 10;
		chislo = (number % 10)+chislo;
		number = number / 10;
	}
	std::cout << chislo;
}
