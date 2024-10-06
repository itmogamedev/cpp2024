#include <iostream>

//Сначала создадим функцию нахождения площади квадрата
int A_quadrate(int a){
	return a * a;
}

//Теперь проверим её работоспособность
int main() {
	std::cout << "Enter side of quadrate: " << std::endl;
	int side = 0;
	std::cin >> side;
	int a = side;
	std::cout << "Area of the square = " << A_quadrate(a) << std::endl;
}