#include <iostream>

int reverse(int n) {
    int rev = 0;
	
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }

    return rev;
}

int main()
{
    int n;
    std::cout << "введите ваше число: ";
    std::cin >> n;
    std::cout << "перевернутое: " << reverse(n);
}