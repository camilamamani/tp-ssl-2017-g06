%{
#include <stdio.h>
int addition, substraction, multiplication,division, lexerror, number;
%}
%%
[0-9]+((\.[0-9]+)?)	{++number;}
\+	{++addition;}
\-	{++substraction;}
\*	{++multiplication;}
\/	{++division;}
.|\t	{++lexerror; }
%%
int main(void){
	yylex();
	printf("addition:%d, substraction:%d multiplication:%d division:%d lexerror:%d number:%d",addition, substraction, multiplication, division, lexerror, number);
	return 0;
}
