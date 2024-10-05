

#include <iostream>

int main()
{
    setlocale(LC_ALL, "russian");
    int numb;
    std::cout << "Введите число: ";
    std::cin >> numb;
    int res = numb;
    while (numb>1){
        if (numb % 2 == 0) {
            numb = numb / 2;
        }
        else {
            numb = ((numb * 3) + 1) / 2;
        }
  
        
    }
    if (numb == 1) {
        std::cout << "Гипотеза Сиракуз для числа " << res << " доказана";
    }
    else {
        std::cout << "Гипотеза Сиракуз для числа " << res << " не доказана, в результате получилось " << numb;
    }

    
}

