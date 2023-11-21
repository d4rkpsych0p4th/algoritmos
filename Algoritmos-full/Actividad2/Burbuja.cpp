/**
 * @file Burbuja.cpp
 * @author Chantal López 
 * 
 * Actividad 2 - Análisis y diseño de algoritmos 
 * Ordenación por el método Burbuja
 * 
 */
#include <iostream>

using namespace std;

/*
 * Algoritmo de Ordenación por Burbuja
 * Ordena un array de números de menor a mayor
 * Se comparan el elemento actual con el de la derecha
 * si es mayor se intercambian posiciones.
 * Complejidad temporal: O(num_datos^2)
 * Complejidad espacial: O(1)
 *
 */
void ordenarBurbuja(int *a, int size);

int main()
{
    int num_datos;
    int* array_num;

    cin>>num_datos;

    array_num= new int[num_datos];

    for(int i=0; i<num_datos; i++){
        cin>>array_num[i];
    }

    ordenarBurbuja(array_num, num_datos);


    delete[] array_num;

    return 0;
}

void ordenarBurbuja(int *a, int size){
     int temp;

    if(size>0){
        for(int i=0; i<size-1; i++){
            for(int j=0; j<size-1; j++){
                //si el elemento de la derecha es menor se intercambian posiciones
                if(a[j]>a[j+1]){
                    temp= a[j+1];
                    a[j+1]=a[j];
                    a[j]=temp;

                }

            }

            for(int k=0; k<size;k++){
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }

    }
}

/*Resuelta la complejidad en clase  (su 1º for es i=1; i<size)
//El 1º for sucede Σ() + 1 (se le suma el uno por el for) sumatorio que va desde i=1 hasta n-1

Su 2º for es j=0; i<size-i
El 2º for sucede  n - i + 1 (el mas 1 es por la condicion)

Resolvemos el sumatorio del 1º for 
    Σ(n - i + 1)
    (descomponemos)
   = Σn  - Σi + Σ1 
   (aplicamos formulas de wikipedia)
   = n*(n-1) - n(n-1)/2 + n - 1
   = n^2 - n - (n^2 - n) / 2 + n - 1
   = (2n^2 - 2n - n^2 - n + 2n - 1) / 2
   = n^2/2 + n/2 + 1 


=> Función tiempo T(n)= n^2/2 + n/2 + 1 y la complejidad temporal es O(n^2)

https://es.wikipedia.org/wiki/Sumatorio 

*/