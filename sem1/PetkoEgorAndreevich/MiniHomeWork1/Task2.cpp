#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main2() // по формуле произведени€ половины суммы оснований трапеции на высоту
{
	setlocale(LC_ALL, "Russian");
	int cat_base1; // котик_бэйз
	int cat_base2; // котик_бэйз
	int high_cat; // высокий_котик
	cout << "¬ведите первое основание трапеции" << endl;
	cin >> cat_base1;
	cout << "¬ведите второй основание трапеции" << endl;
	cin >> cat_base2;
	cout << "¬ведите высоту" << endl;
	cin >> high_cat;
	cout << ((cat_base1 + cat_base2) / 2) * high_cat;
}