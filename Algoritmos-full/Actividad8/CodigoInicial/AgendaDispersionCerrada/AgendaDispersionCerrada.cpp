#include "Agenda.h"
#include "assertdomjudge.h"
#include <iostream>

using namespace std;

/**
 * Constructor de Agenda
 * Inicializa capacidad y reserva memoria de los array
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(n)
 */
Agenda::Agenda(int capacidad){	
	this->capacidad= capacidad;
	nombres=new string[capacidad];
	telefonos=new long[capacidad];
	vacias=new bool[capacidad]; 
	borradas=new bool[capacidad]; 

	for(int i=0; i<capacidad;i++){
		vacias[i]=true;
		telefonos[i]=0;
		borradas[i]=false;
	}
}

/**
 * Obtiene la posicion en la que se debería guardar ese elemento en la tabla hash
 * 
 * Complejidad temporal= O(1)
 * Complejidad espacial= O(1)
 */
int Agenda::obtenerPosicion(long telefono){
	int posicion=telefono%capacidad;

	return posicion;
}

/**
 * Devuelve la posicion donde se debe encontrar el contacto con ese telefono 
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
int Agenda::buscarContacto(long telefono){
	int pos=-1;
	int inicio=obtenerPosicion(telefono);
	bool encontrado=false;
	
	if(existeContacto(telefono)){
		int contador=inicio;
		while(!encontrado){
			

			if(!vacias[contador]){
				encontrado=telefono==telefonos[contador];

				if(encontrado){
					pos=contador;
				}
			}
			
			if(contador+1==inicio){
				encontrado=true;
			}

			contador++;
		}
	}

	return pos;	
}

/**
 * Devuelve la posicion donde hay un hueco para insertar un contacto
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
int Agenda::buscarHueco(long telefono){
	int pos;
	int inicio=obtenerPosicion(telefono);
	bool encontrado=false;
	
	if(!vacias[inicio]){
		int contador=inicio;
			while(!encontrado){
			
				if(vacias[contador]){
					encontrado=true;
					pos=contador;
				
				}

			contador++;
		}
	}
	else{
		pos=inicio;
	}
		
	

	return pos;	
}

/**
 * Devuelve true si la tabla está llena y false si no
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
bool Agenda::isLlena(){
	bool llena=true;

	for(int i=0; i<capacidad && llena;i++){
		llena=!vacias[i];
	}

	return llena;
}

/**
 * Devuelve true si esta el contacto y false si no 
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
bool Agenda::existeContacto(long telefono){
	bool existe=false;

	for(int i=0; i<capacidad && !existe;i++){
		if(!vacias[i])
			existe=telefono==telefonos[i];
	}

	return existe;
}

/**
 * Devuelve el nombre del contacto con ese telefono
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
string Agenda::getContacto(long telefono){
	assertdomjudge(existeContacto(telefono));
	return nombres[buscarContacto(telefono)];
}

/**
 * Introduce el contacto en la tabla 
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
void Agenda::introducirContacto(long telefono, string contacto){
	assertdomjudge(!isLlena());
	int pos=buscarHueco(telefono);

	telefonos[pos]=telefono;
	nombres[pos]=contacto;
	vacias[pos]=false;

}

/**
 * Elimina el contacto de la tabla 
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
void Agenda::eliminarContacto(long telefono){
	assertdomjudge(existeContacto(telefono));
	int pos=buscarContacto(telefono);

	vacias[pos]=true;
	borradas[pos]=true;

}


/**
 * Destructor de Agenda
 * 
 * Complejidad temporal= O(1)
 * Complejidad espacial= O(1)
 */
Agenda::~Agenda(){
	capacidad=0;
	delete[] nombres;
	delete[] telefonos;
	delete[] vacias;
	delete[] borradas;
}

/**
 * Imprime los datos de la tabla 
 *  
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) 
		cout << "Posicion " << i << " | Vacia: " << vacias[i] << " | Borrada: " << borradas[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}

