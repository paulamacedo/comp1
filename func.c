#include "func.h"

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

void armazena_dados(FILE* entrada, FILE* entrada2, PRODUTO *produtos, int tamanho){
	
	int i;
	for(i=0; i< tamanho; i++){
		fscanf(entrada, "%d %s", &produtos[i].codigo, produtos[i].descricao);
		printf("PASSOU POR AQUI i %d %d %s\n ", i, produtos[i].codigo, produtos[i].descricao);
	}
	for(i=0; i< tamanho; i++){
		fscanf(entrada2, "%d %f", &produtos[i].codigo, &produtos[i].preco_unitario);
		printf("PASSOU POR AQUI i %d %d %f\n", i, produtos[i].codigo,  produtos[i].preco_unitario);
	}
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

float calcula_precos(PRODUTO *produtos, int posicao, int quantidade){

	float valor;

	valor = produtos[posicao].preco_unitario * quantidade; 

	return valor; 
	
}	
