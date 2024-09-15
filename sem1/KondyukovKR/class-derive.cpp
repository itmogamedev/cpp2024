#include <iostream>


class Figure {
public:
  int a = 10;
};

class Rectangle : public Figure {
public:
  int b = 100;
};

int main() {

    Figure figure;
    Rectangle rectangle;

    std::cout<<"figure.a " << figure.a << '\n';
    std::cout<<"rectangle.a " << rectangle.a;
    std::cout<<"rectangle.b " << rectangle.b;

    return 0;
}