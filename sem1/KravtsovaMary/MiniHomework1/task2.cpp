#include <iostream>
int strap(int a, int b, int h) {
	return (a + b) / 2 * h;
}
int main() {
	int side1, side2, hight;
	std::cin >> side1 >> side2 >> hight;
	int res = strap(side1, side2, hight);
	std::cout << res;
}