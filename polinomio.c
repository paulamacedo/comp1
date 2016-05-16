/*
Define o TAD polinomio e um conjunto de operacoes sobre polinomios.
*/

//Definicao do tipo t_Polinomio
typedef struct {
   float coef0, coef1, coef2, coef3, coef4, coef5, coef6, coef7, coef8, coef9;
   char variavel; //exemplo 'x', 'y', 'a'
} t_Polinomio;


//Definicao da estrutura de dados para armazenar as raizes de um polinomio de grau 2
struct s_Raizes {
   float raiz1, raiz2;
};



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
	char expressao[256];
	int numero = 0;
	t_Polinomio pol;
	scanf("%s", expressao);
	while(expressao!='='){
		scanf("%c",&expressao);
		if ((expressao!='+')&&(expressao!='-')&&(expressao!=' ') &&(expressao!='=')){
					numero= numero*10+expressao-48;
						
	}
	
	return pol;

}

/* Imprime um polinomio na tela usando o formato <sinal><coeficiente><variavel><potencia> */ 
/* Entrada: um polinomio */ 
/* Saida: polinomio impresso na tela */ 
/* Descricao: Deverao ser omitidos a potencia '1', a variavel com potencia '0', os termos com coeficiente '0'
   e o sinal '+' do primeiro termo.
   Exemplo: 2.0y^7 - 25.0y^3 + 0.3^y - 1 */
void imprimePolinomio (t_Polinomio p);


/* Altera um termo de um polinomio */
/* Entrada: um polinomio, a potencia do termo, o novo coeficiente do termo */ 
/* Saida: o polinomio de entrada com o termo da potencia indicada alterado */ 
t_Polinomio alteraPolinomio (t_Polinomio p, unsigned short int potencia, float novoCoef);


/* Encontra o grau de um polinomio */
/* Entrada: um polinomio */ 
/* Saida: o grau do polinomio de entrada (maior potencia) */ 
unsigned short int grauPolinomio (t_Polinomio p);


/* Soma dois polinomios */
/* Entrada: os dois polinomios que deverao ser somados */ 
/* Saida: um novo polinomio resultado da soma dos dois polinomios de entrada */ 
t_Polinomio somaPolinomios (t_Polinomio p1, t_Polinomio p2);


/* Calcula o valor do polinomio para um dado valor da variavel */
/* Entrada: um polinomio e um valor para a variavel */ 
/* Saida: o valor do polinomio para o valor dado da variavel */ 
float calculaPolinomio(t_Polinomio p, float x);


/* Calcula as raizes reais de um polinomio de grau 2 */
/* Entrada: um polinomio de grau 2 */ 
/* Saida: as raizes reais do polinomio de entrada */ 
struct s_Raizes raizesPolinomioGrau2 (t_Polinomio p);


/* Calcula a derivada de um polinomio */
/* Entrada: um polinomio */ 
/* Saida: o polinomio que corresponde aa derivada do polinomio de entrada */ 
t_Polinomio derivaPolinomio (t_Polinomio p);


/* Calcula os termos nao-constantes da integral indefinida de um polinomio */
/* Entrada: um polinomio de grau maximo 8 */ 
/* Saida: o polinomio com os termos nÃ£o-constantes da integral indefinida do polinomio de entrada */ 
t_Polinomio integraPolinomio (t_Polinomio p);
