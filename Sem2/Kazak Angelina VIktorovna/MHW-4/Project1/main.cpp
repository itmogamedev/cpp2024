#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");
    std::vector<std::string> strings = { "Hello", "world", "C++", "lambda", "expression" };

    auto countChars = [](const std::vector<std::string>& vec) {
        std::vector<size_t> counts;
        for (const auto& str : vec) {
            counts.push_back(str.size());
        }
        return counts;
        };

    std::vector<size_t> charCounts = countChars(strings);

    std::cout << "Количество символов в каждой строке:\n";
    for (size_t i = 0; i < strings.size(); ++i) {
        std::cout << "\"" << strings[i] << "\": " << charCounts[i] << " символов\n";
    }

    return 0;
}