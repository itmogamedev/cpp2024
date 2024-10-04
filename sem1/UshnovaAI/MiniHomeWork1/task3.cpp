#include <iostream>

int fibNumb(int value) {
	if (2>=value) 
		return 1;
	return fibNumb(value-1)+fibNumb(value-2);
}

int main() {
	std::cout << "Enter number ";
	int input;
	std::cin >> input;
	std::cout << "Series of fibonacci numbers of " << input << " elements:";
	for(int i = 1; i<=input;i++){
		std::cout << fibNumb(i) << " ";
	}
}