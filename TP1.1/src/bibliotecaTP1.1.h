/*
 * bibliotecaTP1.1.h
 *
 *  Created on: 29 mar. 2021
 *      Author: mkale
 */

#ifndef BIBLIOTECATP1_1_H_
#define BIBLIOTECATP1_1_H_



#include <stdio.h>
#include <stdlib.h>

/**
 * @fn float calcularSuma(float, float)
 * @brief
 * esta funcion recibe dos numeros, los suma y devuelve el resultado
 * @param a primer numero
 * @param b segundo numero
 * @return resultado (suma)
 */
float calcularSuma(float a, float b);

/**
 * @fn float calcularResta(float, float)
 * @brief
 * esta funcion recibe dos numeros, calcula la diferencia y devuelve el resultado
 * @param a primer numero
 * @param b segundo numero
 * @return resultado (resta)
 */
float calcularResta(float a, float b);

/**
 * @fn float calcularMultiplicacion(float, float)
 * @brief
 * esta funcion recibe dos numeros, calcula el producto entre ellas y devuelve el resultado
 * @param a primer numero
 * @param b segundo numero
 * @return resultado (multiplicacion)
 */
float calcularMultiplicacion(float a, float b);

/**
 * @fn float calcularDivision(float, float)
 * @brief
 * esta funcion recibe dos numeros, calcula el cociente y devuelve el resultado
 * @param a primer numero
 * @param b segundo numero
 * @return resultado (division)
 */
float calcularDivision(float a, float b);

/**
 * @fn float calcularFactorial(float)
 * @brief
 * esta funcion recibe un numero, calcula su factorial y devuelve el resultado
 * @param a numero
 * @return resultado (factorial)
 */
float calcularFactorial(float a);

/**
 * @fn float pedirNumero(char[], float)
 * @brief
 * esta funcion pide un mensaje y permite al usuario escanear un numero y devolverlo
 * @param mensaje
 * @param numero
 * @return numero
 */
float pedirNumero(char mensaje[], float numero );


#endif /* BIBLIOTECATP1_1_H_ */
