#include <iostream>
using namespace std;
int main()
{
    int a = 0, b = 1, c, n, cnst, i;
    cout << "Enter number of numbers: ";
    cin >> n;
    for (i = 1; i <= n; i++) 
    {
        if (i == 1)  // first numb
            c = 0;
        else if (i == 2 or i == 3)
            c = 1;
        else
        {
            cnst = a;
            a = b;
            b = c;
            c = a + b;
        }
        if (i == n) // last number
            cout << c;
        else
            cout << c << ", "; // str
    }
    cout << endl;
    return 0;
}