#include"Nodo.h"
#include<string>
#include<iostream>
#include "assertdomjudge.h"
using namespace std;

class Pila
{
 private:
  Nodo *cima;
  string name;
 public:
 /**
  * Constructor de la pila, inicializa los atributos
  * 
  * Complejidad temporal: O(1)
  * Complejidad espacial: O(1)
  */
  Pila(string name);

  /**
   * Devolvemos el atributo name 
   * 
   * Complejidad temporal: O(1)
   * Complejidad espacial: O(1)
   */
  string nombrePila();

  /**
   * Insertamos un nuevo nodo al final de la lista enlazada 
   * 
   * Complejidad temporal: O(1)
   * Complejidad espacial: O(1)
   */
  void apilar(int num); 

  /**
   * Eliminamos el nodo del final de la lista enlazada
   * 
   * Complejidad temporal: O(1)
   * Complejidad espacial: O(1) 
   */
  int desapilar();

  /**
   * Devuelve true si la pila está vacía y false si no 
   * 
   * Complejidad temporal: O(1)
   * Complejidad temporal: O(1)
   */
  bool estaVacia();
};

  
