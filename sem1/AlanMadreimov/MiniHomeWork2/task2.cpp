#include<iostream>
#include<string>



int SirakuzGip(long n) {
	if (n == 1) {
		return 1;
	}
	else if (n % 2 == 0) {
		return SirakuzGip(n / 2);
	}
	else {
		return SirakuzGip((n * 3 + 1) / 2);
	}
}

/*void Test() {
	for (int i = 1; i < 100000; i++) {
		std::cout << SirakuzGip(i) << " ";
	}
}
*/

int main() {

	std::string instr,digitstr;
	long n = -1;

	while (n <= 0) {
		std::cout << "Enter a natural number: ";
		std::cin >> instr;

		for (int i = 0; i < instr.length(); i++) {
			if (isdigit(instr[i])) {
				digitstr += instr[i];
			}
		}
		n = stoi(digitstr);
		
		if (n <= 0) {
			std::cout << "You entered a non-natural number" << std::endl;
		}

	}
	std::cout << SirakuzGip(n);
	

	return 0;
}