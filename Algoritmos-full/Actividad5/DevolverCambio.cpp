/**
 * @file DevolverCambio.cpp
 * @author Chantal López 
 * Esto es un algoritmo voraz
 */

#include <iostream>
#include <string>

#define MONEDAS 8

using namespace std;

/**
 * Imprime el cambio de un determinado número introducido 
 * por parametros.
 * 
 * Complejidad temporal:  O(n)
 * Complejidad espacial: O(n) //pq son 8 monedas entonces son n 
 * 
 */
void Cambio(int a);


int main()
{

    int a;

    cin>>a;

    while(a>=0){

        Cambio(a);

        cout<<endl;
        
        cin>>a;

    }
    

    return 0;
}

//Esto el lo hace con divisiones que es como se hace un algoritmo voraz
//La complejidad seria O(n) ya que se hace el while en base al número de monedas no en b
void Cambio(int a){
    //Creamos array de monedas
    int b=a;
    int cambio[]= {0,0,0,0,0,0,0,0};
    int monedas[]= {500,200,100,50,25,10,5,1};

    //Calculamos monedas 
    int pos=0;
    while(b!=0){ //T(n)=n+1
        if(b>=monedas[pos]){
            cambio[pos]++;
            b-=monedas[pos];
        }
        else{
            pos++;
        }
    }

    
    for(int i=0; i<MONEDAS; i++){
        cout<<cambio[i]<<" ";
    }


}



