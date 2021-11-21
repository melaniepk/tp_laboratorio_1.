#include "Employee.h"
#include "utn1.h"


/**
 * @fn Employee employee_new*()
 * @brief reserva espacio en memoria para un nuevo empleado
 *
 * @return
 */
Employee* employee_new()
{
	Employee* empleado;
	empleado = (Employee*) calloc(sizeof(Employee),1);

	return empleado;
}

/**
 * @fn Employee employee_newParametros*(char*, char*, char*, char*)
 * @brief
 * reserva espacio en memoria para un nuevo empleado y le asigna caracteristicas que recibe a traves de parametros
 * @param idStr id del empleado
 * @param nombreStr nombre del empleado
 * @param horasTrabajadasStr horas de trabajo del empleado
 * @param sueldoStr sueldo del empleado
 * @return
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* empleado;
	empleado = employee_new();

	int id;
	int horasTrabajadas;
	float sueldo;

	id = atoi(idStr);
	horasTrabajadas = atoi(horasTrabajadasStr);
	sueldo = atof(sueldoStr);

	if(empleado!= NULL)
	{
		employee_setId(empleado,id);
		employee_setNombre(empleado,nombreStr);
		employee_setHorasTrabajadas(empleado,horasTrabajadas);
		employee_setSueldo(empleado,sueldo);
	}
	return empleado;
}

/**
 * @fn void employee_delete(Employee*)
 * @brief
 * libera el espacio en memoria ocupado por un empleado
 * @param this
 */
void employee_delete(Employee* this)
{

	if(this!= NULL)
	{
		free(this);
	}
}

/*FUNCIONES SET*/

/**
 * @fn int employee_setId(Employee*, int)
 * @brief
 *  setea el id recibido en el empleado
 * @param this empleado
 * @param id id recibido
 * @return
 */
int employee_setId(Employee* this,int id)
{
	int retorno =-1;
	if(this!= NULL && id>=0)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}
/**
 * @fn int employee_setNombre(Employee*, char*)
 * @brief
 * setea el nombre recibido en el empleado
 * @param this empleado
 * @param nombre nombre recibido
 * @return
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this!= NULL && nombre != NULL)
	{
		strncpy(this->nombre, nombre, sizeof(this->nombre));
	}
	return retorno;
}

/**
 * @fn int employee_setHorasTrabajadas(Employee*, int)
 * @brief
 * setea las hora de trabajon de un empleado
 * @param this empleado
 * @param horasTrabajadas horas de trabajo
 * @return
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno =-1;
	if(this!= NULL && horasTrabajadas >= 0)
	{
		this->horasTrabajadas = horasTrabajadas;
	}
	return retorno;
}
/**
 * @fn int employee_setSueldo(Employee*, int)
 * @brief
 * setea el sueldo a un empleado
 * @param this empleado
 * @param sueldo sueldo
 * @return
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this!= NULL && sueldo >= 0)
	{
		this->sueldo = sueldo;
	}
	return retorno;
}

/* FUNCIONES GET*/

/**
 * @fn int employee_getId(Employee*, int*)
 * @brief
 * consigue el id de determinado empleado
 * @param this empleado
 * @param id id a buscar
 * @return
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this!= NULL && id!= NULL)
	{
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

/**
 * @fn int employee_getNombre(Employee*, char*)
 * @brief
 * consigue el nombre de determinado empleado
 * @param this empleado
 * @param nombre nombre a buscar
 * @return
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(nombre, this->nombre);
	}
		return retorno;
}
/**
 * @fn int employee_getHorasTrabajadas(Employee*, int*)
 * @brief consigue las horas de trabajo de un empleado
 *
 * @param this empleado
 * @param horasTrabajadas horas
 * @return
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno =-1;
	if(this!= NULL&& horasTrabajadas!= NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;


}
/**
 * @fn int employee_getSueldo(Employee*, int*)
 * @brief
 * consigue el sueldo de un empleado
 * @param this empleado
 * @param sueldo sueldo
 * @return
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno =-1;
	if(this!= NULL && sueldo!= NULL)
	{
		*sueldo = this->sueldo;
		retorno =0;
	}
	return retorno;
}

/**
 * @fn int employee_CompareById(void*, void*)
 * @brief
 * compara a los empleados por id
 * @param empleado1
 * @param empleado2
 * @return
 */
int employee_CompareById(void* empleado1, void* empleado2)
{
	int retorno;
	Employee* unEmpleado;
	Employee* otroEmpleado;

	if(empleado1 != NULL && empleado2!= NULL)
	{
		unEmpleado = (Employee*) empleado1;
		otroEmpleado = (Employee*) empleado2;

		if(unEmpleado->id > otroEmpleado->id)
		{
			retorno = -1;
		}
		else
		{
			if(unEmpleado->id < otroEmpleado->id)
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}
/**
 * @fn int employee_CompareByNombre(void*, void*)
 * @brief
 * compara a los empleados por nombre
 * @param empleado1
 * @param empleado2
 * @return
 */
int employee_CompareByNombre(void* empleado1, void* empleado2)
{

	   int valor=0;
	   valor=strcmp(((Employee*)empleado1)->nombre,((Employee*)empleado2)->nombre);
	   return valor;

}

/**
 * @fn int employee_CompareByHorasTrabajadas(void*, void*)
 * @brief
 * compara a los empleados por horas de trabajo
 * @param empleado1
 * @param empleado2
 * @return
 */
int employee_CompareByHorasTrabajadas(void* empleado1, void* empleado2)
{
	int retorno;
	Employee* unEmpleado;
	Employee* otroEmpleado;

	if(empleado1 != NULL && empleado2!= NULL)
	{
		unEmpleado = (Employee*) empleado1;
		otroEmpleado = (Employee*) empleado2;

		if(unEmpleado->horasTrabajadas > otroEmpleado->horasTrabajadas)
		{
			retorno = -1;
		}
		else
		{
			if(unEmpleado->horasTrabajadas < otroEmpleado->horasTrabajadas)
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}

/**
 * @fn int employee_CompareBySueldo(void*, void*)
 * @brief
 * compara a los empleados por sueldo
 * @param empleado1
 * @param empleado2
 * @return
 */
int employee_CompareBySueldo(void* empleado1, void* empleado2)
{
	int retorno =-1;
	Employee* unEmpleado;
	Employee* otroEmpleado;


	if(empleado1 != NULL && empleado2!= NULL)
	{
		unEmpleado = (Employee*) empleado1;
		otroEmpleado = (Employee*) empleado2;

		if(unEmpleado->sueldo > otroEmpleado->sueldo)
		{
			retorno = -1;
		}
		else
		{
			if(unEmpleado->sueldo < otroEmpleado->sueldo)
			{
				retorno = 1;
			}
			else
			{
				retorno = 0;
			}
		}
	}

	return retorno;
}


