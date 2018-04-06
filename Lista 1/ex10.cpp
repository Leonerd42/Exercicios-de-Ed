// Exercicios de ED1
// Exercicio 10

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

void inclui_final (no *lista, int info){
	
	 no p = (no) malloc(sizeof(struct reg));
	 p->info=info;
	 p->prox=NULL;
	 if (*lista==NULL)
		*lista = p;
	 else {
	 no q = *lista;
	 
	 while (q->prox)
		 q = q->prox;
	 q->prox = p;
 }
}

void mostrar(no lista){
	
	no p = lista; 
	while(p){
		printf("   %d   ",p->info);
		p = p->prox;
	}
}

no lista2; 

// EXERCICIO 10 
int ret_lista(no lista,no *lista2, int n,int k){	//OBS: não é possivel essa rotina ser chamada, caso haja 0 elementos na lista!!!
	
	//Parte do n-esimo elemento
	if(n == 1){
		no p = (no) malloc (sizeof(struct reg));
		p->info = lista->info;
		p->prox = NULL;
		(*lista2) = p;		
	}else ret_lista(lista->prox,&(*lista2),n-1,k);	//Vai contar até o n-esimo numero, quando chegar n será igual a 0
	
	//Parte da quantidade de elementos
	//Adicionará outro nó a lista 
	no q = (no) malloc 	(sizeof(struct reg)); 
	q->info = k; 
	q->prox = NULL; 
	(*lista2)->prox = q; 
	return 0; 
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	no lista = NULL; 
	no segunda_lista = NULL; 
	int n, aux, k, nesimo; 
	
	//	CRIANDO A LISTA ENCADEADA SIMPLES
	printf("\nDigite o valor maximo de elementos da lista: "); 
	do{
		scanf("%d",&n); //Não é possivel haver quantidade negativa de elementos na lista 
	}while(n < 0);
	for(int i=0; i<n; i++){
		printf("Digite um numero: "); 
		scanf("%d",&aux); 
		inclui_final(&lista, aux); 
	}
	
	printf("\nMostrando a lista: \n");
	mostrar(lista);
	
	printf("\nDigite o n-esimo elemento: "); 
	do{
		scanf("%d",&nesimo); //O nesimo numero só pode ser igual ou menor que o numero total de elementos
	}while(nesimo > n);
	
	//ROTINA RECURSIVA PARA GERAR A SEGUNDA LISTA COM O N-ESIMO ELEMENTO E A QUANTIDADE TOTAL DE ELEMENTOS DA LISTA 
	if(nesimo != 0) {
		ret_lista(lista, &segunda_lista, nesimo, n);
		
		//Eu não entendi o exercicio 10 muito bem, mas o que eu entendi foi que
		//A função recursiva era pra pegar o n-esimo numero e colocar em um nó de uma outra lista
		//O proximo nó dessa lista seria a quantidade de elementos dela
		//Captar o n-esimo numero da primeira lista de forma recursiva eu consegui fazer
		//Porém não consegui, na mesma rotina fazer a contagem da quantidade de elementos da lista
		//Então peguei o dado anterior e deixei a função recursiva buscar o n-esimo elemento 
		
		printf("\nMostrando a segunda lista(n-esimo numero, quantidade total de elementos): "); 
		mostrar(segunda_lista);
	}else printf("\n\nDados invalidos, fim do programa!"); //Em caso de que não haja nenhum elemento na lista!

}

