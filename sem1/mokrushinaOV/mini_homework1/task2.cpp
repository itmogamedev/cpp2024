#include <iostream>


int trapeze_area(int hight, int smaller_base, int bigger_base) {
    int area = ((smaller_base + bigger_base) / 2) * hight;
    return area;
}


int main()
{
    std::cout << trapeze_area(2, 3, 4) << std::endl;
}