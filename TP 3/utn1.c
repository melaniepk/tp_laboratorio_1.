/*
 * utn1.c
 *
 *  Created on: 26 mar. 2021
 *      Author: mkale
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn1.h"
#include <string.h>
#include <ctype.h>



int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}


int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL &&
    	myGets(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno=0;
		*pResultado = atoi(bufferString) ;

	}
    return retorno;
}


int esNumerica(char* cadena, int limite)
{
	int retorno = 1; //verdadero
	int i;
	for(i=0;i<limite && cadena[i] != '\0';i++)
	{
		if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}


int utn_getNumero(int* pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do
	{
		printf("%s",mensaje);
		if(	getInt(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}


int getFloat(float* pResultado)
{
	 int retorno=-1;
	 char bufferString[50];
	    if(	pResultado != NULL &&
	    	myGets(bufferString,sizeof(bufferString)) == 0 &&
	    	esNumerica(bufferString,sizeof(bufferString)))
		{
			retorno=0;
			*pResultado = atof(bufferString) ;

		}
	    return retorno;

    return retorno;
}


int esFlotante(char* cadena, int limite)
{
	int retorno = 1;
	int i;
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] == '.')
			{
				continue;
			}
			if(cadena[i] > '9' || cadena[i] < '0')
			{
				retorno = 0;
				break;
			}

		}
	return retorno;
}


int utn_getNumeroFlotante(float* pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos)
{
	int retorno = -1;
		int bufferFloat;
		do
		{
			printf("%s",mensaje);
			if(	getInt(&bufferFloat) == 0 &&
				bufferFloat >= minimo &&
				bufferFloat <= maximo)
			{
				retorno = 0;
				*pResultado = bufferFloat;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	return retorno;
}


int esString(char* cadena, int longitud)
{
	int i;
	int retorno = 0;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0; cadena[i] != '\0' && i < longitud; i++)
		{
			if(cadena[i] != ' ' && cadena[i] != '.' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < '0' || cadena[i] > '9'))
			{
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}


int getString(char* pResultado, int longitud)
{
	int retorno = -1;
	char buffer[4096];

	if(pResultado != NULL)
	{
		if(myGets(buffer, sizeof(buffer)) == 0 && esString(buffer, sizeof(buffer)) == 0 && strnlen(buffer,sizeof(buffer)) < longitud)
		{
			strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
	}
	return retorno;
}


int utn_getString(char* pResultado, int longitud, char mensaje[], char mensajeError[], int reintentos)
{
	char bufferString[4096];
	int retorno = -1;
	while(reintentos >=0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getString(bufferString, sizeof(bufferString))== 0 && strnlen(bufferString, sizeof(bufferString)) < longitud)
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError );
	}
	return retorno;
}


int esPalabra(char* palabra, int longitud)
{
	int i = 0;
	int retorno;
	retorno = -1;

	if(palabra != NULL && longitud > 0)
	{
		for(i=0;i<longitud && palabra[i] != '\0' ;i++)
		{
			if((palabra[i] < 'A' || palabra[i] > 'Z') && (palabra[i] < 'a' || palabra[i] > 'z'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


int getPalabra(char* pResultado,int longitud)
{
	int retorno =-1;
	char buffer[4096];
	if(pResultado != NULL && longitud > 0)
	{
		if(myGets(buffer, sizeof(buffer)) == 0
		   && esPalabra(buffer,sizeof(buffer))
		   && strnlen(buffer,sizeof(buffer)) < longitud)
		{
			strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
	}
	return retorno;
}


int utn_getPalabra(char* pResultado, int longitud, char mensaje[], char mensajeError[], int reintentos)
{
	char bufferPalabra[4096];
	int retorno = -1;

	while(reintentos>=0)
	{
		reintentos--;
		printf("%s", mensaje);
		if(getPalabra(bufferPalabra,sizeof(bufferPalabra)) == 0 && strnlen(bufferPalabra,sizeof(bufferPalabra)) < longitud)
		{
			strncpy(pResultado,bufferPalabra,longitud);
			retorno = 0;
			break;
		}
		printf("%s", mensajeError);
	}
	return retorno;
}




int getString_number(char *message, char *errorMessage, char *value)
{
	int status;
	int i;
	int length;
	status = 0;
	printf("%s", message);
	scanf("%s", value);

	length = strlen(value);

	for (i = 0; i < length; i++)
	{
		while(!isdigit(value[i]))
		{
			printf("%s", errorMessage);
			scanf("%s", value);
		}
	}

	while(atoi(value) < 0)
	{
		printf("%s", errorMessage);
		scanf("%s", value);
	}

	return status;
}
/** \brief Validates that a string has only numbers
 *
 * \param number The string to validate
 * \return 1 in case the string is only numbers and 0 if it's not
 *
 */
static int validatePositiveInteger(char number[]);

/** \brief Validates that a string has only numbers and one '.'
 *
 * \param numberFloat The string to validate
 * \return 1 in case the string is only numbers or number and one '.' and 0 if it's not
 *
 */
