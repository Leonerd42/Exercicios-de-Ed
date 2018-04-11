//
//
// Leonardo Oliveira

#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

typedef struct {
	int hora; 
	int min; 
} tempo ;

typedef struct {
	int num; 
	int temp; 
} Transacao;

typedef struct no{
	int numero; 
	tempo time; 
	int trans;
	struct no *prox; 
} *No;

typedef struct fila {
	No clientes;
} def_fila;

int num_ale(){
	return (rand()%8); 
}

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

No cria_no (int num,int hr, int min){
	
	No q = (No) malloc (sizeof(struct no));
	int aux = num_ale();
	
	q->time.hora = hr;
	q->time.min = min;
	q->trans = aux;
	q->numero = num;
	q->prox = NULL;
}

int vazia(def_fila f){
	
	if(f.clientes == NULL)
		return 1; 
	return 0; 	
}

int enfileira (def_fila *f, int num, int hr, int min){
	
	No p = cria_no(num,hr,min);
	No aux = (*f).clientes;
	
	if ((*f).clientes == NULL){
		(*f).clientes = p; 
		return 1; 
	}else{
		while(aux->prox != NULL)
			aux = aux->prox;
		aux->prox = p;
		return 1; 		
	}	
}

int desenfileira (def_fila *fila, No *q){
	
	if(vazia(*fila)){
		printf("\nFila vazia"); 
		return 0; 
	}
	
	No p = (*fila).clientes; 
	(*fila).clientes = (*fila).clientes->prox;
	(*q) = p;
	free(p);	
	
}

void printa_no(No um_cliente,int time){
	
	printf("\nNumero do cliente: %d",um_cliente->numero);
	printf("\nHora de entrada: %d:%d",um_cliente->time.hora,um_cliente->time.min);
	printf("\nNumero da transação: %d",um_cliente->trans);
	printf("\nTempo da transação: %d",time);  
	printf("\n----\n"); 
	
}

void mostra_fila(def_fila fila){
	
	while(fila.clientes != NULL){		
		printa_no(fila.clientes,temp(fila.clientes->trans));		
		fila.clientes = fila.clientes->prox;
	}
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	
	def_fila banco; 
	No aux; 
	No cx1; 
	int temp1 = 0; 
	banco.clientes = NULL;
	
	desenfileira(&banco,&aux);
	
	for(int i=0; i<10; i++){
		enfileira(&banco,i,i,i);
	}
	
	desenfileira(&banco,&aux);
	
	cx1 = aux; 
	temp1 = temp(cx1->trans);
	
	
	printf("\nCliente retirado: "); 
	printa_no(cx1,temp1);
	
	mostra_fila(banco);

}

