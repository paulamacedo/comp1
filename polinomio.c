/*
Autores : Paula Macedo da Cruz e Rodrigo Avelar Felicidade 
Data: 23/05/2016
Definição: Implementação das funções que tratam do conjunto de operações com polinomios.
*/

#include "polinomio.h"
#include <stdio.h>
#include <math.h>

/* Cria e inicializa um polinomio com todos os coeficientes com valor zero e variavel 'x' */
/* Entrada: <vazio> */ 
/* Saida: o polinomio criado com coeficientes iguais a zero e variavel 'x' */ 
t_Polinomio criaPolinomioZero (void){ 

	t_Polinomio polinomio;
	
	polinomio.coef0 = 0;
	polinomio.coef1 = 0; 
	polinomio.coef2 = 0;
	polinomio.coef3 = 0;
	polinomio.coef4 = 0;
	polinomio.coef5 = 0;
	polinomio.coef6 = 0;
	polinomio.coef7 = 0;
	polinomio.coef8 = 0;
	polinomio.coef9 = 0;
	polinomio.variavel = 'x'; 

	return polinomio;
}

/* Cria e inicializa um polinomio com os valores dos coeficientes lidos da entrada padrao */
/* Entrada: <vazio> */ 
/* Saida: o polinomio criado com os coeficientes lidos */
/* Descricao: a leitura do teclado deve ser feita termo a termo sempre seguindo a ordem:
   <sinal><coeficiente><variavel><potencia>.
   Exemplo: o polinomio dado pela funcao f(x) = 2x^4 - 25x^2 + x - 5 devera ser digitado da seguinte forma: 
   +2x4 -25x2 +1x1 -5x0=
   O operador de igualdade deve ser usado para marcar o final da entrada de termos. */ 
t_Polinomio lePolinomio (void){ 

	//int var = 1;
	float coef;
   	unsigned short int potencia;
   	char variavel, sinal = ' ';
   	t_Polinomio p = criaPolinomioZero(); //inicializa todos os coeficientes com 0
      //Nunca escrever 0x, pois dá erro;
   	while(sinal != '='){
		// lê o polinomio
   		scanf("%f %c %hu %c", &coef, &variavel, &potencia ,&sinal);
		/*if(sinal == '-'){
			var = -1;
		}*/		
         switch (potencia){
            
            case 9 :
               p.coef9 = coef; 
               break;
            case 8 :
               p.coef8 = coef; 
               break;
            case 7 :
               p.coef7 = coef; 
               break;
            case 6 :
               p.coef6 = coef; 
               break;
            case 5 :
               p.coef5 = coef;  
               break;
            case 4 :
               p.coef4 = coef;
               break;
            case 3 :
               p.coef3 = coef;
               break;
            case 2 :
               p.coef2 = coef; 
               break;
            case 1 :
               p.coef1 = coef; 
               break;
            case 0 :
               p.coef0 = coef; 
         }
   		
   		if(sinal == '=') break;	

   	}
   	return p;
}

/* Imprime um polinomio na tela usando o formato <sinal><coeficiente><variavel><potencia> */ 
/* Entrada: um polinomio */ 
/* Saida: polinomio impresso na tela */ 
/* Descricao: Deverao ser omitidos a potencia '1', a variavel com potencia '0', os termos com coeficiente '0'
   e o sinal '+' do primeiro termo.
   Exemplo: 2.0y^7 - 25.0y^3 + 0.3^y - 1 */
