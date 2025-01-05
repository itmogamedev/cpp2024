
#include <iostream>


int Fibon(int count) {
    int Snumb = 1; //Second number
    int Fnumb = 0; //First number
    for (int i = 0; i < count; i++) {
        if (i == 0) {
            std::cout << Fnumb << " ";
        }
        if (i == 1) {
            std::cout << Snumb << " ";
        }
        if (i % 2 == 0) {
            Fnumb = Fnumb + Snumb;
            std::cout << Fnumb << " ";
        }
        if (i % 2 != 0) {
            Snumb = Fnumb + Snumb;
            std::cout << Snumb << " ";
        }
    }
        return 0;

}


int main()
{
    int count = 0;
    std::cout << "Enter yor count of numbers Fibanashi";
    std::cin >> count;
    Fibon(count);
    
    
    return 0;

}