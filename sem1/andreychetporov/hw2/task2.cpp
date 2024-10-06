

#include <iostream>

int main()
{
    int n;
    setlocale(LC_ALL, "RU");
    for (int i = 2; i < 100000; i++) {
        n = i;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= n;
            }
            else {
                n = (3 * n + 1) / 2;
            }
            if (n == 1) {
                std::cout << "число " << i << " удовлетворяет гипотезе Сиракуза"<<"\n";
            }

        }




    }
    std::cout << "первые 100000 натуральных чисел удовлетворяют гипотезе Сиракуза";
}

