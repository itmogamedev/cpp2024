#include <iostream>
 

long SirNum;

int main()
{
    std::cout << "Lets try Syracuse hypothesis. Enter you number ";
    std::cin >> SirNum;
    std::cout << "We will act according to the algorithm and show the value after each iteration" << "\n";
    int SirNumEter = SirNum;
    while (SirNumEter != 1)
    {
        if (SirNumEter % 2 == 0)
        {
            std::cout << SirNumEter << "/2 = ";
            SirNumEter = SirNumEter / 2;
            std::cout << SirNumEter << "\n";
        }
        else
        {
            std::cout << "((" << SirNumEter << " * 3)+ 1) / 2 = ";
            SirNumEter = ((SirNumEter * 3) + 1) / 2;
            std::cout << SirNumEter << "\n";
        }
    }
    std::cout << "Finally we have 1";
}