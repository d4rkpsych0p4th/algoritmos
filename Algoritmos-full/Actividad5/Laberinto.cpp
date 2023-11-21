/**
 * @file Laberinto.cpp
 * @author Chantal López
 *
 *
 */

#include <iostream>
#include <string>

#define TAM 10

using namespace std;

/**
 * Busca la solución del laberinto utilizando el algoritmo backtracking, retorna true si 
 * encuentra la solución y devuelve las posiciones de la solución.
 * Parametros: laberinto, posiciones iniciales del laberinto
 * Retorno: true si encunetra solucion y false si no
 * 
 * T(n)= 4*T(n-1) +1 //con llegar a este punto esta bien en el examen ejercicios etc 
 * Complejidad temporal: O(4^n) se suele expresar como una constantes O(c^n)
 * Complejidad espacial: O(1) 
 */
bool buscarTesoro(char lab[][TAM], int &a, int &b);

/**
 * Imprime el laberinto
 */
void imprimirLaberinto(char laberinto[][TAM]);

int main()
{

    int i, j;
    int sol_x=0, sol_y=0;
    char laberinto[TAM][TAM];

    for (i = 0; i < TAM; i++)
        for (j = 0; j < TAM; j++)
            cin >> laberinto[i][j];

    if (buscarTesoro(laberinto,sol_x, sol_y))
    {
        imprimirLaberinto(laberinto);
        cout << "ENCONTRADO " << sol_x << " " << sol_y << endl;
    }
    else
        cout << "INALCANZABLE" << endl;

    return 0;
}

void imprimirLaberinto(char laberinto[][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        for (int j = 0; j < TAM; j++)
            cout << laberinto[i][j];
        cout << endl;
    }
}

//utilizando algoritmo de Backtraking
bool buscarTesoro(char lab[][TAM], int &a, int &b){
    bool exito=false;
    int corX,corY;
    lab[0][0]='X';

    //posibles movimientos/candidatos (4)
    int posx[]={-1,0,1,0};
    int posy[]={0,1,0,-1};

    //Se repite hasta que haya exito o no mas candidatos
    for(int i=0; i<4 && !exito; i++){ //T(n)=4*T(n-1) + 1
        //Seleccionamos un candidato
        corX= a + posx[i];
        corY= b + posy[i];

        //Comprobamos que el candidato es válido
        if(corX<TAM && corX>-1 && corY<TAM && corY>-1){
            //comprobamos si el candidato es una solución
            if(lab[corX][corY]=='T'){ //encuentra el tesoro
                exito=true;
                
            }
            else{
                if(lab[corX][corY]=='.'){ //puede pasar
                    lab[corX][corY]='X';
                    exito=buscarTesoro(lab,corX,corY); 
//llamamos a la funcion T(n)=T(n-1) pq le tocaria comprobar una casilla menos si n son todas las casillas 

                    //si no tuvo exito - desanotar candidato
                    if(!exito){ 
                        lab[corX][corY]='.';
                    } 
                }
            }       
        }
    }

    //para que se copie a la salida
    if(exito){
        a=corX;
        b=corY;
    }

    return exito;
}

