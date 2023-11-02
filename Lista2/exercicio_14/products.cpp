#include <iostream>
#define L 5
#define C 20


typedef struct Product {
      int num_prod , num_shop ;
      float price ;
}Product ;


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


float **init_matrix(int line , int column) {
    
   float **m = ( float** ) malloc ( sizeof( float* ) * line ) ;

   for (int  i = 0 ; i < line ; i++ ) {
       m[i] = ( float*) malloc ( sizeof ( float ) * column ) ;
   }

   return m;
}


float** assign_matrix(float**(*ptr)(int,int), int line,int column) {
    
  Product *product = (Product*) malloc (sizeof(Product)) ;
  float **m = (ptr)(line,column) ; 	
  int i , j ;

  for (i = 0 ; i < line ; i++ ) {
      
    for (j = 0 ; j < column ; j++ ) {
	std::cout<<"Input the price of product["<<j+1<<"] - Shop["<<i+1<<"]\n" ;
	std::cin>>m[i][j] ;
	  
        if ( i == 0 && j == 0 ) {
           
	   product->price = m[0][0];         
        }

        if ( m[i][j] < product->price ) {
            
          product->price = m[i][j] ;
          product->num_prod = j ;
          product->num_shop = i ;
        }
     }
      						          
  }
    
  std::cout<<"The short price is "<<product->price<<" of product "<<product->num_prod+1<<" from shop "<<product->num_shop+1<<"\n";

  free(product);

  return m;
}

int main (int argc, char ** argv) {
  
  float** prices ;
  
  void (*ptr_print_matrix)(float**, int, int) = &print_matrix ;

  std::cout<<"\n*** Matrix Prices ***\n" ;
  prices = assign_matrix(&init_matrix, L, C) ;
  
  std::cout<<"\n*** MATRIX Prices ***\n" ;
  ptr_print_matrix(prices,L,C) ; 
  
  std::cin.ignore().get() ;

  return (0);
}
