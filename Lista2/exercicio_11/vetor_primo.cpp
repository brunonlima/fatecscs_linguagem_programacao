#include <iostream>

int EPrimo (int prN) {
  int div = 0 ;
  
  for (int i = 1; i <=  prN; i++ ) {
		          
    if (prN % i == 0) 
       div++;
  }

  if (div == 2) { 
    return (0);
				   
  } else  
     return (1);
}
   
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

int* preenche_vetor(int *vet, int tam) {
  int primo = 0;

   for ( int i = 0 ; i < tam ; i++ ) {
        do { 
	    std::cout<<"Forneça o valor de vet["<<i+1<<"]\n" ;
	    std::cin>>vet[i] ;
	    primo = EPrimo(vet[i]);

            if (primo == 1) {        
		std::cout<<"Apenas são permitidos NÚMEROS PRIMOS no vetor!\n" ;
	    }
						          
   	} while(primo == 1) ; 
			
    }

  return vet;

}

int main (void) {

  int *A, N ;

  do {
    
     std::cout<<"Forneça o valor de N:\n";
     std::cin>>N;     
     
  } while (N < 0);

 
  int* (*ptr)(int*, int) = &init_vector;
  void (*ptr_print)(int*, int) = &print_vector;

  A = preenche_vetor((ptr(A,N)), N);
  
  std::cout<<"\n***VETOR NÚMEROS PRIMOS ***\n";
  ptr_print(A,N); 
  
  std::cin.ignore().get() ;

  return (0);
}
