#include <iostream>
#include <string>

int main()
{
    int num;
    std::string eight, sixteen = "";
    std::cout << "Enter number to convert in eight and sixteen system: ";
    std::cin >> num;
    for (int x = num; x > 0;) {
        eight = std::to_string(x % 8) + eight;
        x /= 8;
    }
    for (int x = num; x > 0;) {
        if (x % 16 > 9) {
            switch (x % 16) {
            case 10:
                sixteen += "A";
            case 11:
                sixteen += "B";
            case 12:
                sixteen += "C";
            case 13:
                sixteen += "D";
            case 14:
                sixteen += "E";
            case 15:
                sixteen += "F";
            }
        }
        else {
            sixteen = std::to_string(x % 16) + sixteen;
        }
        x /= 16;
    }
    std::cout << "Your number in eight system: " << eight << std::endl << "Your number in sixteen system: " << sixteen;
    return 0;
}