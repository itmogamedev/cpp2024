#include <iostream>
int sqs(int a) {
	return a * a;
}
int main() {
	int side;
	std::cin >> side;
	int res = sqs(side);
	std::cout << res;
}