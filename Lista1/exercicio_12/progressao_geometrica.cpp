#include <iostream>

int main (void) {
    
    int N = 0 ;
    float a = 0, r = 0, total =0 ;

    do {

       std::cout<<"Forneça o valor N\n";
       std::cin>>N;
    
    } while (N <= 0);

    std::cout<<"Forneça o valor R\n";
    std::cin>>r;

    std::cout<<"Forneça o valor P1\n";
    std::cin>>a;
    
    std::cout<<"Progressão geométrica:\n";


    for ( int i = 0; i < N; i++ ) {
		    
        std::cout<<"(P"<<i+1<<") =  "<<a<<", \n";
	a = a * r;
    
    }

    std::cin.ignore().get();
    
    return 0;   

}
