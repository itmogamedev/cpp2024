#include <iostream>
#include <string>


int setUserSelection() {
	std::cout << "Введите выбор операции:\n" << "1 -- Перевод в восьмиричную систему\n"
		<< "2 -- Перевод в шестнадцатиричную систему\n" << "3 -- Выход из программы\n"
		<< "Ваш выбор : ";
	int choiceMenu{};
	std::cin >> choiceMenu;

	return choiceMenu;
}


int setUserDecimalNum() {
	std::cout << "Введите десятичное натуральное число, которое хотите перевести в 8-чную или 16-чную системы: ";
	int userDecimalNum{};
	std::cin >> userDecimalNum;

	return userDecimalNum;
}


std::string decimalToOct(int userDecimalNum) {
	std::string strOctalNum{};

	while (userDecimalNum != 0) {
		strOctalNum = std::to_string(userDecimalNum % 8) + strOctalNum;
		userDecimalNum /= 8;
	}

	return strOctalNum;
}


std::string decimalToHex(int userDecimalNum) {
	std::string strHexNum{};

	char arrayHex[]{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	while (userDecimalNum != 0) {
		strHexNum = arrayHex[userDecimalNum % 16] + strHexNum;
		userDecimalNum /= 16;
	}
	return strHexNum;
}


std::string startProgramm() {
	int userDecimalNum{};

	while (true) {
		int choiceMenu{ setUserSelection() };

		switch (choiceMenu)
		{
			case 1:
				userDecimalNum = setUserDecimalNum();

				if (userDecimalNum < 0) {
					std::cout << "Вы ввели не натуральное число, постарайтесь ещё!\n";
					break;
				}

				std::cout << "\nРезультат перевода: ";

				return decimalToOct(userDecimalNum);
				break;

			case 2:
				userDecimalNum = setUserDecimalNum();

				if (userDecimalNum < 0) {
					std::cout << "-------------------------------------------------------------------\n" 
						<< "Вы ввели не натуральное число, постарайтесь ещё!\n\n";
					break;
				}

				std::cout << "\nРезультат перевода: ";

				return decimalToHex(userDecimalNum);
				break;

			case 3:
				return "Вы решили выйти из программы, всего хорошего!";
				break;

			default:
				std::cout << "-------------------------------------------------------------------\n"
					<< "Неверный выбор операции, введите число, соответсвующее числу операции!\n\n";
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << startProgramm();
}
