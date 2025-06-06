#include <iostream>


int square(int lenght) {
    return lenght * lenght;
}

int main()
{   
    int input;
    std::cout << "Enter the lenght (>0) ";
    std::cin >> input;
    std::cout << "The square is " << square(input);
}
