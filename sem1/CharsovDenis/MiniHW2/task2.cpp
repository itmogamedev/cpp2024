#include <iostream>
#include <Windows.h>


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


int setUserSelect() {
	int userSelect{};
	std::cout << "Введите номер соответсвтующей команде:\n" << "1 -- Проверить теорию Сиракуз\n"
		<< "2 -- Выйти из программы\n" << "Ваш выбор: ";
	std::cin >> userSelect;

	return userSelect;
}


int setUserNumber() {
	int userNumber{};
	std::cout << "Введите натуральное число, на котором хотите проверить теорию Сиракуз: ";
	std::cin >> userNumber;

	return userNumber;
}


std::string startProgramm() {
	int userNumber{};

	while (true) {
		int userSelect{ setUserSelect() };

		switch (userSelect)
		{
			case 1:
				userNumber = setUserNumber();

				if (userNumber < 1) {
					std::cout << "------------------------------------------------------------------\n";
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
					std::cout << "Вы ввели ненатуральное число, постарайтесь еще раз!\n\n";
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
					break;
				}

				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
				std::cout << "Вычисления:\n";
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

				while (userNumber != 1) {
					if (userNumber % 2 == 0) {
						std::cout << "Четное: " << userNumber << " / 2 = ";
						userNumber /= 2;
						std::cout << userNumber << "\n";
					}
					else {
						std::cout << "Нечетное: (" << userNumber << " * 3 + 1) / 2 = ";
						userNumber = (userNumber * 3 + 1) / 2;
						std::cout << userNumber << "\n";
					}
				}

				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				return "Теория верна, мы получили 1";
				break;

			case 2:
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				return "Вы успешно вышли из программы!";
				break;

			default:
				std::cout << "------------------------------------------------------------------\n";
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				std::cout << "Введена неверная команда, попробуйте ещё!\n\n";
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << startProgramm();
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	return 0;
}
