#include <iostream>

int main()
{
    long long n = 1;
    bool t = true;
    while(n < 10000000){
        long long i = n;
        while(i != 1){
            if(i%2 == 0){
                i = i / 2;
            }else{
                i = i * 3;
                i++;
                i = i / 2;
            }
        }
        n++;
    }
    std::cout << "Function finished => Sirakuz hyphotesys works for all numbers up to 10000000";
    return 0;
}