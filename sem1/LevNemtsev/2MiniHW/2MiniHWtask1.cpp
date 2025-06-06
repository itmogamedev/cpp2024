#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::oct;
using std::hex;

void printHexadecimal(int number) 
{
    cout << "Шестнадцатеричное представление: " << hex << number << endl;
}

void printOctal(int number) 
{
    cout << "Восьмеричное представление: " << oct << number << endl;
}

int main() 
{
    int number;
    cout << "Введите число: ";
    cin >> number;

    printHexadecimal(number);
    printOctal(number);

    return 0;
}
