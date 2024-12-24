#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Функция для преобразования десятичного числа в шестнадцатеричное
string tenTosixteen(int num) {
    string result = "";
    while (num > 0) {
        if (num % 16 < 10) {
            result += to_string(num % 16);
        } else {
            result += (char)(num % 16 + 'A' - 10);
        }
        num /= 16;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Функция для преобразования десятичного числа в восьмеричное
string tenToeight(int num) {
    string result = "";
    while (num > 0) {
        result += to_string(num % 8);
        num /= 8;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    int num;
    std::cout << "Enter number" << endl;
    std::cin >> num;
    tenTosixteen(num);
    tenToeight(num);
    std::cout << "Hex number: " << tenTosixteen(num) << endl;
    std::cout << "Oct number: " << tenToeight(num) << endl;
    return 0;
}