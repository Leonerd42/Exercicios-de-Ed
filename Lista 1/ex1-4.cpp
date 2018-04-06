// Exercicios aula 1 - ED1 
// - Exercicio 1 

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>

//PRINTANDO O VETOR

void imprimir_vetor(int v[], int n){
	
	for(int i=0; i<n; i++)
		printf("  %d  ",v[i]);	
}

//COLETANDO O VETOR MAIN

void le_vetor(int v[], int *n){
	
	int flag = 1; 
	do{
		flag = 0; 
		system("cls");
		printf("Digite um valor maximo para o tamanho do vetor: ");
		scanf("%d",&(*n));
		if((*n)<0 || (*n)>100){
			printf("Validação: 0 < n < 100. Digite novamente");
			flag = 1; 
		}
	}while(flag == 1);
	
	printf("\nDigite os elementos do vetor:\n"); 
	for(int i=0; i<(*n); i++)	{
		printf("Numero %d : ",i+1);
		scanf("%d",&v[i]);
	}	
	
	printf("\n\nVetor salvo!"); 
}

// EXERCICIO 1 

void separar_vetor(int n,int v[], int p[], int i[],int *a, int *m){	
	
	printf("\nSeparando o vetor principal!"); 
	
	for(int j=0; j<n;j++){
		if(v[j] % 2 == 0){
			p[(*a)] = v[j];
			(*a)++; 
		}else{
			i[(*m)] = v[j];
			(*m)++;
		}		
	}	
}

//EXERCICIO 2 
 
 void sub_neg(int n, int v[]){
 	
 	for(int i=0; i<n; i++){
 		if(v[i] < 0)
 			v[i] = 0;
	 }
 }
 
 //EXERCICIO 3 
 
int soma_recursiva(int v[], int n){
	
	if(n == 0) return v[0];
		return (v[n] + soma_recursiva(v,n-1));
}

//EXERCICIO 4 

int fat_recursivo(int n){
	
	if(n < 0) return 0; 
	if(n == 0 || n == 1) return 1; 
	else return (n * fat_recursivo(n-1));	
} 

void print_vet_fat(int v[], int n){
	
	int p[100]; 
	
	for(int i=0; i<n; i++)
		p[i] = fat_recursivo(v[i]);	
	
	printf("\nVetor Fatorado: " ); 
	imprimir_vetor(p,n);	
}
	

int main(){

	setlocale(LC_ALL,"Portuguese");
	int n, a, m; 
	int aux; 
	n = a = m = 0; 
	int vetor [100], par[100], impar[100];
	//COLETANDO O VETOR
	
	le_vetor(vetor,&n);
	
	//SEPARANDO VETOR 
	separar_vetor(n,vetor,par,impar,&a,&m);
	
	//IMPRIMIR OS VETORES 
	printf("\nVetor principal: \n");
	imprimir_vetor(vetor, n); 
	printf("\nVetor par: \n"); 
	imprimir_vetor(par,a); 
	printf("\nVetor impar: \n"); 
	imprimir_vetor(impar,m); 
	
	//SUBSTITUINDO NEGATIVO POR 0 
	
	sub_neg(n,vetor);
	printf("\nVetor substituido: "); 
	imprimir_vetor(vetor,n); 
	
	//SOMANDO VETORES 
	
	aux = soma_recursiva(vetor,n);
	printf("\nSoma total do vetor: %d\n\n",aux); 
	
	//FATORIAL DOS VETORES 
	
	printf("\nVetor: ");
	imprimir_vetor(vetor,n); 
	print_vet_fat(vetor,n);
	
	printf("\n\nFim do programa!");	

}

