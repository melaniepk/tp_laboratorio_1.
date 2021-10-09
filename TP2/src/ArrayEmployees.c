/*
 * ArrayEmployees.c
 *
 *  Created on: 4 may. 2021
 *      Author: mkale
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn1.h"
#include "ArrayEmployees.h"


int InicializarEmpleados(Empleado *list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = TRUE;

			retorno = 0;
		}
	}

	return retorno;
}


Empleado PedirDatosEmpleado()
{
    Empleado miEmpleado;


		utn_getString(miEmpleado.nombre ,sizeof(miEmpleado.nombre), "\nIngrese el nombre del empleado", "\nError!. ", 10);
		utn_getString(miEmpleado.apellido ,sizeof(miEmpleado.apellido ), "\nIngrese el apellido del empleado", "\nError!. ", 10);
		utn_getNumeroFlotante(&miEmpleado.salario,"Ingrese el salario del empleado:\n","Error al ingresar salario.\n",100,999999,10);
		utn_getNumero(&miEmpleado.sector,"Ingrese el sector del empleado: \n","Sector no registrado\n",1,100,10);



    return miEmpleado;

}

int BuscarLibre(Empleado *list, int tam)
{
    int i;
    int index = -1;
    for(i=0; i<tam; i++)
    {
        if(list[i].isEmpty== TRUE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int IncrementarId (int *proximoId)
{
	 int auxId= *proximoId;
	 int nuevoId = auxId+1;
	*proximoId = nuevoId;
	return nuevoId;
}

int AgregarEmpleado(Empleado *list, int len,int id)
{

	int i;
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		i = BuscarLibre(list, len);
		if (i != -1)
		{
			list[i] = PedirDatosEmpleado();
			list[i].id = id;
			list[i].isEmpty = FALSE;

			retorno = 0;
		}

	}
	return retorno;
}

int altaEmpleado(Empleado *list, int len, int id)
{
	int retornoDeAdd;
	int retorno;

	if(list!= NULL && len >0 )
	{
		retornoDeAdd = AgregarEmpleado(list,len,id);
	}

	if(retornoDeAdd == 0)
	{
		retorno = 0;

	}
	else
	{
		printf("Error al cargar empleado\n");

	}

	return retorno;
}

int EncontrarEmpleadoPorId(Empleado *list, int len, int *id)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0 && id >=0)
	{

		for(i=0; i< len;i++)
		{
			if(list[i].id == *id)
			{
				retorno = i;
				break;
			}
		}
	}


	return retorno;
}

int BajaEmpleado(Empleado *list, int len,int id)
{
	int retorno = -1;
	char opcion;

	if(list != NULL && len > 0)
	{
		printf("¿Seguro desea eliminar al empleado %s %s? (S/N)", list[id].apellido, list[id].nombre);
		scanf("%c", &opcion);
		if(opcion == 's')
		{
			list[id].isEmpty = TRUE;
			retorno = 0;
		}
		else
		{
			retorno = -1;

		}
	}
	return retorno;

}

int OrdenarTrabajos(Empleado *list, int len, int *orden)
{
	int retorno = -1;
	int i;
	int j;
	Empleado auxEmployee;


	if (list != NULL && len > 0)
	{
		switch (*orden)
		{
		case 0: //descendente
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if(list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)
					{
						if((list[i].sector < list[j].sector))
						{
							auxEmployee = list[j];
							list[j] = list[i];
							list[i] = auxEmployee;
						}
						else
						{
							if(strcmp(list[i].apellido, list[j].apellido)>0)

							{
								auxEmployee = list[j];
								list[j] = list[i];
								list[i] = auxEmployee;

							}
						}

					}

				}
			}
			retorno = 0;
			break;
		case 1://ascendente
			for (i = 0; i < len - 1; i++)
			{
				for (j = i + 1; j < len; j++)
				{
					if (list[i].isEmpty == FALSE && list[j].isEmpty == FALSE)
					{
						if((list[i].sector > list[j].sector))
						{
							auxEmployee = list[j];
							list[j] = list[i];
							list[i] = auxEmployee;
						}
						else
						{
							if(strcmp(list[i].apellido, list[j].apellido)>0)

							{
								auxEmployee = list[j];
								list[j] = list[i];
								list[i] = auxEmployee;

							}
						}
					}
				}
			}
			retorno = 0;
			break;
		default:
			printf("Criterio de ordenamiento mal ingresado.\n");
			retorno = -1;
			break;
		}
	}
	return retorno;
}

int ImprimirEmpleados(Empleado *list, int len)
{

	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
			   printf("  ID     Nombre       Apellido       Sector        Salario\n ");

		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty != TRUE)
			{
				retorno = 0;

				printf(" %d      %s         %s           %d          %.2f\n ", list[i].id,
														   list[i].nombre,
														   list[i].apellido,
														   list[i].sector,
														   list[i].salario);
			}

		}
	}
	return retorno;
}


int ModificarEmpleado(Empleado *list, int tam)
{

	int idIngresado;
	int i;
	int opcionMod;
	char seguir;
	int retorno = -1;

	ImprimirEmpleados(list, tam);
	printf("Ingrese el ID del empleado a modificar: ");
	scanf("%d", &idIngresado);


	if(list != NULL && tam >0)
	{
		for(i=0; i<tam; i++)
		{
			if(idIngresado == list[i].id )
			{

				do
				{
					utn_getNumero(&opcionMod, "Ingrese el numero que corresponda a lo que quiera modificar:\n1. Nombre\n2. Apellido\n3. Salario\n4. Sector\n","Opcion invalida.\n", 1,4,2);

					switch(opcionMod)
					{
					case 1:
						utn_getPalabra(list[i].nombre,51,"Ingrese nuevo nombre\n", "Error al ingresar el nombre\n", 2);
						break;
					case 2:
						utn_getPalabra(list[i].apellido,51,"Ingrese nuevo apellido\n", "Error al ingresar el apellido\n", 2);
						break;
					case 3:
						utn_getNumeroFlotante(&list[i].salario, "Ingrese nuevo salario\n", "Error al ingresar nuevo salario\n",0, 99999999, 2 );
						break;
					case 4:
						utn_getNumero(&list[i].sector, "Ingrese nuevo sector", "Error al ingresar nuevo sector", 1, 100, 2);
						break;
					}

					retorno = 0;

					printf("Modificacion realizada con exito!.\nDesea realizar alguna otra modificacion? (S/N).");
					scanf("%c", &seguir);

				}while(seguir == 's');

			}

		}
	}


	return retorno;
}


float MostrarTotalYPromedioDeSalarios(Empleado list[], int len)
{

	int i;
	float acumuladorSalario = 0;
	float promedio;
	int contadorEmpleados = 0;

	if(list != NULL && len > 0)
	{
		for(i=0; i<len;i++)
		{
			if(list[i].isEmpty == FALSE)
			{
				acumuladorSalario = acumuladorSalario + list[i].salario;
				contadorEmpleados++;
			}
		}

		promedio = acumuladorSalario / contadorEmpleados;
		printf("El promedio es %.2f\n", promedio);
		printf("El total de la suma de los salarios es: %.2f\n", acumuladorSalario);

	}
	return promedio;


}


void calcularMayoresAPromedio(Empleado *lista, int tam, float promedio)
{
	int acumulador = 0;
	if(lista != NULL && tam >0 && promedio >0)
	{
		for(int i = 0; i <tam;i++)
		{
			if(lista[i].isEmpty == FALSE  && lista[i].salario > promedio)
			{
				acumulador++;
			}
		}
		printf("La cantidad de salarios mayores al promedio es de %d\n", acumulador);
		printf("Nombres de los empleados con sueldos mayor al promedio\n");

		for(int i = 0;i <tam;i++)
		{
			if(lista[i].isEmpty == FALSE  && lista[i].salario > promedio)
			{
				printf("%s\t %s\t\n",lista[i].nombre, lista[i].apellido);

			}
		}
	}


}

