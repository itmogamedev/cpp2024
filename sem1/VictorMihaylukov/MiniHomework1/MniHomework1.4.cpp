#include <iostream>

int main(){
	setlocale(LC_ALL, "rus");
	std::cout << "Введите число:";
	int num = 0;
	std::cin >> num;
	int num_r = 0;

	while (num != 0) {
		if (num_r != 0) {
			num_r *= 10;
		}
		num_r += num % 10;
		num = num / 10;
	}

	std::cout << num_r;
}