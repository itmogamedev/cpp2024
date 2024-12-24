#include <iostream>

int main() {
    int nmbr;
    int rvrsdNmbr = 0;

    std::cout << "Enter a number to reverse: ";
    std::cin >> nmbr;

    while (nmbr != 0)
    {
        rvrsdNmbr *= 10;
        rvrsdNmbr += nmbr % 10;
        nmbr /= 10;
    }

    std::cout << rvrsdNmbr;

} 
