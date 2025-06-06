#include <iostream>
#include <vector>
#include <string>

int main () {
    std::vector<std::string> strings = {"SUMO TATAMI RULIT", "P", "PP", "JUST DO IT", "PLOT"};
    auto getL = [](std::vector<std::string>& ss)-> std::vector<int> {
        std::vector<int> lengths;
        for (int i = 0; i < ss.size(); i++){
            lengths.push_back(ss[i].length());
        }
        return lengths;
    };

    std::vector<int> lengths = getL(strings);
    for (int i = 0; i < lengths.size();i++) {
        std::cout << lengths[i] << " ";
    }
}