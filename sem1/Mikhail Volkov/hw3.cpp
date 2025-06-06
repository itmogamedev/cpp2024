#include <iostream>

int main()
{
    int pp1 = 0;
    int pp2 = 1;
    int nextpp;
    int termP;
    
    std::cout <<"Enter the Fibonnachi elements: ";
    std::cin >> termP;
    
    for(int hhd = 1; hhd < termP; hhd++)
    {
        if (hhd == 1)
        {
            std::cout<< pp1 << "..";
        }
        if ( hhd == 2)
        {
            std::cout<< pp2 << "..";
        }
        else {
            
            nextpp = pp1 + pp2;
            pp1 = pp2;
            pp2 = nextpp;
            
            std::cout << nextpp << "..";
        }
    }
    
    return 0;
}
