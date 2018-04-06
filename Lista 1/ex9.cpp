// EXERCICIOS ED1 
// Exercício 9 

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

void inserir_lista(no *lista, int info) {
	
	 no p = (no) malloc (sizeof(struct reg));
	 p->info = info;
	 
	 if (!*lista) {
		 p->prox = p;
		 *lista = p;
	 }
	 else {
		 no q = *lista;
		 while (q->prox != *lista)
			 q = q->prox;
			 q->prox = p;
			 p->prox = *lista;
			 *lista = p;
	 }
}

void mostrar(no lista){
	
	no p = lista; 
	do{
		printf("   %d   ",p->info);
		p = p->prox;
	}while (p != lista);
}
//EXERCICIO 9 

int trocar(no *lista, int x, int y){
	
	no p = *lista; 
	
	if((*lista) == NULL)
		return 0; 
	else if((*lista)->prox == (*lista)){
			if((*lista)->info == x)
				(*lista)->info = x+y;
			}else{
			while(p->prox != *lista){
				if(p->info == x)
					p->info = x+y; 
				p = p->prox;
			}
		}
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	no lista; 
	lista = NULL; 
	int n, x, y, aux; 
	
	//CRIANDO A LISTA CIRCULAR 
	printf("\nDigite o numero maximo de elementos da lista: "); 
	do{	
		scanf("%d",&n);
	}while(n <= 0);
	for(int i=0; i<n; i++){
		printf("Digite um numero: "); 
		scanf("%d",&aux); 
		inserir_lista(&lista,aux); 		
	}
	
	//MOSTRANDO A LISTA CIRCULAR 
	printf("\n\nLista: \n"); 
	mostrar(lista);

	//TROCANDO OS ELEMENTOS DA LISTA
	printf("\nDigite um numero x: "); 
	scanf("%d",&x); 
	printf("\nDigite um numero y: "); 
	scanf("%d",&y);
	trocar(&lista,x,y); 
	
	//MOSTRANDO A LISTA TROCADA
	printf("\nLista trocada: \n"); 
	mostrar(lista);	
}

