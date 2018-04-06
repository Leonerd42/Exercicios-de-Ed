// Exercicio 19 
// Estrutura de Dados 1
// Leonardo Oliveira

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

/*******************************************************************
						DEFINIÇÃO DA PILHA
*******************************************************************/
typedef struct no_pilha{
	    char dado;
      	struct no_pilha *prox;
        } No;
typedef struct descritor{
	    int quantidade;
      	No *pilha;
        } def_pilha;
        
/*******************************************************************
						MANIPULAÇÃO DA PILHA
*******************************************************************/
int vazia(def_pilha Pilha){
 	if(Pilha.pilha==NULL)
 		return 1; 
 	return 0; 
}
void inicia_pilha(def_pilha *pilha){
	(*pilha).pilha=NULL; 
	(*pilha).quantidade = 0; 
}
No* cria_no(char caracter){	
    No* q = (No*) malloc(sizeof(struct no_pilha));
    q->dado=caracter;
    q->prox=NULL;
    return q;
}
void empilha(def_pilha *Pilha, char caracter){
	No* q = cria_no(caracter);
    if(!vazia(*Pilha)) 
		q->prox = Pilha->pilha;
    Pilha->pilha = q;
    Pilha->quantidade++;
}
int desempilha(def_pilha *Pilha, char *caracter){
	No* q;
    if(vazia(*Pilha)) 
		return 0;
    q = Pilha->pilha;
    *caracter = q->dado;
    (*Pilha).pilha = (*Pilha).pilha->prox;
    free(q);
    (*Pilha).quantidade--;
    return 1;
}

void visualiza(def_pilha Pilha){   
   while (Pilha.pilha!=NULL){
          printf("%c", Pilha.pilha->dado);
          Pilha.pilha=Pilha.pilha->prox;};
    printf("\n");
}

/*******************************************************************
					RESOLUÇÃO DO EXERCICIO
*******************************************************************/

//Leitura e impressão da string
void le_frase(char v[]){
	fflush(stdin);	
	printf("Digite uma frase:");
	gets(v);	
}

void printa_frase(char v[]){	
	printf("%s",v);
}

void jogaNaPilha (char v[], def_pilha *p){		//Essa função pega os caracteres da string 
												//E joga na pilha
	for(int i=0; i<strlen(v); i++)
			empilha(&(*p),v[i]);
}

void uma_palavra(def_pilha *pilha1, def_pilha *pilha2){		//Essa função pega a pilha com a frase
															//E coloca uma palavra + ' '  na pilha 2
	char aux; 	

	while((*pilha1).pilha != NULL){
		if((*pilha1).pilha->dado != ' '){
		   	desempilha(&(*pilha1),&aux);
			empilha(&(*pilha2),aux);
	   	}else {
			desempilha(&(*pilha1),&aux);
			break;
		}
    }	
	empilha(&(*pilha2),' ');	
}

void volta_pilha(def_pilha *p1, def_pilha *p2){		//Passa os dados de uma pilha pra outra
													//Diferente da rotina uma_palavra
	char x;											//Pois essa rotina não exclui o ' ' da passagem 
	
	while(!vazia(*p1)){
		desempilha(&(*p1),&x); 
		empilha(&(*p2),x);
	}
}

void separa (def_pilha *pilha1, def_pilha *pilha2){		//Essa rotina chama as funções uma_palavra e volta_pilha
														//Até que todas as palavras da pilha 1 acabem 
	def_pilha aux; 
	inicia_pilha(&aux);
 
	while(!vazia(*pilha1)){
		uma_palavra(&(*pilha1),&(*pilha2)); 
		volta_pilha(&(*pilha2),&aux);
	}	
	(*pilha1) = aux;									//Atribui a pilha 1 a pilha auxiliar	
}


int main(){

	setlocale(LC_ALL,"Portuguese");
	def_pilha pilha1, pilha2; 
	char frase[50], e; 
	do{
		inicia_pilha(&pilha1); 
		inicia_pilha(&pilha2);
		
		le_frase(frase); 
		printf("\n\tFrase digitada:  "); 
		printa_frase(frase); 
		
		jogaNaPilha(frase,&pilha1);
		
		separa(&pilha1,&pilha2);
		
		printf("\n\tFrase invertida: "); 
		visualiza(pilha1); 
		
		printf("\n\nDeseja continuar? (s/n): "); 
		do{
			scanf("%c",&e); 
			e = toupper(e); 
		}while(e != 'S' && e != 'N');
	}while(e == 'S');
		
	printf("\nFim do programa!");
}

