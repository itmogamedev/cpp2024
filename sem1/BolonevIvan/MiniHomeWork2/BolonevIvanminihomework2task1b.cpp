#include <iostream>
#include <string>
int main()
{
    setlocale(LC_ALL, "ru");
    std::cout << "Введите число для перевода в 16-ю систему"<<std::endl;
    std::string number = "";
    std::string passage = "";
    
    int b, l, a;
    std::cin >> a;
    l = a;
    while (l > 0)
    {
        b = l % 16;
        switch (b)
        {
        case 10:
            passage = "A";
            break;
        case 11:
            passage = "B";
            break;
        case 12:
            passage = "C";
            break;
        case 13:
            passage = "D";
            break;
        case 14:
            passage = "E";
            break;
        case 15:
            passage = "F";
            break;
        default:
            passage = std::to_string(b);
        }
        number = passage + number;
        l = l / 16;
    }
    std::cout << "Ваше число в 16-ой системе: ";
    std::cout << number << std::endl;
}