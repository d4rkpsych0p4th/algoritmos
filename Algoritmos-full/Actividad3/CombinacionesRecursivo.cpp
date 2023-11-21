/**
 * @file CombinacionesRecursivo.cpp
 * @author Chantal López 
 * 
 * 
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Devuelve la combinacion sin repetición
 * Función temporal T(n)=n!
 * O(n!)
 * Función espacial T(n)=n!
 * 
 */
long double Combinaciones(int a, int b);

/**
 * Realiza el factorial de un numero
 * Función temporal T(n)=T(n-1) + 1 resuelto => T(n)= n + 1
 * O(n)
 * Función espacial T(n)=1
 * 
 */
long double Factorial(int a);

int main()
{

    int a;
    int b;

    

    cin>>a;
    cin>>b;

    while(a>=0 && b>=0){
        if(a<b){
            cout<<"ERROR"<<endl;
        }
        else{
            cout<< Combinaciones(a,b)<<endl;
        }
        
        cin>>a;
        cin>>b;

    }
    

    return 0;
}


long double Combinaciones(int a, int b){
    long double numerador= Factorial(a);
    long double denominador= Factorial(b)*Factorial(a-b);

    return numerador/denominador; 

}


long double Factorial(int a){
    long double n=a;
    if(a!=0){
        return n=a*Factorial(a-1);
    }
    else{
        return 1;
    }
}

