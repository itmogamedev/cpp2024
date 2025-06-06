#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "windows.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    std::vector<std::string> strings = {"Sumo", "Tatami", "when is", "the release?"};
    std::vector<std::pair<std::string, size_t>> result;
    result.reserve(strings.size());

    std::transform(strings.begin(), strings.end(), std::back_inserter(result),
                   [](const std::string& s) {
                       return std::make_pair(s, s.size());
                   });

    std::sort(result.begin(), result.end(),
              [](const auto& a, const auto& b) {
                  return a.second < b.second;
              });

    for (const auto& [str, len] : result) std::cout << "\"" << str << "\" состоит из " << len << " символов\n";
}