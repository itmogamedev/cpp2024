#include <iostream>
#include <string>
#include <vector>
int main(){
    std::vector<std::string> book{ "336", "ecy" };

    auto len = [&book](){
            for (std::string part : book)
            {
                std::cout << part.size();
            }
    };
    return 0;
}