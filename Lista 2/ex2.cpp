//	Exercicio 2 
//  ED 1
//Leonardo Oliveira

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10 

typedef struct{
	int topo[2];
	int elementos[MAX];
}defpilha;

void inicializa_pilha(defpilha *p){
	(*p).topo[0] = -1; 
	(*p).topo[1] = MAX;
}

int vazia(int op, defpilha p){		//Se estiver vazia retorna 0
	
	if(!op){
		if(p.topo[op] == -1)
			return 1; 
		return 0; 			
	}else{
		if(p.topo[op] == MAX)
			return 1; 
		return 0; 		
	}
}

int cheia(int op, defpilha p){
	
	if(!op){									//Retorna 1 se a lista 1 estiver cheia
		if(p.topo[0] == (p.topo[1] - 1))
			return 1; 
		return 0; 		
	}else{										//Retorna 1 se a lista 2 estiver cheia
		if(p.topo[1] == (p.topo[0] + 1))
			return 1; 
		return 0; 
	}	
}

int empilha(int opcao, defpilha *p, int x){	//Opção tem que ser restrito a 0 e 1
	
	if(!opcao){ //Se for 0 coloca na primeira pilha
				//Verificação se pilha ta cheia
		if(!cheia(opcao,(*p)))
			(*p).elementos[++(*p).topo[0]] = x; 
		else printf("\nPilha 1 Cheia!\n");
	}else{
				//Verificação se pilha ta cheia
		if(!cheia(opcao,(*p)))
			(*p).elementos[--(*p).topo[1]] = x;		
		else printf("\nPilha 2 Cheia!\n");
	}	
	return 1;
}

int desempilha (int opcao, defpilha *p, int *x){
	
	if(!opcao){
			//Verificação se está vazia
		if(!vazia(opcao,*p)){
			(*x) = (*p).elementos[(*p).topo[0]];
			(*p).topo[0]--; 	
		}else {
			printf("\nPilha 1 vazia!\n");
			return 0; 
		}
	}else{
			//Verificação se está vazia
		if(!vazia(opcao,*p)){
			(*x) = (*p).elementos[(*p).topo[1]]; 
			(*p).topo[1]++; 
		}else {
			printf("\nPilha 2 vazia!\n");
			return 0; 
		}
	}
	return 1; 
}

void ver_pilha(int op, defpilha p){
	
	if(!op){
		while(p.topo[op] >= 0){
			printf(" -> %d",p.elementos[p.topo[op]]);
			p.topo[op]--; 
		}
	}
	else{
		while(p.topo[op] < MAX){
			printf(" -> %d",p.elementos[p.topo[op]]);
			p.topo[op]++; 
		}
		
	}
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	defpilha pilha; 
	int op, x; 
	char e; 
	
	//Pilha inicializada
	inicializa_pilha(&pilha); 
	printf("Para cancelar o empilhamento digite -1 na escolha das pilhas\n\n");
	
	//Leitura dos dados
	do{
		printf("\nEscolha uma pilha (1 ou 2, -1 pra sair): "); 
		do{
			scanf("%d",&op);
		}while((op < 1 || op > 2) && op != -1); 
		if(op == -1) break;
		op--; 
		
		do{
			printf("Digite um elemento: (-1 para sair): ");
			scanf("%d",&x);			
			if(x != -1) empilha(op,&pilha,x);
		}while(x != -1);
	}while(op != -1);
	
	//Ver pilha 1
	printf("\nPilha 1: "); 
	ver_pilha(0, pilha);
	//Ver pilha 2
	printf("\n\nPilha 2: "); 
	ver_pilha(1, pilha);
	
	printf("\n\n");
	
	do{
		printf("\nEscolha uma pilha para desempilhar (1 ou 2, -1 pra sair): ");
		do{
			scanf("%d",&op);
		}while((op < 1 || op > 2) && op != -1);
		
		if(op == -1) break; 
		op--; 
		
		printf("\n");
		do{
			printf("Desempilhar pilha %d? (S/N): ",op+1);
			do{
				e = toupper(getchar());
			}while(e != 'S' && e != 'N'); 
			if(e == 'S'){
				if(desempilha(op,&pilha,&x))
					printf("\nDesempilhado valor: %d\n",x);
			}
				
		}while(e == 'S');
	}while(op != -1);
	
	//Ver pilha 1
	printf("\nPilha 1: "); 
	ver_pilha(0, pilha);
	//Ver pilha 2
	printf("\n\nPilha 2: "); 
	ver_pilha(1, pilha);
	
	printf("\n"); 
	system("pause");
}

