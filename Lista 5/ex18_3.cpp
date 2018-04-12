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

typedef const char *string;

string desc_trans(int x){
	switch(x){
		case 0: return "Saldo";
		case 1: return "Saque";
		case 2: return "Aplicação";
		case 3: return "Extrato Semanal ";
		case 4: return "Extrato Mensal ";
		case 5: return "Pagamento de conta em dinheiro ";
		case 6: return "Pagamendo de conta em cheque";
		case 7: return "Pagamento de conta com saque";
	}
}

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

typedef struct {
	int hora; 
	int min; 
	//int seg; 
} tempo ;

typedef struct no{
	int numero; 
	tempo time; 
	int trans;
	struct no *prox; 
} *No;

typedef struct fila {
	int qtd; 
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
	
	(*f).qtd++; 
	
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
		//printf("\nFila vazia"); 
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

void printa_caixas(No cx1, No cx2, No cx3){
	
	//system("cls"); 
	
	gotoxy(1,1);
	printf("\n\n--------- CAIXA 1 --------"); 
	//printa_no()
	printf("\nNumero do cliente: "); 
	printf("\nHora do cliente: "); 
	printf("\nTransação do cliente: "); 
	printf("\nTempo de transação do cliente:"); 
	
	printf("\n\n--------- CAIXA 2 --------");
	printf("\nNumero do cliente: "); 
	printf("\nHora do cliente: "); 
	printf("\nTransação do cliente: "); 
	printf("\nTempo de transação do cliente:"); 
	
	printf("\n\n--------- CAIXA 3 --------");
	printf("\nNumero do cliente: "); 
	printf("\nHora do cliente: "); 
	printf("\nTransação do cliente: "); 
	printf("\nTempo de transação do cliente:"); 
	
	if(cx1 != NULL){
		gotoxy(20,4); 
		printf("  ");
		gotoxy(20,4); 
		printf("%d",cx1->numero); 
		gotoxy(18,5); 
		printf("  ");
		gotoxy(18,5); 
		printf("%d:",cx1->time.hora); 
		gotoxy(21,5); 
		printf("  ");
		gotoxy(21,5);
		printf("%d",cx1->time.min); 
		gotoxy(23,6); 
		printf("                                                           ");
		gotoxy(23,6); 
		printf("%s",desc_trans(cx1->trans)); 
		
	}//else //printf("\nCaixa vazio!"); 	
	
	if(cx2 != NULL){
		gotoxy(20,10); 
		printf("  ");
		gotoxy(20,10); 
		printf("%d",cx2->numero); 
		gotoxy(18,11); 
		printf("  ");
		gotoxy(18,11); 
		printf("%d:",cx2->time.hora); 
		gotoxy(21,11); 
		printf("  ");
		gotoxy(21,11);
		printf("%d",cx2->time.min); 
		gotoxy(23,12); 
		printf("                                                           ");
		gotoxy(23,12); 
		printf("%s",desc_trans(cx2->trans)); 
		
	}//else //printf("\nCaixa vazio!"); 
	
		if(cx3 != NULL){
		gotoxy(20,16); 
		printf("  ");
		gotoxy(20,16); 
		printf("%d",cx3->numero); 
		gotoxy(18,17); 
		printf("  ");
		gotoxy(18,17); 
		printf("%d:",cx3->time.hora); 
		gotoxy(21,17); 
		printf("  ");
		gotoxy(21,17);
		printf("%d",cx3->time.min); 
		gotoxy(23,18); 
		printf("                                                           ");
		gotoxy(23,18); 
		printf("%s",desc_trans(cx3->trans)); 
		
	}//else //printf("\nCaixa vazio!"); 
}

void cronometro (int *segundos, int *minutos, int *hora, int limite[], int *flag){
	
	(*segundos)++; 
	if((*segundos) == 60){
		(*minutos)++; 
		(*segundos) = 0; 
	}
	
	if((*minutos) == 60){
		(*hora)++; 
		(*minutos) = 0;
	}
	
	if((*hora)== limite[0] && (*minutos)==limite[1] && (*segundos)==limite[2]){
		(*flag) = 1; 
	}	
}

void printa_hora(int sec, int min, int hora){
	
	gotoxy(3,2);
	printf("  "); 
	gotoxy(3,2);
	printf("%d:",hora); 
	gotoxy(5,2);
	printf("  "); 
	gotoxy(5,2);
	printf("%d:",min); 
	gotoxy(7,2);
	printf("  "); 
	gotoxy(7,2);
	printf("%d s",sec); 
	
	
}

void printa_tempo(int t1, int t2, int t3){
		gotoxy(33,7); 
		printf("   "); 
		gotoxy(33,7); 
		printf("%d",t1);
		gotoxy(33,13); 
		printf("   "); 
		gotoxy(33,13); 
		printf("%d",t2);
		gotoxy(33,19); 
		printf("   "); 
		gotoxy(33,19); 
		printf("%d",t3);
}

int min_total(int hr, int min){
	return (hr*60) + min ;
}

int diferencaDeHora(int v1, int v2){
	
	int total = v2 - v1; 	
	return (total < 0) ? total+=1440 : total; 	
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	
	def_fila banco; 
	No aux; 
	No cx1, cx2, cx3; 
	cx1 = cx2 = cx3 = NULL; 
	
	banco.clientes = NULL;
	banco.qtd = 0; 

	
	//Variaveis do tempo 
	int segundos = 1, minutos = 0, hora = 0; 
	int tempo_espera1 = 0, tempo_espera2 = 0, tempo_espera3 = 0; 
	float tempo_total = 0; 
	//Variaveis de limite
	int limite[3]; 
	limite[0] = 0; limite[1] = 10; limite[2] = 0; 
	
	int tr[8] = {0,0,0,0,0,0,0,0};
	int mais_atendida, maior_valor = -1; 
	
	int caixa1 = 1, caixa2 = 1, caixa3 = 1; 
	int temp1 = 0, temp2 = 0, temp3 = 0; 
	int mudanca = 0, quantidade = 0; 
	
	int flag = 0; 
	
	while(!flag){
		
		_sleep(300);
		cronometro(&segundos,&minutos,&hora,limite,&flag);
		if(mudanca == 0)	
			printa_caixas(cx1,cx2,cx3); 
		mudanca = 1; 
		printa_hora(segundos,minutos,hora);
		printa_tempo(temp1,temp2,temp3);	
		
		if(segundos % 10 == 0){
			//quantidade++; 
			enfileira(&banco,quantidade,hora,minutos);			
		}	
		
		if(caixa1){			
			if(desenfileira(&banco,&aux)){
				cx1 = aux; 
				temp1 = temp(cx1->trans); 	
				tempo_espera1 = diferencaDeHora(min_total(cx1->time.hora,cx1->time.min),min_total(hora,minutos));
				if(tempo_total == 0)
					tempo_total = tempo_espera1; 
				else tempo_total = (tempo_total+tempo_espera1)/2;
				tr[cx1->trans]++; 
				quantidade++;
				gotoxy(60,7); 
				printf("Tempo de espera na fila em min: %d",tempo_espera1); 			
				caixa1 = 0; 
				mudanca = 0; 
			}			
		}
		if(caixa2){
			if(desenfileira(&banco,&aux)){
				cx2 = aux; 
				temp2 = temp(cx2->trans);
				tempo_espera2 = diferencaDeHora(min_total(cx2->time.hora,cx2->time.min),min_total(hora,minutos));
				if(tempo_total == 0)
					tempo_total = tempo_espera2; 
				else tempo_total = (tempo_total+tempo_espera2)/2;
				tr[cx2->trans]++; 
				quantidade++;
				gotoxy(60,13); 
				printf("Tempo de espera na fila em min: %d",tempo_espera1); 
				caixa2 = 0 ; 
				mudanca = 0; 
			}
		}
		if(caixa3){
			if(desenfileira(&banco,&aux)){
				cx3 = aux; 
				temp3 = temp(cx3->trans);
				tempo_espera3 = diferencaDeHora(min_total(cx3->time.hora,cx3->time.min),min_total(hora,minutos));
				if(tempo_total == 0)
					tempo_total = tempo_espera3; 
				else tempo_total = (tempo_total+tempo_espera3)/2;
				tr[cx3->trans]++; 
				quantidade++;
				gotoxy(60,19); 
				printf("Tempo de espera na fila em min: %d",tempo_espera1); 
				caixa3 = 0 ; 
				mudanca = 0; 
			}
		}
		if(!caixa1){
			temp1--; 			
			if(temp1 == 0){
				caixa1 = 1;
			}
		}	
		if(!caixa2){
			temp2--; 			
			if(temp2 == 0){
				caixa2 = 1;
			}
		}
		if(!caixa3){
			temp3--; 			
			if(temp3 == 0){
				caixa3 = 1;
			}
		}
		
		gotoxy(1,22); 
		printf("\n\tTempo médio de espera: %.2f",tempo_total); 
		printf("\n\tClientes finalizados até agora: %d",quantidade); 
		printf("\n\tClientes ainda na fila: %d",banco.qtd-quantidade);
			
	}//Fim do while
	
	system("cls"); 
	printf("\n\tDados do dia: "); 
	printf("\n\tQuantidade de clientes total: %d",banco.qtd);
	printf("\n\tQuantidade de cliente atendidos: %d",quantidade); 
	printf("\n\tCliente ainda na fila: %d",banco.qtd-quantidade);
	printf("\n\tTempo médio de espera em min: %.2f",tempo_total);
	printf("\n\n\t\tTransações atendidas "); 
	for(int i=0; i<8; i++){
		printf("\n\tTransação tipo %s, atendido %d vezes hoje!",desc_trans(i),tr[i]);
		if(tr[i] > maior_valor){
			maior_valor = tr[i]; 
			mais_atendida = i; 
		}			
	}
	printf("\n\n\tA transação mais atendida foi a %s",desc_trans(mais_atendida)); 
	//printf("\nSai do loop"); 
	//printa_no(cx1,temp1); 	
}

