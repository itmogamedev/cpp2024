#include <iostream>
#include <string>
 

std::string NewNum("");
int OldNum = 0;
int Bufer = 0;

int main() {
	std::cout << "Enter your number ";
	std::cin >> OldNum;
	while (OldNum != 0) {
		Bufer = OldNum % 16;
		OldNum /= 16;
		switch (Bufer) {
		case 0:
			(NewNum = "0" + NewNum);
			break;
		case 1:
			(NewNum = "1" + NewNum);
			break;
		case 2:
			(NewNum = "2" + NewNum);
			break;
		case 3:
			(NewNum = "3" + NewNum);
			break;
		case 4:
			(NewNum = "4" + NewNum);
			break;
		case 5:
			(NewNum = "5" + NewNum);
			break;
		case 6:
			(NewNum = "6" + NewNum);
			break;
		case 7:
			(NewNum = "7" + NewNum);
			break;
		case 8:
			(NewNum = "8" + NewNum);
			break;
		case 9:
			(NewNum = "9" + NewNum);
			break;
		case 10:
			(NewNum = "A" + NewNum);
			break;
		case 11:
			(NewNum = "B" + NewNum);
			break;
		case 12:
			(NewNum = "C" + NewNum);
			break;
		case 13:
			(NewNum = "D" + NewNum);
			break;
		case 14:
			(NewNum = "E" + NewNum);
			break;
		case 15:
			(NewNum = "F" + NewNum);
			break;
		}//чуть безумный вариант,сам не очень разобрался как работают 
		//варианты с чаром и решил в тупую с инета не копировать,
		//больше такого ужаса не сделаю,надеюсь
	}
	std::cout << "Now your number by 16 numerical basis = " << NewNum;
}