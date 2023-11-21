#include<iostream>
#include"Pila.h"
using namespace std;

/**
 * Resuelve el problema de las torres de hanoi
 * 
 * T(n)=2T(n-1) + 1 -> O(2^(n-1))
 * Complejidad temporal: O(2^(n-1))
 * Complejidad espacial: O(1) 
 */
void Hanoi(int n,Pila *origen,Pila *temporal,Pila *destino) //2T(n-1) + 1
{
  if(n>0){
    Hanoi(n-1,origen,destino,temporal); //T(n-1)
    destino->apilar(origen->desapilar());
    Hanoi(n-1,temporal,origen,destino); //T(n-1)
  }
}


int main()
{  
  Pila *A=new Pila("A");
  Pila *B=new Pila("B");
  Pila *C=new Pila("C");

  int n;
  cin>>n;

  assertdomjudge(n>0);

  for(int i=n;i>0;i--)
    A->apilar(i);

  Hanoi(n,A,B,C);
  
  for(int i=0;i<n;i++)
    C->desapilar();

  return 0;
  
}

