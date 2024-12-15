#include <iostream>


void numTo16(int num) {
    char a[] = "0123456789ABCDEF";
    char result[32];
    int index = 0;
    int oldNum = num;

    if (num == 0) {
        std::cout << "0" << std::endl;
        return;
    }

    while (num > 0) {
        result[index++] = a[num % 16];
        num /= 16;
    }

    std::cout << "Число " << oldNum << " в шестнадцатеричной сс: ";
    for (int i = index - 1; i >= 0; i--) {
        std::cout << result[i];
    }
    std::cout << std::endl;
    return;
}


void numTo8(int num) {
    char result[32];
    int index = 0;
    int oldNum = num;

    if (num == 0) {
        std::cout << "0" << std::endl;
        return;
    }

    while (num > 0) {
        result[index++] = (num % 8) + '0';
        num /= 8;
    }

    std::cout << "Число " << oldNum << " в восьмеричной сс: ";
    for (int i = index - 1; i >= 0; i--) {
        std::cout << result[i];
    }
    std::cout << std::endl;
    return;
}


int main() {
    int choice, num;

    do {
        std::cout << "Меню преобразования:\n";
        std::cout << "1. Преобразовать в шестнадцатеричную систему\n";
        std::cout << "2. Преобразовать в восьмеричную систему\n";
        std::cout << "3. Выйти\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        if (choice == 3) {
            std::cout << "Выход из программы." << std::endl;
            break;
        }

        std::cout << "Введите десятичное число: ";
        std::cin >> num;

        switch (choice) {
            case 1:
                numTo16(num);
                break;
            case 2:
                numTo8(num);
                break;
            default:
                std::cout << "Неверный выбор, попробуйте снова." << std::endl;
        }

        std::cout << std::endl;
    } while (choice != 3);

    return 0;
}
