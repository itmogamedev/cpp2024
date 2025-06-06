// SEM2HW1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <HWDLL.h>
#include <vector>

using std::vector; 
using std::cout;
using std::endl;

int main()
{
    vector <double> numbers = { 2.1, 3, 5, 15.2, 7 };
    cout << "AVERAGE: " << Average(numbers) << endl;
    cout << "MEDIAN: " << Median(numbers) << endl;
    cout << "AVERAGESQR: " << AverageSqr(numbers) << endl;
    cout << "DISPERSION: " << Dispersion(numbers) << endl;
}

