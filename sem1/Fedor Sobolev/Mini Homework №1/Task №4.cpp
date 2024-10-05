
#include <iostream>
using std::cout;
using std::cin;

int main()
{
    setlocale(LC_ALL, "Russian");
    int firstnumber = 0, secondnumber = 0;
    cout << "Введите число:";
    cin >> firstnumber;
    while (firstnumber > 0) {
        secondnumber *= 10;
        secondnumber += firstnumber % 10;
        firstnumber /= 10;
    }
    cout << secondnumber;
}
