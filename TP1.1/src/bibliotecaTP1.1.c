/*
 * bibliotecaTP1.1.c
 *
 *  Created on: 29 mar. 2021
 *      Author: mkale
 */
#include <stdio.h>
#include <stdlib.h>


float calcularSuma(float a, float b)
{

	float suma;
	suma = a + b;
	return suma;
}

float calcularResta(float a, float b)
{
	float resta;
	resta = a - b;
	return resta;

}

float calcularMultiplicacion(float a, float b)
{
	float multiplicacion;
	multiplicacion = a * b;
	return multiplicacion;
}


float calcularDivision(float a, float b)
{
	float resultado;
	resultado = 0;

	if(b != 0)
	{
		float division;
		division = a / b;
		resultado = division;
	}


	return resultado;
}

float calcularFactorial(float a)
{
	int contador;
	float factorial;
	int multiplicador;


	multiplicador=1;
	factorial=1;

	for(contador=0;contador<a;contador++)
	{
		factorial=factorial*multiplicador;

		multiplicador++;
	}

	return factorial;
}

float pedirNumero(char mensaje[], float numero )
{
	printf("%s", mensaje);
	scanf("%f", &numero);
	return numero;
}
