#include <iostream>
int sqs(int a) {
	return a * a;
}
int main() {
	int side = 0;
	std::cin >> side;
	int res = sqs(side);
	std::cout << res;
}