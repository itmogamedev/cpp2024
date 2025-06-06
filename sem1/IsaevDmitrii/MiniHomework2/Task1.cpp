#include <iostream>
#include <string>

std::string numBaseMax16(int num10, int n)
{
    std::string result;
    char base[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','F' };
    while(num10/n!=0)
    {
        result += base[num10 % n];
        num10 /= n;
    }
    result += base[num10 % n];
    reverse(result.begin(),result.end());
    return result;
}
int main()
{
    int num;
    std::cin >> num;
    std::cout << numBaseMax16(num, 8) << "\n" << numBaseMax16(num, 16);
}