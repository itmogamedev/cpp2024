#include <iostream>

//сделаем функцию
int number2reverse(int N) {
	int rev = 0;
	while (N > 0) {
		rev *= 10;
		rev += N % 10;
		N /= 10;
	}
	return rev;
}
//проверяем работу, не выводит числа 10, 20, ... и тд, как 01, 02, ... и тд., т.к при сложение с 0 число не изменяется, нужен стринг либо использование массивов
int main() {
	std::cout << "Enter a number" << std::endl;
	int rev = 0;
	std::cin >> rev;
	int check = 0;
	std::cout << "Your reverse number = " << number2reverse(rev) << std::endl;
}