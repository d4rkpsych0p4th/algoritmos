#include "Matriz.h"
#include <iostream>
#include<math.h>
#include<stdlib.h>
#define assertdomjudge(x) if(!(x)){std::cout<<"ERROR"<<std::endl;exit(0);}



//Asignacion de matrices - ejemplo de la función de tiempo T(n_filas,n_col)= 1 + n_filas + n_filas*n_columnas 
//Su orden de complejidad temporal es O(n_filas*n_columnas)
//Complejidad espacial - memoria que se reserva su orden sería O(n_filas*n_columnas)
Matriz& Matriz::operator= (const Matriz &m)
{
  if(matriz!=NULL) //T(n)=1
  {
      for (int i = 0; i < n_filas; i++) //Bucle T(n)=n_filas
	      delete[] matriz[i];
      
      delete[] matriz;
      matriz=NULL;
  }

  //todo esto son funciones elementales de asignación por tanto valen 1
  this->n_filas=m.n_filas;
  this->n_columnas=m.n_columnas;
  this->matriz=NULL;
  if(n_filas>0 && n_columnas>0) //T(n)=1
  {
      matriz= new double *[n_filas]; //n_filas se reservan en memoria - complejidad espacial
  
      for (int i = 0; i < n_filas; i++) //Bucle anidado n_filas*n_columnas
	    {
	      matriz[i] = new double[n_columnas];  //en cada fila se reserva n_columnas de memoria (n_filas*n_columnas)- complejidad espacial
	      for(int j=0; j <n_columnas; j++)
	         matriz[i][j]=m.matriz[i][j];
	    }
  }
  
  return(*this); 
}


// Leer matriz
void Matriz::rellenarManual()
{
  double elemento;
  for (int i = 0; i < n_filas; i++)
  {
    cout << "Fila " << i << endl;
    for (int j = 0; j < n_columnas; j++)
	  {
	    cout << "Elemento " << j  << endl;
	    cin >> elemento;
	    matriz[i][j] = elemento;
    }

    cout << endl;
  }
  
}

// Rellenar Matriz Aleatoria
void Matriz::rellenarAleatorio(long seed)
{
  srand(seed);
  for (int i = 0; i < n_filas; i++)
    for (int j = 0; j < n_columnas; j++)
      matriz[i][j]=rand();
  
}



// Imprimir Matriz
void Matriz::mostrarMatriz()
{
  for (int i = 0; i < n_filas; i++)
  {
	  for (int j = 0; j < n_columnas; j++)
	    cout << matriz[i][j] << " ";       
    cout << endl;
  }
}



//Constructor sin parámetros
Matriz::Matriz()
{
  n_filas=0;
  n_columnas=0;
  matriz=NULL;
}


//Constructor con dos parámetros
//Función de tiempo T(n)= 1 + n_filas
Matriz::Matriz(int n_fil,int n_col)
{
  if(n_fil>0 && n_col>0){
     n_filas=n_fil;
     n_columnas=n_col;

    reservarMemoria();
  }
  else{
    n_filas=0;
    n_columnas=0;
    matriz=NULL;
  }
 

}


//Constructor copia
Matriz::Matriz(const Matriz &m)            
{
  n_filas=m.n_filas;
  n_columnas=m.n_columnas;

  reservarMemoria();
  copiarDatos(m);
}


//Reservar memoria dinámica
//La función espacial (reserva de memoria) =  1 + (n_filas*n_columnas)
void Matriz::reservarMemoria()
{
  if(n_filas>0 && n_columnas>0){
    matriz = new double*[n_filas]; //Esta no se cuenta pq se reseva luego memoria abajo y se multilpica la mem

  //En la función de tiempo este for es n_final + 1 (el + 1 es la última comprobación para salir del for)
    for (int i=0; i<n_filas;++i){  //Aquí se reserva memoria -> función espacial 1 + (n_filas*n_columnas)
      matriz[i] = new double[n_columnas]; //aquí reserva memoria n_filas*n_columnas
    }
  }
}


//Destructor de la matriz
Matriz::~Matriz()
{
  for(int i=0;i<n_filas;++i){
    delete[] matriz[i];
  }

  delete[] matriz;

  n_filas=0;
  n_columnas=0;
  matriz=NULL;
}


//Copiar datos de una matriz
void Matriz::copiarDatos(const Matriz &m)
{
  if(n_filas==m.n_filas && n_columnas==m.n_columnas){
    for(int i=0; i<n_filas; i++){
      for(int j=0; j<n_columnas; j++){
        matriz[i][j]=m.matriz[i][j];
      }
    }
  }
}


//Operador suma de matrices
Matriz Matriz::operator+ (const Matriz &m) const        
{
  assertdomjudge(n_filas==m.n_filas && n_columnas==m.n_columnas);
  Matriz nueva(n_filas,n_columnas);

  for(int i=0; i<n_filas; i++){
    for(int j=0; j<n_columnas; j++){
      nueva.matriz[i][j]=matriz[i][j]+m.matriz[i][j];
    }
  }
  
    return nueva; 
}



