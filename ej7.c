/*Ejercicio 7: Se tienen las siguientes estructuras de datos:
Dato Alumno, tiene la siguiente información: “Apellidos, Nombres, DNI, Fecha Nacimiento, Domicilio”
Dato Domicilio, tiene la siguiente información: “Ciudad, Barrio, calle, Número, Departamento”
Dato Fecha, tiene la siguiente información: “Año, mes, día”.
Se solicita:
a) Declarar el Tipo dato Registro para cada estructura planteada y definir una variable para cada tipo de
registro.
b) Utilizando las declaraciones de registros del inciso anterior, implementar los módulos para ingresar
los datos asociados con esas estructuras y los módulos para mostrar la información guardada en los
registros cargados.
c) Ingresar los datos de dos alumnos utilizando los identificadores Alu1 y Alu2 y luego mostrarlos en
orden alfabéticos según sus Apellidos */
#include <stdio.h>
#define max 20
typedef char tcad[max];
typedef struct{
	int dia,mes,anio;
}fecha;
typedef struct{
	tcad ciudad,barrio,calle;
	int numero,departamento;
}domicilio;
typedef struct{
	tcad nombre;
	long dni;
	fecha fech;
	domicilio dom;
}alumno;

alumno ingresar();
void leecad(tcad,int);
void mostrar(alumno);
int main() {
	alumno Alu1,Alu2;
	Alu1=ingresar();
	Alu2=ingresar();
	mostrar(Alu1);mostrar(Alu2);
	return 0;
}
alumno ingresar(){
	alumno alu;
	printf("\nIngresar nombre y apellido del alumno: ");
	fflush(stdin);
	leecad(alu.nombre,max);
	printf("\nIngresa DNI del alumno: ");
	scanf("%ld",&alu.dni);
	printf("\nIngresa fecha de nacimiento DDMAAAA: ");
	scanf("%d,%d,%d",&alu.fech.dia, &alu.fech.mes, &alu.fech.anio);
	printf("\n Ciudad: ");
	fflush(stdin);
	leecad(alu.dom.ciudad,max);
	printf("\n Barrio: ");
	fflush(stdin);
	leecad(alu.dom.barrio,max);
	printf("\n Calle: ");
	fflush(stdin);
	leecad(alu.dom.calle,max);
	printf("\n Numero: ");
	scanf("%d",&alu.dom.numero);
	printf("\n Departamento: ");
	scanf("%d",&alu.dom.departamento);
	return alu;
}
void leecad(tcad cad,int tam){
	char c;
	int i=0;
	c=getchar();
	while(i<=tam && c!=EOF && c!='\n'){
		cad[i]=c;
		i++;
		c=getchar();
	}
	cad[i]='\0';
	while(c!=EOF && c!='\n') c=getchar();
	}
void mostrar(alumno alu){
	printf("\n Nombre: %s \n DNI: %ld \n Fecha de nacimiento: %d/%d/%d \n Domicilio: Ciudad :%s, Barrio: %s, Calle: %s, Numero: %d, Dpto: %d",alu.nombre,alu.dni,alu.fech.dia,alu.fech.mes,alu.fech.anio,alu.dom.ciudad,alu.dom.barrio,alu.dom.calle,alu.dom.numero,alu.dom.departamento);
}
