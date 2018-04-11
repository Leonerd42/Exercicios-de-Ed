//	Exercicio 18 
//	Problema dos caixas do banco
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

typedef struct no {
	int num_cliente;
	int transacao; 
	int hora; 
	int min; 
	int temp_trans; 
	struct no* prox; 
}no;

typedef struct fila{
	int qtd; 
	no* clientes; 
} deffila;

int temp(int x){		//Retorna o valor do tempo em segs da transação correspondente
	switch(x){
		case 0: {	return 10; 
					break;
				}
		case 1: {	return 20; 
					break;
				}
		case 2: {	return 30; 
					break;
				}
		case 3: {	return 40; 
					break;
				}
		case 4: {	return 50; 
					break;
				}
		case 5: {	return 60; 
					break;
				}
		case 6: {	return 70; 
					break;
				}
		case 7: {	return 80; 
					break;
				}
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

no* cria_no(int hr, int min,int n_client){	 
	 no* p = (no*) malloc (sizeof(struct no)); 
	 
	 p->num_cliente = n_client; 
	 p->hora = hr; 
	 p->min = min; 
	 p->transacao = num_ale(); 
	 p->prox = NULL; 
	 return p; 
}
//certo
int enfileira(deffila *f, no* q){	
	 
	no* aux = (*f).clientes; 
	//printf("teste");
	if((*f).clientes == NULL){
		(*f).clientes = q; 
		//printf("oi leo"); 
	}else {
		while(aux -> prox != NULL)
			aux = aux->prox;
		aux->prox = q;
		//printf("teste2"); 
	}
	//(*f).qtd++; 
	return 1; 
}
//certo
int desenfileira(deffila *f, no* *q){	
	if(vazia(*f))
		return 0; 
	no* p = (*f).clientes; 
	(*q) = (*f).clientes;
	(*f).clientes = (*f).clientes->prox; 	
	free(p); 
	return 1; 
}
//certo
void inicia_fila(deffila *f){
	//printf("\n\tTeste1");
	(*f).qtd = 0; 
	//printf("\n\tTeste2"); 
	(*f).clientes = NULL;
	//printf("\n\tTeste3");
}

void mostra_fila(no* f){	
	while(f != NULL){
//		printf(" \nTransação: %d  Hr: %d min: %d",f->transacao,f->hora,f->min);
		f = f->prox; 
	}
}

void printa_no(no* p){
	printf("\nCliente: %d",p->num_cliente);
	printf("\nTransação: %d",p->transacao); 
	printf("\nHora de entrada: %d:%d",p->hora,p->min);
	printf("\nTempo de transação: %d",p->temp_trans);
	printf("\n------------\n");
}
//certo 
void cronometro (int *sec, int *min, int *hr, int hr_exp, int *exp){
	
		(*sec)++; 
		if((*sec) == 60){
			(*min)++; 
			(*sec)=0; 
		}
		
		if((*min) == 30){
			(*exp) = 0; 
			(*hr)++; 
			(*min)=0; 
		}
		
		if((*hr) == hr_exp){
			(*exp) = 0; 
		}
}

void visualizar_tempo (int hr, int min, int sec){
	
	gotoxy(2,2); 
	printf("  "); 
	gotoxy(2,2); 
	printf("%d:",hr); 
	gotoxy(5,2); 
	printf("  "); 
	gotoxy(5,2); 
	printf("%d:",min); 
	gotoxy(7,2); 
	printf("  "); 
	gotoxy(7,2); 
	printf("%d",sec);
}

void printa_caixas(no* cx1, no* cx2, no* cx3,int c1, int c2, int c3){
	
	system("cls");
	
	gotoxy(1,5); 
	printf("\n\t ---- CAIXA %d ---- ",c1); 
	printf("\nNúmero cliente: %d",cx1->num_cliente); 
	printf("\nHora de entrada: %d: %d",cx1->hora,cx1->min); 
	printf("\nTipo da transação: %d",cx1->transacao); 
	printf("\nTempo da transação: %d",cx1->temp_trans); 
	
	printf("\n\n\t ---- CAIXA %d ---- ",c2); 
	printf("\nNúmero cliente: %d",cx2->num_cliente); 
	printf("\nHora de entrada: %d: %d",cx2->hora,cx2->min); 
	printf("\nTipo da transação: %d",cx2->transacao); 
	printf("\nTempo da transação: %d",cx2->temp_trans); 
	
	printf("\n\n\t ---- CAIXA %d ---- ",c3); 
	printf("\nNúmero cliente: %d",cx3->num_cliente); 
	printf("\nHora de entrada: %d: %d",cx3->hora,cx3->min); 
	printf("\nTipo da transação: %d",cx3->transacao); 
	printf("\nTempo da transação: %d",cx3->temp_trans); 
	
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
		
	deffila fila; 
	
	no* aux; 	
	no* cx1, cx2, cx3; 
	
	//cx1 = cx2 = cx3 = cria_no(1,1,0); 
	
	int expediente = 1, final_hora = 30; 
	
	int hora = 0, minutos = 0, segundos = 0; 
	int cont = 0, cliente = 0; 
	
	int caixa1 = 0, caixa2 = 0, caixa3 = 0; 
	int cont_cx1 = 0, cont_cx2 = 0, cont_cx3=0 ;
	int flag;	
	
//	printf("\nTeste");
	inicia_fila(&fila);
	
	//ROTINA DO CRONOMETRO 
	do{
		_sleep(1000); 
		cronometro(&segundos,&minutos,&hora,final_hora,&expediente);		
		visualizar_tempo(hora,minutos,segundos); 
		
		//printf("\nteste amendoin"); 
		
		//printa_caixas(cx1,cx2,cx3,caixa1,caixa2,caixa3); 
		
		if(cont == 10){
			cont = 0; 
			
			cliente++; 
			enfileira(&fila,cria_no(hora,minutos,cliente));	
			
			//printf("teste"); 
		
			printf("\nUm cliente entrou na fila!"); 
			system("pause"); 
			//mostra_fila(fila.clientes); 
		}		
			
		//printf("\nsai do enfileira"); 
		
		if(!caixa1){
			printf("teste1"); 
			flag = desenfileira(&fila,&aux); 
			printf("\nValor da flag: %d",flag);
			if(flag != 0 && aux != NULL){
				cx1 = aux; 	
				cx1->temp_trans = temp(cx1->transacao);
				caixa1 = 1; 
				printf("\nCliente entrou no caixa 1! %d",segundos); 
				//printf("\nTempo da transação: %d",cx1->temp_trans);
				printa_no(aux); 
			}
			flag = 0; 
		}
		
		if(caixa1){ 
			cx1->temp_trans--;
			printf("\nContando o valor restante: %d",cx1->temp_trans);
			if(cx1->temp_trans == 0)
				caixa1 = 0; 
		}
		
		/*
		if(!caixa2) {
			flag = desenfileira(&fila,&aux);
			if(flag != 0){ 
				cx2 = aux; 	
				cx2->temp_trans = temp(cx2->transacao);
				caixa2 = 1; 
				//printf("\nCliente entrou no caixa 2!"); 
			}
			flag = 0; 
		}
		
		if(!caixa3){
			flag = desenfileira(&fila,&aux); 
			if(flag != 0){
				cx3 = aux; 	
				cx3->temp_trans = temp(cx3->transacao);
				caixa3 = 1; 
			}
			flag = 0; 
		}/*
		
		 
		if(caixa2) 
			cx2->temp_trans--;
		if(caixa3) 
			cx3->temp_trans--; 
		
		if(cx1 != NULL)
			if(cx1->temp_trans< 1) caixa1 = 0; 
		if(cx2 != NULL)
			if(cx2->temp_trans <1) caixa2 = 0; 
		if(cx3 != NULL)
			if(cx3->temp_trans <1) caixa3 = 0; 		*/
		
		cont++; 
		
	}while(expediente); 
	
	mostra_fila(fila.clientes);
}

