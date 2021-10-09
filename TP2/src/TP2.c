/*
 ============================================================================
 Name        : TP2.c
 Author      : Melanie Paredes Kaleniuk
 Version     : Final
 Copyright   : Your copyright notice
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn1.h"
#include "ArrayEmployees.h"

#define TAM 1000

int main(void) {

	setbuf(stdout, NULL);
	int banderaDeCompletado = 0;
	int opcion;
	int retorno;
	Empleado listaEmpleados[TAM];
	int idEncontrado;

	int numeroId;
	int mostrarLista;
	int id=0;
	int criterio;
	InicializarEmpleados(listaEmpleados, TAM);
	int IdIncremental;

	do{
		utn_getNumero(&opcion, "\nMenu de opciones: \n1. Alta Empleado.\n2. Baja Empleado.\n3. Modificar empleado."
				" \n4. Listado de empleados ordenados alfabeticamente y por sector.\n"
				"5. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n"
				"6.Salir del menu.\nSeleccione alguna de las opciones desplegadas anteriormente:\n", "ERROR! opcion invalida", 1,6,2);

		switch(opcion)
		{
		case 1:
			IdIncremental = IncrementarId(&id);
			retorno = altaEmpleado(listaEmpleados, TAM, IdIncremental);
			if(retorno != -1)
			{
				printf("Empleado cargado exitosamente! Si desea añadir otro empleado pulse 1\n");
				banderaDeCompletado = 1;
			}
			else
			{
				printf("No hay mas lugar!\n");
			}

			break;
		case 2:
			if(banderaDeCompletado != 1)
			{
				printf("ERROR. Primero debe ingresar empleado/s\n");
			}
			else
			{
				mostrarLista = ImprimirEmpleados(listaEmpleados,TAM);
				if(mostrarLista == 0)
				{
					utn_getNumero(&numeroId,"Ingrese el ID del empleado que desea eliminar\n","Error, ID no existente\n",0,1000,10);
					idEncontrado = EncontrarEmpleadoPorId(listaEmpleados,TAM,&numeroId);
					if(idEncontrado == -1)
					{
						printf("No se pudo encontrar a un empleado con ese ID\n");
					}
					else
					{
						retorno = BajaEmpleado(listaEmpleados, TAM, idEncontrado);
						if(retorno == -1 || retorno == 1)
						{
							printf("NO se eliminó correctamente al empleado\n");
						}
						else
						{
							printf("Empleado eliminado con exito!\n");
						}
					}
				}
				else
				{
					printf("NO existen empleados a eliminar\n");
				}

			}
			break;
		case 3:
			if(banderaDeCompletado != 1)
			{
				printf("ERROR. Primero debe ingresar empleado/s\n");
			}
			else
			{
				retorno = ModificarEmpleado(listaEmpleados, TAM);
				if(retorno == -1)
				{
					printf("No se pudo modificar al empleado o el ID no existe\n");
				}
				else
				{
					printf("Empleado modificado\n");
				}
			}
			break;
		case 4:
			if(banderaDeCompletado != 1)
			{
				printf("ERROR. Primero debe ingresar empleado/s\n");
			}
			else
			{
				utn_getNumero(&criterio, "Ingrese un criterio de ordenamiento descendente (0) o ascendente (1)", "ERROR. Fuera de rango", 0, 1,2);

				retorno = OrdenarTrabajos(listaEmpleados, TAM, &criterio);
				if(retorno != -1)
				{
					ImprimirEmpleados(listaEmpleados,TAM);
				}

			}
			break;
		case 5:
			if(banderaDeCompletado != 1)
			{
				printf("ERROR. Primero debe ingresar empleado/s\n");
			}
			else
			{
				float promedio = MostrarTotalYPromedioDeSalarios(listaEmpleados, TAM);
				calcularMayoresAPromedio(listaEmpleados,TAM,promedio);
			}
			break;
		case 6:
			printf("Cerrando menú.\n");
			break;

		}

	}while(opcion != 6);


	return EXIT_SUCCESS;
}
