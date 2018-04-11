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
	int num;
	int transacao; 
	int temp_trans;
	int hora; 
	int min; 
	struct no* prox; 
};

typedef struct fila{
	int qtd; 
	no* clientes; 
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

no* cria_no(int hr, int min,int n_client){	 
	 no* p = (no*) malloc (sizeof(struct no)); 
	 
	 p->num = n_client; 
	 p->hora = hr; 
	 p->min = min; 
	 p->transacao = num_ale(); 
	 p->temp_trans = temp(p->transacao); 
	 p->prox = NULL; 
	 return p; 
}

int enfileira(deffila *f, no* q){	
	no* aux = (*f).clientes; 
	
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

int desenfileira(deffila *f, no* q){	
	if(vazia(*f))
		return 0; 
	no* p = (*f).clientes; 
	(*f).clientes = (*f).clientes->prox; 
	(q) = (*f).clientes; 
	free(p); 
	printf("\nSai do desenfileira");
	return 1; 
}

void inicia_fila(deffila *f){
	//printf("\n\tTeste1");
	(*f).qtd = 0; 
	//printf("\n\tTeste2"); 
	(*f).clientes = NULL;
	//printf("\n\tTeste3");
}

void printa_no(no* p){
	printf("\nCliente: %d",p->num);
	printf("\nTransação: %d",p->transacao); 
	printf("\nHora de entrada: %d:%d",p->hora,p->min);
	printf("\nTempo de transação: %d",p->temp_trans);
	printf("\n------------\n");
}

void printa_no2(no p){
	printf("\nCliente: %d",p.num);
	printf("\nTransação: %d",p.transacao); 
	printf("\nHora de entrada: %d:%d",p.hora,p.min);
	printf("\nTempo de transação: %d",p.temp_trans);
	printf("\n------------\n");
}

void mostra_fila(no* f){	
	while(f != NULL){
		printa_no(f);
		//printf(" \nTransação: %d  Hr: %d min: %d",f->transacao,f->hora,f->min);
		f = f->prox; 
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

void cronometro (int *sec, int *min, int *hr, int hr_exp, int *exp,int time){
	
		//_sleep(time);
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

int main(){

	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
		
	deffila fila; 
	no* aux; 	 
	no cx1; 
	inicia_fila(&fila);
	
	
	//Variaveis auxiliares 
	int flag = 0; 
	//Variaveis do expediente
	int expediente = 1, final_hora = 1; 
	//Variaveis do tempo
	int hora = 0, minutos = 0, segundos = 0;
	//Variaveis da contagem de clientes
	int cont = 0, cliente = 0; 
	//Variaveis dos caixas
	int caixa1 = 0; 
	
	do{
		cronometro(&segundos,&minutos,&hora,final_hora,&expediente,500);		
		//visualizar_tempo(hora,minutos,segundos); 
		
		if(segundos % 10 == 0){
			cliente++; 
			enfileira(&fila,cria_no(hora,minutos,cliente));
		}
		
		if(!caixa1){
				printf("\nTEste"); 
				flag = desenfileira(&fila,&cx1);
			if(flag){
				printf("\nAntes da impressão do cliente!"); 
				printf("\nCliente %d entrou no caixa!",cx1.num);
				printa_no2(cx1); 
				
				caixa1 = 1; 	
			}
		}
		
		if(caixa1){
			(cx1).temp_trans--;
			if((cx1).temp_trans == 0)
				caixa1 = 0; 
		}
		
		/*if(segundos % 30 == 0){
			desenfileira (&fila,&aux); 
			//printa_no(aux); 
		}*/		
		
	}while(cliente < 2);
	
	mostra_fila(fila.clientes);
	printf("\nNumero total de clientes: %d",cliente); 

}


