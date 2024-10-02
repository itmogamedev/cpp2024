#include <iostream>
#include <iomanip> 

int main() {
    int decyatich;

    std::cout << "Vvedite decyatichnoe chislo: ";
    std::cin >> decyatich;

    // Shesnadtcatirichnoe
    std::cout << "Shesnadtcatirichnoe chislo: " 
              << std::hex << std::uppercase << decyatich << std::endl;

    // Vosmerichnoe
    std::cout << "Vosmerichnoe chislo: " 
              << std::oct << decyatich << std::endl;

    return 0;
}