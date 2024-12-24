#include <iostream>
using namespace std;
int main()
{
    int a, b, h;
    cout << "Enter trapezoid's bases" << endl;
    cin >> a >> b;
    cout << "Enter trapeziod's height" << endl;
    cin >> h;
    cout << "Its area is " << (a + b) / 2 * h;
}
