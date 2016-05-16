/*
Autores :
Data: 05/2016
Descrição:
Entrada:
Saída:
*/

#include <stdio.h>
#include "polinomio.h"


int main(){
	// dicionario de dados 
	int opcao; //variável que guarda a opção selecionada pelo usuário.
	
	//imprime o conjunto de opções que o usuário pode escolher (menu).
	printf( "Digite:\n"
		"1. calcular a soma de dois polinomios;\n"
		"2. calcular a derivada de um polinomio;\n"
		"3. calcular a integral de um polinomio;\n"
		"4. calcular as raızes de um polinomio (para polinomios de grau 2 apenas);\n"
		"5. calcular o valor do polinomio para um dado valor da variavel;\n"	
		"6. encerrar o programa\n");
	
	
	//Serão lidas as opções digitadas pelo usuário até que o mesmo digite 6, que é a condição de parada do loop e do programa.
	while (opcao != 6){
		scanf("%d", &opcao);
		switch (opcao){
			case 1:				
				printf("\n");
				break;
			case 2:
				printf("\n");
				break;
			case 3:
				printf("\n");
				break;
			case 4:
				printf("\n");
				break;
			case 5: 
				printf("\n");
				break;
			case 6: 
				return 0;
				break;
			default:
				printf("Opção inválida!");
		}
	}

	return 0; 
}
