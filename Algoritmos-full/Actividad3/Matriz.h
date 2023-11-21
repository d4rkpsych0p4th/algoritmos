#ifndef MATRIZ_H
#define MATRIZ_H

using namespace std;

class Matriz {
 private:
  double **matriz;
  
  int n_filas;
  int n_columnas;

 public:


/* Realiza la asignación entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
	   Parámetro: la matriz que se va a asignar
	   Retorno: una nueva matriz con la matriz pasada como parámetro.
	   Precondicion: Ninguno.
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

  Matriz& operator= (const Matriz &m);


/* Permite rellenar todos los elementos de la matriz del objeto actual preguntando al usuario 
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/
  
  void rellenarManual();


/* Permite rellenar todos los elementos de la matriz del objeto actual de forma aleatoria 
	   Parámetro: semilla que se utiliza para el generador aleatorio
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

  void rellenarAleatorio(long seed);



/* Imprime por pantalla todos los elementos de la matriz del objeto actual  
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: La matriz no debe estar vacía
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/

  void mostrarMatriz();


/*Constructor sin parámetros, inicializa los valores a por defecto
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: Ninguno
	   Complejidad Temporal: O(1)
	   Complejidad Espacial: O(1)
*/

	Matriz();


/*Constructor con parámetros, inicializa los valores
	   Parámetro: numero de filas, numero de columnas
	   Retorno: Ninguno
	   Precondicion: Ninguno
	   Complejidad Temporal: O(n_filas) 				
	   Complejidad Espacial: O(n_filas*n_columnas)		
*/

	Matriz(int n_fil,int n_col);



/*Constructor copia, hace una copia de otra matriz
	   Parámetro: matriz de la que se quiere hacer una copia
	   Retorno: Ninguno
	   Precondicion: Ninguno
	   Complejidad Temporal: O(n_filas*n_columnas)		
	   Complejidad Espacial: O(n_filas*n_columnas)		
*/

	Matriz(const Matriz &m);

/*Reservar memoria dinámica para una matriz
	   Parámetro: Niguno
	   Retorno: Ninguno
	   Precondicion: la matriz debe tener la memoria liberada
	   Complejidad Temporal: O(n_filas)
	   Complejidad Espacial: O(n_filas*n_columnas)

*/

	void reservarMemoria();



/*Destructor de la matriz, libera memoria de la matriz 
	   Parámetro: Ninguno
	   Retorno: Ninguno
	   Precondicion: Ninguno
	   Complejidad Temporal: O(n_filas)
	   Complejidad Espacial: O(1) 		

*/

	 ~Matriz();


/*Copia los datos de una matriz pasado por parámetros
	   Parámetro: Matriz de la que se quieren copiar los datos
	   Retorno: Ninguno
	   Precondicion: n_filas y n_columnas sean mayores que 0
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)
*/

	void copiarDatos(const Matriz &m);


/* Realiza la suma entre dos objetos de la clase Matriz. Crea una nueva matriz con el resultado.
	   Parámetro: la matriz que se va a sumar
	   Retorno: una nueva matriz con la suma de las dos matrices
	   Precondicion: Tengan los mismos valores en n_filas y n_columnas
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)							


*/

  	Matriz operator+ (const Matriz &m) const;


/* Realiza la resta entre dos objetos de la clase Matriz. Crea una nueva matriz  con el resultado.
	   Parámetro: la matriz que se va a restar
	   Retorno: una nueva matriz con la resta de las dos matrices
	   Precondicion: Tengan los mismos valores en n_filas y n_columnas.
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

  	Matriz operator- (const Matriz &m) const;


/* Realiza la multiplicación entre dos objetos de la clase Matriz. Crea una nueva matriz con el resultado.
	   Parámetro: la matriz por la que se va a multiplicar
	   Retorno: una nueva matriz del resultado de multiplicar dos matrices
	   Precondicion: Que las dos matrices se puedan multiplicar
	   Complejidad Temporal: O(n_filas*n_columnas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

  	Matriz operator* (const Matriz &m) const;



/* Realiza la multiplicación entre una matriz y un escalar. Crea una nueva matriz con el resultado.
	   Parámetro: un valor de tipo double
	   Retorno: una nueva matriz con la solución de multiplicar una matriz por un escalar
	   Precondicion: Ninguna
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

  	Matriz operator* (double s) const;


/* Realiza la matriz traspuesta del objeto clase Matriz. Crea una nueva matriz con el resultado.
	   Parámetro: Ninguno
	   Retorno: una nueva matriz que es la matriz traspuesta del objeto con el que se le llama
	   Precondicion: Ninguna
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(n_filas*n_columnas)


*/

  	Matriz calcularTraspuesta () const;


/*Averigua si es una matriz simétrica o no
	   Parámetro: Ninguno
	   Retorno: un valor booleano, true si es simétrica y false si no lo es
	   Precondicion: Ninguna
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)


*/
 
	bool esSimetrica() const;


/*Obtiene el valor mínimo de la matriz
	   Parámetro: Ninguno
	   Retorno: un valor double.
	   Precondicion: Ninguna
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)

*/

	double obtenerMinimo() const;


/*Obtiene el valor máximo de la matriz
	   Parámetro: Ninguno
	   Retorno: un valor double.	
	   Precondicion: Ninguna
	   Complejidad Temporal: O(n_filas*n_columnas)
	   Complejidad Espacial: O(1)

*/

	double obtenerMaximo() const;




/**
 * Devuelve el determinante de una matriz
 * Función temporal T(n)= n*( (n^2 + n) + T(n-1) ) + 1 = n^3 + n^2 + n* T(n-1) + 1
 * O(n^3)
 * Función espacial T(n)= T((n_filas-1)*(n_columnas-1))
 */
	double calcularDeterminante();

};

#endif // MATRIZ_H
