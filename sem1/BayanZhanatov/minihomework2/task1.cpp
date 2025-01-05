#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main() {
    setlocale(LC_ALL, "Russian");
    int a;

    cout << "Ќапишите число в дес€тичной системе исчислени€ и программа переведЄт его в восьмеричную и шестнадцатиричную системы исчислени€." << endl;
    cin >> a;

    cout << "„исло в восьмеричной системе исчислени€: ";
    cout << std::oct << a << endl;

    cout << "„исло в шестнадцатиричной системе исчислени€: ";
    cout << std::hex << a << endl;
}