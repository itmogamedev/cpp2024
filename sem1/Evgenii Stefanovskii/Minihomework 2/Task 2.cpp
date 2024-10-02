#include <iostream>

void siraHypothesis(int num) {
    while(num != 1){
        if(num % 2 == 0){
            num /= 2;
        }
        else{
            num = num * 3 + 1;
        }
        std::cout << num << std::endl;
    }
}

int main() {
    int num;
    std::cout << "Enter natural number: " << std::endl;
    std::cin >> num;
    siraHypothesis(num);
    std::cout << "The final sequence: " << std::endl;
    return 0;
}