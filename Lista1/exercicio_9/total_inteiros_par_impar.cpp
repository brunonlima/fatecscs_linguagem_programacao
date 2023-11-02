#include <iostream>

using namespace std;

int main (void)
{
   int num = 0 ,total_par = 0, total_impar = 0;

   do {
      cout << "Digite um número:";
      cin >> num;	     

      if (num % 2 == 0)  {
         total_par = total_par + num;
      }
      else {
         total_impar = total_impar + num;
      }
     
   } while (num > 0);

   cout << "Total par:" << total_par <<"\n" ;
   cout << "Total ímpar: " << total_impar;

  cin.ignore().get(); 
}
