#include <iostream> 


int main()
{ 
    int pl1 = 0 ;
    int pl2 = 1 ;
    int nextPl; 
    int plN;
     
     std::cout << "Vvedite kol-vo cifr "; 
     std::cin >> plN; 
     
     for (int pl = 1; pl < plN; ++pl) 
     { 
         if (pl == 1) 
         { 
             std::cout << pl1 << ":" ; 
         } 
         if (pl == 2)  
         { 
             std::cout << pl2 <<  ":" ; 
         } 
         else { 
             nextPl = pl1 + pl2 ; 
             pl1 = pl2; 
             pl2 = nextPl; 
             
     std::cout<< nextPl << ":" ;  
      
         } 
     } 
      
} 
    
    
    

   
