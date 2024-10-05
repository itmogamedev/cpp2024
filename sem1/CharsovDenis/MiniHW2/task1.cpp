#include <iostream>
#include <string>
#include <Windows.h>

HANDLE hConsole{GetStdHandle(STD_OUTPUT_HANDLE)};

int setChoiceMenuion() {
	std::cout << "Введите выбор операции:\n" << "1 -- Перевод в восьмиричную систему\n"
		<< "2 -- Перевод в шестнадцатиричную систему\n" << "3 -- Выход из программы\n"
		<< "Ваш выбор: ";
	int choiceMenu{};
	std::cin >> choiceMenu;

	return choiceMenu;
}


int setUserDecimalNum() {
	std::cout << "Введите десятичное число > 0, которое хотите перевести в 8-чную или 16-чную системы: ";
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
		int choiceMenu{ setChoiceMenuion() };

		switch (choiceMenu)
		{
			case 1:
				userDecimalNum = setUserDecimalNum();

				if (userDecimalNum < 0) {
					std::cout << "-------------------------------------------------------------------\n";
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Вы ввели не число < 0, постарайтесь ещё!\n\n";
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					break;
				}
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				std::cout << "\nРезультат перевода: ";
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

				return decimalToOct(userDecimalNum);
				break;

			case 2:
				userDecimalNum = setUserDecimalNum();

				if (userDecimalNum < 0) {
					std::cout << "-------------------------------------------------------------------\n";
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Вы ввели не число < 0, постарайтесь ещё!\n\n";
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
					break;
				}
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				std::cout << "\nРезультат перевода: ";
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
				return decimalToHex(userDecimalNum);
				break;

			case 3:
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				return "Вы решили выйти из программы, всего хорошего!";
				break;

			default:
				std::cout << "-------------------------------------------------------------------\n";
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Неверный выбор операции, введите число, соответсвующее числу операции!\n\n";
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << startProgramm();
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
}
