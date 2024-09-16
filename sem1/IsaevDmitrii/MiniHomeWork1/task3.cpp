#include <iostream>

void fibonachi(int N, int counter, int least1,int least2)
{
    if (counter >= N)
        return;
    if (counter == 0 or counter == 1) {
        std::cout << 1 <<' ';
        return (fibonachi(N, counter + 1, 1, 1));
    }
    std::cout << least1 + least2 << ' ';
    return(fibonachi(N,counter+1,least2, least1 + least2));
}

int main()
{
    int N;
    std::cin >>N;
    fibonachi(N,0,0,0);
}