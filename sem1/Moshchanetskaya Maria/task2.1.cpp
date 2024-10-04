// task2.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using std::string;
using std::endl;
using std::to_string;

int main()
{
    setlocale(LC_ALL, "Russian");
    int number10;
    int number10_copy;
    string remainder = "";
    string number16 = "";
    string number8 = "";
    std::cout << "введите натуральное число" << endl ;
    std::cin >> number10;
    number10_copy = number10;
    char variable;

    
    while (number10 > 0)
    {
        if (number10 % 16 < 10)
        {
            remainder = to_string(number10 % 16);
        }
        else
        {
            variable =  number10%16 + 55;
            remainder = variable;
        }
        number16 = remainder + number16;
        number10 = number10 / 16;
    }
    
    while (number10_copy > 0)
    {
        number8 = to_string(number10_copy % 8) + number8;
        number10_copy = number10_copy / 8;
    }
    std::cout <<" в шестнадцатиричной системе = " <<number16 <<endl;
    std::cout <<" в восьмиричной системе = " << number8;

    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
