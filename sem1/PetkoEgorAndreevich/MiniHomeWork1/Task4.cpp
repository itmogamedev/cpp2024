#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main() // оп переварачиваем
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите число которое хотите перевернуть" << endl;
    int cat;
    int dog = 0;
    cin >> cat;
    while (cat > 0) { // цикл считает пока коты уйдут
        dog *= 10; // умножаем на 10
        dog += cat % 10; // добавляем остаток от деления кота
        cat /= 10; // делим кота
    }
    cout << dog; // вот и собака 
}
