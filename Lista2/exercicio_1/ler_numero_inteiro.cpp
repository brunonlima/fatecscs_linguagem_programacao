#include <iostream>


int LeNumInt(int prMin, int prMax) {
    
    if ( ( prMin != 0 ) && ( prMax != 0 ) ) 
       return ( (prMin / 2 ) + ( prMax / 2 ) ) ;

    if ( ( prMin != 0 ) && ( prMax == 0 ) ) 
       return ( prMin + ( rand() % 10 + 1 ) ) ;
     
    if ( ( prMin == 0 ) && ( prMax != 0 ) )  
       return ( prMax - ( rand() % 10 + 1 ) ) ;
   
    return ( 0 ) ;
}


int main ( void ) {

   int prMin, prMax ;
   
   do {
     std::cout << "Forneça o valor prMin maior que Zero:\n" ;
     std::cin >> prMin ;
   } while ( prMin < 0 ) ;
   
   do {
     std::cout << "Forneça o valor prMax maior que Zero:\n" ;
     std::cin >> prMax ;
   } while ( prMax < 0 ) ;

   std::cout << "retorno da função:" << LeNumInt(prMin,prMax) ;

   std::cin.ignore().get() ;

   return ( 0 ) ;

}
