#include <iostream>

int reverseNumber(int number) {
    int reverse = 0, remainder;

    while (number != 0)
    {
        remainder = number % 10;
        reverse = reverse * 10 + remainder;
        number /= 10;
    };

	return reverse;
}

int main() {
    int n;
    std::cin >> n;
    std::cout << reverseNumber(n);
    return 0;
}