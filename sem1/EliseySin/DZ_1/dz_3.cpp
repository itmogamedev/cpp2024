#include <iostream>

int main()
{
    int ke;
    int e0 = 0;
    int e1 = 1;
    int enext;
    
    std::cout<<"Введите кол-во элементов последовательности фибоначи: ";
    std::cin>> ke;
    
    if (ke == 1)
    {
         std::cout << e0;
    }
    for(int b = 1; b < ke; b++)
    {
        if (b == 1)
        {
            std::cout<< e0 << " ";
        }
        if (b == 2)
        {
            std::cout<< e1 << " ";
        }
        else{
            enext = e0 + e1;
            e0 = e1;
            e1 = enext;
            
            std::cout << enext << " ";
        }
    }
}