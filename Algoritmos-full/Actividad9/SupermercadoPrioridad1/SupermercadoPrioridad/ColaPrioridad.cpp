#pragma once
#include "ColaPrioridad.h"
#include "iostream"

//pregunta que es un montículo??

void ColaPrioridad::encolar(int nuevoElemento){
	int pos=0;
	bool encontrado=false;

	vector.insertarAlFinal(nuevoElemento); //se inserta al final

	reestructurar(); //queremos que se ordene el montículo 

}

int ColaPrioridad::desencolar(){
	int primer_cliente=vector.getValor(vector.getN()-1);

	vector.eliminarAlFinal();

	//resstructuramos montículo
	reestructurar();

	return primer_cliente;
}

bool ColaPrioridad::estaVacia(){
	return vector.getN()==0;
}

void ColaPrioridad::reestructurar(){ 
	int temp;

	//ordenamos de mayor a menor 
	for(int i=0; i<vector.getN()-1;i++){
		for(int j=1; j<vector.getN();j++ ){
			if(vector.getValor(j)>vector.getValor(j-1)){
				temp=vector.getValor(j);
				vector.setValor(j,vector.getValor(j-1));
				vector.setValor(j-1,temp);
			}
		}
		
	}

}


