#include <iostream>

int trapetsia(int a, int b, int c) {
    return (a + b) / 2 * c;
}
int main()
{
    const int a_length = 7; //Первое основание
    const int b_length = 21; //Второе основание
    const int height = 12; //Высота
    std::cout << trapetsia(a_length,b_length,height);
}