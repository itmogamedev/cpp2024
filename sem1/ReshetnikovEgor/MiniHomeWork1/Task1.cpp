#include <iostream>

int Square(int numb) {
	return numb * numb;
}

int main() {
	setlocate(LS_ALL,"Russian");
	int input;
	std::cout << "Введите сторону квадрата: ";
	std::cin >>  input;
	std::cout <<  "Площадь квадрата равна: " << Square(input) << std::endl;
}
