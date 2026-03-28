#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {

    std::vector<std::string> inp = { "Hello", " Konstantin ", "Kondykov"};
    std::vector<int> len;

    std::transform(inp.begin(), inp.end(), std::back_inserter(len),[] (const std::string& i) {return i.size();});

    for (int i : len) {
        std::cout << i << std::endl;
    }
}