#include <iostream>

int OctHex(int numb) 
{
    int numb1 = numb;
    std::cout << "Your number in hexadecimal sys:" << std::hex << numb;
    std::cout << " ";
    std::cout << "Your number in octalal sys:" << std::oct << numb1;
    return 0;
}

int main()
{
    int _userNum;
    std::cout << "Enter your number:";
    std::cin >> _userNum;
    OctHex(_userNum);
}

