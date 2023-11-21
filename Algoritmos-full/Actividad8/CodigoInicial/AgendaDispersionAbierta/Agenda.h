#include <string>
#include "ListaEnlazada.h"



class Agenda
{
private:

	//indica el número máximo de contactos de la tabla hash
	int capacidad;

	//numeros de elementos actuales de la tabla
	int n;

	//es un array de listas enlazadas, cada lista almacena nodos
	ListaEnlazada *tabla;
	

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