void imprimePolinomio (t_Polinomio p){

      //se o coeficiente 9  != 0, ele é impresso direto sem sinal, caso contrário é impresso o próximo coeficiente com a formatação de primeiro coeficiente.
      //depois que o primeiro coeficiente é impresso, é analisado sempre se o coeficiente anterior existe, caso não haja o mesmo, é impresso o sinal correspondente entre os monomios. 

      if(p.coef9!= 0 ){
         p.coef9>0 ? printf(" %.1f%c^9", p.coef9, p.variavel) : printf(" %.1f%c^9", p.coef2, p.variavel);
      }
      if(p.coef8!= 0 ){
         p.coef8>0 ? ((p.coef9 = 0)? printf("%.1f%c^8", p.coef8, p.variavel) :printf(" + %.1f%c^8", p.coef8, p.variavel)) : printf(" %.1f%c^8", p.coef8 , p.variavel);
      }
      
      if(p.coef7!= 0 ){
         p.coef7>0 ? ((p.coef8 = 0)? printf("%.1f%c^7", p.coef7, p.variavel) : printf(" + %.1f%c^7", p.coef7, p.variavel)) : printf(" %.1f%c^7", p.coef7, p.variavel);
      }
      if(p.coef6!= 0 ){
         p.coef6>0 ? ((p.coef7 = 0)? printf("%.1f%c^6", p.coef6, p.variavel) : printf(" + %.1f%c^6", p.coef6, p.variavel)) : printf(" %.1f%c^6", p.coef6 , p.variavel);
      }
      if(p.coef5!= 0 ){
         p.coef5>0 ? ((p.coef6 = 0)? printf("%.1f%c^5", p.coef5, p.variavel) : printf(" + %.1f%c^5", p.coef5, p.variavel)) : printf(" %.1f%c^5", p.coef5 , p.variavel);
      }
  
      if(p.coef4!= 0 ){
         p.coef4>0 ? ((p.coef5 = 0)? printf("%.1f%c^4", p.coef4, p.variavel) : printf(" + %.1f%c^4", p.coef4, p.variavel)) : printf(" %.1f%c^4", p.coef4, p.variavel);
      }
      if(p.coef3!= 0 ){
         p.coef3>0 ? ((p.coef4 = 0)? printf("%.1f%c^3", p.coef3, p.variavel) : printf(" + %.1f%c^3", p.coef3, p.variavel)) : printf(" %.1f%c^3", p.coef3 , p.variavel);
      }
      if(p.coef2!= 0 ){
         p.coef2>0 ? ((p.coef3 = 0)? printf("%.1f%c^2", p.coef2, p.variavel) : printf(" + %.1f%c^2", p.coef2, p.variavel)) : printf(" %.1f%c^2", p.coef2, p.variavel);
      }
      if(p.coef1!= 0 ){
         p.coef1>0 ? ((p.coef2 = 0)? printf("%.1f%c", p.coef1, p.variavel) : printf(" + %.1f%c", p.coef1, p.variavel)) : printf(" %.1f%c", p.coef1 , p.variavel);
      }
      if(p.coef0!= 0 ){
         p.coef0>0 ? ((p.coef1 = 0)? printf("%.1f", p.coef0) : printf(" + %.1f ", p.coef0)) : printf(" %.1f ", p.coef0);
      }
      else{
         printf("polinomio zerado.");   
      }
   
   printf("\n");

   
}

