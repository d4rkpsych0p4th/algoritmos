//#pragma once
#include "cstdlib" // para realloc()
#include "cstring" // para memmove


class ListaContigua
{
	int *vector;

	int n; //Numero de elementos de la lista

	int capacidad; //Capacidad del vector dinamico

	int incremento;

public:
	/**
	 * @brief Constructor que inicializa los atributos y reserva la memoria del vector
	 * @param incremento 
	 * 
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(n)
	 */
	ListaContigua(int incremento);

	/**
	 * @brief Devuelve el valor que se encuentre en la posicion indicada del vector
	 * @param posicion 
	 * @return int 
	 * 
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	int getValor(int posicion);

	/**
	 * @brief Modifica el valor de una posicion del vector
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
	 * @brief Devuelve el valor del atributo capacidad
	 * @return int 
	 * 
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	int getCapacidad(); 

	/**
	 * @brief Inserta en una posicion determinada del vector un valor
	 * @param posicion 
	 * @param nuevoValor 
	 * 
	 * Complejidad temporal: O(n)
	 * Complejidad espacial: O(n)
	 */
	void insertar(int posicion, int nuevoValor);

	/**
	 * @brief Elimina una posicion del vector
	 * @param posicion 
	 * 
	 * Complejidad temporal: O(n)
	 * Complejidad espacial: O(n)
	 */
	void eliminar(int posicion);

	/**
	 * @brief Concatena la lista pasada por parametros con la actual 
	 * @param listaAConcatenar 
	 * 
	 * Complejidad tempora: O(n)
	 * Compejidad espacial: O(n)
	 */
	void concatenar(ListaContigua *listaAConcatenar);

	/**
	 * @brief Busca la posicion en el vector del elemento pasado por parametro
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
	~ListaContigua();
};








