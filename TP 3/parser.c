#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;

	char id[50];
	char nombre[50];
	char horasTrabajadas[50];
	char sueldo[50];
	int i=0;
	int cant;
	pFile = fopen("data.csv","r");
	if(pFile == NULL)
	{
		printf("Error, no es posible leer el archivo");
	}
	else
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]", id,nombre, horasTrabajadas, sueldo);
		while(!feof(pFile))
		{
			cant = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]", id, nombre,
					horasTrabajadas, sueldo);
			if(cant <4)
			{
				break;
			}
			unEmpleado = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
			i++;
			ll_add(pArrayListEmployee,unEmpleado);
		}
	}

	fclose(pFile);
    return i;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* unEmpleadoBinario;
	//int cantidad = ll_len(pArrayListEmployee);
	int cant;

		ll_clear(pArrayListEmployee);
		while(!feof(pFile))
		{

			unEmpleadoBinario = employee_new();
			if(unEmpleadoBinario != NULL)
			{
				cant = fread(unEmpleadoBinario,sizeof(Employee),1,pFile);
				if(cant == 1)
				{
					ll_add(pArrayListEmployee,unEmpleadoBinario);

				}
				else
				{
					break;
				}

			}

			retorno = 0;
		}

    return  retorno;
}
