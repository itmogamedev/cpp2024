

#include <iostream>
void octhex(int n) {
    std::cout << "Число в восьмеричной системе системе: " << std::oct << n << std::endl;
    std::cout << "Число в шестнадцетеричной системе счисления: " << std::hex << n;
    
}
    

     


int main()
{
    setlocale(LC_ALL, "russian");
    int numb;
    std::cout << "Введите число ";
    std::cin >> numb;
    octhex(numb);
}


