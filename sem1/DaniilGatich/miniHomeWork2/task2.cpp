#include <iostream>

int main()
{
    int _userNum;
    std::cout << "What number do u want to check with Syracuse hypothesis?: ";
    std::cin >> _userNum;
    while (_userNum != 1) 
    {
        if (_userNum == 2) 
        {
            std::cout << "It's even number, so we devide it by 2: ";
            std::cout << _userNum << ":2 = " << _userNum / 2 << std::endl;
            std::cout << "It's we finally got 1 ";
            break;
        }
        if (_userNum % 2 == 0) 
        {
            std::cout << "It's even number, so we devide it by 2: ";
            std::cout << _userNum << ":2 = " << _userNum / 2 << std::endl;
            _userNum = _userNum / 2;
        }
        if (_userNum % 2 != 0)
        {
            
            std::cout << "It's not an even number, so we multiply it by 3 plus 1: ";
            std::cout << _userNum << "*3 + 1 = " << _userNum * 3 + 1 << std::endl;
            _userNum = _userNum * 3 + 1;
        }
    }
}
