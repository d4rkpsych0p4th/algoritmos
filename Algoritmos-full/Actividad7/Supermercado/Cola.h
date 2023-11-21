#include"Nodo.h"  
class Cola
{
 private:
  Nodo *principio;
  Nodo *final;
 public:
 /**
  * Constructor de Cola, inicializa los atributos
  * 
  * Complejidad temporal: O(1)
  * Complejidad espacial: O(1)
  */
  Cola();

  /**
   * Añade un nodo nuevo a la cola, al final de la lista
   * 
   * Complejidad temporal: O(1)
   * Complejidad espacial: O(1)
   */
  void encolar(int num);  

  /**
   * Elimina el primer nodo de la cola 
   * 
   * Complejidad temporal: O(1)
   * Complejidad espacial: O(1)
   */
  int desencolar();

  /**
   * Devuelve true si la cola está vacia y false si no 
   * 
   * Complejidad temporal: O(1)
   * Complejidad espacial: O(1)
   */
  bool estaVacia();  
};

  
