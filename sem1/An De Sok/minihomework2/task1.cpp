#include <iostream>
void func(int a,int b)
{
    switch (a) {
        case 0:
            std::cout <<"Ответ: "<< std::oct << b << std::endl;
            break;
        case 1:
            std::cout <<"Ответ: "<<std::hex << b << std::endl;
            break;
    }
}
int main()
{
    int select;
    int numb;
    setlocale(LC_ALL, "Russian");
    while (1){
        select = 0;
        numb = 0;
        std::cout<<"Выберите операцию: "<<std::endl<< "0 - из десятичной в восьмеричную" << std::endl << "1 - из десятичной в шестнадцатеричную" << std::endl;
        std::cin >> select;
        if (select < 2) {
            std::cout << "Введите число: " << std::endl;
            std::cin >> numb;
            func(select, numb);
        }
        else {
            std::cout << "Такой операции нет!" << std::endl;
        }
    }
}