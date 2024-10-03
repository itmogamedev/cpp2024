
#include <iostream>
int input = 0;
int k = 0;
int length = 0;
int last_number = 0;
int result = 0;

int numbers(int a) {
    while (a > 0) {
        a = a / 10;
        k = k + 1;
    }
    return k;
}
int main()
{
    std::cin >> input;
    length = numbers(input);
    while (input > 0) {
        last_number = input % 10;
        result = result + (last_number * pow(10, length - 1));
        input = input / 10;
        length = length - 1;
    }
    std::cout << result;
}