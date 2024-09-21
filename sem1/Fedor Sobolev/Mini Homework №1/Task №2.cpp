
#include <iostream>
using std::cout;
using std::cin;

int main()
{
    setlocale(LC_ALL, "Russian");
    int firstbaseofatrapezoid, secondbaseofatrapezoid, heightoftrapezoid;
    cout << "Введите длину первого основании трапеции:";
    cin >> firstbaseofatrapezoid;
    cout << "Введите длину второго основании трапеции:";
    cin >> secondbaseofatrapezoid;
    cout << "Введите длину высоты трапеции:";
    cin >> heightoftrapezoid;
    cout << (firstbaseofatrapezoid * secondbaseofatrapezoid) / 2 * heightoftrapezoid;
}