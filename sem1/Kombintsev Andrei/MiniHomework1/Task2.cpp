
#include <iostream>

int main()
{
    float a = 0;  //Одно из оснований трапеции
    float b = 0;  //Другое основание трапеции
    float h = 0; //высота 
    int i = 0;
    while (i == 0) 
    {
        std::cout << "Enter sides of trapezoid";
       
        std::cin >> a;
        std::cin >> b;
        std::cout << "Enter trapezoid height";
        
        std::cin >> h;
        if (a != b)
        {
            i = 1;
        }
        else std::cout << "ERROR\n";
    }
    std::cout << "Area of trapezoid" << (a + b) / 2.0 * h;
}

