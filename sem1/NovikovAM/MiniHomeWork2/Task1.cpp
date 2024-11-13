#include <iostream>


std::string TransformDecToHex(int Dec) {
    std::string hex = "0123456789ABCDEF";
    std::string CodeHex;
    char HexChar;
    while (Dec != 0) {
      if (Dec % 16 <= 15 and Dec % 16 > 9) {
          CodeHex = hex[(Dec % 16)] + CodeHex;
          Dec = Dec / 16;
      }
      else {
        CodeHex = std::to_string(Dec % 16) + CodeHex;
        Dec = Dec / 16;
        }
    }
    CodeHex = "0x" + CodeHex;
    return CodeHex;
}

std::string TransformDecToOct(int Dec) {
    std::string oct = "01234567";
    std::string CodeHex;
    while (Dec != 0) {
        if (Dec % 8 <= 7) {
            CodeHex = oct[(Dec % 8)] + CodeHex;
            Dec = Dec / 8;
        }
        else {
            CodeHex = std::to_string(Dec % 8) + CodeHex;
            Dec = Dec / 8;
        }
        }
    CodeHex = "0" + CodeHex;
    return CodeHex;
}

int main() {
    int Dec;
    int Choise;
    bool work = true;

    while (work) {
    std::cout << "Enter your choise transform dec number (1 - 16, 2 - 8, 0 - Exit): ";
    std::cin >> Choise;
    switch (Choise) {
        case 1:
            std::cout << "Enter your Decimal Number: ";
            std::cin >> Dec;
            std::cout << "Oct number: " << TransformDecToHex(Dec) << std::endl;
        break;
        case 2:
          std::cout << "Enter your Decimal Number: ";
          std::cin >> Dec;
          std::cout << "Oct number: " << TransformDecToOct(Dec) << std::endl;
          break;
        case 0:
          work = false;
          break;
        default:
            std::cout << "Invalid Choice!" << std::endl;
            break;
    }
    }
}




