#include<iostream>
#include<string>



void TnumSys(long n, int base){
	char arr[16] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	if (n > 0)
	{
		TnumSys(n / base, base);
		std::cout << arr[n % base];
	}
}


int main() {

	std::string instr,normalstr;
	int type = 0;
	bool iscorrect = 1;
	std::cout << "Enter number: "
	std::cin >> instr;

	for (int i = 0; i < instr.length(); i++) {
		if (isdigit(instr[i])) {
			normalstr += instr[i];
		}
		else {
			if (iscorrect) {
				std::cout << "I think you meant this number :";
				iscorrect = 0;
			}
		}
	}

	if (!iscorrect) {
		std::cout << normalstr << std::endl;
	}

	while (type != 8 and type != 16) {
		std::cout << "Please enter the desired measurement system (8 or 16): ";
		std::cin >> type;
		if (type != 8 and type != 16) {
			std::cout << "Number systems 8 or 16!" << std::endl;
		}
	}

	long num = stoi(normalstr);
	TnumSys(num, type);

	
	return 0;
}
