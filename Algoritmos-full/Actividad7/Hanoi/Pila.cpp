#include"Pila.h"


Pila::Pila(string name)
{
  this->name=name;
  cima=NULL;
}

std::string Pila::nombrePila()
{
  return name;
}

void Pila::apilar(int num)
{
  
  cout<<"Apilando disco "<<num<<" en poste "<<name<<endl;

  if(cima==NULL){
    cima=new Nodo(num);
  }
  else{
    Nodo* nodo=new Nodo(num);
    nodo->siguiente=cima;
    cima=nodo;
  }
}
  
int Pila::desapilar()
{    
  int num=cima->valor;
  
  cout<<"Desapilando disco "<<num<<" del poste "<<name<<endl;
  cima=cima->siguiente; 
  
  return num;

}

bool Pila::estaVacia()
{
  if(cima==NULL){
    return true;
  }
  else{
    return false;
  }
}

