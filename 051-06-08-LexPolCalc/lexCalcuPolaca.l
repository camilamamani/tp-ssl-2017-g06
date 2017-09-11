%option noyywrap
%{
#include <stdio.h>
#include "scanner.h"
%}

NUMBER [0-9]+([\.][0-9]+)?

%%
{NUMBER}	{return Number;}
[ \t]			;
\+			{return Addition;}
\-			{return Substraction;}
\*			{return Multiplication;}
\/			{return Division;}
\n 			{return PopResult;}
.			{return LexError;}
%%
