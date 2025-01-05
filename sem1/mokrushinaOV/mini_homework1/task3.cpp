#include <iostream>


void fibonacci(int num_left, unsigned long int previous_previous = 0, unsigned long int previous = 1) {

    if (previous_previous == 0) {
        num_left -= 2;
        std::cout << previous_previous << " " << previous << " ";
    }

    unsigned long int this_one = previous_previous + previous;
    num_left--;
    std::cout << this_one << " ";

    if (num_left == 0) {
        return;
    }
    return fibonacci(num_left, previous, this_one);
}

int main()
{
    int num_count;
    std::cout << "set Fibonacci sequence length: ";
    std::cin >> num_count;
    fibonacci(num_count);
}