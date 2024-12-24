#include <iostream>

/*Task2: Проверить гипотезу Сиракуз, также известную как гипотеза Коллатца.*/
/*Для визуальной проверки данной гипотезы напишем программу, которая будет выводить сиракузскую последовательность
 * заданного пользователем числа*/

#include <string>
#include <algorithm>
#include <vector>

long long collatz_function(const long long num) {
    if (num % 2 == 0) {
        return num / 2;
    } else {
        return num * 3 + 1;
    }
}

void collatz_conjecture(const long long num, std::vector<long long> &conjecture) {
    long long num_cp = num;
    while (num_cp != 1) {
        conjecture.push_back(num_cp);
        num_cp = collatz_function(num_cp);
    }
    conjecture.push_back(num_cp); // will be 1
}

int main() {
    long long num;
    std::cout << "Enter a beginning number for your collatz conjecture \n";
    std::cin >> num;
    std::vector <long long> conjecture;
    collatz_conjecture(num, conjecture);
    for (auto i: conjecture) {
        std::cout << i << ' ';
    }
    return 0;
}
