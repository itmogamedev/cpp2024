#include <iostream>

int main() {
int a = 0;
int b = 1;
int c;
int n;
std::cout << "Enter n: ";
std::cin >> n;

for (int shag = 1; shag < n; ++shag){
    if (shag == 1){
        std::cout << a << ", ";
    }
    if (shag == 2){
        std::cout << b << ", ";
    }
    else {
        c = a + b;
        a = b;
        b = c;
        std::cout << c << ", ";
    }
}
}