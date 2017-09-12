#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "scanner.h"

extern int yylex(void);
extern char *yytext;

int GetNextToken(Token *t){ 
	
	if((t->type = yylex()) == 0){
		return EOF;
	}
	else{
		if (t->type == LexError){
			t->errorLexema= *yytext;
		}
		else{
			t->val = atof(yytext);
		}
	}
	return 0;
}





