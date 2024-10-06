#include <iostream>

int main() {
	
	setlocale(LC_ALL, "RU");
	int a;
	int b;
	int h;
	std::cout << "¬ведите верхнюю сторону:";
	std::cin >> a ;
	std::cout << "¬ведите нижнюю сторону:";
	std::cin >> b;
	std::cout << "¬ведите высоту:";
	std::cin >> h;
	std::cout << "ѕлощадь равна:" << ((a + b) / 2) * h;

	
	return 0;
}