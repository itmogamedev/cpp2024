#include <iostream>

// task 3

void fibonachi(const int n)
{
    const std::string continue_line = ", ";
    int x_1 = 0;
    int x_2 = 1;
    
    for (int i = 0; i < n; i++)
    {
        if (i == 0 or i == 1)
        {
            std::cout << i << continue_line;
        }
        else
        {
            int next = x_1 + x_2;
            x_1 = x_2;
            x_2 = next;
            
            std::cout << next << continue_line;
        }
    }
    std::cout << '\n';
}

int main()
{
    
    const std::string text = "Enter the number of elements in the sequence: ";
    int n;

    std::cout << text;
    std::cin >> n;
    
    fibonachi(n);

    std::cout << '\n';
    return 0;
}


