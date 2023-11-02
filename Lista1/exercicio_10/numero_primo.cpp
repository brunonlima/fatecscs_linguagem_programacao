#include <iostream>

using namespace std;

int main (void) {

  int num = 0, div = 0;

  cout << "Digite um número inteiro";
  cin >> num;

  for (int i = 1; i <=  num; i++ ) {
      if (num % i == 0) {
        div++;
      }
  }

  if (div == 2) 
     cout << "O número "<<num<<" é primo!";
  else 
     cout << "O número "<<num<<" não é primo!";

  cin.ignore().get();

  return 0;

}
