#include <iostream>

int main() {
    std::cout << "Enter natural number - ";
    int Nat_N;
    std::cin >> Nat_N;

    int res = Nat_N;
    while (res != 1) {
        std::cout << res << " ";  // Вывод текущего значения каждой итерации
        if (res % 2 == 0) {       // Если число четное
            res /= 2;
        }
        else {                    // Если число нечетное
            res = res * 3 + 1;  
        }
    }
    std::cout << res << std::endl;  // Вывод последнего значения, равного 1

    return 0;
}