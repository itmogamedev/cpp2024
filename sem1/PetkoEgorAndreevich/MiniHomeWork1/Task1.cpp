#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите сторону квадрата" << endl;
	int cat_storona_squad; // котики
	cin >> cat_storona_squad;
	cout << cat_storona_squad * cat_storona_squad; // а котики в квадрате круче вдвойне	
}