#include <iostream>
#include "../THIS_LIBRARIE_IS_AWESOME/math_funcs.h"
#include<string>

int main()
{
    setlocale(LC_ALL, "Russian");

    std::vector<float> vec = {};
    int len;

    std::cout << "введите длину списка: ";
    std::cin >> len;

    for (int i = 0; i < len; i++) {
        std::cout << "введите элемент: ";
        float el;
        std::cin >> el;

        vec.push_back(el);
    }

    std::cout << std::endl;

    std::cout << "среднее арифметическое: " << ArithmeticMean(vec) << std::endl;
    std::cout << "медиана: " << Median(vec) << std::endl;
    std::cout << "среднее квадратическое: " << RootMeanSquare(vec) << std::endl;
    std::cout << "дисперсия: " << Variance(vec) << std::endl;

    std::cout << std::endl << "ах, как хорошо что у меня есть целая прекрастная библиотека чтоб всё это считать!" << std::endl;
}
