%{
#include <stdio.h>
int addition, substraction, multiplication,division, lexerror, number, popResult;
%}
%%
[0-9]+([\.][0-9]+)?	{++number;}
\+	{++addition;}
\-	{++substraction;}
\*	{++multiplication;}
\/	{++division;}
\n	{++popResult;)
.|\t	{++lexerror; }
%%
int main(void){
	yylex();
	printf("addition:%d, substraction:%d multiplication:%d division:%d lexerror:%d number:%d popResult:%d",addition, substraction, multiplication, division, lexerror, number,popResult);
	return 0;
}
