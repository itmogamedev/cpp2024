// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


class Task2
{
    int InputNum;
    int supposed1;
public:
    Task2(int suppoused1) {
        supposed1 = suppoused1;

    }

    int Sirakuz(int supposed1) {
        while (supposed1 != 1 and supposed1 != 0) {
            if (supposed1 % 2 == 0) {
                supposed1 = supposed1 / 2;
            }
            else {
                supposed1 = ((supposed1 * 3) + 1) / 2;
            };
        }
        return supposed1;
    }

};

int main() {
    int input;
    std::cout << "Enter number: ";
    std::cin >> input;

    Task2 dsda(input);
    std::cout << dsda.Sirakuz(input);
}