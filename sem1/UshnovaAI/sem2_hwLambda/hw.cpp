#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>

int main() {
    std::vector<std::string> strings = { "lambda", "expression" };

    auto getLengthsMap = [](const std::vector<std::string>& vec) {
        std::map<std::string, size_t> strLengthMap;
        for (const auto& s : vec) {
            strLengthMap[s] = s.size();
        }
        return strLengthMap;
    };

    auto lengthMap = getLengthsMap(strings);
    for (const auto& [str, len] : lengthMap) {
        std::cout << str << ": " << len << std::endl;
    }

    return 0;
}