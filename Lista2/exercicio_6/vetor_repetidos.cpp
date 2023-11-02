#include <iostream>
#define N 20

void imprime_vetor(float* vet, int tam) { 

  for ( int i = 0 ; i < tam ; i++ ) { 
      std::cout<<vet[i]<<",\t";
  }
  
  free(vet);      
}


float *init_vector(float* vet, int tam) {
    
   vet = ( float* ) malloc ( sizeof( float ) * tam ) ;

   return vet;
}

float* preenche_vetor(float *vet, int tam) {

  for ( int i = 0 ; i < tam ; i++ ) {
     
     std::cout<<"Forneça o valor de vet["<<i+1<<"]\n" ;
     std::cin>>vet[i];
	
  }
  return vet;

}

void vetor_resultante(float* (*ptr)(float* , int), float* vet, void(*print_ptr)(float*, int ) ) {
    
    float *resultante,*eliminado;
    int j = 0, k = 0 , cont = 0;  
 
    resultante = (ptr)(resultante,N);
    eliminado = (ptr)(eliminado,N);
   

    for ( int i = 0 ; i < N ; i++ ) {
      
       for ( j = 0 ; j < cont ; j++ ) {
          
	  if (vet[i] == resultante[j]) {
             eliminado[k] = vet[i];
	     k++;
             break;
	  }
      
        }   
       
        if ( j == cont ) {
         
	  resultante[cont] = vet[i];
          cont++;
          
	}	  
         
    }
    
  std::cout<<"\n***Vetor Resultante***\n" ; 
  (print_ptr)(resultante,cont) ; 

  std::cout<<"\n***Vetor Eliminado***\n" ;
  (print_ptr)(eliminado,k) ;
}


int main (void) {

  float *A ;

  float* (*ptr)(float*, int) = &init_vector;

  A = preenche_vetor((ptr(A,N)), N);

  vetor_resultante(&init_vector,A,&imprime_vetor);

  std::cin.ignore().get() ;

  return (0);
}
