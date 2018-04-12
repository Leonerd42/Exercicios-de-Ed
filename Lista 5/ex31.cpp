// Ex 31
// Leonardo Oliveira

#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

struct dados{
	char veiculo[10]; 
	int tipo; 
	int dest;
};

typedef struct no {
	struct dados dado; 
    struct no* prox;
}* def_fila;

int vazia(def_fila Inicio){
     return (Inicio == NULL);
}

def_fila cria_no(struct dados d){	
    def_fila q = (def_fila) malloc(sizeof(struct no));
    
	switch(d.tipo){
		case 1: strcpy(q->dado.veiculo,"Carro"); 
				break; 
		case 2: strcpy(q->dado.veiculo,"Caminhão"); 
				break; 
		case 3: strcpy(q->dado.veiculo,"Moto"); 
				break; 
		case 4: strcpy(q->dado.veiculo,"Bicicleta"); 
				break; 
		case 5: strcpy(q->dado.veiculo,"Van"); 
				break; 
	}
	
	q->dado.tipo = d.tipo; 
	q->dado.dest = d.dest;
    q->prox=NULL;
    return q;
}

void enfileira(def_fila* Inicio, def_fila* Final, struct dados d){ 
     def_fila q = cria_no(d);
     if (*Final != NULL) (*Final)->prox=q;
     else *Inicio=q;
     *Final=q;
}

int desenfileira(def_fila* Inicio,def_fila* Final, struct dados *d){ 
    
	def_fila q;

    if (*Inicio == NULL) return 0;
    q = *Inicio;
    *Inicio = (*Inicio)->prox;
    if (*Inicio == NULL) *Final=NULL;
    (*d) = q->dado;
    free(q);
    return 1;
}

void imprime(def_fila Inicio){ 

    def_fila q;

    q=Inicio;
    while (q != NULL){
          printf("\nTipo: %d",q->dado.tipo); 
          printf("\nVeiculo: %s",q->dado.veiculo); 
          printf("\nDestino: %d",q->dado.dest);
          q=q->prox;}
    printf("\n\n");
}

int num_ale(){
	return (rand()%5+1); 
}

struct dados novo_veiculo(){
	struct dados d; 
	d.dest = num_ale();
	d.tipo = num_ale(); 
	return d;
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	srand(time(NULL));
	def_fila inicio, final;
	inicio=final=NULL;
	int x = 0, cont = 0; 
	//int policial[5] = {1,2,3,4,5};
	struct dados aux; 
	
	for(int i=0; i<100; i++){
		aux = novo_veiculo(); 
		enfileira(&inicio,&final,aux);
		//printf("\n%d %d",aux.tipo,aux.dest);
	}
		
	while(!vazia(inicio)){
		//printf("\ntnc");
		_sleep(1000);
		if(cont % 3 == 0)	system("cls");
		desenfileira(&inicio,&final,&aux);
		//printf("\t\t%d %d",aux.dest, aux.tipo);
		printf("\nVeiculo: %s Destino: %d",aux.veiculo,aux.dest);
		if(aux.dest == (aux.tipo)-1){
			printf("\nPolicial Bloqueou o caminho!"); 
			printf("\n%s pegou a saida %d",aux.veiculo,aux.dest+1); 
			printf("\n----\n");
		}else{
			printf("\nCaminho liberado!"); 
			printf("\n%s seguiu o destino %d",aux.veiculo,aux.dest);
			printf("\n----\n");
		}
		
		cont++; 
	}	
}

