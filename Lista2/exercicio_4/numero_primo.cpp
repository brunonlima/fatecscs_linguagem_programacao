#include <iostream>


int EPrimo (int prN) {

  int div = 0 ;

  for (int i = 1; i <=  prN; i++ ) {
      
      if (prN % i == 0) 
         div++;
      
  }

  if (div == 2) { 
    
      std::cout << "O número "<<prN<<" é primo!\n"; 
      return (prN + ((rand() % 10) + 1 ));
 
  }  else  
       std::cout << "O número "<<prN<<" não é primo!\n"; return ( 0 );
}



int main (void) {

  int N = 0, retorno;

  std::cout << "Digite um número inteiro\n";
  std::cin >> N;
   
  retorno = EPrimo(N);
  std::cout<<"Retorno função: "<<retorno;

  std::cin.ignore().get();

  return ( 0 ) ;

}
