#include <iostream>
int main()
{
    int peps;
    std::cout<<"Enter the first side of trapezoid: ";
    std::cin>> peps;
    int pops;
    std::cout<<"Enter the second side of trapezoid: ";
    std::cin>> pops;
    int cocs;
    std::cout<<"Enter the height of the trapezoid: ";
    std::cin>> cocs;
    
    int sps = (peps*pops)/2*cocs;
    std::cout<<sps;
    
    return 0;
}
