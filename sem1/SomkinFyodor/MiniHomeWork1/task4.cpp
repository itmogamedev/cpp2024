#include <iostream>


int Preobrosovatel(int chislo) {
    int newchislo = 0;
    while (chislo > 0) {
        newchislo = newchislo * 10 + chislo % 10;
        chislo /= 10;
    }
    return newchislo;
}

int main()
{
    int chislo, newchislo;
    std::cin >> chislo;
    newchislo = Preobrosovatel(chislo);
    std::cout << newchislo;
}

