/*Ejercicio 12: Se desea crear un programa que permita realizar operaciones con dos conjuntos de letras.
El programa deberá inicializar ambos conjuntos como conjuntos vacíos y posteriormente presentar un
menú que permita:
a) Agregar un elemento a uno de los conjuntos, ingresando para ello el nombre del conjunto
b) Mostrar uno de los dos conjuntos
c) Mostrar el conjunto resultante de la unión de los dos conjuntos
d) Mostrar el conjunto resultante de la intersección de los dos conjuntos
e) Mostrar el conjunto resultante de la diferencia del primer conjunto con el segundo conjunto
f) Mostrar el conjunto resultante de la diferencia del primer conjunto con el segundo conjunto
Nota: La representación de cada conjunto se realizará mediante un registro con tres campos, donde un
campo será el nombre del conjunto, otro campo será el arreglo de los caracteres conteniendo los
elementos del conjunto y el tercer campo será el tamaño del arreglo. */
#include <stdio.h>
#include <string.h>
#define max 50

typedef char tcad[max];

typedef struct{
	tcad X;
	int tam;
	char nom;
}tconj;

int menu(void);
tconj inicializar(void);
void agregar(tconj*);
void mostrar(tconj);
void unionConj(tconj,tconj);
void interConj(tconj,tconj);
void diferenciaConj(tconj,tconj);
int buscar(tcad,int,char);

int main() {
	tconj A,B;
	int opc;
	char conjVerif;
	A=inicializar();
	B=inicializar();
	do{
		opc=menu();
		switch(opc){
			
		case 0 : printf("\nUsted salio del programa.\n");break;
		
		case 1 : 
			fflush(stdin);
			printf("\nConjunto: ");scanf("%c",&conjVerif);
			if(conjVerif==A.nom)agregar(&A);
			else if(conjVerif==B.nom)agregar(&B);
				else printf("\nNo existe tal conjunto.\n");
		break;
		
		case 2 : 
			fflush(stdin);
			printf("\nConjunto: ");scanf("%c",&conjVerif);
			if(conjVerif==A.nom)mostrar(A);
			else if(conjVerif==B.nom)mostrar(B);
				else printf("\nNo existe tal conjunto.\n");
		break;
		
		case 3 : unionConj(A,B);break;
		case 4 : interConj(A,B);break;
		case 5 : diferenciaConj(A,B);break;
		case 6 : diferenciaConj(B,A);break;
		}
	}while(opc!=0);
	return 0;
}
int menu(void){
	int opc;
	printf("\nIngresar 0 para salir del programa");
	printf("\nIngresar 1 para agregar un elemento a algun conjunto.");
	printf("\nIngresar 2 para mostrar uno de los dos conjuntos.");
	printf("\nIngresar 3 para mostrar la union de los conjuntos.");
	printf("\nIngresar 4 para mostrar la intersección de los conjuntos.");
	printf("\nIngresar 5 para mostrar el primer conjunto menos el segundo.");
	printf("\nIngresar 1 para mostrar el segundo conjunto menos el primero\n");
	scanf("%d",&opc);
	return opc;
}
tconj inicializar(void){
	tconj P;
	P.tam=0;
	fflush(stdin);
	printf("\nIntroducir un nombre para el conjunto (UNA LETRA): ");
	scanf("%c",&P.nom);
	P.X[0]='\0';
	return P;
}
void agregar(tconj *P){
	if(P->tam < max){
		fflush(stdin);
		printf("\nIngresar el caracter: ");
		scanf("%c",&P->X[P->tam]);
		P->tam=(P->tam)+1;
		P->X[P->tam]='\0';
	}else printf("\nTamaño maximo alcanzado.\n");
}
void mostrar(tconj P){
	printf("\nElementos del conjunto %c  de tamanio %d= {%s} \n",P.nom,P.tam,P.X);
	
}
void unionConj(tconj X1,tconj X2){
	tconj U;
	int i,j;
	U.nom='U';
	U.tam=X1.tam;
	strcpy(U.X,X1.X);
	i=U.tam;
	j=0;
	while(i<=max && X2.X[j]!='\0'){
		if(buscar(U.X,U.tam,X2.X[j])==0){
			U.X[U.tam]=X2.X[j];
			U.tam=(U.tam)+1;
		}
		else printf ("\nIgual");
		i++;
		j++;
	}
	U.X[U.tam]='\0';
	mostrar(U);
}

void interConj(tconj A,tconj B){
	int i;
	tconj I;
	I.tam=0;
	I.nom='I';
	for(i=0;i<=A.tam;i++){
		if(buscar(B.X,B.tam,A.X[i])){
			I.X[I.tam]=A.X[i];
			I.tam=(I.tam)+1;
		}
	}
	I.X[I.tam]='\0';
	mostrar(I);
}
void diferenciaConj(tconj X1,tconj X2){
	tconj dif;
	int i;
	dif.tam=0;
	dif.nom='D';
	for(i=0;i<X1.tam;i++){
		if(buscar(X2.X,X2.tam,X1.X[i])==0){
			dif.X[dif.tam]=X1.X[i];
			dif.tam=(dif.tam)+1;
		}
	}
	dif.X[dif.tam]='\0';
	mostrar(dif);
}
int buscar(tcad x,int tam,char buscado){
	int i=0;
	while(i<=tam && x[i]!=buscado){
		i++;
	}
	if(i<=tam) return 1;
	else return 0;
}
