//	Exercicio 18 
//	Problema dos caixas do banco
// Leonardo Oliveira

#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

typedef struct reg {
	int num_cliente;
	int transacao; 
	int hora; 
	int min; 
	struct reg *prox; 
}*no;

typedef struct fila{
	int qtd; 
	no clientes; 
} deffila;

int temp(int x){		//Retorna o valor do tempo em segs da transação correspondente
	switch(x){
		case 0: return 10; 
		case 1: return 20; 
		case 2: return 30; 
		case 3: return 40;
		case 4: return 50; 
		case 5: return 60; 
		case 6: return 70; 
		case 7: return 80; 
	}
}

int vazia(deffila f){
	if(f.clientes == NULL)
		return 1; 
	return 0; 
}

int num_ale(){
	return (rand()%8); 
}

no cria_no(int hr, int min,int n_client){	 
	 no p = (no) malloc (sizeof(struct reg)); 
	 
	 p->num_cliente = n_client; 
	 p->hora = hr; 
	 p->min = min; 
	 p->transacao = num_ale(); 
	 p->prox = NULL; 
	 return p; 
}

int enfileira(deffila *f, no q){	
	no aux = (*f).clientes; 
	
	if((*f).clientes == NULL)
		(*f).clientes = q; 
	else {
		while(aux -> prox != NULL)
			aux = aux->prox;
		aux->prox = q;
	}
	(*f).qtd++; 
	return 1; 
}

int desenfileira(deffila *f, no *q){	
	if(vazia(*f))
		return 0; 
	no p = (*f).clientes; 
	(*q) = (*f).clientes; 
	(*f).clientes = (*f).clientes->prox; 
	free(p); 
	return 1; 
}

void inicia_fila(deffila *f){
	printf("\n\tTeste1");
	(*f).qtd = 0; 
	printf("\n\tTeste2"); 
	(*f).clientes = NULL;
	printf("\n\tTeste3");
}
void mostra_fila(no f){	
	while(f != NULL){
		printf(" \nTransação: %d  Hr: %d min: %d",f->transacao,f->hora,f->min);
		f = f->prox; 
	}
}

void printa_no(no p){
	printf("\nCliente: %d",p->num_cliente);
	printf("\nTransação: %d",p->transacao); 
	printf("\nHora de entrada: %d:%d",p->hora,p->min);
	printf("\n------------\n");
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
		
	deffila fila; no aux; 
	
	printf("\nTeste1"); 
	inicia_fila(&fila);
	printf("\nTeste2");
	for(int i = 0; i < 10; i++){
		enfileira(&fila,cria_no(10-i,i*i,i*2));		
	}
	
	printf("\nTeste3");
	mostra_fila(fila.clientes);
	
	printf("\n\nVamos tirar os primeiros elementos: \n\n");
	
	for(int j = 0; j < 5; j++){
		desenfileira(&fila,&aux); 
		printa_no(aux);
	}
	
	mostra_fila(fila.clientes);

}

