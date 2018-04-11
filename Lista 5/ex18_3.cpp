//
//
// Leonardo Oliveira

#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

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

void printa_caixas(No cx1,int temp1){
	
	system("cls"); 
	
	printf("\n\n--------- CAIXA 1 --------"); 
	//printa_no()
	printf("\nNumero do cliente: "); 
	printf("\nHora do cliente: "); 
	printf("\nTransação do cliente: "); 
	printf("\nTempo de transação do cliente: %d",temp1); 
	
	if(cx1 != NULL){
		gotoxy(30,4); 
		printf("%d",cx1->numero); 
		gotoxy(30,5); 
		printf("%d",cx1->time.hora); 
		gotoxy(35,5); 
		printf("%d",cx1->time.min); 
		gotoxy(30,6); 
		printf("%d",cx1->trans); 
		
	}else printf("\nCaixa vazio!"); 	
	
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	
	def_fila banco; 
	No aux; 
	No cx1, cx2, cx3; 
	cx1 = cx2 = cx3 = NULL; 
	int temp1 = 0; 
	banco.clientes = NULL;
	int quantidade = 0; 
	long segundos = 1; 
	int caixa1 = 1; 
	
	int flag = 0; 
	
	while(!flag){
		
		_sleep(500);
		printa_caixas(cx1,temp1); 
		
		if(segundos % 10 == 0){
			quantidade++; 
			enfileira(&banco,quantidade,segundos*2,segundos);
			//printf("\nUm cliente enfileirado!!!!"); 
			
		}
		
		
		if(caixa1){			
			if(desenfileira(&banco,&aux)){
				cx1 = aux; 
				temp1 = temp(cx1->trans); 
				//printf("\nUm cliente entrou no caixa 1"); 
				printa_no(cx1,temp1); 				
				caixa1 = 0; 
			}			
		}
		
		if(!caixa1){
			//printf("\nContando o tempo restante do cliente!"); 
			//printf("\nTempo: %d",temp1); 
			temp1--; 
			if(temp1 == 0){
				flag = 1; 
				caixa1 = 1;
			}
		}		
		segundos++; 
	}
	
	printf("\nSai do loop"); 
	printa_no(cx1,temp1); 
	
	/*
	desenfileira(&banco,&aux);
	
	for(int i=0; i<10; i++){
		enfileira(&banco,i,i,i);
	}
	
	desenfileira(&banco,&aux);
	
	cx1 = aux; 
	temp1 = temp(cx1->trans);
	
	
	printf("\nCliente retirado: "); 
	printa_no(cx1,temp1);
	
	mostra_fila(banco);*/

}

