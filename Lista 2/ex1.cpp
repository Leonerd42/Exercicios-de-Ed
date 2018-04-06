// lista de exercicio ED1
// Exercicio 1
//Leonardo Oliveira

//COMENTARIO IMPORTANTE: 
// Eu estava com um pouco de duvida de como tinha que ser feito o exercicio
// Então eu comecei a faze-lo da mesma forma que eu faço um trabalho.. com menu e tudo 
// bem mais bonito e com varias opções.. mas ai percebi que n era isso que o exercicio tava pedindo 
// e fiz a interface parecida com a do exemplo: PilhaEst01.c, porém eu não copiei nada do exercicio
// Só fiz a interface parecida pq entendi q o exercicio pedia pra escrever as rotinas e não um trabalho super elaborado. 

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

#define N 10 			//Coloquei 10 elementos como maximo, para facilitar o teste da pilha cheia

typedef int def_pilha[N];

int vazia (int topo){
	if(topo <= 0)
		return 1; 	//Lista vazia
	return 0;		//Lista não vazia
}

int cheia(int topo){
	if (topo == N-1)
		return 1; 
	return 0; 		
}

int empilha(def_pilha p, int *topo, int x){
	if(cheia(*topo))
		return 0; 
	(*topo)++; 
	p[*topo] = x; 
	return 1; 
}

int desempilha(def_pilha p, int *topo){
	int x; 
	if(vazia(*topo))
		return 0; 
	x = p[*topo]; 
	(*topo)--; 
	return x;
}

int inicializa_pilha(def_pilha p){
	p[0] = 0;	//Valor do topo para pilha vazia é 0
	return 1; 
}

void visualizar_pilha(def_pilha p,int topo){
	
	for(int i=1; topo != 0; i++, topo--)
		printf("\nElemento %d: %d",i,p[topo]);
}

int ver_topo(def_pilha p){
	return p[p[0]];
}

int main(){
	
	setlocale(LC_ALL,"Portuguese");
	def_pilha pilha;
	pilha[0] = -1; 	//Pilha não foi inicializada
	int x; 
	char e; 
	
	
	
	if(vazia(pilha[0]))
		printf("Pilha vazia...\n");
	inicializa_pilha(pilha);
	printf("\nPilha inicializada!\n\n");
		
	do{
		printf("Digite um elemento (-1 para sair): ");
		scanf("%d",&x);
		if(x != -1)
			if(!empilha(pilha,&pilha[0],x))
				printf("\nPilha cheia\n");
	}while(x != -1);
	
	//Visualizar a pilha
	printf("\n\nPilha: "); 
	visualizar_pilha(pilha,pilha[0]);
	printf("\n\n");
	
	//Desempilhar
	do{
		printf("\nDeseja desempilhar um elemento? (S/N) "); 
		e = getch();
		e = toupper(e); 
		if(e == 'S'){
			printf("\n\tDesempilhei: %d",desempilha(pilha,&pilha[0]));			
		}
	}while(e != 'N' && !vazia(pilha[0]));
	
	printf("\n\nFim do programa!\n\t"); 
	system("pause");	 	

}

