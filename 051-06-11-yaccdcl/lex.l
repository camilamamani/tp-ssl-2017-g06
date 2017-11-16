%option noyywrap
%{
#include "yacc.tab.h"
%}

VARNAME [a-zA-Z]+[a-zA-Z0-9]*

%%
[ \t]			    ;
\(\)			    {	
					      yylval = *yytext;
					      return PARENS;}
\(				    {
					      yylval = *yytext;
					      return '(';}
\[[0-9]*\]		{
					      yylval = *yytext;
					      return BRACKETS;}
{VARNAME}		  {
                yylval = *yytext;
                return NAME;}
\n 				    {
                yylval = *yytext;
                return END;}	
.				      {	return *yytext;}
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
