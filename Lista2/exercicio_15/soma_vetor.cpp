#include <iostream>
#define L 3
#define C 6

void print_vector(float*  v, int line) { 

  int i = 0;
 
  for ( i = 0 ; i < line ; i++ ) {
	  
      std::cout<<v[i]<<",\t";
 
      std::cout<<"\n";
  }

  free(v);
}

void print_matrix(float** m, int line, int column) { 

  int i = 0,  j = 0 ;
 
  for ( i = 0 ; i < line ; i++ ) {
  
    for (j = 0 ; j < column ; j++) {
	  
      std::cout<<m[i][j]<<",\t";
   
    }
 
      std::cout<<"\n";
  }
  
  free(m);      
}


float *init_vector(int line) {
    
   float *v;
  
   v = ( float* ) malloc ( sizeof( float ) * line ) ;


   return v;
}

float **init_matrix(int line , int column) {
    
   float **m;
  
   m = ( float** ) malloc ( sizeof( float ) * line ) ;

   for ( int i = 0 ; i < line ; i++ ) {
       m[i] = ( float*) malloc ( sizeof ( float ) * column ) ;
   }

   return m;
}


float** assign_matrix(float **m, int line,int column) {

   for (int  i = 0 ; i < line ; i++ ) {
      
     for (int j = 0 ; j < column ; j++ ) {
	    std::cout<<"Forneça o valor de M["<<i+1<<"]["<<j+1<<"]\n" ;
	    std::cin>>m[i][j] ;
      }
						          
    }

  return m;

}

float* assign_vector(float **m, int line,int column,float* (*ptr)(int)) {
    
  float* v = (ptr)(C);
  float sum = 0 ;

   for (int  j = 0 ; j < column ; j++ ) {
      
     for (int i = 0 ; i < line ; i++ ) {

	     sum = sum + m[i][j] ;
     }
      
      v[j] = sum ;
      sum = 0 ;
    }

  return v;

}
int main (int argc, char ** argv) {

  float** M;
  float*  V;

  float** (*ptr_matrix)( int, int) = &init_matrix;
  
  void (*ptr_print_matrix)(float**, int, int) = &print_matrix;
  void (*ptr_print_vector)(float*, int) = &print_vector;



  std::cout<<"\n*** Matrix 3 x 6 ***\n";
  M = assign_matrix((ptr_matrix(L,C)), L, C) ;

  V = assign_vector(M,L,C,&init_vector);

  std::cout<<"\n*** Vector  ***\n";
  ptr_print_vector(V,C); 
  
  
  std::cout<<"\n*** MATRIX 3 x 6 ***\n";
  ptr_print_matrix(M,L,C); 
  
  std::cin.ignore().get() ;

  return (0);
}
