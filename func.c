#include "func.h"

int acha_quant_linhas(FILE *entrada){

	int contador = 0 ;


	return contador;
}

PRODUTO armazena_dados(FILE *entrada, FILE *entrada2, PRODUTO produtos, int tamanho){
	int i;

	for(i=0; i<tamanho; i++){
		fscanf(entrada, "%d %s", &produtos[i].codigo, produtos[i].descricao);
	}
	for(i=0; i<tamanho; i++){
		fscanf(entrada2, "%d %f", &produtos[i].codigo, &produtos[i].preco_unitario);
	}

	return produtos;
}

int busca_produtos(PRODUTO produtos, int tamanho, int codigo){

	int direita, esquerda, meio;
	esquerda = 0;
	direita = tamanho-1;
	while(esquerda <= direita) {
		meio = (esquerda+direita)/2;
		if(produtos[meio] == codigo) return meio;
		if(codigo > produtos[meio]) esquerda = meio+1;
		else direita = meio-1;
	}
	return -1;

}

float calcula_preços(PRODUTO produtos, int posicao, int quantidade){

	float valor;

	 valor = podutos[posicao].preço_unitario * quantidade; 

	return valor; 
	
}	
