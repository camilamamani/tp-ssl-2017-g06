%option noyywrap
%{
#include "dcl.h"
%}

VARNAME [a-zA-Z]+[a-zA-Z0-9]*

%%
[ \t]			;
\(\)			{return PARENS;}
\(				{return '(';}
\[[0-9]*\]		{return BRACKETS;}
{VARNAME}		{return NAME;}
\n 				{return END;}	
.				{return *yytext;}
%%
