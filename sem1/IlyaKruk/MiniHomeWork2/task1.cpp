#include <iostream> 
using namespace std;

void dectooctal(int n)
{
    int arr[100];
    int i = 0;
    while (n != 0) {
        arr[i] = n % 8;
        n = n / 8;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << arr[j];
    }
}

void dectohex(int n)
{
    char arr[100];
    int i = 0;
    while (n != 0) {
        int temp = 0;
        temp = n % 16;
        if (temp < 10) {
            arr[i] = temp + 48;
            i++;
        }
        else {
            arr[i] = temp + 55;
            i++;
        }
        n = n / 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        cout << arr[j];
    }
}

int main()
{
    cout << "If you want to convert decimal to octal - 0" << endl;
    cout << "If you want to convert decimal to hex - 1" << endl;
    int n, a;
    cin >> n;
    if (n == 0) {
        cout << "Which number do you want to convert?" << endl;
        cin >> a;
        dectooctal(a);
    }
    else if (n == 1) {
        cout << "Which number do you want to convert?" << endl;
        cin >> a;
        dectohex(a);
    }
    else {
        cout << "Wrong input";
    }
}