/*Ejercicio 8: Se tienen la siguiente estructura para un inmueble: N° Catastro, Nombre del Propietario,
Calle y N°, Tipo (Terreno, Construcción, Edificado), Metros cuadrados de construcción, Cantidad de
baños, Cantidad de habitaciones.
Se solicita cargar 3 inmuebles y a través de un menú realizar las siguientes operaciones:
a) Mostrar los datos del inmueble con el mayor valor de metros cuadrados de construcción.
b) Ingresar un N° de Catastro y permitir modificar la información del registro.
c) Dado el Nombre del Propietario mostrar todos los inmuebles declarados. */
#include <stdio.h>
#include <string.h>
#define max 20
typedef char tcad[max];
typedef struct{
	int catastro,calle,num,metros,cBanios,cHabit;
	tcad nombre,tipo;
}inmueble;
inmueble ingreso();
void mostrar(inmueble);
void leecad(tcad,int);
void mostrarMetros(inmueble,inmueble,inmueble);
void modificar(inmueble*,inmueble*,inmueble*);
void mostrarProp(inmueble,inmueble,inmueble);
void modificarR(inmueble*);
int menu();
int main() {
	int opc;
	inmueble a,b,c;
	a=ingreso();
	c=ingreso();
	b=ingreso();
	do{
		opc=menu();
		switch(opc){
		case 0 : printf("\nSaliste del programa."); break;
		case 1 : mostrarMetros(a,b,c);break;
		case 2 : modificar(&a,&b,&c);break;
		case 3 : mostrarProp(a,b,c);break;
		}
	}while(opc!=0);
	return 0;
}
inmueble ingreso(){
	inmueble aux;
	printf("\nIngresar numero de catastro: ");
	scanf("%d",&aux.catastro);
	printf("\nIngresar nombre de propietario: ");
	fflush(stdin);
	leecad(aux.nombre,max);
	printf("\nIngresar calle: ");
	scanf("%d",&aux.calle);
	printf("\nIngresar numero: ");
	scanf("%d",&aux.num);
	printf("\nIngresar tipo: ");
	fflush(stdin);
	leecad(aux.tipo,max);
	printf("\nIngresar metros cuadrados de la construccion: ");
	scanf("%d",&aux.metros);
	printf("\nIngresar cantidad de baños: ");
	scanf("%d",&aux.cBanios);
	printf("\nIngresar cantidad de habitaciones: ");
	scanf("%d",&aux.cHabit);
	return aux;
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
int menu(){
	int opc;
	printf("\nIngresar 0 para salir");
	printf("\nIngresar 1 para mostrar datos del inmueble con mayor numero de metros cuadrados.");
	printf("\nIngresar 2 para modificar informacion del registro.");
	printf("\nIngresar 3 para buscar inmuebles de un propietario.");
	scanf("%d",&opc);
	return opc;
}
void mostrar(inmueble alu){
	printf("\nNumero de catastro: %d Nombre de propietario: %s Calle: %d Numero: %d Tipo: %s Metros cuadrados: %d Cantidad de baños: %d Cantidad de habitaciones: %d",alu.catastro,alu.nombre,alu.calle,alu.num,alu.tipo,alu.metros,alu.cBanios,alu.cHabit);
}
void mostrarMetros(inmueble a,inmueble b,inmueble c){
	if(a.metros > b.metros && a.metros>c.metros) mostrar(a);
	else if(b.metros>a.metros && b.metros>c.metros) mostrar(b);
	else mostrar(c);
}
void modificar(inmueble *a,inmueble *b,inmueble *c){
	int aux;
	printf("\nIngresar numero de catastro a modificar ");
	scanf("%d",&aux);
	if(a->catastro==aux)
		modificarR(a);
	else if(b->catastro==aux) modificarR(b);
	else if(c->catastro==aux) modificarR(c);
	else printf("\nNo se encuentra el catastro.");
}
void modificarR(inmueble *aux){
	printf("\nIngresar nombre de propietario: ");
	fflush(stdin);
	leecad(aux->nombre,max);
	printf("\nIngresar calle: ");
	scanf("%d",&aux->calle);
	printf("\nIngresar numero: ");
	scanf("%d",&aux->num);
	printf("\nIngresar tipo: ");
	fflush(stdin);
	leecad(aux->tipo,max);
	printf("\nIngresar metros cuadrados de la construccion: ");
	scanf("%d",&aux->metros);
	printf("\nIngresar cantidad de baños: ");
	scanf("%d",&aux->cBanios);
	printf("\nIngresar cantidad de habitaciones: ");
	scanf("%d",&aux->cHabit);
}
void mostrarProp(inmueble a,inmueble b,inmueble c){
	tcad nuevonom;
	int aux;
	printf("\nIngresar nombre del propietario a buscar: ");
	fflush(stdin);
	leecad(nuevonom,max);
	aux=strcmp(nuevonom,a.nombre);
	if(aux==0) mostrar(a);
	aux=strcmp(nuevonom,b.nombre);
	if(aux==0) mostrar(b);
	aux=strcmp(nuevonom,c.nombre);
	if(aux==0) mostrar(c);
}
