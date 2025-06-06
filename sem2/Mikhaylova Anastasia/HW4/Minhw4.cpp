#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> strings = { "apple", "banana", "cherry" };
    std::vector<size_t> lengths;
    auto countChars = [](const std::string& str) { return str.size(); };
    for (const auto& str : strings) {
        lengths.push_back(countChars(str));
    }
    for (const auto& l : lengths) {
        std::cout << l << std::endl;
    }

    return 0;
}
