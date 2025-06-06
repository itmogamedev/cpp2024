#include <iostream>

int Sirakuza(unsigned long long int i) {
    while (i != 1) {
        if (i % 2 == 0) {
            i /= 2;
        }

        else {
            i = (i * 3 + 1) / 2;
        }

    }
    return i;
}
int main()
{
    std::cout << "Write a number more than zero\n";
    unsigned long long int i;
    std::cin >> i;
    std::cout << Sirakuza(i);
}