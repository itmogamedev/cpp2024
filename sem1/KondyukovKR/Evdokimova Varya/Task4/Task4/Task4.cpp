#include <iostream>
using namespace std;

int Flip(int numb)
{
    int result = 0;
    while (numb){
        result = result * 10 + numb % 10;
        numb /= 10;
    }
    return result;
}

int main()
{
    {
        int numb = 0;
        cout << "Enter number to flip: ";
        cin >> numb;
        if (numb > 9)
        {
            cout << "Flip number: ";
            cout << Flip(numb) << endl;
        }
        else
        {
            cout << "Tipical number, luzer: " << numb << endl;
        }
    }
}
