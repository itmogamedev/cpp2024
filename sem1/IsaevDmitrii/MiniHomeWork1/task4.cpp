#include <iostream>
#include <cmath>
 int reverse(int N) {
    int ans = 0;
    int numCounter = 0;
    for (int i = 1; (N % (int)pow(10, (i - 1))) != N; i++) {
        numCounter++;
    }
    for (int i=1; (N % (int)pow(10, (i - 1))) != N; i++) {
        int num = N % (int)pow(10, i) / (int)pow(10,i-1);
        ans += num * (int)pow(10, (numCounter-i));
    }
    return ans;
}

int main()
{
    int N;
    
    std::cin >>N;
    std::cout<<reverse(N);
}