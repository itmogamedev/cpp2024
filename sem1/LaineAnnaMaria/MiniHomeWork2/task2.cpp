#include <iostream>

bool CheckHypothesis(int number) {
    while (number != 1) {
        number = (number % 2 == 0) ? number / 2 : (number * 3 + 1) / 2;
    }

    return number == 1;
}

int main() {
    std::cout
        << "Enter interval:"
        << "\n";

    int begin, end;
    std::cin >> begin >> end;

    if (begin > end) { return 1; }

    bool hypothesis = true;
    for (int i = begin; i <= end && hypothesis; ++i) {
        hypothesis = CheckHypothesis(i);
    }

    if (hypothesis) {
        std::cout << "The Syracuse hypothesis is CORRECT for this interval" << '\n';
    }
    else {
        std::cout << "The Syracuse hypothesis is INCORRECT for this interval" << '\n';
    }
}