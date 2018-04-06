// Exercicios 1° lista ED1
// Exercicio 5 

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

typedef struct reg *no; 
struct reg {
	int info;
	struct reg *prox; 
};

void inserir_comeco(no *lista,int dado){
	
	no p = (no) malloc (sizeof(struct reg));
	
	p->info = dado; 
	p->prox = *lista; 
	*lista = p; 
}

void mostrar_lista(no lista){
	no p = lista; 
	while(p){
		printf("  %d  ",p->info);
		p = p->prox;
	}
}
//EXERCICIO 5
int cont_lis (no lista){	
	if(lista == NULL) return 0; 
	else {
		lista = lista->prox;
		return 1 + cont_lis(lista);
	}
}

//EXERCICIO 6
int soma_rec (no lista){
	int aux; 
	if(lista == NULL) return 0; 
	else{
		aux = lista->info;
		lista = lista->prox;
		return (aux + soma_rec(lista));
	}
}

//EXERCICIO 7 
int remove_no(no *lista, int n){
	
	int i = 1; 
	no p, q, r; 
	
	r = *lista; 
	
	if(*lista == NULL){
		return 0;
	}else if((*lista)->prox == NULL){
		*lista = NULL;
		free(r);
		return 0;
	}else{
		
		p = *lista; 
		while(i < n){
			q = p;
			p = p->prox;
			i++;
		}
		
		q->prox = p->prox;
		free(p);
		*lista = r; 
	}
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	no teste; 
	teste = NULL; 
	
	int n,aux; 
	printf("\nDigite a quantidade de elementos da lista: ");
	scanf("%d",&n);
	printf("\nDigite os elementos da lista: \n");
	for(int i=0; i< n; i++){
		printf("Digite um numero: ");
		scanf("%d",&aux);
		inserir_comeco(&teste,aux);
	}
	
	printf("\n\nPrintar lista:");
	mostrar_lista(teste);
	
	//PRINTANDO A CONTAGEM RECURSIVA DE ELEMENTOS DA LISTA
	printf("\n\nContando os elementos da lista de forma recursiva...\n");
	printf("Numeros de elementos da lista: %d\n",cont_lis(teste));
	//system("pause");
	
	//PRINTANDO A SOMA RECURSIVA DOS ELEMENTOS DA LISTA
	printf("\nSoma dos nós da lista: "); 
	printf("\nTotal: %d",soma_rec(teste));
	
	//INTERAÇÃO PARA A REMOÇÃO DE UM ELEMENTO DA LISTA 
	printf("\n\nDigite o numero de um elemento da lista para remove-lo: ");
	do{
		scanf("%d",&aux);	//Verificação para impedir a digitação de um numero maior que n
	}while(aux > n);
	remove_no(&teste, aux); 
	
	printf("\nPrintando a lista de novo: \n"); 
	mostrar_lista(teste);
	
		
	
	
	
}

