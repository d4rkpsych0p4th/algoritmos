#include "iostream"

using namespace std;

void colorear(int** matriz,int* colores,int filas_columnas,int indice, int colorArellenar);

bool rojiBlanco(int** matriz,int* colores,int filas_columnas);

int main()
{
  int numvertices=0;
  int numaristas=0;
  int ex_d=0,ex_i=0;
  bool rojiblanco=false;
  int* colores;

  cin>>numvertices;


  do{

    cin>>numaristas;

    //inicializamos matriz y grafo
    int **matriz=new int *[numaristas];

    for(int i=0; i< numaristas; i++){
      matriz[i]=new int[numaristas];
    }

    for(int i=0; i<numaristas;i++){
      for(int j=0; j<numaristas;j++){
        matriz[i][j]=0;
      }
      
    }

    //inicializamos los colores del grafo (0 ningun color, 1 color rojo, 2 color blanco)
    colores=new int[numaristas];

    for(int i=0; i<numaristas;i++){
      colores[i]=0;
    }


    //rellenamos la matriz de adyacencia (grafos)
    for(int i=0; i<numaristas;i++){
      cin>>ex_d;
      cin>>ex_i;

      matriz[ex_d][ex_i]=1;
      matriz[ex_i][ex_d]=1;
      
    }

    //coloreamos el grafo
    colorear(matriz,colores,numaristas,0,1);

    rojiblanco=rojiBlanco(matriz,colores,numaristas);
    

    if(rojiblanco){
      cout<<"SI"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }


    cin>>numvertices;


  }while(numvertices!=0);

 
  

  return 0;
}

/**
 * Colorea el grafo de rojo y blanco
 * 
 * Complejidad temporal: O(T(n-1)*n)   
 * Complejidad espacial: O(1)
 */
void colorear(int** matriz,int* colores,int filas_columnas, int indice, int colorArellenar){

  if(colores[indice]==0){ //coloreamos el vértice
    colores[indice]=colorArellenar;

  }

  //coloreamos los adyacentes que no tengan color asignado
  for(int i=0; i<filas_columnas;i++){
    if(matriz[indice][i]==1 && colores[i]==0){
      if(colorArellenar==1){
        colorArellenar=2;
      }
      else{
        colorArellenar=1;
      }

      colorear(matriz,colores,filas_columnas,i,colorArellenar);

    }
  } 
}

/**
 * Devuelve true si es rojiblanco y false si no 
 * 
 * Complejidad temporal: O(n^2)
 * Complejidad espacial: O(1)
 */
bool rojiBlanco(int** matriz,int* colores, int filas_columnas){
  bool loEs=true;

  for(int i=0; i<filas_columnas && loEs;i++){
    for(int j=0; j<filas_columnas && loEs;j++){
      if(matriz[i][j]==1){ //si es adyacente de i comprobamos que son distintos colores
        loEs=colores[i]!=colores[j];
      }
    }
  }

  return loEs;
}


