/**
 * @file RaizCuadrada.cpp
 * @author Chantal López 
 * 
 * 
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * Devuelve la raíz cuadrada de un numero con un error dado
 * Función temporal T(n)=T(n/2) + 1 resuelto => T(n)= 1 + (log(n)/log(2)) (Esta bien)
 * O(log(n))
 * Función espacial T(n)=1
 */
void raizCuadrada(double num,double sup,double inf, double error);

int main()
{
    double numero;
    double error;

    cin>>numero;
    cin>>error;

    if(numero<=0 || error<=0){
        cout<<"ERROR"<<endl;
    }
    else{
        raizCuadrada(numero,numero,0,error);
    }

    
    return 0;
}


//se podria haber utilizado el fabs que es el valor absoluto de la resta para que siempre diese positivo
void raizCuadrada(double num,double sup, double inf,double error){
    double mitad;
    double limite_inf=inf;
    double limite_sup=sup;

    mitad=(limite_sup+limite_inf)/2;
  
    if(mitad*mitad>num){
        if((mitad*mitad)-num<=error){
            cout<<mitad<<endl;
        }
        else{
            cout<<mitad<<endl;
            raizCuadrada(num,mitad,limite_inf,error);
        }
        
        
    
    }
    else{
        if(num - (mitad*mitad)<=error){ 
            cout<<mitad<<endl;
        }
        else{
            cout<<mitad<<endl;
            raizCuadrada(num,limite_sup,mitad,error);
        }
            
        
    }    
   
}

/**
 * Apuntes en clase 
 * n= numero/error
 * Complejidad temporal: T(n)=T(n/2) + 1 (se hace n/2 ya que cuando llamamos a la funcion se ha dividido el espacio entre dos)
 * 
 */


//Dice que en el examen no va a ver que resolver esto solo llegar hasta  T(n)=T(n/2) + 1 pero qye no va a ver algo tan dificil (no me fio)