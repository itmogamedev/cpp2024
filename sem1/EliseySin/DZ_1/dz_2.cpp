#include <iostream>

int calculateTrapezoidArea(int bst, int mst, int vt) 
{
    return ((bst + mst) * vt) / 2;
}

int main() 
{
    int bst;
    int mst;
    int vt;
    
    std::cout << "Введите большую сторону трапеции: ";
    std::cin >> bst;
    std::cout << "Введите меньшую сторону трапеции: ";
    std::cin >> mst;
    std::cout << "Введите высоту трапеции: ";
    std::cin >> vt;
    
    int pt = calculateTrapezoidArea(bst, mst, vt);
    std::cout << "Площадь трапеции: " << pt;
    
    return 0;
}
