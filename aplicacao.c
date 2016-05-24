/*
Autores : 
Data: 05/2016
Descrição: O programa realiza contas envolvendo polinomios.
*/

#include "polinomio.h"
#include <stdio.h>
#include <math.h>


int main(){
	// dicionario de dados 
	int opcao; //variável que guarda a opção selecionada pelo usuário.
	t_Polinomio polinomio1, polinomio2;
	float resultado, valor = 0;
	t_Polinomio resultado1;  
	struct s_Raizes r;
	

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
				puts("Você selecionou a opção de soma de dois polinomios. Primeiro, digite o polinomio 1:");
				polinomio1 = lePolinomio();
				puts("Digite o polinomio 2:");
				polinomio2 = lePolinomio();
				resultado1 = somaPolinomios (polinomio1, polinomio2);
				imprimePolinomio(resultado1);
				printf("\n");
				break;
			case 2:
				puts("Você selecionou a opção calcular a derivada de um polinomio. Entre com o polinomio");
				polinomio1 = lePolinomio();
				derivaPolinomio (polinomio1);
			
				printf("\n");
				break;
			case 3:
				puts("Você selecionou a opção calcular a integral de um polinomio. Entre com o polinomio");
				polinomio1 = lePolinomio();
				integraPolinomio(polinomio1);
				printf("\n");
				break;
			case 4:
				puts("Você selecionou a opção calcular as raızes de um polinomio(para polinomios de grau 2 apenas!).Entre com o polinomio");
				polinomio1 = lePolinomio();
				r = raizesPolinomioGrau2(polinomio1); 
				printf("Raiz%f %f\n", r.raiz1, r.raiz2 );
				printf("\n");
				break;
			case 5:
				puts("Você selecionou a opção calcular o valor do polinomio para um dado valor da variavel. Primeiro, entre com o polinomio");
				polinomio1 = lePolinomio();
				puts("Agora, entre com o valor da variável:");
				scanf("%f", &valor);
				resultado = calculaPolinomio(polinomio1, valor);
				printf("%.1f", resultado);
				printf("\n");
				break;
			case 6: 
				return 0;
				break;
			default:
				printf("Opção inválida!");
				break;
		}
	}

	return 0; 
}
