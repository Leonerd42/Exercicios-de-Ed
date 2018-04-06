// Exercicios - Estrutura de Dados I 
// Exercicio 8

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

typedef struct reg *no;
struct reg{
	int info; 
	struct reg *prox; 
};

void inserir_lista(no *lista, int n){
	
	no p = (no) malloc (sizeof(struct reg));
	p->info = n; 
	p->prox = *lista; 
	*lista = p; 
}

//EXERCICIO 8 
void trocando_x_y(no *lista, int x, int y){
	
	no p = *lista; 
	while(p){
		if(p->info == x){
			p->info = y; 
		}
		p = p->prox; 
	}
}

void mostra(no lista){
	
	while(lista){
		printf("   %d   ",lista->info);
		lista = lista->prox;
	}
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	no lista, aux2; 
	lista = NULL; 
	int n, aux, x, y; 
	
	//CRIANDO UMA LISTA E INSERINDO NO COMEÇO 
	printf("\nDigite a quantidade de elementos da lista: "); 
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Digite um numero: "); 
		scanf("%d",&aux); 
		inserir_lista(&lista, aux);
	}
	
	//PRINTANDO A LISTA 
	mostra(lista);
	aux2 = lista; 
	
	//TROCANDO OS NUMEROS 
	printf("\nDigite um numero para ser substituido: ");
	scanf("%d",&x);
	printf("\nDigite um numero que substituirá: ");
	scanf("%d",&y);
	
	printf("\n\nTrocando os dados, se houver: "); 
	trocando_x_y(&lista,x,y);
	printf("\nLista: "); 
	mostra(lista);
	
	
}

