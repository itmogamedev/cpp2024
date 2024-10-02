#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int second_last = 1, first_last = 1;
    for (int i = 0; i < n; i++)
    {
        if (i <= 1)
        {
            std::cout << 1 << " ";
            continue;
        }
        int next = first_last + second_last;
        second_last = first_last;
        first_last = next;

        std::cout << next << " ";
    }

    return 0;
}
