#include <iostream> 
#include <string> 
 
using namespace std; 
 
string decToOct(int dec) { 
  string oct = ""; 
  if (dec == 0) { 
    return "0";  
  } 
  while (dec > 0) { 
    int remainder = dec % 8;  
    oct = to_string(remainder) + oct;  
    dec /= 8;  
  } 
  return oct; 
} 
 
string decToHex(int dec) { 
  string hex = ""; 
  if (dec == 0) { 
    return "0";  
  } 
  while (dec > 0) { 
    int remainder = dec % 16;  
    if (remainder < 10) {  
      hex = to_string(remainder) + hex; 
    } else {   
      char hexDigit = 'A' + (remainder - 10);  
      hex = hexDigit + hex;  
    } 
    dec /= 16;  
  } 
  return hex; 
} 
 
int main() { 
  int decNum; 
  cout << "Десятичное число: "; 
  cin >> decNum; 
 
  cout << "Восьмеричное число: " << decToOct(decNum) << endl; 
  cout << "Шестнадцатеричное число: " << decToHex(decNum) << endl; 
 
  return 0; 
}