/* Altera um termo de um polinomio */
/* Entrada: um polinomio, a potencia do termo, o novo coeficiente do termo */ 
/* Saida: o polinomio de entrada com o termo da potencia indicada alterado */ 
t_Polinomio alteraPolinomio (t_Polinomio p, unsigned short int potencia, float novoCoef){

	

	

/* Encontra o grau de um polinomio */
/* Entrada: um polinomio */ 
/* Saida: o grau do polinomio de entrada (maior potencia) */ 
unsigned short int grauPolinomio (t_Polinomio p){

   //avalia a existencia de um coeficiente, se esse coeficiente for o maior, ele retorna o número correspondente ao coeficiente. Ex.: p.coef9=0 e p.coef8!=0, o valor retornado será 8.
   if(p.coef9 != 0){
      return 9;
   }
   else{
      if(p.coef8 != 0){
         return 8;
      }
      else if(p.coef7 != 0){
            return 7;
      }
      else if(p.coef6 != 0){
            return 6;
         }
      else if(p.coef5 != 0){
            return 5;
         }
      else if(p.coef4 != 0){
            return 4;
         }
      else if(p.coef3 != 0){
            return 3;
         }
      else if(p.coef2 != 0){
            return 2;
         }
      else if(p.coef1 != 0){
            return 1;
         }
      else{
         return 0;
      }
   }

         

}


/* Soma dois polinomios */
/* Entrada: os dois polinomios que deverao ser somados */ 
/* Saida: um novo polinomio resultado da soma dos dois polinomios de entrada */ 
t_Polinomio somaPolinomios (t_Polinomio p1, t_Polinomio p2){


   
   t_Polinomio resultado;

   //soma todos os coeficientes, mantendo atribuindo zero ao resultado da soma de dois coeficientes correspondentes de cada polinomio que estão zerados.
   
   resultado.coef0 = p1.coef0 + p2.coef0;
   resultado.coef1 = p1.coef1 + p2.coef1;
   resultado.coef2 = p1.coef2 + p2.coef2;
   resultado.coef3 = p1.coef3 + p2.coef3;
   resultado.coef4 = p1.coef4 + p2.coef4;
   resultado.coef5 = p1.coef5 + p2.coef5;
   resultado.coef6 = p1.coef6 + p2.coef6;
   resultado.coef7 = p1.coef7 + p2.coef7;
   resultado.coef8 = p1.coef8 + p2.coef8;
   resultado.coef9 = p1.coef9 + p2.coef9;

   return resultado;

   }

/* Calcula o valor do polinomio para um dado valor da variavel */
/* Entrada: um polinomio e um valor para a variavel */ 
/* Saida: o valor do polinomio para o valor dado da variavel */ 
float calculaPolinomio(t_Polinomio p, float x){ 

  //gera o valor de x correspondente a potencia do coeficiente 
   float x2 = x*x;
   float x3 = x2 * x;
   float x4 = x3 * x;
   float x5 = x2 * x3;
   float x6 = x2 * x4;
   float x7 = x5 * x2;
   float x8 = x6 * x2;
   float x9 = x8 * x;

   //soma todos os monomios com os respectivos valores de x assumidos  
   float valor = (p.coef9 * x9 + p.coef8 * x8 + p.coef7 * x7 + p.coef6 * x6 + p.coef5 * x5 + p.coef4 * x4 + p.coef3 * x3 + p.coef2 * x2 + p.coef1 * x + p.coef0 ); 
   return valor;

}


/* Calcula as raizes reais de um polinomio de grau 2 */
/* Entrada: um polinomio de grau 2 */ 
/* Saida: as raizes reais do polinomio de entrada */ 
struct s_Raizes raizesPolinomioGrau2 (t_Polinomio p){

	struct s_Raizes r;
 	r.raiz1 = 0;
	r.raiz2 = 0;
	float delta = 0;

	delta = ((p.coef1 * p.coef1) - (4* p.coef2 * p.coef0));
   	if(delta < 0){
      		printf("Raízes imaginárias");
      		return r;
		//se o delta for negativo, imprime uma mensagem e retorna as raizes zeradas 
   	}
   	else if(delta>0){
   	 	r.raiz1 = ((-p.coef1 + (sqrt(delta)))/(2*p.coef2));
   	 	r.raiz2 = ((-p.coef1 - (sqrt(delta)))/(2*p.coef2)); 	
	   	return r;
   	}
   	else{
      		r.raiz1 = -p.coef1/(2*p.coef2);
       		r.raiz2= r.raiz1;
      		return  r;
   }
}

/* Calcula a derivada de um polinomio */
/* Entrada: um polinomio */ 
/* Saida: o polinomio que corresponde aa derivada do polinomio de entrada */ 
t_Polinomio derivaPolinomio (t_Polinomio p){


   if(p.coef9 !=0){
      p.coef9 = 9*p.coef9;
      printf(" %.1f%c^8", p.coef9, p.variavel);
    }
   if(p.coef8 !=0){
      p.coef8 = 8*p.coef8;
      printf(" %.1f%c^7", p.coef8, p.variavel);
   }
   if(p.coef7 !=0){
      p.coef7 = 7*p.coef7;
      printf(" %.1f%c^6", p.coef7, p.variavel);
   }
   if(p.coef6 !=0){
      p.coef6 = 6*p.coef6;
      printf(" %.1f%c^5", p.coef6, p.variavel);
   }
   if(p.coef5 !=0){
      p.coef5 = 5*p.coef5;
      printf(" %.1f%c^4", p.coef5, p.variavel);
   }
   if(p.coef4 !=0){
      p.coef4 = 4*p.coef4;
      printf(" %.1f%c^3", p.coef4, p.variavel);
   }
   if(p.coef3 !=0){
      p.coef3 = 3*p.coef3;
      printf(" %.1f%c^2", p.coef3, p.variavel);
   }
   if(p.coef2 !=0){
      p.coef2 = 2*p.coef2;
      printf(" %.1f%c^", p.coef2, p.variavel);
   }
   if(p.coef1 !=0){
      p.coef1 = 1*p.coef1;
      printf(" %.1f", p.coef1);
   }
   if(p.coef0 !=0){
      printf("0.0");
   }

   return p;

}


/* Calcula os termos nao-constantes da integral indefinida de um polinomio */
/* Entrada: um polinomio de grau maximo 8 */ 
/* Saida: o polinomio com os termos nÃ£o-constantes da integral indefinida do polinomio de entrada */ 
t_Polinomio integraPolinomio (t_Polinomio p){

   if(p.coef8 !=0){
      p.coef8 = (p.coef8)/9;
      printf(" %.1f%c^9", p.coef8, p.variavel);
   }
   if(p.coef7 !=0){
      p.coef7 = (p.coef7)/8;
      printf(" %.1f%c^8", p.coef7, p.variavel);
   }
   if(p.coef6 !=0){
      p.coef6 = (p.coef6)/7;
      printf(" %.1f%c^7", p.coef6, p.variavel);
   }
   if(p.coef5 !=0){
      p.coef5 = (p.coef5)/6;
      printf(" %.1f%c^6", p.coef5, p.variavel);
   }
   if(p.coef4 !=0){
      p.coef4 = (p.coef4)/5;
      printf(" %.1f%c^5", p.coef4, p.variavel);
   }
   if(p.coef3 !=0){
      p.coef3 = (p.coef3)/4;
      printf(" %.1f%c^4", p.coef3, p.variavel);
   }
   if(p.coef2 !=0){
      p.coef2 = (p.coef2)/3;
      printf(" %.1f%c^3", p.coef2, p.variavel);
   }
   if(p.coef1 !=0){
      p.coef1 = (p.coef1)/2;
      printf(" %.1f%c^2", p.coef1, p.variavel);
   }
   if(p.coef0 !=0){
      p.coef0 = (p.coef0);
      printf(" %.1f%c", p.coef1, p.variavel);
   }

   return p;

}
