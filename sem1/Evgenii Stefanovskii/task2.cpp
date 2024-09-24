#include <iostream>

int main() {
int a = 0;
int b = 0;
int h = 0;
std::cout<<"Enter base 1: ";
std::cin>>a;
std::cout<<"Enter base 2: ";
std::cin>>b;
std::cout<<"Enter height: ";
std::cin>>h;
int p = (a+b)/2;
int s = p*h;
std::cout<<s;
return 0;
}