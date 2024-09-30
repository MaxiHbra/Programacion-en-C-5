/*Ejercicio 3: Se necesitan cargar los datos de un alumno, con el siguiente orden: DNI, Apellido, Nombre
y Fecha de Nacimiento (aaaammdd). Posteriormente mostrar los datos del alumno ingresado. */
#include <stdio.h>
#define max 20

typedef char Tcad [max];

void ingreso(long*,Tcad,Tcad,long*);
void mostrar(long,Tcad,Tcad,long);
void leecad(Tcad,int);

int main() {
	Tcad apellido,nombre;
	long dni,fecha;
	ingreso(&dni,apellido,nombre,&fecha);
	mostrar(dni,apellido,nombre,fecha);
	return 0;
}
void ingreso(long *DNI, Tcad apellido, Tcad nombre, long *Fecha){
	printf("\nDNI: ");scanf("%ld",DNI);
	fflush(stdin);
	printf("\nApellido: ");
	leecad(apellido,max);
	fflush(stdin);
	printf("\nNombre: ");
	leecad(nombre,max);
	printf("\nFecha de nacimiento: (AAAAMMDD): ");scanf("%ld",Fecha);
}
void mostrar(long DNI,Tcad apellido,Tcad nombre,long Fecha){
	printf("\nDNI= %ld \t Apellido= %s \t Nombre= %s \t Fecha de nacimiento= %ld",DNI,apellido,nombre,Fecha);
}
void leecad(Tcad cadena,int tam){
	int j, m;
	j=0;
	while(j<tam-1 && (m=getchar())!=EOF && m!='\n'){
	cadena[j]=m;
	j++;}
	cadena[j]='\0';
	if(m != EOF && m != '\n') /*limpia el buffer*/
	while((m=getchar())!=EOF && m!='\n');
	}
