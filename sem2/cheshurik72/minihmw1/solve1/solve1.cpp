#include <iostream>
#include <Windows.h>
#include <locale.h>
#include "math.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    vector<float> data = { 9, 22, 52, 79, 97, 111, 228, 343 };

    cout << "Среднее арифметическое: " << arm(data) << endl;
    cout << "Медиана: " << med(data) << endl;
    cout << "Среднее квадратическое: " << dsp(data) << endl;
    cout << "Дисперсия: " << sq(data) << endl;

    return 0;
}