#include <iostream>

using namespace std;

int main(void) 
{
    int num = 0;
    
    cout<<"Digite um número:";
    cin>>num;

    if (num % 2 == 0)
    {
        cout<<"Este número é par";
    } 
    else 
    {
       cout<<"Este número é ímpar";
    }

    cin.ignore().get();
    
    return 0;
}
