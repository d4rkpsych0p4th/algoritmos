
#include "Nodo.h"

class ABB{

private:

    //numero de elementos que hay en el arbol
    int n;

    //es la raiz del arbol
    Nodo *raiz;

    /**
     * Imprime el arbol
     * 
     * Complejidad temporal: T(n)=2T(n-1) O(2^(n-1))
     * Complejidad espacial: O(1)
     */
    void imprimirRecorrido(Nodo *raizSubarbol);

    /**
     * Lee los datos a introducir en el subarbol
     * 
     * Complejidad temporal: T(n)=2T(n-1) O(2^(n-1))
     * Complejidad espacial: O(1)
     */
    Nodo *leerSubarbol(Nodo *padre);

    /**
     * Elimina los nodos que cuelgan de raizSubarbol
     * 
     * Complejidad temporal: O(2^(n-1))
     * Complejidad espacial: O(1)
     */
    void eliminarSubarbol(Nodo *raizSubarbol);

    /**
     * Devuelve el padre del futuro nodo a insertar 
     * 
     * Complejidad temporal: O(2^(n-1))
     * Complejidad espacial: O(1)
     */
    Nodo *buscarHueco(Nodo *raizSubarbol, int elementoAInsertar);

    /**
     * Devuelve el nodo con el contenido que buscamos
     * 
     * Complejidad temporal: O(2^(n-1))
     * Complejidad espacial: O(1)
     */
    Nodo *buscarRecursivo(Nodo *raizSubarbol, int elementoABuscar);

    /**
     * Devuelve el nodo con el valor maximo 
     * 
     * Complejidad temporal: O(n)
     * Complejidad espacial: O(1)
     */
    Nodo *buscarMaximo(Nodo *raizSubarbol);

    /**
     * Devuelve el nodo con el valor minimo 
     * 
     * Complejidad temporal: O(n)
     * Complejidad espacial: O(1)
     */
    Nodo *buscarMinimo(Nodo *raizSubarbol);

    /**
     * Elimina los hijos del nodo
     * 
     *Complejidad temporal: O(1)
     *Complejidad espacial: O(1)
     */
    void eliminarNodo(Nodo *nodoParaEliminar);

    /**
     * Devuelve la altura del arbol desde raizSubarbol
     * 
     * Complejidad temporal: O(2^(n-1))
     * Complejidad espacial: O(1)
     */
    int alturaNodo(Nodo *raizSubarbol);

    /**
     * Devuelve true si es un ABB y false si no
     * 
     * Complejidad temporal: O(C^(n))
     * Complejidad espacial: O(1)
     */
    bool esSubABB(Nodo *raizSubarbol);

    /**
     * Devuelve true si es un AVL y false si no
     * 
     * Complejidad temporal: O(C^(n))
     * Complejidad espacial: O(1)
     */
    bool esSubAVL(Nodo *raizSubarbol);

public:

    /**
     * Inicializa los atributos
     * 
     * Complejidad temporal: O(1)
     * Complejidad espacial: O(1)
     */
    ABB();

    /**
     * Elimina los atributos
     * 
     * Complejidad temporal: O(n)
     * Complejidad espacial: O(1)
     */
    ~ABB();

    /**
     * Lee los datos a introducir en el arbol
     * 
     * Complejidad temporal: T(n)=2T(n-1) O(2^(n-1))
     * Complejidad espacial: O(1)
     */
    void leerArbol();

    /**
     * Imprime el arbol
     * 
     * Complejidad temporal: O(2^(n-1))
     * Complejidad espacial: O(1)
     */
    void imprimir();

    /**
     * Inserta los elementos al arbol
     * 
     * Complejidad temporal: O(2^(n-1))
     * Complejidad espacial: O(1)
     */
    void insertar(int nuevoElemento);

    /**
     * Devuelve el nodo con el contenido que buscamos
     * 
     * Complejidad temporal: O(2^(n-1))
     * Complejidad espacial: O(1)
     */
    Nodo* buscar(int elementoABuscar);

    /**
     * Elimina el nodo con ese contenido pasado por parametros
     * 
     * Complejidad temporal: O(c^n)
     * Complejidad espacial: O(1)
     */
    void eliminar(int elementoABuscar);

    /**
     * Devuelve true si es un ABB y false si no
     * 
     * Complejidad temporal: O(C^(n))
     * Complejidad espacial: O(1)
     */
    bool esABB();

    /**
     * Devuelve true si es un AVL y false si no
     * 
     * Complejidad temporal: O(C^(n))
     * Complejidad espacial: O(1)
     */
    bool esAVL();


};