#include <string>
#include <iostream>

int gipotheza(int chislo) {
	while (chislo != 1) {
		if (chislo % 2 == 0) {
			chislo /= 2;
		}
		else {
			chislo = (chislo * 3 + 1) / 2;
		}
	}
	std::cout << chislo << "\n";
}

int main()
{
	for(int i = 1; i<100000; i++){
		gipotheza(i);
	}
}



