#include <cstdlib>
#include "ListaCircular.h"




Nodo * ListaCircular::getNodo(int posicion){
	//assertdomjudge(posicion < n);
	Nodo * temp=lista;

	for(int i=0; i<posicion;i++){
		temp=temp->siguienteNodo;
	}

	return temp;
}

ListaCircular::ListaCircular(){
	n=0;
	lista=NULL;
}

string ListaCircular::getValor(int posicion){
	Nodo * temp=getNodo(posicion);

	return temp->elemento;
}

void ListaCircular::setValor(int posicion, string nuevoValor){
	Nodo * temp=getNodo(posicion);

	temp->elemento=nuevoValor;
}

int ListaCircular::getN(){
	return n;
}

void ListaCircular::insertar(int posicion, string nuevoValor){
	//assertdomjudge(posicion <= n);
	// si la lista esta vacia
	if (lista == NULL)
	{
		lista = new Nodo;
		lista->elemento = nuevoValor;
		lista->siguienteNodo = NULL;
		lista->anteriorNodo =NULL;
		n++;
		
	}
	else
	{
		Nodo *temp=lista;
		Nodo *nodo= new Nodo;

		nodo->elemento=nuevoValor;
		nodo->anteriorNodo=getNodo(posicion-1);
		nodo->siguienteNodo=getNodo(0);


		Nodo * nodo_ant=getNodo(posicion-1);
		nodo_ant->siguienteNodo=nodo;

		n++;

		if(posicion!=0){
			nodo_ant=getNodo(0);
			nodo_ant->anteriorNodo=getNodo(n-1);
		}

		
		


	}
}

void ListaCircular::eliminar(int posicion){

	//assertdomjudge(posicion < n);
	Nodo *temp =lista;

	if(posicion==0){
		lista=lista->siguienteNodo;
		n--;
	}
	else{
		temp=getNodo(posicion-1);

		temp->siguienteNodo=temp->siguienteNodo->siguienteNodo;
		n--;
	}
}

void ListaCircular::girar(int p){

	if(p>0){ //se desplaza a la derecha

		for(int i=0; i<p; i++){
			lista=lista->siguienteNodo;
		}


	}
	else{ //Se desplaza a la izquierda
		for(int i=0; i<(-1*p);i++)
			lista=lista->anteriorNodo;
	}
}

ListaCircular::~ListaCircular(){
	while(n!=0){
		eliminar(0);
	}
}
