#include <iostream>
using namespace std;

int main()
{
    while(1){
        cout<<"Select octal and hexadecimal number system\nWrite 8 or 16\n";
        int numSys,num;
        cin>>numSys;
        if ((numSys==16) or (numSys==8)){
            cout<<"Enter your number:\n";
            cin>>num;
            switch(numSys){
                case 16:
                cout<<"Hexadecimal number: "<<hex<<num<<endl;
                break;
                case 8:
                cout<<"Octal number: "<<oct<<num<<endl;
                break;
            }
        }else{
        cout<< "Invalid input\n";
        }
        
    }
    return 0;
}