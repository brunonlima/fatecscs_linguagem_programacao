#include <iostream>
#define N 10

void print_vector(int* vet, int tam) { 

  for ( int i = 0 ; i < tam ; i++ ) { 
      std::cout<<vet[i]<<",\t";
  }
  
  free(vet);      
}


int *init_vector(int* vet, int tam) {
    
   vet = ( int* ) malloc ( sizeof( int ) * tam ) ;

   return vet;
}

int verifica_repetido(int* v, int n, int qtd) {

    for (int i = 0 ; i < qtd ; i++) {

	if (v[i] == n) {
	   return (1) ;
	}    
    
    }
    
    return (0);
}

int* preenche_vetor(int *vet, int tam) {

 int repetido = 0;

  for ( int i = 0 ; i < tam ; i++ ) {
     do {
       std::cout<<"Forneça o valor de vet["<<i+1<<"]\n" ;
       std::cin>>vet[i];

        repetido = verifica_repetido(vet,vet[i],i);

       if (repetido == 1) {
     
         std::cout<<"Números repetidos não são permitdos!\n" ;
       }
     
      } while(repetido == 1) ; 
	
  }
  return vet;

}


int main (void) {

  int *A ;

  int* (*ptr)(int*, int) = &init_vector;
  void (*ptr_print)(int*, int) = &print_vector;

  A = preenche_vetor((ptr(A,N)), N);
  
  ptr_print(A,N); 

  std::cin.ignore().get() ;

  return (0);
}
