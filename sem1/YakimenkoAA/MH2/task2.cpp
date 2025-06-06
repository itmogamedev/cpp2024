#include <iostream>

int HypSyrakuz(int Nnumber);

int main() {
    int Nnumber;
    std::cout << "Enter Natural number:";
    std::cin >> Nnumber;
    std::cout << HypSyrakuz(Nnumber);
    return 0;
}

int HypSyrakuz(int Nnumber) {
    while (Nnumber != 1) {
        if (Nnumber % 2 == 0) {
            Nnumber = Nnumber / 2;
        }
        else {
            Nnumber = Nnumber * 3 + 1;
        }
    }
    return Nnumber;
}
/// Гипотеза работает для любых Nnumber >= 1