#include<iostream>
int main()
{
    int n,k0,k1,k;
    std::cin>>n;
    k0 = 0;
    k1 = 1;
    std::cout<<"0 1 ";
    while((k0+k1)<n)
    {
        k = k0 + k1;
        std::cout<<k<<" ";
        k0=k1;k1=k;
    }
    return 0;
}
