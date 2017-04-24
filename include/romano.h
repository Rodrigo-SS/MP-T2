#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

//função para testar se o usuario digitou letras nao validas
int letras_diferentes(char *);

//funcao para excluir os numeros invalidos que possuem 4 letras iguais
int quatro_letras(char *);

//funcao para excluir numeros que tenham dois V, L ou D
int casos_duplos(char *);

//verifica se ha letras com valores maiores depois de letras com valores menores
//que nao seja IX, XL, XC 
int verificacao(char *);

//transforma o numero romano em arabico
void arabico(int *, int);

//detecta casos especiais como XLX, CDC, VIX, etc
int casos_especiais(char *);