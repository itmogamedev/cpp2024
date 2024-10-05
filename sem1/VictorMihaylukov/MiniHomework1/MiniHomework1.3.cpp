#include <iostream>

int main(){
	setlocale(LC_ALL, "rus");
	int n = 0;
	std::cout << "Введите N:";
	std::cin >> n;
	if (n == 0) {
		std::cout << "";
	}
	if (n > 0){
		std::cout << 1;
		std::cout << " ";
	}
	while (n < 0) {
		std::cout << "Вы ввели недопустимое число\nВведите N:";
		std::cin >> n;
	}
	int pre1 = 0;
	int pre2 = 1;
	int count = 1;
	int i = 0;
	while (count < n) {
		i++;
		if (pre1 + pre2 == i) {
			count++;
			pre1 = pre2;
			pre2 = i;
			std::cout<<i;
			std::cout << " ";
		}
	}
}