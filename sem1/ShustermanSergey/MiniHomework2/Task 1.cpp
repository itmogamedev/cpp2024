#include <iostream>
#include <string>


std::string ToSixteen(long long int decimal) { // Переводит число в шестнадцатиричную сс
	std::string new_number = "";
	char nums[16] = { '0', '1', '2', '3' ,'4' , '5', '6' ,'7' , '8' ,'9', 'A', 'B' , 'C' , 'D', 'E', 'F' };
	if (decimal == 0) {
		return "0";
	}
	while (decimal > 0) {
		new_number = nums[decimal % 16] + new_number;
		decimal /= 16;
	}
	return new_number;
}

std::string ToEight(long long int decimal) { // Переводит число в восьмеричную сс
	std::string new_number = "";
	char nums[8] = { '0', '1', '2', '3' ,'4' , '5', '6' ,'7' };
	if (decimal == 0) {
		return "0";
	}
	while (decimal > 0) {
		new_number = nums[decimal % 8] + new_number;
		decimal /= 8;
	}
	return new_number;
}

int main(){
	long long int decimal_number = 0; // Число в десятичной сс, которое может быть очень большим
	int base = 0; // сс в которую переведёт прога
	std::string answer = "";
	while (decimal_number == 0) { // Проверяет изменилось ли число после ввода. Если нет то ввод надо повторить
		std::cout << "Enter your decimal number (not higher than 10^18): ";
		std::cin >> decimal_number;
		// Защита от "дурака"
		if (!std::cin) { // Если ввод не удался (по каким-то причинам)
			std::cin.clear(); // Мы сбрасываем поле для ввода
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Мы вычёркиваем полученные данные дабы они не навернули программу.
		}
	}
	while (base != 8 and base != 16) {
		std::cout << "Now, enter base you would like to convert your number in (8 or 16): ";
		std::cin >> base;
		// Защита от "дурака"
		if (!std::cin) { // Если ввод не удался (по каким-то причинам)
			std::cin.clear(); // Мы сбрасываем поле для ввода
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Мы вычёркиваем полученные данные дабы они не навернули программу.
		}
		if (base == 8) {
			answer = ToEight(decimal_number);
		}
		if (base == 16) {
			answer = ToSixteen(decimal_number);
		}
	}
	std::cout << "The number " << decimal_number << " in " << base << " numeral system is: " << answer << std::endl;
	return 0;
}