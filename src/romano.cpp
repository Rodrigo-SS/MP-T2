#include <romano.h>

//vetores usados para transformar romano em arabico
char letras[8]={'I','V','X','L','C','D','M','\0'};
int valor[7]={1,5,10,50,100,500,1000}, i=0;

int controller(char * palavra){

int i=0, c;

	while(palavra[i]){
      palavra[i] = toupper(palavra[i]);
      i++;
	}

	c=letras_diferentes(palavra);
	if (c==-1){
		return -1;
	}

	c=quatro_letras(palavra);
	if (c==-1){
		return -1;
	}

	c=casos_duplos(palavra);
	if (c==-1){
		return -1;
	}

	c=casos_especiais(palavra);
	if (c==-1){
		return -1;
	}

	c=verificacao(palavra);
	if (c==-1){
		return -1;
	}

	return c;
}

//função para testar se o usuario digitou letras nao validas
int letras_diferentes(char * palavra){
//procura em cada espaco da string se ha letras diferentes de I, V, X, L, C, D, M
	for(i=0; i<strlen(palavra); i++){
		if(palavra[i]!='I' && palavra[i]!='V' && palavra[i]!='X' && palavra[i]!='L' && palavra[i]!='C' && palavra[i]!='D' && palavra[i]!='M'){
			return -1;
		}
	}

	return 0;
}

//funcao para excluir os numeros invalidos que possuem 4 letras iguais
int quatro_letras(char * palavra){
//verifica se ha quatro letras seguidas iguais
	if(strlen(palavra)>3){
		for(i=0; i<strlen(palavra)-3; i++){
			if(palavra[i]==palavra[i+1] && palavra[i]==palavra[i+2] && palavra[i]==palavra[i+3]){
				return -1;
			}
		}
	}

	return 0;
}

//funcao para excluir numeros que tenham dois V, L ou D
int casos_duplos(char * palavra){
int cont=0;

//procura na string se ha mais de um V
	for(i=0; i<strlen(palavra); i++){
		if(palavra[i]=='V'){
			cont++;
			if(cont==2){
				return -1;
			}
		}
	}

	cont=0;

//procura na string se ha mais de um L
	for(i=0; i<strlen(palavra); i++){
		if(palavra[i]=='L'){
			cont++;
			if(cont==2){
				return -1;
			}
		}
	}

	cont=0;

//procura na string se ha mais de um D
	for(i=0; i<strlen(palavra); i++){
		if(palavra[i]=='D'){
			cont++;
			if(cont==2){
				return -1;
			}
		}
	}

	return 0;	
}

//detecta casos especiais como XLX, CDC, VIX, etc
int casos_especiais(char * palavra){
//procura na string a sequencia especifica para cada caso invalido
	for(i=0; i<strlen(palavra); i++){
		if(palavra[i]=='X' && palavra[i+1]=='C' && palavra[i+2]=='X' || palavra[i]=='X' && palavra[i+1]=='L' && palavra[i+2]=='X' || 
			palavra[i]=='C' && palavra[i+1]=='D' && palavra[i+2]=='C' || palavra[i]=='C' && palavra[i+1]=='M' && palavra[i+2]=='C' || 
			palavra[i]=='V' && palavra[i+1]=='I' && palavra[i+2]=='X'){
			return -1;
		}
	}
return 0;
}

//verifica se ha letras com valores maiores depois de letras com valores menores
//que nao seja IX, XL, XC 
int verificacao(char * palavra){
int j, k=0, tam;
int aux1[30], resultado;

//tam recebe o tamanho da string
tam=strlen(palavra);

//as letras da string sao transformadas em valores e salvas em um vetor de inteiros
//cada letra é relacionada com o vetor de letras e associada ao valor correspodente
	for(i=0; i<tam;	 i++){
		for(j=0; j<8; j++){
			if(palavra[i]==letras[j]){
				aux1[k]=valor[j];
				k++;
			}
		}
	}

//procura no vetor de inteiros os numeros que sao maiores que seus anteriores para palavras com mais de uma letra
//só aceita os valores IV, IX, XL, XC, CD, CM, depois para palavras com 3 numeros procura se as duas primeiras letras sao iguais
//se for maior que 3 para i>0 verifica se o numero anterior é maior que o atual e se o numero duas casas depois é menor que o atual(ex.: MCDII)
//se i tiver na penultima casa verifica se o anterior é maior que o atual(ex.: dcix)
	if(tam>1){
		for(i=0; i<tam-1; i++){
			if(aux1[i+1]>aux1[i]){
				if(aux1[i]==1 && aux1[i+1]==5 || aux1[i]==1 && aux1[i+1]==10 || aux1[i]==10 && aux1[i+1]==50 || 
					aux1[i]==10 && aux1[i+1]==100 || aux1[i]==100 && aux1[i+1]==500 || aux1[i]==100 && aux1[i+1]==1000){
					if(tam=3){
						if(aux1[0]==aux1[1]){
							return -1;
						}
					}else if(tam>3){
						if(i=tam-2){
							if(aux1[i-1]<=aux1[i]){
								return -1;
							}
						}else if(i>0 && i<tam-2){
							if(aux1[i-1]<=aux1[i] || aux1[i]>=aux1[i+2]){
								return -1;
							}
						}
					}
				}else{
					return -1;
				}
			}
		}
	}

	tam=strlen(palavra);
	resultado=arabico(aux1, tam);

	return resultado;
}

//transforma o numero romano em arabico
int arabico(int * aux1, int tam){
int numero=0;	

//cada letra é somada ao numero que incia com zero
//se a letra seguinte for maior que a anterior faz-se a seguinte menos a atual(aux1[i+1]-aux1[i])
	for(i=0; i<tam; i++){
		if(i<tam-1 && aux1[i+1]>aux1[i]){
			numero = numero + (aux1[i+1]-aux1[i]);
			i++;
		}else{
			numero = numero + aux1[i];
		}
	}

	return numero;
}