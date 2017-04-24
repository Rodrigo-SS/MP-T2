#include <gtest/gtest.h>
#include <romano.h>

// int main(int argc, char const *argv[])
// {
// char palavra[30];
// int i=0, c;
	
// 	printf("Digite um numero romano: ");
// 	scanf("%s", palavra);

// 	while(palavra[i]){
//       palavra[i] = toupper(palavra[i]);
//       i++;
// 	}

// 	c=letras_diferentes(palavra);
// 	if (c==-1){
// 		printf("Numero invalido!\n");
// 		exit(0);
// 	}

// 	c=quatro_letras(palavra);
// 	if (c==-1){
// 		printf("Sera\n");
// 		printf("Numero invalido!\n");
// 		exit(0);
// 	}

// 	c=casos_duplos(palavra);
// 	if (c==-1){
// 		printf("Numero invalido!\n");
// 		exit(0);
// 	}

// 	c=casos_especiais(palavra);
// 	if (c==-1){
// 		printf("Numero invalido!\n");
// 		exit(0);
// 	}

// 	c=verificacao(palavra);
// 	if (c==-1){
// 		printf("Numero invalido!\n");
// 		exit(0);
// 	}

// 	return 0;
// }

//Testa os Numeros basicos 
TEST(RomanTest, Letras){
	EXPECT_EQ(0, letras_diferentes((char*)"I"));
	EXPECT_EQ(0, letras_diferentes((char*)"V"));
	EXPECT_EQ(0, letras_diferentes((char*)"X"));
	EXPECT_EQ(-1, letras_diferentes((char*)"s"));
	EXPECT_EQ(-1, letras_diferentes((char*)"t"));
	EXPECT_EQ(-1, letras_diferentes((char*)"R"));
}

// TEST(RomanTest, quatro){
// 	EXPECT_EQ(0, quatro_letras((char*)"XVII"));
// 	EXPECT_EQ(0, quatro_letras((char*)"III"));
// 	EXPECT_EQ(0, quatro_letras((char*)"CCC"));
// 	EXPECT_EQ(-1, quatro_letras((char*)"IIII"));
// 	EXPECT_EQ(-1, quatro_letras((char*)"VVVV"));
// 	EXPECT_EQ(-1, quatro_letras((char*)"CCCC"));
// }

// TEST(RomanTest, Letras){
// 	EXPECT_EQ(0, letras_diferentes((char*)"I"));
// 	EXPECT_EQ(0, letras_diferentes((char*)"V"));
// 	EXPECT_EQ(0, letras_diferentes((char*)"X"));
// 	EXPECT_EQ(-1, letras_diferentes((char*)"s"));
// 	EXPECT_EQ(-1, letras_diferentes((char*)"t"));
// 	EXPECT_EQ(-1, letras_diferentes((char*)"R"));
// }

// TEST(RomanTest, Letras){
// 	EXPECT_EQ(0, letras_diferentes((char*)"I"));
// 	EXPECT_EQ(0, letras_diferentes((char*)"V"));
// 	EXPECT_EQ(0, letras_diferentes((char*)"X"));
// 	EXPECT_EQ(-1, letras_diferentes((char*)"s"));
// 	EXPECT_EQ(-1, letras_diferentes((char*)"t"));
// 	EXPECT_EQ(-1, letras_diferentes((char*)"R"));
// }

