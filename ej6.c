/*Ejercicio 6: Se tiene una Agenda con datos de N clientes, de cada cliente se guarda la siguiente
información: Apellido, Nombre, Ciudad de nacimiento, Edad. Se desea ingresar la lista de clientes y que
la misma se ordene según su Apellido y Nombre, a medida que se ingresan los clientes. A continuación,
el programa presentará un menú que permita:
d) Dada una edad ingresada por teclado, mostrar todos los clientes que tengan la misma edad.
e) Dada una ciudad, eliminar todos los clientes con igual ciudad de nacimiento.
f) Agregar un nuevo cliente, manteniendo el orden
g) Dado el Apellido y nombre de un cliente, mostrar sus demás datos
h) Mostrar la lista de clientes.
Nota: Para representar la lista de clientes usar vectores relacionados. */
#include <stdio.h>
#include <string.h>
#define max 30

typedef char tcadena[max];
typedef tcadena nombre[max];
typedef tcadena ciudad[max];
typedef int tedad[max];

int menu();
void ingreso(nombre,ciudad,tedad,int*);
void ordenar(nombre,ciudad,tedad,int);
void mostrar(tcadena,tcadena,int);
void leecad(tcadena,int);
void mostraredad(nombre,ciudad,tedad,int);
void eliminarCiudad(nombre,ciudad,tedad,int*);
void mostrarEsp(nombre,ciudad,tedad,int);
void agregaOrd(nombre,ciudad,tedad,int*);
int main() {
	nombre nom;
	int i;
	ciudad cn;
	tedad edad;
	int n,opc;
	ingreso(nom,cn,edad,&n);
	ordenar(nom,cn,edad,n);
	do{
		opc=menu();
		switch(opc){
			case 0 : printf("\nSaliste del programa. "); break;
			case 1 : mostraredad(nom,cn,edad,n); break;
			case 2 : eliminarCiudad(nom,cn,edad,&n); break;
			case 3 : agregaOrd(nom,cn,edad,&n); break;
			case 4 : mostrarEsp(nom,cn,edad,n); break;
			case 5 : 
			for(i=1;i<=n;i++) mostrar(nom[i],cn[i],edad[i]);
			break;
		}
	}while(opc!=0);
	return 0;
}
int menu(){
	int opc;
	printf("\nPresione 0 para salir del programa.");
	printf("\nPresione 1 para mostrar clientes de una edad en especifico.");
	printf("\nPresione 2 para eliminar todos los clientes de una ciudad determinada.");
	printf("\nPresione 3 para agregar un nuevo cliente manteniendo el orden.");
	printf("\nPresione 4 para mostrar datos de un cliente en especifico.");
	printf("\nPresione 5 para mostrar la lista. ");
	scanf("%d",&opc);
	return opc;
}
void ingreso(nombre nom,ciudad cn,tedad edad,int *n){
	int i;
	printf("\nPor favor ingresar valor de N: ");
	scanf("%d",n);
	for(i=1;i<=*n;i++){
		printf("\n---NUEVO CLIENTE---\n");
		printf("\nIngrese nombre y apellido del cliente: ");
		fflush(stdin);
		leecad(nom[i],max);
		printf("\nIngrese ciudad de nacimiento de %s: ",nom[i]);
		fflush(stdin);
		leecad(cn[i],max);
		printf("\nIngrese la edad de %s: ",nom[i]);
		scanf("%d",&edad[i]);
		printf("\n---CLIENTE INGRESADO---\n");
	}
}
void leecad(tcadena cad,int tam){
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
void ordenar(nombre nom,ciudad cn,tedad edad,int n){
	int i,j,result,auxE;
	tcadena auxN;
	for(i=1;i<=n-1;i++)
		for(j=i+1;j<=n;j++){
			result=strcmp(nom[i],nom[j]);
			if(result>0){
				strcpy(auxN,nom[j]);
				strcpy(nom[j],nom[i]);
				strcpy(nom[i],auxN);
				strcpy(auxN,cn[j]);
				strcpy(cn[j],cn[i]);
				strcpy(cn[i],auxN);
				auxE=edad[j];
				edad[j]=edad[i];
				edad[i]=auxE;
			}
		}
}
void mostraredad(nombre nom,ciudad cn,tedad edad,int n){
	int i,ed;
	printf("\nPor favor ingresar la edad: ");
	scanf("%d",&ed);
	for(i=1;i<=n;i++){
		if(edad[i]==ed){ 
			mostrar(nom[i],cn[i],edad[i]);}
	}
}
void mostrar(tcadena nom,tcadena cn,int edad){
	printf("\nCliente:\t Nombre: %s \t Ciudad de nacimiento: %s \t Edad: %d",nom,cn,edad);
}
void eliminarCiudad(nombre nom,ciudad cn,tedad edad,int *n){
	tcadena c;
	int aux,i=1,pos;
	printf("\nIngresar la ciudad: ");
	fflush(stdin);
	leecad(c,max);
	while(i<=*n){
		aux=strcmp(c,cn[i]);
		if(aux==0){
			for(pos=i;pos<=*n-1;pos++){
				strcpy(nom[pos],nom[pos+1]);
				strcpy(cn[pos],cn[pos+1]);
				edad[pos]=edad[pos+1];
			}
			*n=*n-1;
		}
		else i++;
	}
}
void mostrarEsp(nombre nom,ciudad cn,tedad edad,int n){
	tcadena c;
	int i=1,aux,b=0;
	printf("\nIngresar nombre completo del cliente a buscar: ");
	fflush(stdin);
	leecad(c,max);
	while(i<=n && b==0){
	aux=strcmp(c,nom[i]);
	if(aux==0)b=1;
	i++;
	}
	if(b==1) mostrar(nom[i-1],cn[i-1],edad[i-1]);
	else printf("\nNo se encontro el cliente. ");
}
void agregaOrd(nombre nom,ciudad cn,tedad edad,int *n){
	tcadena nomb, ciu;
	int eda,aux,i=0,pos;
	printf("\nIngrese nombre y apellido del cliente: ");
	fflush(stdin);
	leecad(nomb,max);
	printf("\nIngrese ciudad de nacimiento de %s: ",nomb);
	fflush(stdin);
	leecad(ciu,max);
	printf("\nIngrese la edad de %s: ",nomb);
	scanf("%d",&eda);
	aux=strcmp(nom[1],nomb);
	while(i<=*n && aux<0){ 
	i++;
	aux=strcmp(nom[i],nomb);
	}
	*n=*n+1;
	if(i<=(*n)-1){
		for(pos=*n-1;pos>=i;pos--){
			strcpy(nom[pos+1],nom[pos]);
			strcpy(cn[pos+1],cn[pos]);
			edad[pos+1]=edad[pos];
		}
		strcpy(nom[i],nomb);
		strcpy(cn[i],ciu);
		edad[i]=eda;
	}
	else{
		strcpy(nom[*n],nomb);
		strcpy(cn[*n],ciu);
		edad[*n]=eda;
	}
}
