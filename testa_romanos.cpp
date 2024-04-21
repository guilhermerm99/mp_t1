#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "romanos.hpp"

// Teste para verificar a conversão de algarismos romanos únicos.
TEST_CASE( "Numeros romanos - algarismos únicos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("I") == 1 );
    REQUIRE( romanos_para_decimal("V") == 5 );
    REQUIRE( romanos_para_decimal("X") == 10 );
    REQUIRE( romanos_para_decimal("L") == 50 );
    REQUIRE( romanos_para_decimal("C") == 100 );
    REQUIRE( romanos_para_decimal("D") == 500 );
    REQUIRE( romanos_para_decimal("M") == 1000 );
}

// Teste para verificar a conversão de algarismos romanos inválidos.
TEST_CASE( "Numeros romanos - algarismos inválidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("G") == -1 );
    REQUIRE( romanos_para_decimal("i") == -1 );
    REQUIRE( romanos_para_decimal("1") == -1 );
    REQUIRE( romanos_para_decimal("@") == -1 );
}

 // Teste para verificar a conversão de números romanos válidos.
TEST_CASE( "Numeros romanos - números válidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("IV") == 4 );
    REQUIRE( romanos_para_decimal("IX") == 9 );
    REQUIRE( romanos_para_decimal("LVIII") == 58 );
    REQUIRE( romanos_para_decimal("MCMXCIV") == 1994 );
}

// Teste para verificar a conversão de números romanos com subtração.
TEST_CASE( "Numeros romanos - números com subtração", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("IV") == 4 );
    REQUIRE( romanos_para_decimal("IX") == 9 );
    REQUIRE( romanos_para_decimal("XL") == 40 );
    REQUIRE( romanos_para_decimal("XC") == 90 );
    REQUIRE( romanos_para_decimal("CD") == 400 );
    REQUIRE( romanos_para_decimal("CM") == 900 );
}

// Teste para verificar a conversão de números romanos com adição.
TEST_CASE( "Numeros romanos - números com adição", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("III") == 3 );
    REQUIRE( romanos_para_decimal("VII") == 7 );
    REQUIRE( romanos_para_decimal("XV") == 15 );
    REQUIRE( romanos_para_decimal("LX") == 60 );
    REQUIRE( romanos_para_decimal("DCCC") == 800 );
    REQUIRE( romanos_para_decimal("MM") == 2000 );
}

// Teste para verificar a conversão de números romanos complexos.
TEST_CASE( "Numeros romanos - números complexos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("MCMXCVI") == 1996 );
    REQUIRE( romanos_para_decimal("MMXXIV") == 2024 );
    REQUIRE( romanos_para_decimal("DCCVII") == 707 );
    REQUIRE( romanos_para_decimal("CDXLIV") == 444 );
    REQUIRE( romanos_para_decimal("CMXCIX") == 999 );
}

// Teste para verificar a conversão de strings vazias e nulas.
TEST_CASE( "Numeros romanos - strings vazias e nulas", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("") == 0 ); // String vazia
}

// Teste para verificar a conversão de números romanos com caracteres inválidos.
TEST_CASE( "Numeros romanos - números com caracteres inválidos", "[romanos]" ) {
    REQUIRE( romanos_para_decimal("A") == -1 ); // Caractere inválido
}