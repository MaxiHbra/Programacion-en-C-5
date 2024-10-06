/*Ejercicio 5: Se tiene una lista de N ciudades de la argentina que se desea ingresar, a continuación, se
solicita ordenar alfabéticamente la lista. A través de un menú, realizar las siguientes operaciones:
a) Mostrar cuántos nombres de ciudades están formadas con una misma vocal, como en el caso
de la ciudad “Salta”;
b) Dada una ciudad, determinar la posición en la que se encuentra dentro de la lista
c) Mostrar toda la lista. */
#include <stdio.h>
#include <string.h>
#define max 20

typedef char tcadena[max];
typedef tcadena tvector[max];

int menu(void);
void ingreso(tvector, int*);
void ordenar(tvector,int);
void analizar_vocales(tvector,int);
void posicion(tvector,int);
int busqueda(tvector, int, tcadena);
void mostrar(tvector, int);
void leecad(tcadena,int);

int main() {
	int opc,n;
	tvector ciudades;
	ingreso(ciudades, &n);
	ordenar(ciudades,n);
	do{
		opc=menu();
		switch(opc){
		case 0 : printf("\nSaliste del programa.");break;
		case 1 : 
			analizar_vocales(ciudades,n);
			break;
		case 2 : 
			posicion(ciudades,n);
			break;
		case 3 : 
			mostrar(ciudades,n);
			break;
		}
	}while(opc!=0);
	return 0;
}
int menu(void){
	int opc;
	printf("\n-----------------------------------\n");
	printf("\nIngresar 0 para salir del programa.");
	printf("\nIngresar 1 para mostrar cuantos nombres estan formado con una misma vocal.");
	printf("\nIngresar 2 para ubicar una ciudad en la lista.");
	printf("\nIngresar 3 para mostrar la lista.");
	printf("\n-----------------------------------\n");
	scanf("%d",&opc);
	return opc;
}
void ingreso(tvector ciudades, int *n){
	int i;
	printf("\nPor favor ingresar el valor de N: ");
	scanf("%d",n);
	for(i=1;i<=*n;i++){
		printf("\nPor favor ingresar nombre de ciudad: ");
		fflush(stdin);
		leecad(ciudades[i],max);
	}
}
void ordenar(tvector ciudades,int n){
	int i,j,maymen;
	tcadena aux;
	for(i=1;i<=n-1;i++)
		for(j=i+1;j<=n;j++){
			maymen=strcmp(ciudades[i],ciudades[j]);
			if(maymen>0){
				strcpy(aux,ciudades[j]);
				strcpy(ciudades[j],ciudades[i]);
				strcpy(ciudades[i],aux);
			}
		}
}
void leecad(tcadena cadena,int cant){ 
	char c;
	int i=0;
	c=getchar();
	while(c!=EOF && c!='\n' && i<=cant){
		cadena[i]=c;
		i++;
		c=getchar();
	}
	cadena[i]='\0';
	while(c!=EOF && c!='\n') c=getchar();
}
void mostrar(tvector ciudades, int n){
	int i;
	for(i=1;i<=n;i++) printf("\nLa ciudad N° %d de la lista es: %s",i,ciudades[i]);
}
void analizar_vocales(tvector ciudades,int n){
	int cont=0,i,j,b;
	char vocal='\0';
	tcadena aux;
	for(i=1;i<=n;i++){
		strcpy(aux,ciudades[i]);
		j=0;
		b=0;
		while(aux[j]!='\0' && b==0){
			if(aux[j]=='a' || aux[j]=='e' || aux[j]=='i' || aux[j]=='o' || aux[j]=='u'){
				if(vocal=='\0')vocal=aux[j];
				else if(vocal!=aux[j]) b=1;
				else cont++;
			}
			j++;
		}
	}
	printf("\nLa cantidad de nombres de ciudades formadas por una misma vocal es: %d",cont);
}
int busqueda(tvector ciudades, int n, tcadena buscado){
	int i=1,b=0,aux;
	while(i<=n && b==0){
		aux=strcmp(ciudades[i],buscado);
		if(aux==0)
			b=i;
		i++;
	}
	return b;
}
void posicion(tvector ciudades,int n){
	tcadena aux;
	int busq;
	printf("\nPor favor ingresar la ciudad a buscar en la lista: ");
	fflush(stdin);
	leecad(aux,max);
	busq=busqueda(ciudades,n,aux);
	if( busq != 0) printf("\n%s se encuentra en la lista en la posicion %d",aux,busq);
	else printf("\n%s no se encuentra en la lista.",aux);
	
}
