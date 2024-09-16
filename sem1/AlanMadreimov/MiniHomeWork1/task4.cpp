#include<iostream>

using namespace std;

int Reverser(int num, int nDoz) {
	int addN, nNeg = -1;
	int result = 0;
	while(num != 0) {
		addN = num / pow(10, nDoz);
		result += addN * pow(10, nNeg);
		num = num - addN * pow(10, nDoz);
		nDoz--;
		nNeg++;
	}
	return result;
}

int main() {
	int number,numDozens;
	cout << "Enter number to reverse: ";
	cin >> number;
	for (int i = 1; pow(10,i) <= number; i++) {
		numDozens = i;
	}
	numDozens++;
	cout << Reverser(number, numDozens);

	return 0;
}
/*
* ≈сли  можно использовать vector и нужны незначащие нули, то можно использовать код ниже
* ѕокопалс€ немного с cin.peek() и cin.get() заодно решил добавил isdigit
#include <iostream>
#include <vector>
using namespace std;

void revers() {
    char ch;
    vector<int> digits;

    cout << "Enter number: ";

    while (cin.peek() != '\n') {
        ch = cin.get(); 
        if (isdigit(ch)) {
            digits.push_back(ch - '0');
        }
    }
    for (int i = digits.size() - 1; i >= 0; --i) {
		cout << digits[i]; 
    }
    cout << endl;
}

int main() {

    revers();

    return 0;
}
*/