//#pragma once
//#include "Nodo.h"
#include <string>

class Agenda
{
private:

	//indica el número máximo de contactos de la tabla hash
	int capacidad;

	//array de nombres
	std::string *nombres;

	//array de telefonos
	long *telefonos;

	//arry de booleanos que nos dice si las posiciones están ocupadas o no
	bool *ocupados;
	

public:
	Agenda(int capacidad);

	int obtenerPosicion(long telefono);

	bool existeContacto(long telefono);

	std::string getContacto(long telefono);

	void introducirContacto(long telefono, std::string contacto);

	void eliminarContacto(long telefono);

	void imprimir();

	~Agenda();
};







