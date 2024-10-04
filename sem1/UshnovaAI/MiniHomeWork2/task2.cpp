#include <iostream>
using namespace std;

int main()
{
    while(1){
        cout<<"Enter any natural number\n";
        int num;
        cin>>num;
        while (num>1){
            if (num%2==0){
                num=num/2;
                cout<<num<<endl;
            } else if (num%2==1){
                num=(num*3+1)/2;
                cout<<num<<endl;
            }  
        }
    }
    return 0;
}