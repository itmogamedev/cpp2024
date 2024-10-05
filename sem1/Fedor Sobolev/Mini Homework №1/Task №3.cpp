
#include <iostream>
using std::cout;
using std::cin;

int main()
{
    setlocale(LC_ALL, "Russian");
    int firstnumber = 0, secondnumber = 1, thirdnumber, amount, counter = 0;
    cout << "Введите количество элементов числа Фибоначчи:";
    cin >> amount;
    cout << firstnumber << " " << secondnumber << " ";
    for (counter; amount - 1 > counter; ++counter) {
        thirdnumber = firstnumber + secondnumber;
        firstnumber = secondnumber;
        secondnumber = thirdnumber;
        cout << thirdnumber << " ";
    }
}
