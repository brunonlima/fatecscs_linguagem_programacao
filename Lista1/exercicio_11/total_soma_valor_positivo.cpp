#include <iostream>

int main (void) {
   
    int N = 0;
    float total = 0,num = 0;

    do {
	 std::cout<<"Forneça um valor N positivo e maior que 0 ";
	 std::cin>>N;

    } while (N <=0);

    for ( int i = 0; i < N ;i++ ) {
	    
	 std::cout<<"("<<i+1 <<")"<<" Forneça um valor real";
	 std::cin>>num;
         
	 if (num >= 0) {
	    total = total +num;
	 }
    }

     std::cout<<"Total de números fornecidos positivos: "<<total;

     std::cin.ignore().get();

     return 0;
}
