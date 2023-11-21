/**
 * @file CombinacionesDinamica.cpp
 * @author Chantal López 
 * 
 * 
 * programacion dinamica la creas y la consultas o la vas creando a la misma vez 
 */

#include <iostream>
#include <string>

#define NIVELES 10

using namespace std;

//El triangulo deberia estar en otra funcion y la combinaciones solamente en una 

/**
 * Devuelve la combinación sin repetición
 * Complejidad temporal: O(n^2)
 * Complejidad espacial: O(n^2)
 */
double Combinaciones(int a, int b);


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

//Cada vez que depende algo de i hacer lo de los sumatorios 

/**
 * Devuelve la combinación sin repetición
 * Función de tiempo: T(n)= n+ Σ(i+1) + 1 => resolver 
 * El 1º for sucede  Σ(i+1) + 1 desde i=0 hasta i=n-1 
 * El 2º for sucede i+1
 * Resolvemos: Σ(i+1) + 1
 *  Σi + Σ1 + 1 = n(n-1)/2 + n + 1 = (n^2 - n + 2n + 2)/2 
 *  T(n)=(2n + n^2 - n + 2n + 2)/2 = (n^2 + 3n + 2)/2
 * 
 * Complejidad temporal: O(n^2)
 * Complejidad espacial: O(n^2)
 */

double Combinaciones(int a, int b){
    //vamos a crear una piramide de 10 niveles
    int** piramide= new int *[NIVELES];

    //Reservamos memoria
    for(int i=0; i<NIVELES; i++) {
        piramide[i]= new int[i+1];
    
    }

    //Rellenamos piramide
    for(int i=0; i<NIVELES; i++){ //T(n)=Σ(i+1) + 1
        for(int j=0; j<i+1;j++){   //T(n)=i + 1
            if(i==j || j==0){
                piramide[i][j]=1;
            }
            else{
                piramide[i][j]=piramide[i-1][j-1]+piramide[i-1][j];
            }
            
        }
    }

    return piramide[a][b];

}



