#include <iostream>

int main()
{   
    int input = 0;
    int prev = 0;
    int prev2 = 1;
    int curr = 0;
    std::cout << "Enter N: ";
    std::cin >> input;
    for (int i = 0; i < input; i++) {
        if (i < 2) {
            std::cout << i << " ";
        }
        else {
            curr = prev2 + prev;
            std::cout << curr << " ";
            prev = prev2;
            prev2 = curr;
        }
    }
}