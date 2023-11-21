#pragma once
#include "ListaEnlazada.h"
#include "assertdomjudge.h"

/**
 * Constructor de listaEnlazada
 *  
 * Complejidad temporal= O(1)
 * Complejidad espacial= O(1)
 */
ListaEnlazada::ListaEnlazada()
{
	n = 0;
	lista = NULL;
	punteroUltimoNodoAccedido= NULL;

}

/**
 * Devuelve el nodo de esa posición que nos pasan por parámetros
 *  
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
Nodo *ListaEnlazada::getNodo(int posicion)
{
	assertdomjudge(posicion < n);
	posicionUltimoNodoAccedido=posicion;
	Nodo *temp=lista;

	for(int i=0; i<posicion;i++){
		temp=temp->next;
	}

	punteroUltimoNodoAccedido=temp;

	return temp;
}

/**
 * Devuelve el contacto de una posición determinada 
 *  
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
Contacto ListaEnlazada::getValor(int posicion)
{
	assertdomjudge(posicion < n);
	Nodo *temp=getNodo(posicion);
	return temp->elemento;
}

/**
 * Cambia el contacto de una posición ya existente
 *  
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
void ListaEnlazada::setValor(int posicion, Contacto nuevoValor)
{
	assertdomjudge(posicion < n);
	Nodo *temp=getNodo(posicion);

	temp->elemento=nuevoValor;

	
}

/**
 * 	Devuelve el número de elementos 
 *  
 * Complejidad temporal= O(1)
 * Complejidad espacial= O(1)
 */
int ListaEnlazada::getN()
{
	return n;
}

/**
 * Inserta los datos en la tabla hash
 *  
 * Complejidad temporal= O(1)
 * Complejidad espacial= O(1)
 */
void ListaEnlazada::insertar(int posicion, Contacto nuevoValor)
{
	assertdomjudge(posicion <= n);
	// si la lista esta vacia
	if (lista == NULL)
	{
		lista = new Nodo;
		lista->elemento = nuevoValor;
		lista->next = NULL;
		n++;
		
	}
	else
	{
		//se añade al principio

		Nodo *temp=lista;
		Nodo *nuevo=new Nodo;

		nuevo->next=temp;
		temp->anteriorNodo=nuevo;
		nuevo->elemento=nuevoValor;
		lista=nuevo;

		n++;
		
	}
}

/**
 * Elimina los datos de la tabla 
 *  
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
void ListaEnlazada::eliminar(int posicion)
{
	assertdomjudge(posicion < n);
	Nodo *temp =lista;

	if(posicion==0){
		lista=lista->next;
		n--;
	}
	else{
		temp=getNodo(posicion-1);

		temp->next=temp->next->next;
		n--;
	}

	

}

/**
 * Concatena una listaEnlazada con otra
 *  
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar)
{
	Nodo *temp = listaAConcatenar->lista;
 
    while (temp->next!=NULL) {
        insertar(n,temp->elemento);
        temp = temp->next;
    }
	insertar(n,temp->elemento);
	temp->next=NULL;

}

/**
 * Busca un contacto en la tabla y devuelve la posición donde se encuentra
 *  
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
int ListaEnlazada::buscar(Contacto elementoABuscar)
{
	int pos=-1;
	bool encontrado=false;
	Nodo *temp=lista;

	for(int i=0; i<n && !encontrado ;i++){
		encontrado=elementoABuscar.telefono==temp->elemento.telefono;
		if(encontrado){
			pos=i;
		}
		else{
			temp=temp->next;
		}
		
	}


	return pos;
}

/**
 * Destructor de la ListaEnlazada
 *  
 * Complejidad temporal= O(n^2)
 * Complejidad espacial= O(1)
 */
ListaEnlazada::~ListaEnlazada()
{
	while(n!=0){
		eliminar(0);
	}
	//debemos borrar todos los nodos de la lista uno a uno hasta que la lista apunte a NULL
}