static int validatePositiveFloat(char numberFloat[]);

/** \brief Validates that a string has only letters
 *
 * \param string The string to validate
 * \return 1 in case the string is only letters and 0 if it's not
 *
 */
static int isOnlyLetters(char string[]);

/** \brief Validates that a string has only letters and numbers
 *
 * \param string The string to validate
 * \return 1 in case the string is only letters and numbers and 0 if it's not
 *
 */
static int isNumberAndLetters(char string[]);


int getIntNew(char message[],char errorMessage[])
{
    char strNumber[32];
    int number;

    puts(message);
    fflush(stdin);
    fgets(strNumber,sizeof(strNumber),stdin);
    strNumber[strlen(strNumber)-1]='\0';

    while(!validatePositiveInteger(strNumber))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(strNumber,sizeof(strNumber),stdin);
        strNumber[strlen(strNumber)-1]='\0';
    }

    number=atoi(strNumber);

    return number;
}
/*
SIZEOF:La función recibe como único parámetro o el nombre de una variable, o el nombre de un tipo de datos, y devuelve su tamaño en bytes
STRLEN: muestra la cantidad de caracteres
FGETS: La alternativa segura de gets es fgets que si permite establecer el máximo de caracteres que pueden leerse.
ATOI: Permite convertir un literal (o texto entre comillas), que contenga un número entero, en un valor constante que puede asignarse
a cualquier dato.
VARIABLE ESTATICA: es una variable que ha sido ubicada estáticamente y cuyo tiempo de vida se extiende durante toda la ejecución del programa.
*/
float getFloatNew(char message[],char errorMessage[])
{
    char strFloat[32];
    float number;

    puts(message);
    fflush(stdin);
    fgets(strFloat,sizeof(strFloat),stdin);
    strFloat[strlen(strFloat)-1]='\0';

    while(!validatePositiveFloat(strFloat))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(strFloat,sizeof(strFloat),stdin);
        strFloat[strlen(strFloat)-1]='\0';
    }

    number=atof(strFloat);

    return number;
}

static int validatePositiveInteger(char number[])
{
    int returnValue=1;

    for(int i=0;number[i]!='\0';i++)
    {
        if(number[i]<'0'||number[i]>'9')
        {
            returnValue=0;
            break;
        }
    }

    return returnValue;
}

static int validatePositiveFloat(char numberFloat[])
{
    int returnValue=1;
    int pointCounter=0;

    for(int i=0;numberFloat[i]!='\0';i++)
    {
        if(numberFloat[i]<'0'||numberFloat[i]>'9')
        {
            if(numberFloat[i]=='.'&&pointCounter==0)
            {
                pointCounter++;
            }else
            {
                returnValue=0;
                break;
            }
        }
    }

    return returnValue;
}

void getString2(char string[],int len,char message[],char errorMessage[])
{
    puts(message);
    fflush(stdin);
    fgets(string,len,stdin);
    string[strlen(string)-1]='\0';

    while(!isOnlyLetters(string))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(string,len,stdin);
        string[strlen(string)-1]='\0';
    }
}

static int isOnlyLetters(char string[])
{
    int returnValue=1;

    for(int i=0;string[i]!='\0';i++)
    {
        if((string[i]<'a'||string[i]>'z')&&(string[i]<'A'||string[i]>'Z'))
        {
            returnValue=0;
        }
    }

    return returnValue;
}

char getChar(char message[],char errorMessage[])
{
    char aux;

    puts(message);
    fflush(stdin);
    scanf("%c",&aux);

    while((aux<'a'||aux>'z')&&(aux<'A'||aux>'Z'))
    {
        puts(errorMessage);
        fflush(stdin);
        scanf("%c",&aux);
    }

    return aux;
}

char getCharTwoOptions(char message[],char errorMessage[],char option1,char option2)
{
    char aux;

    puts(message);
    fflush(stdin);
    scanf("%c",&aux);
    aux=tolower(aux);//lo paso a toLower para no tener que pasarlo en el main

    while(aux!=option1&&aux!=option2)
    {
        puts(errorMessage);
        fflush(stdin);
        scanf("%c",&aux);
        aux=tolower(aux);
    }

    return aux;
}

static int isNumberAndLetters(char string[])
{
    int returnValue=1;

    for(int i=0;string[i]!='\0';i++)
    {
        if((string[i]<'a'||string[i]>'z')&&(string[i]<'A'||string[i]>'Z')&&(string[i]<'0'||string[i]>'9'))
        {
            returnValue=0;
        }
    }

    return returnValue;
}

void getStringWithNumbers(char string[],int len,char message[],char errorMessage[])
{
    puts(message);
    fflush(stdin);
    fgets(string,len,stdin);
    string[strlen(string)-1]='\0';

    while(!isNumberAndLetters(string))
    {
        puts(errorMessage);
        fflush(stdin);
        fgets(string,len,stdin);
        string[strlen(string)-1]='\0';
    }
}
