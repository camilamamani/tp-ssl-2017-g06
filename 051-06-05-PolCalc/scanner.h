 /* scanner.h
  * Equipo 06
  * 02/07/2017
  */
#ifndef SCANNER_H
#define SCANNER_H

/*
Qué exporta:
	▪ GetNextToken
	▪ Token
	▪ TokenType
	▪ TokenValue
*/
enum TokenType {
 Number,
 Addition='+',
 Multiplication='*',
 Substraction='-',
 Division='/',
 PopResult='\n',
 LexError
};

typedef enum TokenType TokenType;
typedef double TokenValue;

struct Token{
 TokenType type;
 TokenValue val;
 char errorLexema;
};

typedef struct Token Token;
int GetNextToken(Token *t);

#endif
