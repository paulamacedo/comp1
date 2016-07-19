

typedef struct{
	char descricao[50];
	int codigo;
	float preco_unitario; 
}PRODUTO;


int acha_quant_linhas(FILE* entrada);
  

void armazena_dados(FILE* entrada, FILE* entrada2, PRODUTO * produtos, int tamanho);


int busca_produtos(PRODUTO *produtos, int tamanho, int codigo);


float calcula_precos(PRODUTO *produtos, int posicao, int quantidade);
	