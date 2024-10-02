#include <iostream>

void hypotiz(int n) {
    if (n <= 0) {
        std::cout << "Vvedite polozitelnoe chislo." << std::endl;
        return;
    }

    std::cout << "Posledovatlnost' dlya chisla " << n << ": ";
    
    while (n != 1) {
        std::cout << n << " ";
        if (n % 2 == 0) {
            n /= 2; // if chetnoe
        } else {
            n = 3 * n + 1; // if nechetnoe
        }
    }
    std::cout << n << std::endl; // vivodim chislo
}

int main() {
    int nmbr;

    std::cout << "Vvedite polozitelnoe chislo: ";
    std::cin >> nmbr;

    hypotiz(nmbr);

    return 0;
}