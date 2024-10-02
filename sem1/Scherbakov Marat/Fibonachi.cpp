#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int main()
{
    setlocale(LC_ALL, "Russian");
    int A = 0, B = 0, C = 1, Amonut_of_N;
    cout << "Введите кол-во элементов:" << endl;
    cin >> Amonut_of_N;
    cout << C << " ";
    for (int i = 0; i < Amonut_of_N - 1; ++i) {
        B = A + C;
        A = C;
        C = B;
        cout << B << " "; //Я не понял, как вывести отдельно ноль в начале(
    }
}