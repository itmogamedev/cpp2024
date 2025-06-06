#include <iostream>
#include <cmath>



int turnnumb(int numb) {
    int size = 0;
    int numbL = numb; //Переменная которуюя буду мучать
    while (numbL % 10 != 0) {
        size += 1;
        numbL /= 10;

    }

    int sizeL = 0;//Переменная которая поможет мне вывернуть число наоборот
    for (int i = 0; i < size; i++) {
        int a = pow(10, sizeL);
        int b = pow(10, sizeL + 1);
        std::cout << (numb % b) / a;
        sizeL += 1;
        //std::cout <<" "<< sizeL << " " << a << " "; // Проверка была
    }
    return 0;
};





int main()
{
    int numb = 0;
    std::cout << "Enter your number ";
    std::cin >> numb;
    turnnumb(numb);
    return 0;
}