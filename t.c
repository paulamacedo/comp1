#include <stdio.h>
#include <stdlib.h>
#define MAX 50


typedef struct{
	char descricao[MAX];
	int codigo;
	float preco_unitario; 
}PRODUTO;


//FUNCIONA
int acha_quant_linhas(FILE* entrada){

	int contador = 0 ;
	int caractere, existe_linhas = 0;
  
  	while((caractere = fgetc(entrada)) != EOF){
    	existe_linhas = 1; // há conteúdo no arquivo
    
    	if(caractere == '\n'){ //se houver quebra de linha, incrementar o contador
      		contador++;             
    	} 
  }

  //Incrementar novamente o contador, pois na última linha não há quebra de linha e o contador não irá ser incrementado
  	if(existe_linhas){
  		contador++;
  	}
	return contador;//retorna o número de linhas do arquivo
}
//FUNCIONA
void armazena_dados(FILE* entrada, FILE* entrada2, PRODUTO *produtos, int tamanho){
	int i;

	for(i=0; i<tamanho; i++){
		fscanf(entrada, "%d %s", &produtos[i].codigo, produtos[i].descricao);
		printf("PASSOU POR AQUI i %d %d %s\n ", i, produtos[i].codigo, produtos[i].descricao);
	}
	for(i=0; i<tamanho; i++){
		fscanf(entrada2, "%d %f", &produtos[i].codigo, &produtos[i].preco_unitario);
		printf("PASSOU POR AQUI i %d %d %f\n", i, produtos[i].codigo,  produtos[i].preco_unitario);
	}

	
}
// falha de segmentação 


float calcula_precos(PRODUTO *produtos, int posicao, int quantidade){

	float valor;

	valor = produtos[posicao].preco_unitario * quantidade; 

	return valor; 
	
}

int busca_produtos(PRODUTO *produtos, int tamanho, int cod){

	int direita, esquerda, i=0;
	esquerda = 0;
	direita = tamanho-1;
	while(esquerda <= direita) {
		i = (esquerda+direita)/2;
		if(produtos[i].codigo == cod){ 
			return i;
		}
		if(cod > produtos[i].codigo) {
			esquerda = i+1;
		}
		else {
			direita = i-1;
		}	
	}
	return -1;

}

int main(){

	//variáveis de arquivo 
	FILE *entrada, *entrada2, *saida;
	char nome_entrada[MAX], nome_entrada2[MAX], nome_saida[MAX];
	
	//variáveis de estrutura
	PRODUTO *produtos;
	
	int i;
	//variáveis de controle do menu
	int cod, posicao, quantidade, opcao = 1; 
	
 
	//Interação com o usuário 1 - Solicitação de arquivo de entrada 1
	puts("Por favor, entre com o nome do arquivo 1 (codigo e descrição)");	
	scanf("%s", nome_entrada);

	//Abertura de arquivo para leitura e teste
	entrada = fopen(nome_entrada, "r");
	if(!entrada){
		puts("Erro! Não foi possível realizar a leitura do arquivo.");
		return 1;	
	}
	
	//Achar quantidade de linhas do arquivo
	int tamanho_arq = acha_quant_linhas(entrada);
	printf("PASSOU POR AQUI 1 tamanho linha %d\n",tamanho_arq);
	
	//Alocação dinâmica de memória para um vetor do tipo PRODUTO e teste  
	produtos = (PRODUTO*)malloc(tamanho_arq * sizeof(PRODUTO));
	if(!produtos){
		puts("Erro! Não foi possível alocar memoria suficiente para este vetor.");
		return 1;
	}
	//

	
	//Interação com o usuário 2 - Solicitação de arquivo de entrada 2
	puts("Por favor, entre com o nome do arquivo 2 (codigo e preço unitário)");	
	scanf("%s", nome_entrada2);
	
	//Abertura de arquivo para leitura e teste
	entrada2 = fopen(nome_entrada2, "r"); 
	if(!entrada2){
		puts("Erro! Não foi possível realizar a leitura do arquivo.");
		return 1;	
	}
	puts("PASSOU POR AQUI 3");
	//Armazena os dados provenientes de dois arquivos de entrada numa estrutura do tipo PRODUTO
	armazena_dados(entrada, entrada2, produtos, tamanho_arq);
	puts("PASSOU POR AQUI 4");

	
	//Gera um arquivo para escrita
	saida = fopen("saida.csv", "w");
	if(!saida){
		puts("Erro! Arquivo de saida não pode ser gerado.");
		return 1;	
	}
	puts("PASSOU POR AQUI 5");
	//Interação com o usuário 3 - MENU
	puts("Vamos começar a nossa busca?"); 
		
	while(opcao!= 0){		

			puts("Entre com o código do produto e a quantidade ");
			scanf("%d %d", &cod, &quantidade);
			posicao = busca_produtos(produtos, tamanho_arq, cod);
			if(posicao < 0){
				puts("Código não encontrado!");
				continue;			
			}
			float valor;
			valor = calcula_precos(produtos, posicao, quantidade);	
			printf("%f\n", valor);
			//gera_csv(saida, produtos)//olhar essa função depois
			printf("Deseja continuar com a busca?\n"
				" 1 . Para continuar\n"
				" 0 . Para encerrar busca e gerar csv\n ");	
			scanf("%d", &opcao);
		}
		
	
	return 0;

}
	