#include <string>
#include <cassert>

std::string ConvertDecimalNumber(int decimal_number, const int radix) {
    std::string result;

    if (decimal_number < 0 || radix < 2 || radix > 16) {return result;}

    while(decimal_number > 0) {
        const int remainder = decimal_number % radix;
        result = ((remainder < 10) ? char('0' + remainder) : char('A' + (remainder - 10))) + result;
        decimal_number /= radix;
    }

    return result;
}

void Test() {
    assert(ConvertDecimalNumber(670, 8) == "1236");
    assert(ConvertDecimalNumber(144, 8) == "220");
    assert(ConvertDecimalNumber(47, 8) == "57");

    assert(ConvertDecimalNumber(619, 16) == "26B");
    assert(ConvertDecimalNumber(934, 16) == "3A6");
    assert(ConvertDecimalNumber(9999, 16) == "270F");

    assert(ConvertDecimalNumber(-1, 16).empty());
    assert(ConvertDecimalNumber(229, 1).empty());
    assert(ConvertDecimalNumber(112, 17).empty());
}

int main() {
    Test();
}