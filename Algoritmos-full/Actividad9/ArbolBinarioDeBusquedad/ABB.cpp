#include <iostream>
#include "ABB.h"

using namespace std;

ABB::ABB()
{
  n = 0;
  raiz = NULL;
}

ABB::~ABB()
{
  while (n != 0)
    eliminar(0);
}

void ABB::leerArbol()
{
  raiz = leerSubarbol(NULL);
}

void ABB::imprimir()
{
  if (raiz == NULL)
    cout << "VACIO" << endl;
  else
    imprimirRecorrido(raiz);
}

// no se si esta bien
void ABB::insertar(int nuevoElemento)
{

  if (raiz == NULL)
  {
    Nodo *nuevo = new Nodo();
    nuevo->contenido = nuevoElemento;
    raiz = nuevo;
    raiz->hijoDerecho = NULL;
    raiz->hijoIzquierdo = NULL;
  }
  else
  { // Se inserta al final
    // aqui hay que llamar a buscar hueco
    Nodo *padre = buscarHueco(raiz, nuevoElemento);

    Nodo *nuevo = new Nodo();
    nuevo->contenido = nuevoElemento;

    if (padre->contenido < nuevoElemento)
    {
      padre->hijoDerecho = nuevo;
    }
    else
    {
      padre->hijoIzquierdo = nuevo;
    }

    nuevo->padre = padre;
    nuevo->hijoDerecho = NULL;
    nuevo->hijoIzquierdo = NULL;
  }

  n++;
}

Nodo *ABB::buscar(int elementoABuscar)
{
  return buscarRecursivo(raiz, elementoABuscar);
}

// el texto ponia hacerlo de otra manera
void ABB::eliminar(int elementoABuscar)
{
  Nodo *eliminar = buscar(elementoABuscar);
  Nodo *temp;

  // si el nodo es la raiz
  if (raiz->contenido == elementoABuscar)
  {
    // si solo tiene un subarbol
    if (raiz->hijoDerecho == NULL)
    {
      raiz = raiz->hijoIzquierdo;
    }
    else
    {
      // si solo tiene un subarbol
      if (raiz->hijoIzquierdo == NULL)
      {

        if (raiz->hijoDerecho->hijoIzquierdo != NULL)
        {
          Nodo *temp = raiz->hijoDerecho->hijoIzquierdo;
          temp->hijoIzquierdo = NULL;
          temp->hijoDerecho = raiz->hijoDerecho;
          raiz->hijoDerecho->hijoIzquierdo = NULL;
          raiz = temp;
        }
        else
        {
          raiz = raiz->hijoDerecho;
        }
      }
      else
      { // si tiene dos subarboles
        int altura_drc = alturaNodo(raiz->hijoDerecho);
        int altura_izq = alturaNodo(raiz->hijoIzquierdo);

        if (altura_drc > altura_izq)
        {
          raiz->hijoDerecho->hijoIzquierdo = raiz->hijoIzquierdo;
          raiz->hijoIzquierdo->padre = raiz->hijoDerecho;

          raiz = raiz->hijoDerecho;
        }
        else
        {
          raiz->hijoIzquierdo->hijoDerecho = raiz->hijoDerecho;
          raiz->hijoDerecho->padre = raiz->hijoIzquierdo;
          raiz = raiz->hijoIzquierdo;
        }
      }
    }
  }
  else if (eliminar->hijoDerecho == NULL && eliminar->hijoIzquierdo == NULL)
  { // si es una hoja
    Nodo *padre = eliminar->padre;
    if (padre != NULL)
    {
      if (padre->contenido > eliminar->contenido)
      {
        padre->hijoIzquierdo = NULL;
      }
      else
      {
        padre->hijoDerecho = NULL;
      }
    }
  }
  else
  { // si es un nodo interno
    int cont_dr = -2;
    int cont_iz = -2;

    Nodo *padre = eliminar->padre;
    Nodo *hijo_dr;
    Nodo *hijo_izq;

    if (eliminar->hijoDerecho != NULL)
    {
      cont_dr = alturaNodo(eliminar->hijoDerecho);
    }
    else if (eliminar->hijoIzquierdo != NULL)
    {
      cont_iz = alturaNodo(eliminar->hijoDerecho);
    }

    if (padre->hijoDerecho->contenido == eliminar->contenido)
    {
      if (cont_dr > cont_iz)
      {
        padre->hijoDerecho = eliminar->hijoDerecho;
        eliminar->hijoDerecho->padre = padre;
      }
      else
      {

        padre->hijoDerecho = eliminar->hijoIzquierdo;
        eliminar->hijoIzquierdo->padre = padre;
      }
    }
    else if (padre->hijoIzquierdo->contenido == eliminar->contenido)
    {
      if (cont_dr > cont_iz)
      {
        padre->hijoIzquierdo = eliminar->hijoDerecho;
        eliminar->hijoDerecho->padre = padre;
      }
      else
      {

        padre->hijoIzquierdo = eliminar->hijoIzquierdo;
        eliminar->hijoIzquierdo->padre = padre;
      }
    }
  }

  

  n--;
}

