#include <iostream>

void imprime_vetor(int* vet, int tam) { 

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

  for ( int i = 0 ; i < tam ; i++ ) {
     
     std::cout<<"Forneça o valor de vet["<<i+1<<"]\n" ;
     std::cin>>vet[i];
	
  }
  return vet;

}

void junta_vetor(int* (*ptr)(int* , int), int* A, int* B,int NA,int NB,void(*print_ptr)(int*, int ) ) {
    
    int *vetor_juncao;
    int NC;
    NC = NA + NB;
    
    vetor_juncao = (ptr)(vetor_juncao,NC);
    
    int i;
    for ( i = 0 ; i < NA ; i++ ) {
         vetor_juncao[i] = A[i];
    }

    for ( int j = 0 ; j < NB ; j++ ) {
        vetor_juncao[i] = B[j] ;
        i++ ;//desta forma você atualiza a posição em que será inserido no vetor c
    }

    std::cout<<"\n***Vetor Junção***\n" ; 
    (print_ptr)(vetor_juncao,NC) ; 

}


int main (void) {

  int *A, *B, NA, NB ;

  do {
    
     std::cout<<"Forneça o valor de NA:\n";
     std::cin>>NA;     
     
  } while (NA < 0 || NA > 20);

  do {
    
     std::cout<<"Forneça o valor de NB:\n";
     std::cin>>NB;     
     
  } while (NB < 0 || NB > 20);
 
  int* (*ptr)(int*, int) = &init_vector;

  A = preenche_vetor((ptr(A,NA)), NA);
  B = preenche_vetor((ptr(B,NB)), NB);
 
  junta_vetor(&init_vector,A,B,NA,NB,&imprime_vetor);

  std::cin.ignore().get() ;

  return (0);
}
