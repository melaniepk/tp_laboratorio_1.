/*
 * ArrayEmployees.h
 *
 *  Created on: 4 may. 2021
 *      Author: mkale
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn1.h"

#define TRUE 0
#define FALSE 1
#define LEN 1000


typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;
}Empleado;


/**
 * @fn int IncrementarId(int*)
 * @brief
 * recibe un numero por parametro y lo incrementa
 * @param pGenerarId numero indicado desde el main
 * @return retorna el nuevo valor generado
 */
int IncrementarId (int *pGenerarId);


/**
 * @fn int removeEmployee(Employee*, int, int)
 * @brief
 * esta funcion recibe el id del empleado que se quiere eliminar
 *  y cambia el estado de su campo isEmpty a TRUE
 * @param list lista de empleados enviada desde el main
 * @param len cantidad de espacios en el array recibido
 * @param id identificador del empelado
 * @return 0 si se eliminó al empleado, -1 si no
 */
int BajaEmpleado(Empleado *list, int len, int id);

/**
 * @fn int addEmployee(Employee*, int)
 * @brief
 * esta funcion llama a la funcion para completar los datos del empleado,
 * asi como tambien completa su id y su campo isEmpty.
 * @param list lista de empleados enviada desde el main
 * @param len cantidad de espacios en el array recibido
 * @return 0 si se completaron los datos, -1 si no fue asi
 */
int AgregarEmpleado(Empleado *list, int len, int id);

/**
 * @fn int altaEmpleado(Employee*, int)
 * @brief
 * toma los datos de la funcion addEmployee y los carga
 * @param list lista de empleados
 * @param len cantidad de espacios en el array
 * @return 0 si tuvo exito, -1 si ocurrió un error
 */
int altaEmpleado(Empleado *list, int len,int id);

/**
 * @fn Employee PedirDatosEmpleado()
 * @brief
 * pide los datos del empleado
 * @return devuelve los datos del empleado, excepto en los campos id e isEmpty
 */
Empleado PedirDatosEmpleado();

/**
 * @fn int ModificarEmpleado(Employee*, int)
 * @brief
 * pide el id y modifica el campo que el usuario quiera modificar
 * en alguno de los empleados ingresados
 * @param list lista de empleados pasada desde el main
 * @param tam tamaño del array recibido
 * @return 0 si se realizo la modificacion, -1 si no
 */
int ModificarEmpleado(Empleado *list, int tam);

/**
 * @fn int BuscarLibre(Employee*, int)
 * @brief
 * recorre la lista en busca de algun campo isEmpty que tenga como valor TRUE y devuelve lo que encontró
 * @param list lista de empleados
 * @param tam tamaño de la lista
 * @return devuelve la posicion en la que encuentra el primer campo isEmpty en TRUE, o devuelve -1 si no hay lugar
 */
int BuscarLibre(Empleado *list, int tam);



/**
 * @fn int ObtenerID()
 * @brief
 * obtiene un nuevo numero de ID para el empleado que se este cargando,
 * de manera incremental
 * @return numero de id
 */
int ObtenerID();

/**
 * @fn int initEmployees(Employee*, int)
 * @brief
 * inicializa el campo isEmpty en todo el array con el valor TRUE
 * @param list array de empleados
 * @param len tamaño del array
 * @return 0 si logra inicilizar, -1 si no
 */
int InicializarEmpleados(Empleado *list, int len);

/**
 * @fn int findEmployeeById(Employee*, int, int*)
 * @brief
 * encuentra los datos de un cieto empleado con su id
 * @param list lista de empleados
 * @param len tamaño de la lista
 * @param id id del empelado que se busca
 * @return retorna al empleado si encontró a un empleado con ese id, -1 si no
 */
int EncontrarEmpleadoPorId(Empleado *list, int len, int *id);

/**
 * @fn int sortEmployees(Employee*, int, int*)
 * @brief
 * ordena a los empleados por sector y alfabeticamente por apellido
 * de forma ascendente o descendente
 * @param list lista de empleados
 * @param len tamaño de la lista
 * @param order criterio de ordenamiento ascendete o descendente
 * @return 0 si se ordenó, -1 si no
 */
int OrdenarTrabajos(Empleado *list, int len, int *orden);

/**
 * @fn int printEmployees(Employee*, int)
 * @brief
 * Imprime los datos de los empleados ingresados hasta el momento, sin incluir a los ya eliminados
 * @param list lista de empleados
 * @param len tamaño de la lista
 * @return 0 si hay empleados que mostrar, -1 si no
 */
int ImprimirEmpleados(Empleado *list, int length);


/**
 * @fn void calcularMayoresAPromedio(Empleado*, int, float)
 * @brief recibe el promedio de los salaios de lso empleados y compara el salario de
 * cada uno con este numero, muestra el nombre de los empleados cuyos salarios superan
 * el promedio
 * recibe la lista de empleados
 * @param lista lista de empleados
 * @param tam tamaño de la lista
 * @param promedio promedio de los sueldos
 */
void calcularMayoresAPromedio(Empleado *lista, int tam, float promedio);

/**
 * @fn float MostrarTotalYPromedioDeSalarios(Empleado[], int)
 * @brief
 * recibe la lista de empelados, suma sus salarios y muestra el promedio entre estos
 * @param list lista de empleados
 * @param len tamaño de la lista
 * @return devuelve el promedio
 */
float MostrarTotalYPromedioDeSalarios(Empleado list[], int len);


#endif /* ARRAYEMPLOYEES_H_ */