bool ABB::esABB()
{
  return esSubABB(raiz);
} 

bool ABB::esAVL()
{
  return esSubAVL(raiz);
}

void ABB::imprimirRecorrido(Nodo *raizSubarbol)
{
  cout << raizSubarbol->contenido << endl;
  if (raizSubarbol->hijoIzquierdo != NULL)
  {
    cout << "I";
    imprimirRecorrido(raizSubarbol->hijoIzquierdo);
    cout << endl;
  }
  if (raizSubarbol->hijoDerecho != NULL)
  {
    cout << "D";
    imprimirRecorrido(raizSubarbol->hijoDerecho);
    cout << endl;
  }
}

Nodo *ABB::leerSubarbol(Nodo *padre)
{
  int contenido;
  cin >> contenido;
  if (contenido >= 0)
  {
    Nodo *arbol = new Nodo;
    arbol->contenido = contenido;
    arbol->hijoIzquierdo = leerSubarbol(arbol);
    arbol->hijoDerecho = leerSubarbol(arbol);
    arbol->padre = padre;
    return arbol;
  }
  else
  {
    return NULL;
  }
}

void ABB::eliminarSubarbol(Nodo *raizSubarbol)
{

  // comprobamos si es un nodo hoja
  if (raizSubarbol->hijoDerecho == NULL && raizSubarbol->hijoIzquierdo == NULL)
  {
    eliminarNodo(raizSubarbol->padre);
  }
  else
  {
    // si no es un nodo hoja
    if (raizSubarbol->hijoDerecho != NULL)
    {
      eliminarSubarbol(raizSubarbol->hijoDerecho);
    }
    else if (raizSubarbol->hijoIzquierdo != NULL)
    {
      eliminarSubarbol(raizSubarbol->hijoIzquierdo);
    }

    eliminarNodo(raizSubarbol);
  }
}

// no se si esta bien
// he tenido en cuenta que es solo al final
Nodo *ABB::buscarHueco(Nodo *raizSubarbol, int elementoAInsertar)
{
  Nodo *hueco;

  if (raizSubarbol->contenido > elementoAInsertar)
  {
    if (raizSubarbol->hijoIzquierdo == NULL)
    {
      hueco = raizSubarbol;
    }
    else
    {
      hueco = buscarHueco(raizSubarbol->hijoIzquierdo, elementoAInsertar);
    }
  }
  else
  {
    if (raizSubarbol->hijoDerecho == NULL)
    {
      hueco = raizSubarbol;
    }
    else
    {
      hueco = buscarHueco(raizSubarbol->hijoDerecho, elementoAInsertar);
    }
  }

  return hueco;
}

