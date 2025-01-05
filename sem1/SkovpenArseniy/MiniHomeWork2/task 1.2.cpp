#include <iostream>

int main()
{ 
    int DecNumber, OctNumber, HexNumber;
    std::cout << "Enter a decimal number:";
    std::cin >> DecNumber;
    std::cout << "OctNumber = " << std::oct << DecNumber<< std::endl;
    std::cout << "HexNumber = " << std::hex << DecNumber;
    return 0;


    
}
