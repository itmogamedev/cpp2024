#include <iostream>

int main()
{
    long long int term1 = 0;
    long long int term2 = 1;
    long long int nextTerm = 0;
    int termN;

    std::cout << "On which term should we end the fibonacci sequence? ";
    std::cin >> termN;


    if (termN == 1)
    {
        std::cout << "0";
    }
    for (int step = 1; step < termN; step++)
    {
        if (step == 1)
        {
            std::cout << term1 << ", ";
        }
        if (step == 2)
        {
            std::cout << term2 << ", ";
        }
        else {

            nextTerm = term1 + term2;
            term1 = term2;
            term2 = nextTerm;

            std::cout << nextTerm << ", ";

        }
    }
}