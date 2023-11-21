/**
 * @file PalindromoRecursivo.cpp
 * @author Chantal López 
 * 
 * 
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Devuelve 0 si no es un palindromo y 1 si lo es
 * n= numero de letras de la palabra
 * Función temporal T(n)=T(n-2) + 1 = n/2 
 * O(n)
 * Función espacial M(n)=M(n-2) + 1 = n/2
 * O(n)
 */
int Palindromo(const string palabra);

int main()
{

    string palabra;

    cin>>palabra;

    cout<< Palindromo(palabra);

    return 0;
}


int Palindromo(const string palabra){
    string palabra_acortada;
    int ultima_pos=palabra.length()-1;

    if(palabra.length()>=2){
         if(palabra[0]==palabra[ultima_pos]){
             palabra_acortada=palabra.substr(1,ultima_pos-1);
             return Palindromo(palabra_acortada);
         }
        else{
            return 0;
        }
    }
    else{
        return 1;
    }
   


}