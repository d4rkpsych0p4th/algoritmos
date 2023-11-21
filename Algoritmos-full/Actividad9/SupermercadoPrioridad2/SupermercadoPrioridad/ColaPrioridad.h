#pragma once
#include "ListaContigua.h"

// Clase que implementa una cola con prioridad mediante un monticulo (arbol binario completo en el cual la clave de cada nodo es menor que la de sus descendientes) e implementado sobre una lista contigua
class ColaPrioridad
{
protected:

	//lista contigua donde se implementará el montículo 
	ListaContigua vector; 

public:

	/**
	 * Inserta el nuevo elemento al montículo en su posición correcta 
	 * 
	 * Complejidad temporal: O(n)
	 * Complejidad espacial: O(1)
	 */
	void encolar(int nuevoElemento);

	/**
	 * Devolvemos el elemento que desencolamos
	 * 
	 * Complejidad temporal: O(n)
	 * Complejidad espacial: O(1)
	 */
	int desencolar();

	/**
	 * Devuelve true si la lista contigua está vacia y false si no 
	 * 
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	bool estaVacia();

protected:
	
	/**
	 * Ordenamos de nuevo el montículo 
	 * 
	 * Complejidad temporal: O(n)
	 * Complejidad espacial: O(1)
	 */
	void reestructurar();
};

