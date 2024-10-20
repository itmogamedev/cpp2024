#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main() // котики посчитали
{
    setlocale(LC_ALL, "Russian");
    int cata = 0; //котикнуль
    int catb = 1; //котик_у_мамы_один
    int catc; //котик_с
    int catx; //котик_икс
    cout << "¬ведите количествово элементов" << endl;
    cin >> catx;
    cout << 1 << " ";
    for (int i = 0; i < catx - 1; ++i) {
        catc = cata + catb; 
        cata = catb;
        catb = catc; 
        cout << catc << " ";
    }
}
 