#include <iostream>

int main (void) {

   int min = 0, max = 0 ;

   do {

      std::cout << "Forneça o valor minimo:\n" ;
      std::cin >> min ;	      
   
      std::cout << "Forneça o valor máximo:\n" ;
      std::cin >> max ;	      
   
      if (min >= max) {
      
         std::cout << "O valor máximo não pode ser menor ou igual ao valor mínimo!\n" ;
      
      }

   } while (min >= max) ;

   
   for (int i = min ; i <= max ; i++) {
       
       if ( i % 5 == 0 ) {
          
          std::cout << i << ",\t" ;
       }	   
   
   }

  std::cin.ignore().get();

  return 0 ;
}
