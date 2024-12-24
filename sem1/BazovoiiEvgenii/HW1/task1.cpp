
#include <iostream>

int sq(int a) {
    return a * a;

}
   
int main()
{
    int a;
    std::cout << "type the value of side" << std::endl;
    std::cin >> a;
    std::cout << "value of the square area:" << std :: endl<< sq(a);
}

