#include <iostream>

void imprime_vetor(float* vet, int tam) {
  
  float soma = 0 ;  

  for ( int i = 0 ; i < tam ; i++ ) { 
      std::cout<<vet[i]<<",\t";
      soma = soma + vet[i] ;
  }

  std::cout<<"\nQuantidade: "<<tam ;
  std::cout<<"\nSomatorio: "<<soma ;
  
  free(vet);      
}


float *init_vector(float* vet, int tam) {
    
   vet = ( float* ) malloc ( sizeof( float ) * tam ) ;

   return vet;
}

void preenche_vetor(void (*print_ptr)(float*,int),float *vet, float *neg, float *pos , int tam) {

  
  int j = 0 , k = 0 ;

  for ( int i = 0 ; i < tam ; i++ ) {
     
     std::cout<<"Forneça o valor de vet["<<i+1<<"]\n" ;
     std::cin>>vet[i];

     if ( vet[i] < 0 ) {
    
	 neg[j] = vet[i] ;
	 j++ ;

     } else {
     
       pos[k] = vet[i] ;
       k++ ;
     }
	
  }
  
  std::cout<<"\n***Vetor Negativo***\n" ; 
  (print_ptr)(neg,j) ; 

  std::cout<<"\n***Vetor Positivo***\n" ;
  (print_ptr)(pos,k) ;
  
  free(vet);

}

int main (void) {
  
  int N = 0 ;
  float *A,*NEG,*POS ;

  do {
    std::cout<<"Forneça o valor N entre 0 e 50\n" ;
    std::cin>>N ;
  
  } while(N < 0 || N > 50);

  float* (*ptr)(float*, int) = &init_vector;

  preenche_vetor(&imprime_vetor ,(ptr(A,N)) , (ptr)(NEG,N) , (ptr)(POS,N) , N);
      
  std::cin.ignore().get() ;

  return (0);
}
