// Estrutura de dados 1
// Lista de ex 4 - ex 1
// Leonardo Oliveira

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

#define max 10 

typedef int def_fila[max]; 

void limpa_vetor(def_fila f){
	for (int i=0; i<max; i++){
		f[i] = NULL; 
	}
}

void fila_vazia(def_fila fila, int *i, int *f){
	(*i) = (*f) = -1; 
	limpa_vetor(fila); 	
}

int cheia(int i, int f){
	if((f == max-1 && i == 0) || (i != 0 && f == i-1))
		return 1; 
	return 0; 
}

int vazia (int i, int f){
	if(i == -1 && f == -1)
		return 1; 
	return 0; 
}

int enfileira (def_fila fila, int *i, int *f,int x){
	if(!cheia(*i,*f)){
		if((*f) == -1)
			(*i)++; 
		(*f)++; 
		//---------
		if((*f) == max)
			(*f) = 0; 		
		fila[*f] = x; 
		return 1; 
	}else {
		printf("\nFila cheia\n");
		return 0; 
	}	
}

int desenfileira (def_fila fila, int *i, int *f, int *x){
	
	if(!vazia(*i,*f)){
		(*x) = fila[*i]; 
		fila[*i] = NULL; 
		(*i)++; 
		if((*i) == max)
			(*i) = 0; 
		if(((*i) > (*f) && fila[*i] == NULL))		//Todos os elementos foram retirados!	
			(*i) = (*f) = -1; 
		return 1; 
	}else return 0;
}

void mostra(def_fila fila, int i, int f){
	/*for(int j=0; j<max; j++)
		if(fila[j] != NULL || fila[j] == 0)
			printf(" %d ",fila[j]);
		else printf(" N ");
	//int aux_inicio, aux_final; */
	
	int aux = max, cont = 0; 
	
	for(int j=i; j <= f || j <= max-1;){
		//if(j != f)
		
		printf("  %d  ",fila[j]);
		if(j == f) break;	
		j++;
		if(j == max) j = 0;
		
	}
	
	/*for(aux_inicio = i; aux_inicio < max && aux_inicio <= f; aux_inicio++){
		//if(fila[aux_inicio] != NULL || fila[aux_inicio] == 0)
			printf(" %d ",fila[aux_inicio]);
		//else break; 	
	}
	for(aux_final = f; aux_final < i; aux_final++){
		//if(fila[aux_final] != NULL || fila[])
			printf(" %d ",fila[aux_final]);
		//else break;
	}*/
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	def_fila fila; 
	int inicio, final; 
	int x; 
	char e; 
	
	fila_vazia(fila,&inicio,&final); 
	
	do{
		printf("Digite um elemento: ");
		scanf("%d",&x); 
		if(x != -1)
			enfileira(fila,&inicio,&final,x); 
	}while(x != -1);
	
	mostra(fila,inicio,final);
	
	do{
		printf("\nDeseja desenfileirar? (s/n)");
		do{
			scanf("%c",&e);
		}while(e != 's' && e != 'n'); 
		if(e == 's'){
			desenfileira(fila,&inicio,&final,&x); 
			printf("\nElemento retirado: %d",x);
		}		
	}while(e == 's');
	
	mostra(fila,inicio,final);
	printf("\n");
	
	do{
		printf("Digite um elemento: ");
		scanf("%d",&x); 
		if(x != -1)
			enfileira(fila,&inicio,&final,x); 
	}while(x != -1);
	
	mostra(fila,inicio,final);
	
	do{
		printf("\nDeseja desenfileirar? (s/n)");
		do{
			scanf("%c",&e);
		}while(e != 's' && e != 'n'); 
		if(e == 's'){
			desenfileira(fila,&inicio,&final,&x); 
			printf("\nElemento retirado: %d",x);
		}		
	}while(e == 's');
	
	mostra(fila,inicio,final);

}

