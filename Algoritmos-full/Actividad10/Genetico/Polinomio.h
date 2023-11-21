#pragma once

#include "SolucionParcial.h" // Estructura que guarda el "x" e "y" de una soluci�n parcial

// Clase que representa una funci�n polin�mica de cualquier grado y de una variable independiente
class Polinomio
{
 private:
 	int n; // Grado del polinomio. Tiene que ser >= 0
	float *coeficientes; // Array de coeficientes del polinomio (tama�o: n+1). Primero los coeficientes de los sumandos de grado menor.

	// Funci�n para obtener un n�mero aleatorio que siga una distribuci�n normal estandar (media 0 y desviaci�n 1).
	// Retorno: n�mero aleatorio siguiendo una distribuci�n normal entre [-6, +6]
	// Complejidad temporal y espacial: O(1)
	float obtenerAleatorioNormalEstandar();

	/**
	 * Obtiene la raiz de forma recursiva basandose en 10 hijos 
	 * 
	 * Complejidad temporal: O(T(n-1))
	 * Complejidad espacial: O(n)
	 */
	float obtenerRaizRecursivo(SolucionParcial solucionParcialInicial);

public:

	/**
	 * Inicializa los atributos del array coeficientes 
	 * 
	 * Complejidad temporal: O(n)
	 * Complejidad espacial: O(n)
	 */
	Polinomio(int n, float *coeficientes);

	/**
	 * Devuelve la solucion de la ecuacion al sustituir la x
	 * 
	 * Complejidad temporal: O(n)
	 * Complejidad espacial: O(1)
	 */
	float evaluar (float x);

	/**
	 * Obtiene la raiz
	 * 
	 * Complejidad temporal: O(T(n-1))
	 * Complejidad espacial: O(n)
	 */
	float obtenerRaiz();

	/**
	 * Destructor del polinomio
	 * 
	 * Complejidad temporal: O(1)
	 * Complejidad espacial: O(1)
	 */
	~Polinomio();
};

