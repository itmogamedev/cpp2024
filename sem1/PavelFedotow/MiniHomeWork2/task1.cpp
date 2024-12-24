#include <iostream>

void clear_screen() {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

char* to_base_n(int chosenNumber, int base) {

    int tempNumber = chosenNumber;
    int length = 0;
    while (tempNumber > 0) {
        tempNumber /= base;
        length++;
    }

    char* finalNumber = new char[length + 1];
    finalNumber[length] = '\0';

    tempNumber = chosenNumber;
    for (int i = length - 1; i >= 0; i--) {
        const int digit = tempNumber % base;
        tempNumber /= base;
        if (digit < 10)
            finalNumber[i] = '0' + digit;
        else
            finalNumber[i] = 'A' + digit - 10;
    }

    return finalNumber;
}


void menu() {
    setlocale(LC_ALL, "Russian");

    bool isWorking = true;
    while (isWorking) {
        int chosenOption;
        clear_screen();
        std::cout << "Добро пожаловать в мега преобразователь 2015\nВ какую систему счисления вы хотите перевести число?\
           \n1 - шестнадцатиричная система\n2 - восьмиричная система\n3 - ни в какую! Дайте выйти из программы!\n\nВаш вариант: ";
        std::cin >> chosenOption;
        clear_screen();

        if (std::cin.fail()) {
            std::cout << "Я вижу ты еще новичок, я попросил у тебя ввести цифу, а ты ввел букву. Цифры находятся сверху от букв, больше не ошибайся" << std::endl;
            std::cin.clear();
            std::cin.ignore(2, '\n');
            std::cin.get();
            chosenOption = -1;
            continue;
        }


        int x;
        switch (chosenOption) {
        case 1:
            std::cout << "Введите число, которое надо преобразовать: ";
            std::cin >> x;
            std::cout << "Ваше число в шестнадцатиричной системе: " << to_base_n(x, 16) << std::endl;
            std::cin.ignore(1, '\n'); std::cin.get();
            break;
        case 2:
            std::cout << "Введите число, которое надо преобразовать: ";
            std::cin >> x;
            std::cout << "Ваше число в восьмиричной системе: " << to_base_n(x, 8) << std::endl;
            std::cin.ignore(1, '\n'); std::cin.get();
            break;
        case 3:
            std::cout << "Ну ладно, пока";
            std::cin.ignore(1, '\n'); std::cin.get();
            isWorking = false;
            break;
        default:
            std::cout << "Введена неверная комманда, попробуйте еще раз" << std::endl;
            std::cin.ignore(1, '\n'); std::cin.get();

            break;
        }
    }

    return;
}

int main()
{
    

    menu();
}