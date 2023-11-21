#pragma once
#include "ColaPrioridad.h"
#include "iostream"


void ColaPrioridad::encolar(int nuevoElemento){
	int pos_padre;
	int pos_hijo;

	vector.insertarAlFinal(nuevoElemento);
    pos_padre = (vector.getN()-1 -1)/2;
    pos_hijo = vector.getN()-1;

	//lo metemos en su sitio
	while(vector.getValor(pos_hijo)<vector.getValor(pos_padre)){ 
		if(pos_hijo!=0){
			//colocamos en su lugar
			vector.setValor(pos_hijo,vector.getValor(pos_padre));
			vector.setValor(pos_padre,nuevoElemento);

			pos_hijo=pos_padre;
			pos_padre= (pos_hijo-1)/2;
		}
	}


}

int ColaPrioridad::desencolar(){
	int primer_cliente=vector.getValor(0);

	vector.setValor(0,vector.getValor(vector.getN()-1));

	vector.eliminarAlFinal();

	//resstructuramos montículo
	reestructurar();

	return primer_cliente;

}

bool ColaPrioridad::estaVacia(){
	return vector.getN()==0;
}

void ColaPrioridad::reestructurar(){ //ponemos en orden la cola

	ColaPrioridad temp;

    for(int i=0; i<vector.getN();i++){
        temp.encolar(vector.getValor(i)); //para que se ordene
    }
	
    for(int i=0; i<vector.getN();i++){
        vector.setValor(i,temp.vector.getValor(i));
    }
	
}


