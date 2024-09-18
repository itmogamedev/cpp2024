#include <iostream>

int ploshad(int height, int width) {
    int squarearea;
    squarearea = height * width;
    return squarearea;

}

int main()
{
    int height, width, squarearea;
    std::cin >> height >> width;
    squarearea = ploshad(height, width);
    std::cout << squarearea;
}

