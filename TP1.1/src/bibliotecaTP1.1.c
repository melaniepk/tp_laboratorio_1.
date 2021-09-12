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
	float division;


	if(b != 0)
	{
		division = a / b;
		resultado = division;
	}

	return resultado;
}

float calcularFactorial(float a)
{

	float b;
	float fact = 1;

	for (b = a; b > 1; b--)
	{
		fact = fact * b;
	}

	return fact;
}

float pedirNumero(char mensaje[], float numero )
{
	printf("%s", mensaje);
	scanf("%f", &numero);
	return numero;
}
