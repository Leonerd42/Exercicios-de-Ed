// Exercicio 7 
// Estrutura de dados 1
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
	    float  dado;
      	struct no_pilha *prox;
        } No;
typedef struct descritor{
	    int quantidade;
      	No *pilha;
        } def_pilha;
        
/*******************************************************************
						MANIPULAÇÃO DA PILHA
*******************************************************************/
void inicia_pilha(def_pilha *pilha){
	(*pilha).pilha = NULL; 
	(*pilha).quantidade = 0; 
}

void limpa_lista(def_pilha *pilha){
	
	No* q; 
	while((*pilha).pilha!=NULL){
		q = (*pilha).pilha; 
		(*pilha).pilha = (*pilha).pilha->prox; 
		(*pilha).quantidade--; 
		free(q);
	}
}

int vazia(def_pilha Pilha){
 	return(Pilha.pilha==NULL);
}

No* cria_no(float numero){	
    No* q = (No*) malloc(sizeof(struct no_pilha));
    q->dado=numero;
    q->prox=NULL;
    return q;
}

void empilha(def_pilha* Pilha, float numero){
	No* q = cria_no(numero);
    if(!vazia(*Pilha)) q->prox = Pilha->pilha;
    Pilha->pilha = q;
    Pilha->quantidade++;
}

int desempilha(def_pilha* Pilha, float *numero){
	No* q;
    if(vazia(*Pilha)) 
		return 0;
    q = Pilha->pilha;
    (*numero) = q->dado;
    Pilha->pilha = Pilha->pilha->prox;
    free(q);
    Pilha->quantidade--;
    return 1;
}

void visualiza(def_pilha Pilha){
   
   while (Pilha.pilha!=NULL){
          printf("\t%f", Pilha.pilha->dado);
          Pilha.pilha=Pilha.pilha->prox;};
    printf("\n");
}

/*******************************************************************
						RESOLUÇÃO DO EXERCICIO 
*******************************************************************/
void limpa_vetor(char e[]){
	
	for(int i=0; i<20; i++)
	e[i] = '\0';	
}


float resultado (def_pilha *p, char v[]){
	
	char aux[20];
	limpa_vetor(aux);
	float aux2, aux3; 
	float result; 	
	int j; 
	
	for(int i=0; i<strlen(v); i++){
		switch(v[i]){
			case '+':	desempilha(&(*p),&aux2);			//Desempilha os dois ultimos elementos da pilha
						desempilha(&(*p),&aux3);			//A terem sido adicionados e realiza a operação entre eles
						result = aux3 + aux2; 				//* ou + ou - ou / e o resultado empilha na pilha
						empilha(&(*p),result); 
						break; 
			case '-':	desempilha(&(*p),&aux2);
						desempilha(&(*p),&aux3);
						result = aux3 - aux2; 
						empilha(&(*p),result);
						break; 
			case '*':	desempilha(&(*p),&aux2);
						desempilha(&(*p),&aux3);
						result = aux3 * aux2; 
						empilha(&(*p),result); 
						break; 
			case '/':	desempilha(&(*p),&aux2);
						desempilha(&(*p),&aux3);
						result = aux3 / aux2; 
						empilha(&(*p),result); 
						break; 
			case 'e':
			case 'E':	for(j=i+1; j<strlen(v); j++){		//Converte parte da string para numero e empilha na pilha
							if(v[j] == 'E' || v[j] == 'e' || (v[j] != '0' && v[j] != '1' && v[j] != '2' && v[j] != '3' && v[j] != '4' && v[j] != '5' && v[j] != '6' && v[j] != '7' && v[j] != '8' && v[j] != '9' )){
								i = j-1; 
								break;
							}else {
								aux[j-i-1] = v[j];
							}
						}
						//aux[j-i+1] = '\0';
						aux2 = atoi(aux);
						//printf("\nNumero: %.3f",aux2);  //Printf para testar os numeros lidos 
						limpa_vetor(aux);
						empilha(&(*p),aux2);
						break; 
			case 'c':
			case 'C':	limpa_lista(&(*p));						//Se o caracter c for usado
						break;
			default:
						break; 
		}
	}
	
	desempilha(&(*p),&result);		//Retorna o ultimo elemento da lista 
	return result; 
}

void le_expressao (char v[]){			//Função para a leitura da string
	fflush(stdin);
	printf("Digite a expressão: "); 
	gets(v); 
}

int main(){

	setlocale(LC_ALL,"Portuguese");
	char expressao[50], e;  
	def_pilha inteiros; 
	
	do{
		inicia_pilha(&inteiros);
			
		printf("\nDigite a expressão com as letras maiusculas e sem espaço!\n");
		le_expressao(expressao);
		
		printf("\n\tResultado: %.2f",resultado(&inteiros,expressao)); 
		
		printf("\n\nDeseja continuar? (s/n): ");
		do{
			scanf("%c",&e); 
			e = toupper(e);
		}while(e != 'S' && e != 'N');
	}while(e == 'S');	
	printf("\n\nFim do programa!");
}

