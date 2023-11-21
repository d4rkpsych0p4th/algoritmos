/**
 * @file seleccion.cpp
 * @author Chantal López 
 * 
 * Actividad 2 - Análisis y diseño de algoritmos 
 * Ordenación por selección
 * 
 */
 


#include <iostream>

using namespace std;

/*
 * Algoritmo de Ordenación por Selección
 * Ordena un array de números de menor a mayor
 * Busca el mínimo y lo intercambia con el elemento 
 * de la posicion i.
 * Complejidad temporal: O(num_datos^2)
 * Complejidad espacial: O(1)
 *
 */
void ordenarSeleccion(int *a, int size);

int main()
{
    int num_datos;
    int* array_num;

    cin>>num_datos;

    array_num= new int[num_datos];

    for(int i=0; i<num_datos; i++){
        cin>>array_num[i];
    }
    
    ordenarSeleccion(array_num, num_datos);
    

    delete[] array_num;

    return 0;
}

void ordenarSeleccion(int *a, int size){
    int min=0;
    int pos=0;
    int temp;


    if(size>0){
        for(int i=0; i<size; i++){ 
            min=a[i];
            pos=i;

            //seleccionamos el mínimo
            for(int j=i+1; j<size; j++){ 
                if(min>a[j]){ //T(n)=1
                    min=a[j];
                    pos=j;
                }

            }

            //intercambiamos las posiciones del mínimo
            temp= a[i];
            a[i]=a[pos];
            a[pos]=temp;

            for(int k=0; k<size;k++){
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }
    }
}


/*Resuelta la complejidad en clase 
//El 1º for sucede Σ(n-i + 1) + 1(se le suma el uno por el for) sumatorio que va desde i=0 hasta n-1

El 2º for sucede n-i + 1 (el mas 1 es por la condicion)

Resolvemos el sumatorio del 1º for 
    Σ(n-i + 1)
    (descomponemos)
    = Σ n - Σi + Σ1
    (aprenderse las formulas dice, estan en wikipedia)
    =n^2 - ((n-1)*n)/2 + n 
    (operamos)
    =2n^2-n^2+n+2n/2 + 1
    =n^2/2 + 3n/2 + 1

=> Función tiempo T(n)=n^2/2 + 3n/2 + 1 y la complejidad temporal es O(n^2)


*/