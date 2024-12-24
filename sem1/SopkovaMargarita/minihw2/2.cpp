#include <iostream>
#include <set>

int Sirakuz(int user_number) {
    int temporary;
    temporary = user_number;
    std::set<int> previous_numbers;
    while (temporary != 1 or previous_numbers.find(temporary) == previous_numbers.end()) {
        previous_numbers.insert(temporary);
        if (temporary % 2 == 0) {
            temporary = temporary / 2;
        }
        else {
            temporary = (temporary * 3 + 1) / 2;
        }
    }
    if (temporary == 1) {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int user_number;
    std::cout << "Enter the number" << std::endl;
    std::cin >> user_number;
    if (Sirakuz(user_number) == 1) {
        std::cout << "Theory is true" << std::endl;
    }
    else
    {
        std::cout << "Theory is false" << std::endl;
    }

}

