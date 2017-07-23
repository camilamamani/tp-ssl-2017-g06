 /* scanner.c
  * Equipo 06
  * 22/07/2017
  */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "scanner.h"

/*
◦ Qué hace: Obtiene operadores y operandos.
◦ Qué usa:
	▪ Biblioteca Estándar
		• getcar
		• EOF
		• isdigit
		• ungetc
◦ Qué exporta:
		
◦	GetNextToken
◦	Token
◦	TokenType
◦	TokenValue

*/

#define MAXTOKEN 100

char lexeme[MAXTOKEN];

int GetNextToken(Token *t){ 
	int c,i;
	TokenType tipo;
	TokenValue valor;

	while ((lexeme[0] = c = getchar()) == ' ' || c == '\t')
		;

	lexeme[1] = '\0';

	if (!isdigit(c) && c != '.'){ 
		
		switch (c) {
				case EOF:
					return EOF;
				case Addition :
					tipo = Addition;
					break;
				case Multiplication :
					tipo = Multiplication;
					break;
				case Substraction :
					tipo = Substraction;
					break;
				case Division :
					tipo = Division;
					break;
				case PopResult :
					tipo = PopResult;
					break;
				default :
					tipo = LexError;
					t->errorLexema= c;
					break;
		}

	}
	else {
		i = 0;
		if (isdigit(c)){
	 		while ( isdigit ( lexeme[++i] = c = getchar() ) )
	 		;

		}
		
		if (c == '.'){ 
			while (isdigit(lexeme[++i] = c = getchar()))
	 			;
	 	}
		lexeme[i] = '\0';

		if (c != EOF)
			ungetc(c,stdin);

		tipo = Number;
		valor = atof(lexeme);

	}	
	
	t->type = tipo;
	t->val = valor;
	return 0;
}


