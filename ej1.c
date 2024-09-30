/*Ejercicio 1: Se tienen las siguientes cadenas:
A= “Sergio”; B= “Autos usados” y C= “Caseros, en el año 1245”
Se solicita:
a) Representar gráficamente las cadenas A, B y C
b) Escribir un programa que Defina el Tipo dato Cadena y declare e inicialice las variables A, B y C.
Posteriormente, recorra cada variable, mostrando cada uno de sus caracteres. Nota: sólo utilizar la librería stdio */
#include <stdio.h>
#define max 30
int main() {
	int i=0;
	char A[max]="Sergio";
	char B[max]="Autos usados";
	char C[max]="Caseros, en el año 1245";
	while(A[i]!='\0'){ 
	printf(" %c ",A[i]);
	i++;
	}
	printf("\n");
	i=0;
	while(B[i]!='\0'){ 
	printf(" %c ",B[i]);
	i++;
	}
	i=0;
	printf("\n");
	while(C[i]!='\0'){ 
	printf(" %c ",C[i]);
	i++;
	}
	return 0;
}


