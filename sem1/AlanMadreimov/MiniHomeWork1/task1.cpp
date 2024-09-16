#include <iostream>

using namespace std;

double SquareArea(double a) {
    return a * a;

}

int main()
{
    double a;
    do {
        cout << "Enter square side: ";
        cin >> a;
        if (a <= 0) {
            cout << "Side can't be - or 0" << endl;
        }
    } while (a <= 0);

    cout << "Square area is: " << SquareArea(a);
    return 0;
}

