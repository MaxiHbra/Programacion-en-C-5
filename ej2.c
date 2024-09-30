/*Ejercicio 2: Crear un programa que permita ingresar y mostrar dos Cadenas en las variables llamadas
Pal y OPal. Utilizar la siguiente declaración para el tipo de dato cadena: typedef char TCad [6];
Resolver:
a) Utilizando las sentencias printf() y scanf()
b) Utilizando las sentencias gets() y puts().
Nota: Para probar el programa usar los siguientes textos: “Casa Blanca” y “hipopótamos”, en ese orden y
viceversa ¿cuáles problemas se pueden observar? */
#include <stdio.h>
typedef char TCad [6];
int main() {
	TCad Pal,Opal;
	/*fflush(stdin);
	printf("\nIngresar Pal: "); scanf("%",&Pal);
	fflush(stdin);
	printf("\nIngresar OPal: "); scanf("%s",&Opal);
	printf("\nPal= %s",Pal);
	printf("\nOPal= %s",Opal);        La funcion con scanf y print corta la cadeba en el espacio en blanco/
	/*gets(Pal);
	gets(Opal);
	puts(Pal);
	puts(Opal);  La funcion con gets presenta un desbordamiento de caracteres si se supera el tamaño, no tiene control*/
	return 0;
}


