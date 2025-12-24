#include <iostream>
#include <sstream>
#include <vector>
#include "StatisticLib.h"  // Подключаем заголовочный файл нашей библиотеки

int main()
{
    std::cout << "Введите числа, разделенные пробелами: ";
    std::string input;
    std::getline(std::cin, input);

    std::istringstream iss(input);
    double number;
    std::vector<double> numbers;

    // Считываем числа из строки
    while (iss >> number)
    {
        numbers.push_back(number);
    }

    if (numbers.empty())
    {
        std::cout << "Вы не ввели ни одного числа." << std::endl;
        return 0;
    }

    int count = static_cast<int>(numbers.size());
    double* data = numbers.data();

    double average = CalculateAverage(data, count);
    double median = CalculateMedian(data, count);
    double rms = CalculateRMS(data, count);
    double variance = CalculateVariance(data, count);

    std::cout << "Среднее арифметическое: " << average << std::endl;
    std::cout << "Медиана: " << median << std::endl;
    std::cout << "Среднее квадратическое: " << rms << std::endl;
    std::cout << "Дисперсия: " << variance << std::endl;

    return 0;
}