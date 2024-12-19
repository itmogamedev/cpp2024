#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main() 
{
    int N;
    cout << "Enter the number of Fibonacci elements (N): ";
    cin >> N;

    long long first = 0, second = 1;

    cout << "A Fibonacci series of " << N << " elements: " << endl;

    for (int i = 0; i < N; ++i) 
    {
        if (i == 0) 
	{
            cout << first << " "; 
        } 
	else if (i == 1) 
	{
            cout << second << " "; 
        }
	else 
	{
            long long next = first + second; 
            cout << next << " "; 
            first = second; 
            second = next; 
        }
    }
    return 0; 
}
