#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define MAX 80

typedef struct{
	int codigo;
	char descricao;
	float preco_unitario;

}PRODUTO;

int main(){
	FILE * entrada1, *entrada2, *saida;// Dois arquivos de entrada e um referente a saída
	char nome_arquivo1[MAX];
	char nome_arquivo2[MAX];
	int tamanho; //armazena a quantidade de linhas do arquivo
	PRODUTO *produtos; // armazena a quantidade de produtos num vetor dinâmico
	int i;

	puts("Entre com o nome do arquivo referente à descrição ");
	scanf("%s", nome_arquivo1); //lê o nome do arquivo fornecido pelo usuário
	entrada1 = fopen(nome_arquivo1, "r"); //abre o arquivo para leitura
	if(!entrada1){
		puts("ERRO! Arquivo não pode ser lido ou encontrado ou aberto.");
		return -1;
	} 
	tamanho = calcula_tamanho_arquivo(arquivo); // atribui a variavel o retorno da função que descobre a quantidade de linhas do arquivo de entrada
	
	produtos = (PRODUTO*)malloc(tamanho*sizeof(PRODUTO)); //aloca memória para um vetor tipo PRODUTO
	if(!produtos){
		puts("ERRO! Não foi possível alocar memória");
		return -2;
	}
	//lê e armazena os dados do arquivo numa estrutura
	for(i=0; i<tamanho; i++){
		fscanf(entrada1, "%d %s", &produtos.codigo[i], produtos.descricao);
	
	}

	puts("Entre com o nome do arquivo referente aos preços ");
	scanf("%s", nome_arquivo2); //lê o nome do outro arquivo fornecido pelo usuário
	entrada2 = fopen(nome_arquivo2, "r"); // abre o outro arquivo para leitura
	if(!entrada2){
		puts("ERRO! Arquivo não pode ser lido ou encontrado ou aberto.");
		return -3;
	} 
	//lê e armazena os dados do arquivo numa estrutura
	for(i=0; i<tamanho; i++){
		fscanf(entrada1, "%d %f", &produtos.codigo[i], &produtos.preco_unitario[i]);
	
	}
	
	menu(); //função menu pergunta ao usuário se ele quer digitar um código para busca, se sim, o usuário digitará 1, caso contrário 0;
	saida = fopen("busca.csv", "w");
	if(!saida){
		puts("ERRO! Arquivo não pode ser criado.");
		return -4;
	} 
	
	




	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
operacao_arquivo(FILE *arquivo, FILE* arquivo2, int tamanho){
	puts("Entre com o código do produto");
	scanf("");

}

int calcula_tamanho_arquivo(FILE *arquivo){

	int cont = 0;
	while (fgets(arquivo) != NULL){ //enquanto não for encontrada uma linha nula, o contador será incrementado, retornando ao final a quantidade de linhas do arquivo
		cont ++;
	}
	return cont;

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu(void);
	int opcao;

	while(opcao){
		puts("Se você deseja realizar a busca para um determinado código digite 1, caso contrário digite 2");
		switch(opcao){
			case 1: 


	}
	