//Operador resta de matrices 
Matriz Matriz::operator- (const Matriz &m) const
{
  assertdomjudge(n_filas==m.n_filas && n_columnas==m.n_columnas);
  Matriz nueva(n_filas,n_columnas);

  for(int i=0; i<n_filas; i++){
    for(int j=0; j<n_columnas; j++){
      nueva.matriz[i][j]=matriz[i][j]-m.matriz[i][j];
    }
  }

    return nueva; 
}


//Operador de mulitplicación de matrices                   
//Consideramos que son iguales el número de columnas que es el peor caso    
//Por tanto su O(n_filas * n_columnas^2)        
//Su FUNCION DE TIEMPO sería T(n_filas, n_columnas) = (1 + n_filas) + (n_filas + 1) * (n_columnas + 1)^2;
//Se opera = ( 1 + n_filas) + (n_filas + 1) * (n_columnas^2 + n_columnas + 1);
// = ( 1 + n_filas) + (n_columnas^2*n_filas + n_filas*n_columnas + n_filas + n_columnas^2 + n_columnas + 1);
// = 1 + 2n_filas + n_columnas^2*n_filas + n_filas*n_columnas + n_columnas^2 + n_columnas ;
//Lo ordenamos T(n)= n_columnas^2*n_filas + n_columnas^2 + n_filas*n_columnas + n_columnas + 2n_filas + 1;
//Así hemos demostrado su orden O(n_columnas^2*n_filas);

//Su función espacial sería = n_filas*n_columnas + 1;

Matriz Matriz::operator* (const Matriz &m) const                 
{
  assertdomjudge(n_columnas==m.n_filas);
  Matriz nueva(n_filas,m.n_columnas);  //esto sería 1 + n_filas (función tiempo )- función espacial (n_filas*n_columnas + 1)

//su función de tiempo se empieza en el bucle mas interno hacia afuera 
  for (int i = 0; i < n_filas; i++) {   //n_filas + 1 *(n_columnas + 1)^2
    for (int j = 0; j < m.n_columnas; j++) {  //n_columnas + 1 * n_columnas + 1 (esto es cogiendo el bucle de abajo)
        for (int k = 0; k < n_columnas; k++) {  //n_columnas + 1  (es + 1 por la ultima condición del for)
            nueva.matriz[i][j] += (matriz[i][k] * m.matriz[k][j]);
        }
    }
  }
   
  return nueva;
}


//Operador de multiplicación de una matriz por un escalar
Matriz Matriz::operator* (double s) const                    
{
  assertdomjudge(matriz!=NULL);
  Matriz nueva(n_filas,n_columnas);

  for(int i=0; i<n_filas; i++){
    for(int j=0; j<n_columnas; j++){
      nueva.matriz[i][j]=matriz[i][j]*s;
    }
  }
  
  return nueva;
}


//Calcula la matriz traspuesta
Matriz Matriz::calcularTraspuesta () const
{                      
  assertdomjudge(matriz!=NULL);
  Matriz nueva(n_columnas,n_filas);

  for(int i=0; i<n_columnas; i++){
    for(int j=0; j<n_filas; j++){
      nueva.matriz[i][j]=matriz[j][i];
    }
  }

  return nueva;
}


//Nos dice si la matriz es simétrica o no
bool Matriz::esSimetrica() const                              
{
  assertdomjudge(matriz!=NULL);
  bool esSimetrica=true;

  if (n_filas == n_columnas) {
    for (int i = 0; i < n_filas; i++) {
      for (int j = 0; j < n_columnas; j++) {
          if (matriz[i][j] != matriz[j][i]) {
              esSimetrica=false;
          }
      }
    }
  }
  else{
    esSimetrica=false;
  }
 
    
  return esSimetrica;
  
}


//Devuelve el valor mínimo de La matriz
double Matriz::obtenerMinimo() const                  
{
  assertdomjudge(matriz!=NULL);
  double minimo= matriz[0][0];

  for(int i=0; i<n_filas; i++){
    for(int j=0; j<n_columnas; j++){
      if(matriz[i][j]<minimo){
         minimo=matriz[i][j];
      }
    }
  }

  return minimo;

}


//Devuelve el valor máximo de la matriz
double Matriz::obtenerMaximo() const                    
{
  assertdomjudge(matriz!=NULL);
  double maximo= matriz[0][0];

  for(int i=0; i<n_filas; i++){
    for(int j=0; j<n_columnas; j++){
      if(matriz[i][j]>maximo){
         maximo=matriz[i][j];
      }
    }
  }

  return maximo;
}



/*  Esto es solo un EJEMPLO pero dice que no lo vamos a usar
Complejidad temporal 
Función de tiempo T(n_filas,n_columnas)=((n_fil*n_col+1) * n_col*n_filas)
// Imprimir Matriz
void Matriz::mostrarMatriz()
{
  for (int i = 0; i < n_filas; i++) 
  {
	  for (int j = 0; j < n_columnas; j++)  
	    rellenaraleatorio(seed); ////estoo tendría T(n)= n_fil*n_col +1 con O(n_fil*n_col)
  }
}
*/