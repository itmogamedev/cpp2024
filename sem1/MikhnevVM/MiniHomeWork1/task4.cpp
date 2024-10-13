#include <iostream>

int main()
{
    int number, revers_number,cnt;
    cnt = 0;
    revers_number = 0;
    std::cout << "Введите число и я переверну его цифры:";
    std::cin >> number;
    while (number > 0){
        if(number%10 == 0){
            cnt+=1;
            
        }
        revers_number += number%10;
        number/=10;
        revers_number*=10;
    }
    if (cnt > 0){
        std::cout << '0' <<  revers_number/10;
    }else{
        std::cout << revers_number/10;
    }
}