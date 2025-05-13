#include <iostream>
#include <vector>
#include <string>

int main () {
    std::vector<std::string> strings = {"Hello", "I", "Can","Use", "Lambda", "Yeeee!!!11"};
    auto getStringLengths = [](const std::vector<std::string>& strs)-> std::vector<std::size_t> {
        std::vector<size_t> lengths;
        for (const std::string& s : strs) {
            lengths.push_back(s.size());
        }
        return lengths;
    };

    std::vector<size_t> lengths = getStringLengths(strings);
    for (size_t len : lengths) {
        std::cout << len << " ";
    }
}