#include<iostream>

int OldNum;
int NewNumReverse = 0;
int NewNum = 0;
int Remain = 0;
int Remain2 = 0;

int main() {
    std::cout << "Enter your number ";
    std::cin >> OldNum;
    while (OldNum != 0) {
        Remain = OldNum % 8;
        NewNumReverse = NewNumReverse * 10 + Remain; //перевод числа в восьмеричку, но оно "переворачивается", как в минидомашке1
        OldNum /= 8;
    }
    while (NewNumReverse != 0)
    {
        Remain2 = NewNumReverse % 10;
        NewNum = NewNum * 10 + Remain2;  //собственно,обратный переворот без изменения цифр,а значит,система счисления остается восьмеричной
        NewNumReverse /= 10;
    }
    std::cout << "Now your number by 8 numerical basis = " << NewNum;
}