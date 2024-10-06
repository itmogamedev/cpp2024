#include <iostream>

int main()
{ 
    int numb;
    std:: cout << "Enter number: ";
    std::cin >> numb;

    if (numb > 0) {
        while (numb != 1) {

            if (numb % 2 == 0) {
                numb /= 2;
            }

            else {
                numb *= 3;
                numb++;
                numb /= 2;
            }
        }
        std::cout << "Result: " << numb << "\n";
        std::cout << "Hurray! U get 1 - hypotheses of Syracuse is TRUE!";
    }
    else {
        std::cout << "This hypothesis is only for positive numbers greater than 0, sorry :( ";
    }
}

