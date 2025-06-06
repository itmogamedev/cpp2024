#include <iostream>
#include <vector>
#include "HW_DLL.h"

int main() {
    std::vector<float> a{ 8, 6, 4, 7, 3, 1 };

    std::cout << median(a.data(), a.size());
}