#include "Cola.h"


Cola::Cola(){
    principio=NULL;
    final=NULL;
}

void Cola::encolar(int num){
    
    if(principio==NULL){
        principio=new Nodo(num);
        
    }else{
        if(final==NULL){
            final=new Nodo(num);
            principio->siguiente=final;
        }
        else{
            Nodo *nuevo=new Nodo(num);
            final->siguiente=nuevo;
            final=nuevo;
        }
    }
}

int Cola::desencolar(){
    Nodo * primero=principio;
    principio=principio->siguiente;

    return primero->valor;
}

bool Cola::estaVacia(){
  if(principio==NULL){
      return true;
  }
  else{
      return false;
  }
}
