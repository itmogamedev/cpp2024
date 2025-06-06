#include <iostream>


int main()
{
    int fib1, fib2, n, storage;
    fib1 = 0;
    fib2 = 1;
    std::cout << "Введите любимое число больше 0 и я выведу ряд чисел Фибоначчи:" << "\n";
    std::cin >> n;
    while (n <= 0){
         std::cout << "Прошлое число не больше 0, введите пожалуйста любое число больше 0:" << "\n";
         std::cin >> n;
    }
     if (n == 1){
         std::cout << 0;
     }
     else if (n == 2)
     {
         std::cout << "0 1";
     }
     else
       {
         for(int i = 0; i < n; i++)
         {
             std::cout << fib1 << " ";
             storage = fib2;
             fib2 += fib1;
             fib1 = storage;
         }
             
        }
    
    
}