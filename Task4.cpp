
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void Converter() {
    int n1;
    int n2 = 0;
    cin >> n1;
    while (n1 > 0) {
        n2 = n1 % 10;
        n1 = n1 / 10;
        cout << n2;
    } 
}
int main()
{
    cout << "Enter a number"<< endl;
    Converter();
}