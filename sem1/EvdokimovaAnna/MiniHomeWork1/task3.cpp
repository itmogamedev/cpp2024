#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() 
{
    int N;
	
    cout << "Enter the number of Fibonacci elements (>0): ";
    cin >> N;

    long long first = 0, second = 1;

    cout << "\nA Fibonacci series of " << N << " elements: " << endl;

    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            cout << first << " "; 
        } else if (i == 1) {
            cout << second << " "; 
        } else {
            long long next = first + second; 
            cout << next << " ";
            first = second; 
            second = next; 
        }
    }
	cout << endl; 
    	return 0; 
}
