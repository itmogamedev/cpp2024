#include<iostream>


void Fibo(int n,int firstn=0,int secondn=1) {
	int temp;
	if (n == 0) {
		std::cout << firstn;
	}
	else if (n == 1) {
		std::cout << firstn << " " << secondn;
	}
	else {
		std::cout << "0" << " " << "1 ";
		for (int i = 2; i < n; i++) {
			temp = firstn + secondn;
			firstn = secondn;
			secondn = temp;
			std::cout << temp << " ";
		}
	}
}

int main() {

	int n;
	std::cout << "Please enter n: ";
	std::cin >> n;

	Fibo(n);

	return 0;
}