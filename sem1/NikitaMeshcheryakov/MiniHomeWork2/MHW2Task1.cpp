#include <iostream>
#include <stack>

void Int10ToInt8(long long number);
void Int10ToInt16(long long number);

int main()
{
    setlocale(LC_ALL, "RU");

    std::cout << "Введите число: ";
    long long number1;
    std::cin >> number1;

    std::cout << "Число в 8 - ричной системе записывается как: ";
    Int10ToInt8(number1);

    std::cout << "Введите число: ";
    long long number2;
    std::cin >> number2;

    std::cout << "Число в 16 - ричной системе записывается как: ";
    Int10ToInt16(number2);
}

void Int10ToInt8(long long num)
{
    std::stack<int> numStack;
    int temp = 0;

    do 
    {
        temp = num % 8;
        num = (num - temp) / 8;
        numStack.push(temp);

    } while (num != 0);

    while (!numStack.empty())
    {
        std::cout << numStack.top();
        numStack.pop();
    }

    std::cout << std::endl;
}

void Int10ToInt16(long long number)
{
    std::stack<int> numStack;
    int temp = 0;
    char nums[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

    do
    {
        temp = number % 16;
        number = (number - temp) / 16;
        numStack.push(temp);

    } while (number != 0);

    while (!numStack.empty())
    {
        std::cout << nums[numStack.top()];
        numStack.pop();
    }

    std::cout << std::endl;
}


