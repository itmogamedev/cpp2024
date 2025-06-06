#include <cassert>

int ReverseNumber(int number) {
    int reverse_number = 0;

    while (number > 0) {
        reverse_number = reverse_number * 10 + number % 10;
        number /= 10;
    }

    return reverse_number;
}

void Test() {
    assert(ReverseNumber(1234) == 4321);
    assert(ReverseNumber(1002) == 2001);
    assert(ReverseNumber(2000) == 2);
}

int main() {
    Test();
}
