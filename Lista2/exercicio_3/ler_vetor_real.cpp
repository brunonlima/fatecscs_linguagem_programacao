#include <iostream>


void LeVetorReal(int prN, float *prV ) {
    
    prV = ( float* ) malloc ( sizeof ( float ) * prN ) ;

    for ( int i = 0 ; i < prN ; i ++ ) {
        std::cout<<"Forneça o valor real para V["<<i+1<<"] :\n " ;
        std::cin>>prV[i];	
    }    

    for ( int i = 0 ; i < prN ; i ++ ) {
        std::cout<<"O valor para V["<<i+1<<"] é : "<<prV[i]<<"\n" ;	
    }

    free( prV );    
}


int main ( void ) {

   int N = 0 ;
   float *v ;

   do {
   
       std::cout<<"Forneça um valor positivo para N:\n";
       std::cin>>N;	   
   
   } while ( N < 0 ) ;
   
  LeVetorReal( N , v ) ;
  
  std::cin.ignore().get() ;

  return ( 0 ) ;

}
