#include <iostream>
using namespace std;
 
int main() {  
    int nm, reverse = 0, rem;    
    cout << "Enter a number: ";    
    cin >> nm;    
    while (nm > 0) {    
        rem = nm % 10;      
        reverse = reverse * 10 + rem;    
        nm /= 10;    
    }    
    cout << "Reversed Number: " << reverse << endl;     
    return 0;  
}
