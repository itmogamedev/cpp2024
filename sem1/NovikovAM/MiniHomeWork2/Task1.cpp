#include <iostream>

std::string RevertToHexToOct(int Dec, std::string tableSym) {
    std::string HexOctNum;
    while (Dec > 0) {
        HexOctNum = tableSym[Dec%tableSym.length()] + HexOctNum;
        Dec = Dec /tableSym.length();
    }
    return HexOctNum;
}


int main() {
    std::string OctTable = "01234567";
    std::string HexTable = "0123456789ABCDEF";

    bool Exit = true;

    int Choiсe;
    int Dec;

    while (Exit){
        std::cout << "Enter choice revert(1 - Hex, 2 - Oct, 0 - Exit): ";
        std::cin >> Choiсe;
        std::cout << "Enter your Dec number: " << std::endl;
        std::cin >> Dec;
        switch (Choiсe) {
            case 1:
                std::cout<< "Your Hex number: " << RevertToHexToOct(Dec,HexTable) << std::endl;

            break;
            case 2:
                std::cout<< "Your Oct number: " << RevertToHexToOct(Dec,OctTable) << std::endl;
            break;
            case 0:
                Exit = false;
                break;
            default:
                std::cout << "Invalid Choice";
            break;
        }
    }
}