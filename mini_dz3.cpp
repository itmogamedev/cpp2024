#include <iostream>
#include <vector>
#include <string>
#include <functional>

int main() {
    std::vector<std::string> lines = {
        "Minecraft film",
        "KRK the best",
        "15 symbols",
        "sumoT"
    };

    std::function<std::vector<int>(const std::vector<std::string>&)> countSymbols =
        [](const std::vector<std::string>& vec) {
        std::vector<int> result;
        for (const auto& str : vec) {
            result.push_back(str.length());
        }
        return result;
        };

    std::vector<int> lengths = countSymbols(lines);

    for (int len : lengths) {
        std::cout << len << std::endl;
    }

    return 0;

}