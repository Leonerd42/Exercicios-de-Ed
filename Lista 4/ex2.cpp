//  Exercicio 6 da apostila 
//  Ex 2 moodle - ED1
// Leonardo Oliveira

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

#define max 100
typedef int deffila[max];

void limpa_vetor(deffila f){
	for(int i=0; i<max; i++)
		f[i] = 0; 
}

void inicia_fila(deffila fila){	
	limpa_vetor(fila); 	
	fila[0] = fila[1] = -1; 
	
}

int vazia(deffila fila){
	if(fila[0] == -1 && fila[1] == -1)
		return 1; 
	return 0; 
}

int cheia(deffila fila){
	if(fila[1] == max-1)
		return 1; 
	return 0; 
}

int enfileira (deffila fila, int x){
	int aux; 
	if(!cheia(fila)){
		if(fila[1] == -1)
			fila[0] = fila[1] = 2; 			
		else fila[1]++; 
		//aux = fila[1]; 
		//printf("\n VALOR AUXILIAR: %d",aux);
		fila[fila[1]] = x; 
		
		return 1;
	}else{
		printf("\nFila cheia\n"); 
		return 0; 
	}
	
}

int desenfileira(deffila fila, int *x){
	if(!vazia(fila)){
		(*x) = fila[fila[0]]; 
		fila[0]++;
		if(fila[0] > fila[1] || fila[0] == max)
			fila[0] = fila[1] = -1; 
		return 1; 
	}else{
		printf("\nFila vazia\n"); 
		return 0; 
	}
}

void mostra_fila(deffila f){
	for(int i=f[0]; i<f[1]; i++)
		printf("\nElemento %d: %d ",i,f[i]);
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	deffila fila; 
	int x; 
	char e; 
	
	inicia_fila(fila);
	
	do{
		printf("Digite um elemento: ");
		scanf("%d",&x); 
		if(x != -1)
			enfileira(fila,x); 
	}while(x != -1);
	
	mostra_fila(fila);
	
	do{
		printf("\nDeseja desenfileirar? (s/n)");
		do{
			scanf("%c",&e);
		}while(e != 's' && e != 'n'); 
		if(e == 's'){
			desenfileira(fila,&x); 
			printf("\nElemento retirado: %d",x);
		}		
	}while(e == 's');
	
	mostra_fila(fila);
	printf("\nDigite novamente para empilhar\n"); 
	
	do{
		printf("Digite um elemento: ");
		scanf("%d",&x); 
		if(x != -1)
			enfileira(fila,x); 
	}while(x != -1);
	
	mostra_fila(fila);
	
	do{
		printf("\nDeseja desenfileirar? (s/n)");
		do{
			scanf("%c",&e);
		}while(e != 's' && e != 'n'); 
		if(e == 's'){
			desenfileira(fila,&x); 
			printf("\nElemento retirado: %d",x);
		}		
	}while(e == 's');
	
	mostra_fila(fila);
}
