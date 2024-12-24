#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Russian");
    double a; 
    double b; 
    double h;
    
    cout << "Введите нижнюю сторону: ";
    cin >> a;
    cout << "Введите верхнюю сторону: ";
    cin >> b;
    cout << "Введите высоту: ";
    cin >> h;

    double area = (a + b) / 2 * h;

    cout << "Площадь трапеции: " << area << endl;

    return 0;
}