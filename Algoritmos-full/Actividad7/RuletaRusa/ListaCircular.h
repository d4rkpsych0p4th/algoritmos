#include<cstdlib>
#include "Nodo.h"

class ListaCircular
{
	Nodo *lista;

	int n;

	/**
	 * Devuelve el nodo de una posicion de la lista
	 * 
	 * Comlejidad temporal: O(n)
	 * Complejidad espacial: O(1)
	 */
	Nodo * getNodo (int posicion);

public:

	/**
	 * Constructor de ListaCircular, inicializa los atributos
	 * 
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	ListaCircular();

	/**
	 * Devuelve el valor que hay en la posición pasada por parámetros
	 * 
	 * Complejidad temporal: O(n)
	 * Complejidad espacial: O(1)
	 */
	string getValor(int posicion);

	/**
	 * Modifica el valor de un nodo de una posicion de la lista ya existente
	 * 
	 * Complejidad temporal: O(n)
	 * Complejidad espacial: O(1)
	 */
	void setValor(int posicion, string nuevoValor);

	/**
	 * Devuelve el valor de la variable n, numero de elementos de la lista enlazada
	 * 
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	int getN(); 

	/**
	 * Insertamos un nuevo nodo a la lista en una posicion determinada
	 * 
	 * Complejidad temporal: O(n)
	 * Complejidad espacial: O(1)
	 */
	void insertar (int posicion, string nuevoValor);

	/**
	 * Eliminamos un nodo de una posicion determinada
	 * 
	 * Complejidad temporal: O(n)
	 * Complejidad espacial: O(1) 
	 */
	void eliminar (int posicion);

	/**
	 * Giramos la lista hacia la derecha o izquierda
	 * 
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	void girar (int p);

	/**
	 * Destructor de ListaCircular, elimina todos los nodos de la lista enlazada
	 * 
	 * Complejidad temporal:
	 * Complejidad espacial:
	 */
	~ListaCircular();
};







