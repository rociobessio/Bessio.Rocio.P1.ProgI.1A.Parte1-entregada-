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


3. Dada la siguiente estructura generar una función que permita ordenar un array de dicha estructura por tipo.
Ante igualdad de tipo deberá ordenarse por efectividad creciente. Hardcodear datos y mostrarlos desde el main.
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <ctype.h>

#include "utn.h"

#define TAM 5

typedef struct{
	int id;
	char nombre[220];
	char tipo;
	float efectividad;

}eVacuna;
int aplicarAumento(int numero,float* resultado);

void reemplazarCaracteres(char string1[], char caracter1, char caracter2,int* cantidad);

int ordenamientoVacuna(eVacuna array[],int tam);



int main(void) {
	setbuf(stdout,NULL);

	eVacuna auxVacuna[TAM]={
			{1000,"JUAN",'A',90.99},
			{1001,"MARIA",'P',70.03},
			{1002,"ESTELA",'S',02.05},
			{1003,"RENATA",'S',20.30},
			{1004,"PAULA",'S',15.00},
	};


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

	ordenamientoVacuna(auxVacuna, TAM);

	printf("\n____________________________________________________________");
	printf("\n                                                            |");
	printf("\n             LISTA VACUNA                                   |\n");
	printf("____________________________________________________________|\n");

	for(int i= 0;i<TAM;i++)
	{
		printf("%4d %10s  %c   %.2f\n",auxVacuna[i].id,
									auxVacuna[i].nombre,
									auxVacuna[i].tipo,
									auxVacuna[i].efectividad);
	}

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

int ordenamientoVacuna(eVacuna array[],int tam)
{
	int todoOk = -1;

	eVacuna aux;

	if(array!=NULL && tam>0)
	{
		for(int i=0;i<tam;i++)
		{
			for(int j=i;j<tam;j++)
			{
				if((array[i].tipo>array[j].tipo) || (array[i].tipo==array[j].tipo && array[i].efectividad>array[j].efectividad) )
				{
					aux = array[i];
					array[i] = array[j];
					array[j] = aux;
				}
			}
		}
	}


	return todoOk;
}
