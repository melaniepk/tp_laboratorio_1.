/*
 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaTP1.1.h"



int main(void) {

	setbuf(stdout, NULL);


	float x;
	float y;
	int bandera = 0;
	float suma;
	float resta;
	float multiplicacion;
	float division;
	float factorial;
	float factorial2;
	int opcion;
	int banderaCalculo = 0;

	do
	{
		printf("MENÚ DE OPCIONES\n");

		printf("1. Ingresar primer operando: A = %.2f\n", x);
		printf("2. Ingresar segundo operando: B = %.2f \n", y);
		printf("3. Calcular todas las operaciones: \n");
		printf("a) Suma\n");
		printf("b) Resta\n");
		printf("c) Multiplicacion\n");
		printf("d) Division\n");
		printf("e) Factorial\n");
		printf("4. Mostrar resultados\n");
		printf("5. Salir\n");

		scanf("%d", &opcion);
		while(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5)
		{
			printf("Error, debe ingresar alguna de las opciones enumeradas\n");
			scanf("%d", &opcion);
		}

		switch(opcion)
		{
			case 1:
				x = pedirNumero("Ingresar el primer operando\n", x);
				printf("Usted ha ingresado el primer operando: %.2f\n", x);
				bandera++;
			break;
			case 2:
				if(bandera > 0)
				{
					y = pedirNumero("Ingresar el segundo operando\n", y);
					printf("Uted ha ingresado el segundo operando: %.2f\n", y);
					printf("Operandos a utilizar: %.2f y %.2f\n", x,y);
					bandera++;
				}
				else
				{
					printf("Error, primero debe ingresar el primer operando, ingrese opcion 1\n");
					printf("Presione cualquier tecla para continuar");
					scanf("%d", &opcion);
				}
			break;
			case 3:
				if(bandera > 1 )
				{
					printf("Presione 4 para ver los resultados\n");

					suma = calcularSuma(x, y);

					resta = calcularResta(x, y);

					multiplicacion = calcularMultiplicacion(x,y);

					if(y != 0)
					{
						division = calcularDivision(x,y);
					}

					if(x> -1)
					{
						factorial = calcularFactorial(x);
					}

					if(y>-1)
					{
						factorial2 = calcularFactorial(y);
					}
					banderaCalculo = 1;
				}
				else
				{
					printf("Error, Primero debe ingresar los operandos\n");
				}
			break;
			case 4:
				if(bandera >1 && banderaCalculo >0)
				{
						printf("El resultado de %.2f + %.2f es: %.2f\n",x, y,  suma);
						printf("El resultado de %.2f - %.2f es: %.2f\n",x, y, resta);
						printf("El resultado de %.2f * %.2f es : %.2f\n",x, y, multiplicacion);
						if(y == 0){
							printf("Error en la division. No se puede dividir por 0\n");
						}
						else
						{
							printf("El resultado de %.4f / %.4f es: %.4f\n",x, y, division);

						}

						if(x > -1 && factorial >0)
						{
							printf("El factorial %.2f es: %.2f\n",x, factorial);
						}
						else
						{
								printf("No se puede calcular el factorial de un numero menor a 0\n");
						}

						if(y > -1 && factorial > 0)
						{
							printf("El factorial del %.2f es: %.2f\n",y, factorial2);
						}
						else
						{
								printf("No se puede calcular el factorial de un numero menor a 0\n");					}
						}
				else
				{
					if(bandera < 1)
					{
					printf("Error, primero debe ingresar los operandos\n");
					}
					else
					{
						if(banderaCalculo == 0)
						{
							printf("Error, primero debe realizar los calculos\n");
						}
					}
				}
			break;

			case 5:
				printf("GRACIAS POR USAR LA CALCULADORA!\n");
			break;


		}

	}while(opcion!=5);

	return EXIT_SUCCESS;
}

