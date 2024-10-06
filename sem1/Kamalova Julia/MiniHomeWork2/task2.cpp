#include<iostream>
using namespace std;

int main(){
    int x;
    cout << "Введите число: ";
    cin >> x;
    
    while (x != 1) { 
        if (x % 2 == 0) {
            x /= 2; 
            cout << x << " "; 
        } else {
            x = (x * 3) + 1; 
            cout << x << " "; 
        }
    }
    cout << endl;
    cout << "Гипотеза верна";
    return 0;
}