Nodo *ABB::buscarRecursivo(Nodo *raizSubarbol, int elementoABuscar)
{
  Nodo *buscado = NULL;
  if (raiz != NULL)
  {
    if (raizSubarbol->contenido == elementoABuscar)
    {
      buscado = raizSubarbol;
    }
    else
    {
      if (elementoABuscar < raizSubarbol->contenido)
      {
        if (raizSubarbol->hijoIzquierdo != NULL)
        {
          buscado = buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
        }
      }
      else
      {
        if (raizSubarbol->hijoDerecho != NULL)
        {
          buscado = buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
        }
      }
    }
  }

  return buscado;
}

Nodo *ABB::buscarMaximo(Nodo *raizSubarbol)
{
  Nodo *maximo = raizSubarbol;

  if (raizSubarbol->hijoDerecho != NULL)
  {
    while (maximo->hijoDerecho != NULL)
    {
      maximo = maximo->hijoDerecho;
    }
  }

  return maximo;
}

Nodo *ABB::buscarMinimo(Nodo *raizSubarbol)
{
  Nodo *minimo=raizSubarbol;

  if (raizSubarbol->hijoIzquierdo != NULL)
  {
    while (minimo->hijoIzquierdo != NULL)
    {
      minimo = minimo->hijoIzquierdo;
    }
  }

  return minimo;
}

void ABB::eliminarNodo(Nodo *nodoParaEliminar)
{
  nodoParaEliminar->hijoDerecho = NULL;
  nodoParaEliminar->hijoIzquierdo = NULL;
}

int ABB::alturaNodo(Nodo *raizSubarbol)
{
  int altura = 0;

  if (raiz == NULL)
  {
    return -1;
  }
  else if (raizSubarbol->hijoDerecho == NULL && raizSubarbol->hijoIzquierdo == NULL)
  {
    return 0;
  }
  else
  {
    int contador_derecha=0;
    int contador_izquierda=0;

    if (raizSubarbol->hijoDerecho != NULL)
    {
      contador_derecha = alturaNodo(raizSubarbol->hijoDerecho);
    }

    if (raizSubarbol->hijoIzquierdo != NULL)
    {
      contador_izquierda = alturaNodo(raizSubarbol->hijoIzquierdo);
    }

    if (contador_derecha < contador_izquierda)
    {
      altura = contador_izquierda + 1 ;
    }
    else
    {
      altura = contador_derecha + 1 ;
    }
  }

  return altura;
}

bool ABB::esSubABB(Nodo *raizSubarbol) 
{
  bool loEs=false;
  
  if (raizSubarbol == NULL || (raizSubarbol->hijoDerecho == NULL && raizSubarbol->hijoIzquierdo == NULL))
  {
    return true;
  }
  else{
    Nodo *maximo;
    Nodo *minimo;

    if (raizSubarbol->hijoIzquierdo != NULL){
      maximo=buscarMaximo(raizSubarbol->hijoIzquierdo);

      if(maximo->contenido<raizSubarbol->contenido){
        loEs=esSubABB(raizSubarbol->hijoIzquierdo);
      }
      else{
        return false;
      }
    }

    if (raizSubarbol->hijoDerecho != NULL){
      minimo=buscarMinimo(raizSubarbol->hijoDerecho);

      if(minimo->contenido>raizSubarbol->contenido){
        loEs=esSubABB(raizSubarbol->hijoDerecho);
      }
      else{
        return false;
      }
    }

  }

  return loEs;

  
}

bool ABB::esSubAVL(Nodo *raizSubarbol) 
{ 
  bool loes = false;
  int cont_d;
  int cont_i;

  if(esSubABB(raizSubarbol)){

    if(raizSubarbol->hijoDerecho!=NULL){
      cont_d=alturaNodo(raizSubarbol->hijoDerecho);
    }

    if(raizSubarbol->hijoIzquierdo!=NULL){
      cont_i=alturaNodo(raizSubarbol->hijoIzquierdo);

    }


    if((cont_d-cont_i)<-1 || (cont_d-cont_i)>1){
      return false;
    }
    else{
      if(esSubABB(raizSubarbol->hijoDerecho) && esSubABB(raizSubarbol->hijoIzquierdo)){
        return true;
      }

    }
  }

  

  return loes;
}
