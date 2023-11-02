#include <iostream>
#define N 15 

void print_vector(int* vet, int tam) { 

  for ( int i = 0 ; i < tam ; i++ ) { 
      std::cout<<vet[i]<<",\t";
  }
  
}

int *init_vector(int* vet, int tam) {
    
   vet = ( int* ) malloc ( sizeof( int ) * tam ) ;

   return vet;
}

void vet_uniao (int* A, int* B, int tamA, int tamB, int* (*ptr)(int*,int) ) {
    
  int* uniao = ptr( uniao , tamA + tamB );
  int  i = 0 , tamUniao = 0 , j = 0 , repetido = 0;
    
  for (tamUniao = 0; tamUniao < tamA; tamUniao++)
     uniao[tamUniao] = A[tamUniao];
   
  for (i = tamA ; i < tamA + tamB ; i++) {    
        
      repetido = 0; // Inicia com 0 a cada loop.
        
      for (j = 0; j < tamA; j++) {
	
	  if (B[i - tamA] == A[j]) { 
	      repetido = 1;
	      break;
	   }
       }
        
       if (repetido == 0) { // Se o repetido for falso, ele entra na união.
	    uniao[tamUniao] = B[i - tamA];
	    tamUniao++;
       }  
   }

  std::cout<<"\n*** Vetor UNIÃO ***\n" ;
  print_vector(uniao,tamUniao);
  
  free(uniao); 

}

void vet_inter (int* A, int* B, int tamA, int tamB , int* (*ptr)(int*,int) ) {

 int* inter = ptr( inter , tamA + tamB );
 int  i = 0 , tamInter = 0 , j = 0 , repetido = 0;

 for (i = 0; i < tamA; i++) {
   
     for (j = 0; j < tamB; j++) {
	
	  if (A[i] == B[j]) { 

	     inter[tamInter] = A[i];
	     tamInter++; 
	     break;
	  }
      }
  }
 
 std::cout<<"\n*** Vetor INTERSECÇÃO ***\n" ;
 print_vector(inter,tamInter);

 free(inter); 

}

void vet_dife (int* A, int* B, int tamA, int tamB , int* (*ptr)(int*,int) ) {
 
 int* dife = ptr( dife , tamA + tamB );
 int  i = 0 , tamDife = 0 , j = 0 , repetido = 0;

 for (i = 0; i < tamA; i++) {
 
    repetido = 0;
    
    for (j = 0; j < tamB; j++) {
        
       if (A[i] == B[j]) { // Se o valor do vetor A for igual ao valor do vetor B.
	    
	  repetido = 1; // Será verdadeiro e ele sairá do loop.
          break;
      	}
     }
    
     if (repetido == 0) { // Se for falso, ele irá igualar dife a A e incrementar o índice.
        dife[tamDife] = A[i] ;
        tamDife++ ;
     }																	  } 
 
 
 std::cout<<"\n*** Vetor DIFERENÇA ***\n" ;
 print_vector(dife,tamDife);
 
 free(dife);

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


int main (int argc , char** argv) {

  int *A,*B,tamA = N ,tamB = N ;
  
  int* (*ptr)(int*, int) = &init_vector;
  void (*ptr_print)(int*, int) = &print_vector;

  std::cout<<"\n*** VETOR A ***\n" ;
  A = preenche_vetor((ptr(A,tamA)), tamA);
 
  std::cout<<"\n*** VETOR B ***\n" ;
  B = preenche_vetor((ptr(B,tamB)), tamB);
  
  std::cout<<"\n*** VETOR A ***\n" ;
  ptr_print(A,tamA);
  
  std::cout<<"\n*** VETOR B ***\n" ;
  ptr_print(B,tamB);
  
  vet_uniao(A,B,tamA,tamB,&init_vector);
  vet_inter(A,B,tamA,tamB,&init_vector);
  vet_dife(A,B,tamA,tamB,&init_vector);

  free(A);
  free(B);

  std::cin.ignore().get() ;

  return (0);
}
