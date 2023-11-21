/**
 * @file MergeSort.cpp
 * @author Chantal López 
 * 
 * Actividad 2 - Análisis y diseño de algoritmos 
 * Ordenación por mergesort
 * 
 */

#include <iostream>

using namespace std;

/**
 * Ordena un array de forma ascendente por mitades
 * Complejidad temporal: O(log2(n))
 * Complejidad espacial: O(1)
 */
void ordenarMergeSort(int *a, int size);


int main()
{
    int num_datos;
    int* array_num;

    cin>>num_datos;

    array_num= new int[num_datos];

    for(int i=0; i<num_datos; i++){
        cin>>array_num[i];
    }

    ordenarMergeSort(array_num, num_datos);
    

    delete[] array_num;

    return 0;
}

/**
 * Ordena un array de forma ascendente por mitades
 * Función de tiempo: T(n)= 3n + 1 + 2*T(n/2) = se resuelve con wolfram alpha
 * Complejidad temporal: O(log2(n))
 * Complejidad espacial: O(1)
 */
void ordenarMergeSort(int *a, int size){
 
    int min;
    int temp;
    int mitad;

    //caso base cuando hay dos numeros y se ordenan 
    if(size==2){ 
        min=a[0];
        for(int i=1; i<size; i++){
            if(a[i]<min){
                temp=a[i];
                a[i]=min;
                a[0]=temp;
            }
        }

        for(int i=0; i<size; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    else{
        if(size==3){
            int *array1=new int[2];
            int array2=a[0];

            for(int i=0; i<size-1;i++){
                array1[i]=a[i+1];
            }

            ordenarMergeSort(array1,2);

            //Rellenamos array ordenado
           if(array2<array1[0]){
                a[0]=array2;
                a[1]=array1[0];
                a[2]=array1[1];
           }
           else if(array2>array1[0] && array2<array1[1]){
                a[0]=array1[0];
                a[1]=array2;
                a[2]=array1[1];
           }
           else{
                a[0]=array1[0];
                a[1]=array1[1];
                a[2]=array2;
           }

            //imprimimos
            for(int i=0; i<size;i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";

        }
        else{
            if(size>3){ //Este es el peor caso T(n)= 3n + 1 + 2*T(n/2)
                int tam2=0;
                int util=0;

                mitad=size/2;
            
                int *array2;
                int *array1= new int[mitad];

            
                if(size%2==0){
                    array2= new int[mitad];
                    tam2=mitad;
                }
                else{
                    array2= new int[mitad+1];
                    tam2=mitad+1;
                }
            



                //rellenamos arrays temporales
                for(int i=0; i<size;i++){ //T(n)= n + 1
                    if(size%2==0){
                        if(i<mitad){
                            array1[i]=a[i];
                        }
                        else{
                            array2[util]=a[i];
                            util++;
                        }
                    }
                    else{
                        if(i<mitad){
                            array1[i]=a[i];
                        }
                        else{
                            if(i>=mitad){
                                array2[util]=a[i];
                                util++;
                            }
                        
                        }
                    }
                
                }
            

                //ordenamos los arrays
                ordenarMergeSort(array1,mitad); //T(n)= T(n/2)
                ordenarMergeSort(array2,tam2); //T(n)= T(n/2)
                

                //Ordenamos el array
                int pos=0;
                int pos2=0;

                for(int i=0; i<size;i++){ //T(n)= n + 1
                    if(array1[pos]>array2[pos2] && pos2<tam2){
                        a[i]=array2[pos2];
                        pos2++;
                        
                    }
                    else{
                        if(pos<mitad){
                            a[i]=array1[pos];
                            pos++;
                            
                        }
                        
                    }
                    
                }

                
                //imrpimimos el array
                for(int i=0; i<size;i++){ //T(n)= n + 1
                    cout<<a[i]<<" ";
                }
                cout<<"\n";
            

                delete[] array1;
                delete[] array2;
            }
            else{
                if(size==1){
                    cout<<a[0]<<" ";
                }
            }
        }
        
    }
}


