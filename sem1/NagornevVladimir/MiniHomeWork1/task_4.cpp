#include <iostream>
using namespace std;

int main()
{
    int n;
    int rev_n = 0;
    cout << "Enter a number: ";
    cin >> n;   

    while (n)
    {
        rev_n = rev_n * 10 + (n % 10);
        n /= 10;
    }

    cout << "inverted number: " << rev_n;
}