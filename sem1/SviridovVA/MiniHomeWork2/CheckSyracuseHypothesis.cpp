#include <iostream>
#include <chrono>

bool CheckSyracuseHypothesis(int number) {
    const auto start{std::chrono::steady_clock::now()};

    while (number != 1) {
        const std::chrono::duration<double> elapsed_seconds{std::chrono::steady_clock::now() - start};

        if (elapsed_seconds.count() > 5) {return false;}

        number = (number % 2 == 0) ? (number / 2) : (((number * 3) + 1) / 2);
    }

    return true;
}


void Test(int number) {
    if (number <= 0) {
        std::cout << "Incorrect number " << '\n';
        return;
    }

    if (CheckSyracuseHypothesis(number)) {
        std::cout << "The hypothesis is CORRECT for " << number << '\n';
    } else {
        std::cout << "The hypothesis is INCORRECT for " << number << '\n';
    }
}

void Test(int begin, int end) {
    if (begin <= 0 || end <= 0 || (begin > end)) {
        std::cout << "Incorrect number range" << '\n';
        return;
    }

    for (int number = begin; number <= end; ++number) {
        if (CheckSyracuseHypothesis(number)) {
            std::cout << "The hypothesis is CORRECT for " << number << '\n';
        } else {
            std::cout << "The hypothesis is INCORRECT for " << number << '\n';
        }
    }
}

int main() {
    Test(1000000);
    Test(1, 10000);
}
