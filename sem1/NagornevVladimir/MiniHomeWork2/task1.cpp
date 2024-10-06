#include <iostream>
int func_conversion(int n) 
{
    std::cout << std::oct << "oct - " << n << '\n';
    std::cout << std::hex << "hex - " << n << '\n';
    return 0;
}


int main()
{
    int num;
    std::cout << "Input: ";
    std::cin >> num;
    func_conversion(num);
}
