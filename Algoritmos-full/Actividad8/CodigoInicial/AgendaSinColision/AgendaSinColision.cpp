#include "Agenda.h"
#include "assertdomjudge.h"
#include "iostream"

using namespace std;

/**
 * Constructor de Agenda
 * Inicializa capacidad y reserva memoria 
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(n)
 */
Agenda::Agenda(int capacidad){
	this->capacidad= capacidad;
	nombres=new string[capacidad];
	telefonos=new long[capacidad];
	ocupados=new bool[capacidad]; 

	for(int i=0; i<capacidad;i++){
		ocupados[i]=false;
		telefonos[i]=0;
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
 * Devuelve true si existe el contacto y false si no
 * 
 * Complejidad temporal= O(n)
 * Complejidad espacial= O(1)
 */

bool Agenda::existeContacto(long telefono){
	bool existe=false;

	for(int i=0; i<capacidad && !existe;i++){
		if(ocupados[i])
			existe=telefono==telefonos[i];
	}

	return existe;
}

/**
 * Devuelve el nombre del telefono que nos proporciona por parámetros 
 * 
 * Complejidad temporal= O(n) //contando la llamada a la funcion existeContacto()
 * Complejidad espacial= O(1)
 */
string Agenda::getContacto(long telefono){
	assertdomjudge(existeContacto(telefono));
	int pos=obtenerPosicion(telefono);

	return nombres[pos];
}

/**
 * Introduce los contactos en la posición que le corresponde 
 * 
 * Complejidad temporal: O(1)
 * Complejidad espacial: O(1)
 */
void Agenda::introducirContacto(long telefono, string contacto){
	assertdomjudge(!ocupados[obtenerPosicion(telefono)]);
	int pos=obtenerPosicion(telefono);

	
	telefonos[pos]=telefono;
	nombres[pos]=contacto;
	ocupados[pos]=true;
	
}

/**
 * Elimina el contacto de la tabla 
 * 
 * Complejidad temporal= O(n) //contando la llamada a la funcion existeContacto()
 * Complejidad espacial= O(1)
 */
void Agenda::eliminarContacto(long telefono){
	assertdomjudge(existeContacto(telefono));
	int pos=obtenerPosicion(telefono);

	
	ocupados[pos]=false;

}

/**
 * Destructor de agenda
 * Complejidad temporal: O(1)
 * Complejidad espacial: O(1)
 */
Agenda::~Agenda(){
	capacidad=0;
	delete[] nombres;
	delete[] telefonos;
	delete[] ocupados;
}

/**
 * Imprime los datos de la tabla
 * 
 * Complejidad temporal= O(n) 
 * Complejidad espacial= O(1)
 */
 
void Agenda::imprimir() {
	for (int i=0; i<capacidad; i++) cout << "Posicion " << i << " | Ocupada: " << ocupados[i] << " | Telefono: " << telefonos[i] << " | Nombre: " << nombres[i] << endl;
}


