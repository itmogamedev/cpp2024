#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> strings = { "Hello", "C++", "Lambda", "Function" };

    auto countChars = [](const std::string& str) {return str.size(); };

    for (auto str : strings) {
        std::cout << str << " - " << countChars(str) << " Symbol\n";
    }

    return 0;
}