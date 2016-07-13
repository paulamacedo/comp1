#include <stdio.h>
#include <stdlib.h>
#define MAX 50
#include "func.c"
 
int main(){

	//variáveis de arquivo 
	FILE *entrada, *entrada2, *saida;
	char nome_entrada[MAX], nome_entrada2[MAX], nome_saida[MAX];
	//
	//variáveis de estrutura
	PRODUTO *produtos;
	// 
	//variáveis de controle do menu
	int cod, posicao, quantidade, opcao=0; 
	//
 
	//Interação com o usuário 1 - Solicitação de arquivo de entrada 1
	puts("Por favor, entre com o nome do arquivo 1 (codigo e descrição)");	
	scanf("%s", &nome_entrada);
	//Abertura de arquivo para leitura e teste
	entrada = fopen(nome_entrada, "r");
	if(!entrada){
		puts("Erro! Não foi possível realizar a leitura do arquivo.");
		return 1;	
	}
	//
	//Achar quantidade de linhas do arquivo
	int tamanho_arq = acha_quant_linhas(entrada);
	//
	//Alocação dinâmica de memória para um vetor do tipo PRODUTO e teste  
	produtos = (PRODUTO*)malloc(tamanho_arq * sizeof(PRODUTO));
	if(!produtos){
		puts("Erro! Não foi possível alocar memoria suficiente para este vetor.");
		return 1;
	}
	//
	//Interação com o usuário 2 - Solicitação de arquivo de entrada 2
	puts("Por favor, entre com o nome do arquivo 2 (codigo e preço unitário)");	
	scanf("%s", &nome_entrada2);
	//
	//Abertura de arquivo para leitura e teste
	entrada = fopen(nome_entrada2, "r"); 
	if(!entrada){
		puts("Erro! Não foi possível realizar a leitura do arquivo.");
		return 1;	
	}
	//Armazena os dados provenientes de dois arquivos de entrada numa estrutura do tipo PRODUTO
	armazena_dados(entrada, entrada2, produtos, tamanho);
	//
	//Gera um arquivo para escrita
	saida = fopen(nome_saida, "w");
	if(!saida){
		puts("Erro! Arquivo de saida não pode ser gerado.");
		return 1;	
	}
	//Interação com o usuário 3 - MENU

	puts("Vamos começar a nossa busca?"); 
	while(opcao!= 0){		
			puts("Entre com o código do produto e a quantidade ");
			scanf("%d %d", &cod, &quantidade);
			posicao = busca_produto(produtos, cod);
			calcula_preços(saida, produtos, posicao, quantidade);	
			gera_csv(saida, produtos)//olhar essa função depois
			printf("Deseja continuar com a busca?\n"
				" 1 . Para continuar\n"
				" 0 . Para encerrar busca e gerar csv ");	
			scanf("%d", &opcao);
		}
		
				

	return 0;

}
