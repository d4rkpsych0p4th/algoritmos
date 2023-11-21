/**
 * @file insercion.cpp
 * @author Chantal López 
 * 
 * Actividad 2 - Análisis y diseño de algoritmos 
 * Ordenación por inserción
 * 
 */

#include <iostream>

using namespace std;


/*
 * Algoritmo de Ordenación por Insercción
 * Ordena un array de números de menor a mayor
 * El primer for marca el elemento clave el 
 * cual vamos a meter en nuestro "subvector ordenado"
 * en su posicion correcta (segundo for). Los elementos anteriores a 
 * ese elemento clave es el subvector ordenado.
 * Complejidad temporal: O(num_datos^2)
 * Complejidad espacial: O(1)
 *
 */
void ordenarInsercion(int *a, int size);


int main()
{
    int num_datos;
    int* array_num;

    cin>>num_datos;

    array_num= new int[num_datos];

    for(int i=0; i<num_datos; i++){
        cin>>array_num[i];
    }

    ordenarInsercion(array_num, num_datos);
    

    delete[] array_num;

    return 0;
}


void ordenarInsercion(int *a, int size){
    int temp;
    int pos=-1;

    if(size>0){
        for(int i=1; i<size; i++){ 
            temp=a[i];
            
            //subvector ordenado buscamos la posicion para insertar
            for(int j=i-1; j>=0; j--){          //T(n)= i + 1 ( el + 1 es por la condicion del 1º for)
                if(temp<a[j]){
                    a[j+1]=a[j]; //Desplazamos a la derecha
                    pos=j;
                }
                    
            }

            if(pos!=-1){
                a[pos]=temp;
            }
            

            for(int k=0; k<size;k++){
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }
    }
}


/*Resuelta la complejidad en clase 
//El 1º for sucede Σ(i + 1) + 1 (se le suma el uno por el for) sumatorio que va desde i=1 (pq el 1ºfor empieza en 1) hasta n-1

El 2º for sucede  i + 1 (el mas 1 es por la condicion)

Resolvemos el sumatorio del 1º for 
    Σ(i + 1)
    (descomponemos)
   = Σ i + Σ 1
   (aplicamos formulas de wikipedia)
   = n(n-1)/2 + n -1 
   = (n^2 - n + 2n)/2 + 1 
   = n^2/2 + n/2 + 1


=> Función tiempo T(n)= n^2/2 + n/2 + 1 (+1 se anula ya que 1+1=1)y la complejidad temporal es O(n^2)


*/