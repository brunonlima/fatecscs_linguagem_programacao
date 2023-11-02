#include <iostream>
#include <iomanip>

int main (void) {
   
    int N = 0;
    float total = 0.0, num = 0.0, min, max;

    do {
	 std::cout<<"Forneça um valor N positivo e maior que 0"<<std::endl;
	 std::cin>>N;

    } while ( N <= 0 );


    for ( int i = 0; i < N ;i++ ) {
	    
	 std::cout<<"("<<i+1 <<")"<<" Forneça um valor real"<<std::endl;
	 std::cin>>num;
 
	 if ( num >= 0 ){

	    if ( i == 0 ) {
	       min = num;
	       max = num;
	    }
           
	    if ( num >= min ) {
	     
                if (num >= max ) {
	           max = num;
	    
	        }    
	 
	     }  

	    if ( num <= min ) {
	    
                min = num;
	     }
         }
     }

     std::cout << std::fixed;
     std::cout << std::setprecision(2);
     std::cout<<"Menor número: "<<min<<std::endl;
     std::cout<<"Maior número: "<<max<<std::endl;

     std::cin.ignore().get();

     return 0;
}
