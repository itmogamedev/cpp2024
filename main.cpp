#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> well = {"wellll", "wl", "wellwellwell", "nu-nu"};

    std::vector<size_t> lengths;
    std::transform(well.begin(), well.end(), std::back_inserter(lengths),
                   [](const std::string& w) { return w.size(); });

    for (size_t len : lengths) {
        std::cout << len << " ";
    }

    return 0;
}
