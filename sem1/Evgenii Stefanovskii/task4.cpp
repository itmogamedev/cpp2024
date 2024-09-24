#include <iostream>

int main() {
int n;
int revn;

std::cout << "Enter number: ";
std::cin >> n;

while (n != 0){
    revn *= 10;
    revn += n % 10;
    n /= 10;
}
std::cout << revn;

}