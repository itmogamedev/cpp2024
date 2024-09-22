#include <iostream>

int main()
{
    int bst;
    int mst;
    int vt;
    std::cout<<"Введите большую сторону трапеции: ";
    std::cin>> bst;
    std::cout<<"Введите меньшую сторону трапеции: ";
    std::cin>> mst;
    std::cout<<"Введите высоту трапеции: ";
    std::cin>> vt;
    
    int pt = (bst*mst)/2*vt;
    std::cout<< pt;
    
    return 0;
}