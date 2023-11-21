#include "Agenda.h"
#include "ListaEnlazada.h"
#include "assertdomjudge.h"
#include <iostream>
#include "impresionListasEnlazadas.h" // Para el m�todo imprimir de la tabla hash

using namespace std;

/**
 * Constructor de Agenda
 * 
 * Complejidad temporal= O(1)
 * Complejidad espacial= O(n)
 */
Agenda::Agenda(int capacidad){
	this->capacidad=capacidad;
	n=0;
	tabla=new ListaEnlazada[capacidad];

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
 * Devuelve true si esta el contacto y false si no 
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
bool Agenda::existeContacto(long telefono){
	int pos=obtenerPosicion(telefono);
	Contacto temp;
	temp.telefono=telefono;
	bool existe=false;

	if(tabla[pos].buscar(temp)!=(-1)){
		existe=true;
	}

	return existe;
}

/**
 * Devuelve el nombre del contacto con ese telefono
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
std::string Agenda::getContacto(long telefono){
	assertdomjudge(existeContacto(telefono));
	int pos=obtenerPosicion(telefono);
	Contacto temp;
	temp.telefono=telefono;
	Contacto final=tabla[pos].getValor(tabla[pos].buscar(temp));

	return final.nombre;
}

/**
 * Introduce el contacto en la tabla 
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
void Agenda::introducirContacto(long telefono, std::string contacto){

	Contacto nuevo;
	nuevo.nombre=contacto;
	nuevo.telefono=telefono;
	
	int pos_tabla=obtenerPosicion(telefono);
	int pos_inserccion=tabla[pos_tabla].getN();

	tabla[pos_tabla].insertar(pos_inserccion,nuevo);

	n++;

}

/**
 * Elimina el contacto de la tabla 
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */
void Agenda::eliminarContacto(long telefono){
	assertdomjudge(existeContacto(telefono));
	int pos=obtenerPosicion(telefono);
	Contacto temp;
	temp.telefono=telefono;

	tabla[pos].eliminar(tabla[pos].buscar(temp));
	n--;
}

/**
 * Destructor de Agenda
 * 
 * Complejidad temporal= O(1)
 * Complejidad espacial= O(1)
 */
Agenda::~Agenda(){
	n=0;
	capacidad=0;
	delete[] tabla;

}

/**
 * Imprime los datos de la tabla 
 *  
 * Complejidad temporal= O(n^2)
 * Complejidad espacial= O(1)
 */
void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) {
		cout << "Posicion " << i << ": ";
		imprimirListaEnlazada(&tabla[i]);
	}
}

