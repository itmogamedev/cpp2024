#include <iostream>
#include "readyFunctions.hpp"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Добро пожаловать на самый продвинутый агрегатор поступления в вузы 2025! :з" << '\n';

    std::cout << "Введите число абитуриентов: ";
    int n;
    std::cin >> n;
    std::vector<double> numbers(n);

    std::cout << "Введите кол-во баллов каждого абитуриента: ";
    for (int i = 0; i < n; i++) std::cin >> numbers[i];
    std::cout << "Для вывода максимально подробной статистики нажмите Enter: ";
    std::cin.ignore();
    std::cin.get();

    std::cout << "Среднее арифметическое баллов: " << arithmeticMean(numbers) << '\n';
    std::cout << "Медиана баллов: " << median(numbers) << '\n';
    std::cout << "Среднее квадратическое значение баллов: " << averageSquareValue(numbers) << '\n';
    std::cout << "Дисперсия баллов: " << dispersion(numbers) << '\n' << '\n';

    std::cout << "Поверьте, это самая полезная информация, которая поможет вам выбрать университет! :)" << '\n';

}
