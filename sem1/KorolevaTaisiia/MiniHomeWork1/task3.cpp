#include <iostream>

/*Вывести на экран ряд чисел Фибоначчи,
состоящий из N элементов.
Значение N вводится пользователем с клавиатуры.
*/



void fibbonacci_print(int n) {
    long long cur_num = 1;
    long long prev_num = 0;
    if (n > 0) {
        std::cout << prev_num << " ";
    }
    if (n > 1) {
        std::cout << cur_num << " ";
    }
    for (int i = 2; i < n; ++i) {
        prev_num += cur_num;
        std::cout << prev_num << " ";
        std::swap(prev_num,
                  cur_num);
    }
}

int main() {
    int n;
    std::cout << "Enter how many Fibonacci numbers do you want to see \n";
    std::cin >> n;
    //std::cout << '\n';
    fibbonacci_print(n);
    return 0;
}
