#include <iostream>
#include <vector>
#include <iterator>
#include <list>
void sist(int n, int sis){
    char el[6] = {'A','B','C','D','E','F'};
    std::vector<char> v;
    while (n!=0)
    {
        switch (n % sis)
        {
        case 10:
            v.insert(v.begin(), el[0]);
            break;
        case 11:
            v.insert(v.begin(), el[1]);
            break;
        case 12:
            v.insert(v.begin(), el[2]);
            break;
        case 13:
            v.insert(v.begin(), el[3]);
            break;
        case 14:
            v.insert(v.begin(), el[4]);
            break;
        case 15:
            v.insert(v.begin(), el[5]);
            break;
        default:
            v.insert(v.begin(), char(n % sis));
            break;
        }    
        n /= (int)sis;
    }
    std::copy(v.begin(), v.end(), std::ostream_iterator<char>(std::cout, ""));
}
int main()
{
    int namber;
    std::cout << "Enter the number: "; std::cin >> namber; std::cout << std::endl;
    int sis;
    std::cout << "Enter the number system: "; std::cin >> sis; std::cout << std::endl;
    
    sist(namber,sis);
    return 0;
}
