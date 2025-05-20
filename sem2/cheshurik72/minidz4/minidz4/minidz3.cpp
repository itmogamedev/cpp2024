#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> strings = { "ikona greha", "pupok", "ragazza", "steam"};
    std::vector<size_t> lengths;
    std::for_each(strings.begin(), strings.end(), [&](const std::string& s) {
        lengths.push_back(s.length());
        });

    for (size_t len : lengths) {
        std::cout << len << " ";
    }
    std::cout << std::endl;

    return 0;
}

