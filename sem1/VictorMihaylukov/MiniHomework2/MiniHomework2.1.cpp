#include <iostream>
#include <string>

std::string func(int n, int cc) {
	std::string abc = { "0123456789ABCDEF" };
	std::string result = "";
	int i = 0;
	do {
		i = n % cc;
		result = result + abc[i];
		n = n / cc;
	} while (n > 0);
	reverse(result.begin(), result.end());
	return result;
}

int main(){
	setlocale(LC_ALL, "rus");

	std::cout << "Введите число:";
	int number = 0;
	std::cin >> number;
	while (number < 0) {
		std::cout << "Число не может быть меньше 0\n";
		std::cout << "Введите число:";
		std::cin >> number;
	}

	int choice = 0;
	std::cout << "Введите 1, если хотите перевести число в восьмеричиную систему счисления.\nИли введите 2, если хотите перевести число в шестнадцатеричную систему счисления\n";
	std::cin >> choice;
	while (choice != 1 and choice != 2) {
		std::cout << "Вы ввели не допустимое число\n";
		std::cout << "Введите 1, если хотите перевести число в восьмеричиную систему счисления.\nИли введите 2, если хотите перевести число в шестнадцатеричную систему счисления\n";
		std::cin >> choice;
	}

	if (choice == 1) {
		std::cout << func(number, 8);
	}
	else {
		std::cout << func(number, 16);
	}
}