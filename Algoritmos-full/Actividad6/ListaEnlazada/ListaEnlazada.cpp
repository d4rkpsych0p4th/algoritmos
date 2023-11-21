//#pragma once
#include "ListaEnlazada.h"
#include "assertdomjudge.h"

ListaEnlazada::ListaEnlazada()
{
	n = 0;
	lista = NULL;
}

Nodo *ListaEnlazada::getNodo(int posicion)
{
	assertdomjudge(posicion < n);
	Nodo *temp=lista;

	for(int i=0; i<posicion;i++){
		temp=temp->next;
	}

	return temp;
}

int ListaEnlazada::getValor(int posicion)
{
	assertdomjudge(posicion < n);
	Nodo *temp=lista;

	for(int i=0; i<posicion; i++){
		temp=temp->next;
	}

	return temp->dato;
}

void ListaEnlazada::setValor(int posicion, int nuevoValor)
{
	assertdomjudge(posicion < n);
	Nodo *temp=lista;

	for(int i=0; i<posicion; i++){
		temp=temp->next;
	}

	temp->dato=nuevoValor;

	
}

int ListaEnlazada::getN()
{
	return n;
}

void ListaEnlazada::insertar(int posicion, int nuevoValor)
{
	assertdomjudge(posicion <= n);
	// si la lista esta vacia
	if (lista == NULL)
	{
		lista = new Nodo;
		lista->dato = nuevoValor;
		lista->next = NULL;
		n++;
		
	}
	else
	{
		Nodo *temp=lista;
		Nodo *nodo= new Nodo;

		if (posicion <= n - 1) // Se añade entre medias
		{ 
			//hay que hacer hueco y cambiar los next

			if(posicion==0){
				nodo->dato=nuevoValor;
				nodo->next=lista;
				lista=nodo;

			}else{
				for(int i=0; i<posicion-1;i++){
					temp=temp->next;
				}

				nodo->dato=nuevoValor;
				nodo->next=temp->next;
				temp->next=nodo;
				
			}

			n++;
		}
		else
		{ // se añade al final
			//Recorremos la lista hasta el final
			while(temp->next!=NULL){
				temp=temp->next;
			}

			//En el final añadimos el nuevo nodo
			temp->next= new Nodo;
			temp=temp->next;
			temp->dato=nuevoValor;
			temp->next=NULL;

			n++;
		}
	}
}

void ListaEnlazada::eliminar(int posicion)
{
	assertdomjudge(posicion < n);
	Nodo *temp =lista;

	if(posicion==0){
		lista=lista->next;
		n--;
	}
	else{
		for(int i=0; i<posicion-1;i++){
			temp=temp->next;
		}

		temp->next=temp->next->next;
		n--;
	}

	

}

void ListaEnlazada::concatenar(ListaEnlazada *listaAConcatenar)
{
	Nodo *temp = listaAConcatenar->lista;
 
    while (temp->next!=NULL) {
        insertar(n,temp->dato);
        temp = temp->next;
    }
	insertar(n,temp->dato);
	temp->next=NULL;

}

int ListaEnlazada::buscar(int elementoABuscar)
{
	int pos=-1;
	bool encontrado=false;
	Nodo *temp=lista;

	for(int i=0; i<n && !encontrado ;i++){
		encontrado=elementoABuscar==temp->dato;
		if(encontrado){
			pos=i;
		}
		else{
			temp=temp->next;
		}
		
	}


	return pos;
}

ListaEnlazada::~ListaEnlazada()
{
	delete lista;
}
