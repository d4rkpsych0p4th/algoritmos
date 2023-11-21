//#pragma once
#include "nodo.h"

class ListaEnlazada
{
	Nodo *lista;

	int n;

	Nodo * getNodo (int posicion);

public:
	/**
	 * @brief Constructor que inicializa los atributos
	 * @param incremento 
	 * 
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	ListaEnlazada();

	/**
	 * @brief Devuelve el valor que se encuentre en la posicion indicada de la lista
	 * @param posicion 
	 * @return int 
	 * 
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	int getValor(int posicion);

	/**
	 * @brief Modifica el valor de una posicion de la lista
	 * @param posicion 
	 * @param nuevoValor 
	 * 
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	void setValor(int posicion, int nuevoValor);

	/**
	 * @brief Devuelve el valor del atributo n
	 * @return int 
	 * 
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	int getN(); 

	/**
	 * @brief Inserta un nodno enuna posicion determinada del vector un valor
	 * @param posicion 
	 * @param nuevoValor 
	 * 
	 * Complejidad temporal: O(n)
	 * Complejidad espacial: O(1)
	 */
	void insertar (int posicion, int nuevoValor);

	/**
	 * @brief Elimina un nodo de la lista 
	 * @param posicion 
	 * 
	 * Complejidad temporal: O(n)
	 * Complejidad espacial: O(1)
	 */
	void eliminar (int posicion);

	/**
	 * @brief Concatena la lista pasada por parametros con la actual 
	 * @param listaAConcatenar 
	 * 
	 * Complejidad tempora: O(n)
	 * Compejidad espacial: O(1)
	 */
	void concatenar(ListaEnlazada *listaAConcatenar);

	/**
	 * @brief Busca la posicion en la lista del elemento pasado por parametro
	 * @param elementoABuscar 
	 * @return int 
	 * 
	 * Complejidad tempora: O(n)
	 * Compejidad espacial: O(1)
	 */
	int buscar(int elementoABuscar);

	/**
	 * @brief Destructor del vector
	 * 
	 * Complejidad tempora: O(1)
	 * Compejidad espacial: O(1)
	 */
	~ListaEnlazada();
};







