#include <iostream>
#include <cmath>
//задание 4
int main() {
	setlocale(LC_ALL, "RU");
	std::cout << "Введите необходимое число";
	int ToCountLenght;
	std::cin >> ToCountLenght;
	int ToReverse = ToCountLenght;
	int len = 0;
	do {
		len++;
	} while (ToCountLenght /= 10);
	int  result = 0;
	for (int i = 0; i < len; i++) {
		std::cout << ToReverse / int(pow(10, len - i - 1)) % 10 << "\n";
		result += ToReverse / int(pow(10, len - i - 1)) % 10 * pow(10, i);
	}
	std::cout << result << "\n";
	return 0;

}