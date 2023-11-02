#include <iostream>
#define N 3
   
void print_matrix(int** m, int tam) { 

  int i = 0,  j = 0 ;
 
  for ( i = 0 ; i < tam ; i++ ) {
  
    for (j = 0 ; j < tam ; j++) {
	  
      std::cout<<m[i][j]<<",\t";
   
    }
 
      std::cout<<"\n";
  }
  
  free(m);      
}


int **init_matrix(int tam) {
    
   int i = 0,  j = 0 ;
   int **m;
  
   m = ( int** ) malloc ( sizeof( int ) * i ) ;

   for (  i = 0 ; i < tam ; i++ ) {
       m[i] = ( int*) malloc ( sizeof ( int ) * j ) ;
   }

   return m;
}

int ** sum_matrix (int**a , int** b , int tam) {
  
   int** c;
   int i = 0, j = 0 ;

   c = ( int** ) malloc ( sizeof( int* ) * tam ) ;

   for (  i = 0 ; i < tam ; i++ ) {
       c[i] = ( int*) malloc ( sizeof ( int ) * tam ) ;
   }

   
   for (  i = 0 ; i < tam ; i++ ) {
      
     for (j = 0 ; j < tam ; j++ ) {
	  c[i][j] = a[i][j] + b[i][j] ;
      }
						          
    }

   return c ;
}


int** assign_matrix(int **m, int tam) {
 
   int i = 0,  j = 0 ;

   for (  i = 0 ; i < tam ; i++ ) {
      
     for (j = 0 ; j < tam ; j++ ) {
	    std::cout<<"Forneça o valor de M["<<i+1<<"]["<<j+1<<"]\n" ;
	    std::cin>>m[i][j] ;
      }
						          
    }

  return m;

}

int main (int argc, char ** argv) {

  int **A,**B,**C ;

  int** (*ptr)( int) = &init_matrix;
  void (*ptr_print)(int**, int) = &print_matrix;
  int** (*ptr_sum)( int**,int**,int) = &sum_matrix;
  
  A = assign_matrix((ptr(N)), N);
  B = assign_matrix((ptr(N)), N);
  C = ptr_sum(A,B,N);

  std::cout<<"\n*** MATRIX A ***\n";
  ptr_print(A,N); 
  
  std::cout<<"\n*** MATRIX B ***\n";
  ptr_print(B,N); 
  
  std::cout<<"\n*** MATRIX C ***\n";
  ptr_print(C,N); 
  
  std::cin.ignore().get() ;

  return (0);
}
