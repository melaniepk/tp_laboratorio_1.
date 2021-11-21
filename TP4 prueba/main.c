#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn1.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
	    char seguir = 's';
	    int carga = 0;

	    LinkedList* listaEmpleados = ll_newLinkedList();

	    do{

	    		switch(menu()) {
	            case 1:
	            	if(carga == 0)
	            	{
		            	controller_loadFromText("data.csv",listaEmpleados);
		            	carga = 1;
	            	}
	            	else
	            	{
	            		printf("No se puede abrir otro archivo en este momento ya que se sobreescribirian\n");
	            		system("cls");
	            	}
	                break;
	            case 2:
	            	if(carga == 0)
					{
						if(controller_loadFromBinary("data.bin",listaEmpleados)==1)
						{
							carga = 1;
						}
					}
					else
					{
						printf("No se puede abrir otro archivo en este momento ya que se sobreescribirian\n");
						system("cls");
					}
					break;
	            	break;
	            case 3:
	            	controller_addEmployee(listaEmpleados);
	            	break;
	            case 4:
	            	if(carga == 0)
					{
						printf("Aun no se ha cargado ningun archivo\n");
						system("cls");
					}
	            	else
					controller_editEmployee(listaEmpleados);
	            	break;
	            case 5:
	            	if(carga == 0)
	            	{
	            		printf("Aun no se ha cargado ningun archivo\n");
	            		system("cls");
	            	}
	            	else
	            	controller_removeEmployee(listaEmpleados);
	            	break;
	            case 6:
	            	if(carga == 0)
	            	{
	            		printf("Aun no se ha cargado ningun archivo\n");
	            		system("cls");
	            	}
	            	else
	            	controller_ListEmployee(listaEmpleados);
	            	break;
	            case 7:
	            	if(carga == 0)
	            	{
	            		printf("Aun no se ha cargado ningun archivo\n");
	            		system("cls");
	            	}
	            	else
	            	controller_sortEmployee(listaEmpleados);
	            	break;
	            case 8:
	            	controller_saveAsText("data.csv",listaEmpleados);
	            	break;
	            case 9:
	            	controller_saveAsBinary("data.bin", listaEmpleados);
	            	break;
	            case 10:
	            	seguir = 'n';
	            	printf("Cerrando el programa.\n");
	            	break;
	    		}


	    }while(seguir == 's');

	    ll_deleteLinkedList(listaEmpleados);
	    return 0;
    return 0;
}

