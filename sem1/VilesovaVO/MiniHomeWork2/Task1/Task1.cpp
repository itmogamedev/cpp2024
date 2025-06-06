#include <iostream>
#include <stack>
#include <Windows.h>
#include <stdio.h>
#include <string>
using namespace std;

int tenToEight(int);


int main()
{
    int in_10, result_8, num, temp;
    cout << "Enter a number ";
    cin >> in_10;
    
    result_8 = tenToEight(in_10);

    string num16;

    num = in_10;

    do
    {
        temp = num % 16;

        if (temp > 9)
        {
            switch (temp) {
            case 10:
                num16 += "A";
                break;
            case 11:
                num16 += "B";
                break;
            case 12:
                num16 += "C";
                break;
            case 13:
                num16 += "D";
                break;
            case 14:
                num16 += "E";
                break;
            case 15:
                num16 += "F";
                break;
            }
        }
        else
        {
            num16 += to_string(temp);
        }

        num /= 16;

    } while (num > 0);


    reverse(num16.begin(), num16.end());


    cout << "Octal " << result_8 << endl << "Hexadecimal " << num16 << endl;
    

}
int tenToEight(int a)
{
    int div_8 = 8, buffer, result;
    buffer = a / 8;
    result = a % 8;
    stack<int> stack;
    stack.push(result);
    while (buffer > 0)
    {
        result = buffer % 8;
        buffer /= 8;
        stack.push(result);
       
    }
    result = 0;
    while (!stack.empty())
    {
        result *= 10;
        result += stack.top();
        stack.pop();
    }
    return result;
}
