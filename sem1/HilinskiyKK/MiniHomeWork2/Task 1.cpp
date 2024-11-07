#include <iostream>
#include <string>
#include <sstream>

std::string decimalToHex(int num) {
    std::stringstream ans;
    ans << std::hex << num;
    return ans.str();
}

std::string decimalToOct(int num) {
    std::stringstream ans;
    ans << std::oct << num;
    return ans.str();
}

int main() {
    int num;

    std::cout << "Enter number: ";
    std::cin >> num;

    std::string hexNum = decimalToHex(num);
    std::string octNum = decimalToOct(num);

    std::cout << "Hex number: " << hexNum << std::endl;
    std::cout << "Oct number: " << octNum << std::endl;

    return 0;
}
