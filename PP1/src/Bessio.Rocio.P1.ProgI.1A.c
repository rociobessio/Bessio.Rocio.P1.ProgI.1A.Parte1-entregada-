/*
 ============================================================================
 Name        : 1A.c
 Author      : Rocio Bessio





1. Crear una función llamada aplicarAumento que reciba como parámetro el precio de un producto
y devuelva el valor del producto con un aumento del 5%. Realizar la llamada desde el main.


2. Crear una función que se llame reemplazarCaracteres que reciba una cadena de caracteres como primer parámetro,
un carácter como segundo y otro carácter  como tercero,
 la misma deberá reemplazar cada ocurrencia del segundo parámetro por el tercero y
  devolver la cantidad de veces que se reemplazo ese carácter  en la cadena
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#include "utn.h"

int aplicarAumento(int numero,float* resultado);

void reemplazarCaracteres(char string1[], char caracter1, char caracter2,int* cantidad);

int main(void) {
	setbuf(stdout,NULL);

	int numero = 100;
	float resultadoAumento;

	char string[20] = "TAPA EMPANADA";
	char caracter1 = 'A';
	char caracter2 = 'F';
	int cantidadVeces;

	printf("\n____________________________________________________________");
	printf("\n                                                            |");
	printf("\n               PP1      PROGRAMACION                        |\n");
	printf("____________________________________________________________|\n");

	aplicarAumento(numero,&resultadoAumento);
	printf("\nAUMENTO: %.2f",resultadoAumento);

	printf("\n\n\n");

	reemplazarCaracteres(string,caracter1,caracter2,&cantidadVeces);
	printf("\nCANTIDAD DE VECES QUE SE REEMPLAZO EL CARACTER A: %d ",cantidadVeces);

	return EXIT_SUCCESS;
}

int aplicarAumento(int numero,float* resultado)
{
	int todoOk=0;

	float aumento;
	int numeroInicial;
	int precioConAumento;

	if(numero>0)
	{

		numeroInicial = numero+(numero*5);

		aumento = (float)numeroInicial/100;
		precioConAumento = numero + aumento;

		*resultado = precioConAumento;

		todoOk =1;
	}

	return todoOk;
}

void reemplazarCaracteres(char string1[], char caracter1, char caracter2,int* cantidad)
{

	int contador = 0;
	for(int i=0;i<strlen(string1);i++)
	{
		if(string1[i] == caracter1)
		{
			string1[i] = caracter2;
			contador++;
		}
	}
	*cantidad = contador;
	printf("\nSTRING REEMPLAZADA: %s ",string1);
}
