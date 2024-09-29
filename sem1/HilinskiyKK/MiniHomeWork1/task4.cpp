#include <iostream>
void func4(int x) {
    while (x > 0) {
        std::cout << x % 10;
        x /= 10;
    }
}
int main()
{
    //Задание 4
    std::cout << "4) num = ";
    int k;
    std::cin >> k;
    func4(k);
}