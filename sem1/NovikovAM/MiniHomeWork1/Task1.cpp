
#include <iostream>

int quadro(int a);

int main()
{
    int a;
    std::cout << "Input side: \n";
    std::cin >> a;    
    std::cout << "S = " << quadro(a);
    return 0;
}

int quadro(int a) {
    return a * a;
}