#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void hypothesis(int number) 
{
    cout << "Последовательность для числа " << number << ": ";
    while (number != 1) 
    {
        cout << number << " ";
        
        if (number % 2 == 0) 
        {
            number /= 2;
        } 
        
        else 
        {
            number = (number * 3 + 1) / 2;
        }
    }
    cout << number << endl;
}

int main() {
    int number;
    cout << "Введите натуральное число: ";
    cin >> number;

    hypothesis(number);

    return 0;
}
