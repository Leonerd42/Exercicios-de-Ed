//	Exercicio 11 
//  Lista ED1
//Leonardo Oliveira

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

#define max 20

typedef struct{
	int topo; 
	float value[max];
} defpilha;

void inicia_pilha(defpilha *p){
	(*p).topo = -1; 
}

int vazia(int topo){
	if(topo == -1)
		return 1; 
	return 0; 
}

int cheia(int topo){
	if(topo == max-1)
		return 1; 
	return 0;
}

int empilha (defpilha *p, int *topo, float x){
	if(cheia(*topo))
		return 0;
	(*topo)++; 
	(*p).value[*topo] = x; 
	return 1; 
}

int desempilha (defpilha *p, int *topo, float *x){
	if(vazia(*topo))
		return 0; 
	(*x) = (*p).value[*topo];
	(*topo)--; 
	return 1; 
}

void ver_pilha(defpilha p, int topo){
	
	while(topo >= 0){
		printf("-> %.2f", p.value[topo]);
		topo--; 
	}
}

int empilhar_pilha(defpilha *p1, defpilha *p2){
	defpilha aux; 
	aux.topo = -1; 
	float aux2; 
	
	if(cheia((*p1).topo))
		return 0; 
	
	while(!vazia((*p2).topo)){
		desempilha (&(*p2),&(*p2).topo,&aux2);
		empilha(&aux,&aux.topo,aux2); 
	}	
	
	//Pilha dois desempilhadada
	
	while(!vazia(aux.topo)){
		desempilha(&aux,&aux.topo,&aux2); 
		if(!empilha(&(*p1),&(*p1).topo,aux2))
			return 0;
	}
	
	//Pilha dois passada para pilha 1
	
	return 1; 
	
}
int main(){

	setlocale(LC_ALL,"Portuguese");
	defpilha p1, p2; 
	float aux = 0; 	
	
	//Inicia a primeira lista
	inicia_pilha(&p1); 
	//Inicia a segunda lista
	inicia_pilha(&p2); 
	
	printf("\tPor favor digite os valores da primeira pilha\n\n");
	
	do{
		printf("Digite um elemento da P1 (-1 para sair): "); 
		scanf("%f",&aux); 
		if(aux == -1)	
			break;
		else if(!empilha(&p1,&p1.topo,aux))
				printf("\nPilha cheia! Dado perdido\n\n"); 
	}while(aux != -1); 
	
	printf("\nDigite a pilha 2: \n\n"); 
	do{
		printf("Digite um elemento da P2 (-1 para sair): "); 
		scanf("%f",&aux); 
		if(aux == -1)
			break; 
		else if(!empilha(&p2,&p2.topo,aux))
				printf("\nPilha Cheia! Dado perdido\n\n"); 
	}while(aux != -1); 
	
		
	//Visualizar pilha 1
	printf("\n\tPilha 1: \t");
	ver_pilha(p1,p1.topo); 
	//Visualizar pilha 2
	printf("\n\n\tPilha 2: \t"); 
	ver_pilha(p2,p2.topo); 
	printf("\n\n"); 	
	system("pause"); 
	
	printf("\nPassando a pilha 2 para a pilha 1"); 
	if(empilhar_pilha(&p1,&p2))
		printf("\n\nPilha 2 passada para a pilha 1!\n");
	else printf("\nPilha 1 Cheia, operação não foi completada!!!\nResultado obtido:\n\n"); 
	
	//Visualizar pilha 1
	printf("\n\tPilha 1: \t");
	ver_pilha(p1,p1.topo); 
	//Visualizar pilha 2
	printf("\n\n\tPilha 2: \t"); 
	ver_pilha(p2,p2.topo); 
	printf("\n\nFim do programa!"); 
	printf("\n\n"); 	
	system("pause"); 
}

