#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> strings = { "i", "prosto", "hoteti", "pospaty" };

    auto getLengths = [](const std::vector<std::string>& vec) {

        std::vector<size_t> leng;

        for (const auto& str : vec) 

        {
            leng.push_back(str.size());
        }

        return leng;
        };

    std::vector<size_t> lengths = getLengths(strings);

    for (auto leng : lengths)

    {
        std::cout << leng << std::endl;
    }

    return 0;
}