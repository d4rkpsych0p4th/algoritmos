#include"Supermercado.h"

using namespace std;

Supermercado::Supermercado(int n){
  n_cajas=n;
  cajas=new ColaPrioridad[n_cajas];
}

void Supermercado::nuevoUsuario(int n,int id){
  cajas[n].encolar(id);
} 

void Supermercado::cerrarCaja(int n){
  while(!cajas[n].estaVacia()){ //n*n_cajas + n + 1
        for(int i=0; i<n_cajas && !cajas[n].estaVacia();i++){ //n_cajas + 1
            if(i!=n){
                cajas[i].encolar(cajas[n].desencolar());
            }
        }
    }
}

int Supermercado::atenderUsuario(int n){
  return cajas[n].desencolar();
}

bool Supermercado::cajaVacia(int n){
  return cajas[n].estaVacia();
}
