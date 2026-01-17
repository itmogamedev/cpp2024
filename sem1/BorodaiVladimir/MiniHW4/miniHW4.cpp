
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> strings = { "SumoTatami", "c++", "HelloWorld", "LambdaFunction" };

    for (const auto& str : strings) {
        auto length = [](const std::string& s) { return s.length(); }(str);
        std::cout << length << " ";
    }
    std::cout << std::endl;

    return 0;
}