#include <iostream>

int syracuse_theorem_step(int number){
    return number % 2 == 0 ? number / 2 : (number * 3 + 1) / 2;
}

void syracuse_theorem(){
    int num = 0;
    std::cout << "Enter a number greater than zero for a Syracuse theorem example: ";
    std::cin >> num;
    std::cout << std::endl << num << " -> ";

    while (num != 1)
    {
        num = syracuse_theorem_step(num);
        std::cout << num << " -> ";
    }
    
    std::cout << "quod est demonstrandum." << std::endl;
}

int main() {
    syracuse_theorem();
    return 0;
}