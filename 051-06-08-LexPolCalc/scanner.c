#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "scanner.h"

extern int yylex(void);
extern char *yytext;

int GetNextToken(Token *t){ 
	printf(">> %d <<", yylex());
	printf("-- %s --", yytext);
	/*
	if(t->type = yylex() == 0){
		putchar('0');
		return EOF;
	}
	else{
		putchar('1');
		if (t->type == LexError){
			t->errorLexema= *yytext;
		}
		else{
			t->val = atof(yytext);
		}
	}*/
	return 0;
}





