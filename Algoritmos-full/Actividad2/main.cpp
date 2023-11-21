/**
 * @file seleccion.cpp
 * @author Chantal López 
 * 
 * Actividad 2 - Análisis y diseño de algoritmos 
 * Ordenación por seleccion, burbuja, insercion
 * 
 */
 


#include <iostream>

using namespace std;



int main()
{
    int num_datos;
    int* array_num;

    cin>>num_datos;

    array_num= new int[num_datos];

    for(int i=0; i<num_datos; i++){
        cin>>array_num[i];
    }


    /*
    * Algoritmo de Ordenación por Selección
    * Ordena un array de números de menor a mayor
    * Complejidad temporal: O(num_datos^2)
    * Complejidad espacial: O(1)
    *
    */

    int min=0;
    int pos=0;
    int temp;


    if(num_datos>0){
        for(int i=0; i<num_datos; i++){
            min=array_num[i];
            pos=i;

            //seleccionamos el mínimo
            for(int j=i+1; j<num_datos; j++){
                if(min>array_num[j]){
                    min=array_num[j];
                    pos=j;
                }

            }

            //intercambiamos las posiciones del mínimo
            temp= array_num[i];
            array_num[i]=array_num[pos];
            array_num[pos]=temp;

            for(int k=0; k<num_datos;k++){
                cout<<array_num[k]<<" ";
            }
            cout<<endl;
        }
    }
    

    delete[] array_num;

    return 0;
}
