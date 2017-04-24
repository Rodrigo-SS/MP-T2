#include <gtest/gtest.h>
#include <romano.h>

char palavra[30];

//Testa as letras romanas
TEST(RomanTest, Letras){
	EXPECT_EQ(0, letras_diferentes((char*)"I"));
	EXPECT_EQ(0, letras_diferentes((char*)"III"));
	EXPECT_EQ(0, letras_diferentes((char*)"XII"));
	EXPECT_EQ(-1, letras_diferentes((char*)"S"));
	EXPECT_EQ(-1, letras_diferentes((char*)"vit"));
	EXPECT_EQ(-1, letras_diferentes((char*)"DCU"));
}

//testa se há quatro letras iguais
TEST(RomanTest, Quatro){
	EXPECT_EQ(0, quatro_letras((char*)"XVII"));
	EXPECT_EQ(0, quatro_letras((char*)"III"));
	EXPECT_EQ(0, quatro_letras((char*)"CCC"));
	EXPECT_EQ(-1, quatro_letras((char*)"DCIIII"));
	EXPECT_EQ(-1, quatro_letras((char*)"VVVV"));
	EXPECT_EQ(-1, quatro_letras((char*)"CCCC"));
}

// //testa se ha duplicidade
// TEST(RomanTest, Duplicidade){
// 	EXPECT_EQ(0, casos_duplos((char*)"III"));
// 	EXPECT_EQ(0, casos_duplos((char*)"XLII"));
// 	EXPECT_EQ(0, casos_duplos((char*)"MMDCXXXIII"));
// 	EXPECT_EQ(-1, casos_duplos((char*)"VVI"));
// 	EXPECT_EQ(-1, casos_duplos((char*)"LLVII"));
// 	EXPECT_EQ(-1, casos_duplos((char*)"DDXL"));
// }

// //testa as funçoes de verificacao e arabico
// TEST(RomanTest, Verificacao_e_Arabico){
// 	EXPECT_EQ(190, verificacao((char*)"CXC"));
// 	EXPECT_EQ(1919, verificacao((char*)"MCMXIX"));
// 	EXPECT_EQ(999, verificacao((char*)"CMXCIX"));
// 	EXPECT_EQ(-1, verificacao((char*)"IIV"));
// 	EXPECT_EQ(-1, verificacao((char*)"DCVLMI"));
// 	EXPECT_EQ(-1, verificacao((char*)"MMCDDI"));
// }

// //testa os casos especiais que sao invalidos(ex.: XLX, XCX, CDC, CMC, VIX)
// TEST(RomanTest, Casos_especiais){
// 	EXPECT_EQ(0, casos_especiais((char*)"CXC"));
// 	EXPECT_EQ(0, casos_especiais((char*)"XIX"));
// 	EXPECT_EQ(0, casos_especiais((char*)"MCM"));
// 	EXPECT_EQ(-1, casos_especiais((char*)"VIX"));
// 	EXPECT_EQ(-1, casos_especiais((char*)"XCX"));
// 	EXPECT_EQ(-1, casos_especiais((char*)"CDC"));
// }

// //resultado final dos numeros romanos
// TEST(RomanTest, Resultado){
// 	EXPECT_EQ(1677, controller((char*)"mdclxxvii"));
// 	EXPECT_EQ(1999, controller((char*)"mcmXCIX"));
// 	EXPECT_EQ(642, controller((char*)"dcxlii"));
// 	EXPECT_EQ(-1, controller((char*)"iiv"));
// 	EXPECT_EQ(-1, controller((char*)"dcti"));
// 	EXPECT_EQ(-1, controller((char*)"mmmmdc"));
// }

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
