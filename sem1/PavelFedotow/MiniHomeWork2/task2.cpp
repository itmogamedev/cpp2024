#include <iostream>

bool hypotesisChecker(int value) {
	int number = value;
	while (number > 1) {
		if (number % 2 == 0) {
			std::cout << number << " - чётное число. Делим на 2" << std::endl;
			number = number / 2;
		}
		else {
			std::cout << number << " - нечётное число. Умножаем на 3, прибавляем единицу и делим на 2" << std::endl;
			number = (number * 3 + 1) / 2;
		}
	}

	std::cout << "Конечное число: " << number << std::endl;

	if (number == 1) {
		std::cout << "Гипотеза Сиракуза работает для числа " << value;
	}
	else {
		std::cout << "Гипотеза Сиракуза не работает для числа " << value;
	}

	return number == 1;
}

void clear_screen() {
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}

int main() {
	setlocale(LC_ALL, "Russian");

	bool isWorking = true;


	while (isWorking) {
		std::cout << "Программа проверки гипотезы Сиракуза" << std::endl;
		std::cout << "Введите любое натуральное число, которое хотите проверить на соответствие гипотезе: ";

		int chosenNumber;
		std::cin >> chosenNumber;

		if (std::cin.fail()) {
			std::cout << "Ошибка, введено неверное значение для натурального числа" << std::endl;
			std::cout << "Нажмите enter, чтобы продолжить";
			std::cin.clear();
			std::cin.ignore(2, '\n');
			std::cin.get();
			clear_screen();
			continue;
		}

		if (chosenNumber < 1) {
			std::cout << "Ошибка, число не натуральное. Попробуйте снова." << std::endl;
			std::cin.ignore(100, '\n');
			std::cout << "Нажмите enter, чтобы продолжить";
			std::cin.get();
			clear_screen();
		}
		else {
			hypotesisChecker(chosenNumber);
			isWorking = false;
			std::cin.get();
		}
	}

}