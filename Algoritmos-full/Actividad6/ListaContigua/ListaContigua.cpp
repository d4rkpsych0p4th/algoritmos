//#pragma once
#include "ListaContigua.h"
#include "assertdomjudge.h"



ListaContigua::ListaContigua(int incremento){
	assertdomjudge(incremento>0);
	this->incremento=incremento;
	this->capacidad=incremento;
	//vector= new int[incremento];
	vector= (int*) malloc(sizeof(int)*incremento);
	n=0;

}

int ListaContigua::getValor(int posicion){
	assertdomjudge(posicion<n);
	return vector[posicion];

}

void ListaContigua::setValor(int posicion, int nuevoValor){
	assertdomjudge(posicion<n);
	vector[posicion]=nuevoValor;
}

int ListaContigua::getN(){
	return n;
}

int ListaContigua::getCapacidad(){
	return capacidad;
}

void ListaContigua::insertar(int posicion, int nuevoValor){
	assertdomjudge(posicion<=n);
	if(n==capacidad){
		capacidad+=incremento;
		vector=(int*) realloc(vector,capacidad); //complejidad etemporal pq se copia para hacer memoria n 
	}

	if(posicion<=n-1){   
		//desplazar hacia la derecha
		//memmove(pos+1,pos,numerosAmover)
		memmove(&vector[posicion+1],&vector[posicion],sizeof(int)*(n-posicion+1)); //complejidad n pq aumentas
		vector[posicion]=nuevoValor;
		n++;
		
	}
	else{
		vector[posicion]=nuevoValor;
		n++;

	}
	

}

void ListaContigua::eliminar(int posicion){
	assertdomjudge(posicion<n);

	if(posicion<n-1){ 
		//desplazar hacia la izquierda
		memmove(&vector[posicion-1],&vector[posicion],sizeof(int)*(n-posicion+1)); //n
		n--;
	}
	else{
		n--;
	}

	if(n<=capacidad-2*incremento){
		capacidad-=incremento;
		vector=(int*) realloc(vector,sizeof(int)*capacidad); //no se me olvido que había que realojar la memoria
		//complejidad es 1 pq consideramos que disminuye capacidad
		
	}

}

void ListaContigua::concatenar(ListaContigua *listaAConcatenar){

	int pos=n;
	n+=listaAConcatenar->getN();
	capacidad=n;
	//vector=(int*) realloc(vector,capacidad);
	int* temp=(int*)malloc(sizeof(int)*capacidad); //complejidad temporal 1
	
	for(int i=0; i<capacidad;i++){
	    if(i<pos){
	        temp[i]=vector[i];
	    }
	    else{
	        temp[i]=listaAConcatenar->getValor(i-pos);
	    }
	    
	}
	
	vector=temp;
	
}

int ListaContigua::buscar(int elementoABuscar){
	int pos=-1;
	bool encontrado=false;

	for(int i=0; i<n && !encontrado; i++){
		encontrado=elementoABuscar==vector[i];

		if(encontrado){
			pos=i;
		}
		
	}

	return pos;
}

ListaContigua::~ListaContigua(){
	//delete[] vector;
	free(vector);
	n=0;
	capacidad=0;
	incremento=0;
}









