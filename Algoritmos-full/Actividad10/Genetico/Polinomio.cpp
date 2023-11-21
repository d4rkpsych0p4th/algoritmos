#include "Polinomio.h"
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

float Polinomio::obtenerAleatorioNormalEstandar() {
	// Una variable aleatoria normal est�ndar se puede calcular o bien con "normal_distribution" de la biblioteca "random" (versi�n 2011 de C++)
	// o bien mediante 12 sumas sucesivas de valores aleatorios uniformes entre 0 y 1 (nos lo da rand()/(float)RAND_MAX),
	// y luego rest�ndole 6. M�s detalles sobre este m�todo en 
	// http://en.wikipedia.org/wiki/Normal_distribution#Generating_values_from_normal_distribution
	// Para calcular una normal no est�ndar recordemos que ser�a X = media + desviaci�n*Z, donde Z es la normal est�ndar

	float suma=0; // Suma de 12 variables aleatorias uniformes entre 0 y 1
	for (int i=0; i<12; i++) suma = suma + rand()/(float)RAND_MAX;
	return(suma-6);	
}

float Polinomio::obtenerRaizRecursivo(SolucionParcial padre) {
	float resultado=0.0;
	int pos=0;
	float minimo=0.0;

	// Imprimimos el padre
    cout<<"Seleccionada"<<endl;
	padre.imprimir();
	cout<<"Mutaciones"<<endl;
	
	// Calculamos la mutaci�n para cada hijo (10)  y evaluamos el polinomio para dicha mutaci�n
	SolucionParcial *hijos=new SolucionParcial[10];

	for(int i=0; i<10;i++){
		hijos[i].x= padre.x+obtenerAleatorioNormalEstandar(); 
		hijos[i].y=evaluar(hijos[i].x);

	}

	for(int i=0; i<10;i++){
		hijos[i].imprimir();
	}

	// Imprimimos la solucion parcial encontrada para las mutaciones (hijo.imprimir())
	// Elegimos el mejor hijo de numeroHijos
	minimo=abs(hijos[0].y);
	pos=0;

	for(int i=1; i<10;i++){

		if(abs(hijos[i].y)<minimo){
			minimo=abs(hijos[i].y);
			pos=i;
			
		}
	}
	
	// Si el mejor hijo es mejor que el padre, hacemos que tenga descendencia. Si no, hemos acabado
	if(minimo<abs(padre.y)){
		resultado=obtenerRaizRecursivo(hijos[pos]);
	}
	else{
		resultado=padre.x;
	}

	return resultado;
	
}

Polinomio::Polinomio(int n, float *coeficientes) {
	this->n=n;
	this->coeficientes= new float[n+1];

	for(int i=0; i<n+1;i++){
		this->coeficientes[i]=coeficientes[i];
	}

}

float Polinomio::evaluar(float x) {
	float resultado=0.0;

	for(int i=0; i<n+1;i++){
		resultado=resultado + coeficientes[i] * pow(x,i);
	}

	return resultado;
}


float Polinomio::obtenerRaiz() {
	SolucionParcial p;
	p.x=0;
	p.y=evaluar(0);

	return obtenerRaizRecursivo(p);
}


Polinomio::~Polinomio() {
	delete[] coeficientes;
}
