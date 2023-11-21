#include"Cola.h"
#include "cstdlib" // para realloc()

class Supermercado
{
private:
  Cola *cajas;
  int n_cajas;
public:
  /**
   * Constructor de supermercado, inicializa los atributos
   * 
   * Complejidad temporal: O(1)
   * Complejidad espacial: O(n)
   */
  Supermercado(int n);

  /**
   * Se inserta un nuevo usuario a una cola determinada 
   * 
   * Complejidad temporal: O(1)
   * Complejidad espacial: O(1) 
   */
  void nuevoUsuario(int n,int id); 

  /**
   * Cierra una cola, reparte a los usuarios de esa cola entre las otras colas disponibles  
   * 
   * Complejidad temporal: O(n*m)
   * Complejidad espacial: O(1)
   */
  void cerrarCaja(int n);  

  /**
   * Al atender a un usuario de una cola se elimina de ella
   * 
   * Complejidad temporal: O(1)
   * Complejidad espacial: O(1)
   */
  int atenderUsuario(int n);

  /**
   * Nos dice si una caja determinada está vacia o no
   * 
   * Complejidad temporal: O(1)
   * Complejidad espacial: O(1) 
   */
  bool cajaVacia(int n);
};
