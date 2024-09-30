#include <iostream>
using namespace std;

int main()
{ 
	int num, select;
	while (true) {
		cout << "Enter your decimal: ";
		cin >> num;
		cout << "Select what to convert to: \n 1 - octal \n 2 - hexadecimal" << endl;
		cin >> select;
		switch (select) {
			case 1:
				cout << oct << num << endl;
				break;
			case 2: 
				cout << hex << num << endl;
				break;
		}
	}
}







