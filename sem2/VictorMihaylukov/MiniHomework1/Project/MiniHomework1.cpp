#include <iostream>
#include <string>
#include "MathLibrary.h"
#include <vector>

int main(){
	setlocale(LC_ALL, "rus");
	std::cout << "Введите число, которое хотите добавить в последовательность, когда закончите ввод чисел, введите '!':";
	std::string number;
	std::cin >> number;
	std::vector<int> sequence = {};
	while (number!="!"){
		int num = stoi(number);
		sequence.push_back(num);
		std::cin >> number;
	}
	int choice = 1;
	while (choice != 0) {
		std::cout << "Введите, что вы хотите вычеслить\n1 - Среднее арифметическое\n2 - Медиану\n3 - Среднее квадратическое\n4 - Дисперсию\n0 - Хочу выйти из программы\n";
		std::cin >> choice;
		switch (choice) {
		case 0:
			break;
		case 1:
			std::cout << average(sequence) << std::endl;
			break;
		case 2:
			std::cout << median(sequence) << std::endl;
			break;
		case 3:
			std::cout << average_square(sequence) << std::endl;
			break;
		case 4:
			std::cout << variance(sequence) << std::endl;
			break;
		}
	}
}