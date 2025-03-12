
#include <vector>
#include <algorithm>
#include <cmath>

double Median(std::vector<double> numbers) {
	std::sort(numbers.begin(),numbers.end());
	int size = numbers.size();
	if (size % 2 != 0){
		return ((numbers[size / 2 - 1] + numbers[size / 2]) / 2);
	}
	else {
		return numbers[size / 2];
	}

}
double Mean(std::vector<double> numbers) {
	int size = numbers.size();
	double sum = 0;
	for (int i=0; i < size; i++) {
		sum += numbers[i];
	}
	return sum / size;
}
double RMS(std::vector<double> numbers) {
	int size = numbers.size();
	double sum = 0;
	for (int i = 0; i < size; i++){
		sum += numbers[i]*numbers[i];
	}
	return sqrt(sum / size);
}
double Variance(std::vector<double> numbers) {
	int size = numbers.size();
	double sum = 0;
	double mean = Mean(numbers);
	for (int i=0; i < size; i++) {
		sum += (numbers[i] - mean) * (numbers[i] - mean);
	}
	return sum / size;
}