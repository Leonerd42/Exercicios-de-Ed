// Exercicio 12 - Pilhas dinamicas
// Estrutura de dados 1
// Leonardo Oliveira

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

/*******************************************************************
						DEFINIÇÃO DA PILHA
*******************************************************************/
typedef struct reg *no; 
struct reg {
	int info; 
	struct reg *prox; 
};

typedef struct pilha def_pilha; 
struct pilha {
	int quant; 
	no lista; 
};

/*******************************************************************
						MANIPULAÇÃO DA LISTA
*******************************************************************/
void cria_lista(no *lista){
	*lista = NULL; 	
}

void inclui_inicio (no *lista, int info){			//Inclui no inicio da lista circular
	no p = (no) malloc (sizeof(struct reg));
	p->info = info; 
	if(!*lista){
		p->prox = p;
		*lista = p; 
	}else{
		no q = *lista; 
		while(q->prox != *lista)
			q = q->prox; 
		q->prox = p; 
		p->prox = *lista; 
		*lista = p; 
	}
}

int remove_inicio(no *lista, int *info){		//Remove do inicio da lista circular 
	if(!*lista)
		return 0; 
	if((*lista)->prox == *lista){
		(*info) = (*lista)->info;
		free(*lista); 
		(*lista) = NULL; 
	}else{
		no q = *lista; 
		while(q->prox != *lista)
			q = q->prox; 
		no p = *lista; 
		*lista = p->prox; 
		q->prox = *lista; 
		(*info) = p->info;
		free(p); 
	}
	return 1; 	
}

int mostra(no lista){
	
	if(lista == NULL){
		printf("  Pilha vazia!"); 
		return 1; 
	}
	no p = lista; 
	do{
		printf(" %d ",p->info);
		p = p->prox;
	}while(p != lista);	
}

/*******************************************************************
						MANIPULAÇÃO DA PILHA
*******************************************************************/

int inicia_pilha(def_pilha *p){
	(*p).quant = 0; 
	cria_lista (&((*p).lista));	
	return 1; 
}

int vazia(def_pilha p){
	if(p.quant == 0)
		return 1; 
	return 0; 
}

int empilha(def_pilha *p, int info){
	
	(*p).quant++; 
	inclui_inicio(&(*p).lista,info); 
	return 1; 	
}

int desempilhar(def_pilha *p, int *info){
	if(!vazia(*p)){
		remove_inicio(&((*p).lista),&(*info));
		(*p).quant--; 
		return 1; 
	}else return 0; 
}
int main(){
	
	setlocale(LC_ALL,"Portuguese");
	def_pilha pilha; 
	int x; 
	char e; 
	
	inicia_pilha(&pilha);
	
	do{
		printf("Digite um elemento (-1 pra sair): ");
		scanf("%d",&x);
		if(x != -1){
			empilha(&pilha,x); 			
		}
	}while(x != -1);
	
	printf("\nMostrando a pilha: "); 
	mostra(pilha.lista); 
	
	printf("\n");
	
	do{
		fflush(stdin);
		printf("\nDeseja desempilhar? (S/N): "); 
		e = getchar(); 
		e = toupper(e);
		if(e == 'S'){
			if(desempilhar(&pilha,&x)){
				printf("\tElemento desempilhado: %d\n",x); 
				printf("\nPilha atualmente: "); 
				mostra(pilha.lista); 
			}else printf("\nNão é possível desempilhar!"); 
		} 
	}while(e == 'S'); 
	
	printf("\n\nPilha final: "); 
	mostra(pilha.lista); 
	printf("\n"); 
	system("pause");
}

