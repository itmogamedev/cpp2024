#include <iostream>
#include <string>

int main()
{
    std::string num = "";

    int a;
    std::cin >> a;

    while (a > 0)
    {
        if (a % 16 == 10)
        {
            num = "A" + num;
        }
        else if (a % 16 == 11)
        {
            num = "B" + num;
        }
        else if (a % 16 == 12)
        {
            num = "C" + num;
        }
        else if (a % 16 == 13)
        {
            num = "D" + num;
        }
        else if (a % 16 == 14)
        {
            num = "E" + num;
        }
        else if (a % 16 == 15)
        {
            num = "F" + num;
        }
        else {
            num = std::to_string(a % 16) + num;    
        }
        
        a = a / 16;
    }

    std::cout << num << std::endl;
}