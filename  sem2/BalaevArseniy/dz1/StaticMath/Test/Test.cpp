

#include <iostream>
#include "Header.h"
#include <vector>

int main()
{
    double a = 7.4;
    int b = 99;
    std::vector<double> data = { 5,3,4,10,-11};
    setlocale(LC_ALL, "Russian");
    std::cout <<"Среднее арefм.: " <<MathLibrary::Arithmetic::Avg(data) << std::endl;
    std::cout << "Медиан: " <<MathLibrary::Arithmetic::MED(data) << std::endl;
    std::cout <<"Среднее геом.: " << MathLibrary::Arithmetic::RMS(data) << std::endl;
    std::cout << "Дисперсия: " << MathLibrary::Arithmetic::Disp(data) << std::endl;
    return 0;
}
