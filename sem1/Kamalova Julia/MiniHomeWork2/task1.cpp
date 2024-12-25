#include <iostream> 
#include <string> 
 
std::string decToOct(int dec) { 
    std::string oct = ""; 
    if (dec == 0) { 
        return "0"; 
    } 
    while (dec > 0) { 
        int remainder = dec % 8; 
        oct = std::to_string(remainder) + oct;  
        dec /= 8; 
    } 
    return oct; 
} 
 
std::string decToHex(int dec) { 
    std::string hex = ""; 
    if (dec == 0) { 
        return "0"; 
    } 
    while (dec > 0) { 
        int remainder = dec % 16; 
        if (remainder < 10) { 
            hex = std::to_string(remainder) + hex;  
        } 
        else { 
            char hexDigit = 'A' + (remainder - 10); 
            hex = hexDigit + hex; 
        } 
        dec /= 16; 
    } 
    return hex; 
} 
 
int main() { 
    setlocale(LC_ALL, "RUS"); 
    int decNum; 
    std::cout << "Десятичное число: "; 
    std::cin >> decNum; 
 
    std::cout << "Восьмеричное число: " << decToOct(decNum) << std::endl; 
    std::cout << "Шестнадцатеричное число: " << decToHex(decNum) << std::endl; 
 
    return 0; 
}
