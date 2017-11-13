/*dcl yacc
 *Equipo 06
 *12/11/17
*/

%{
#include <stdio.h>
#include <string.h>
#define MAXTOKEN 100
#define YYSTYPE const char*

char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
%}

%token END
%token PARENS
%token BRACKETS
%token NAME
%token CADENA

%%

statement: END
		| dcl END 		{printf("%s: %s %s\n", name, out, datatype);}
		;

dcl: asterisco dirdcl		{putchar('s');}	
    | CADENA                {strcpy(datatype, $1);} 
    ;

asterisco: '*'				{strcat(out, " apuntador a");} 
		| asterisco '*'
		| /*vacio*/
		;

dirdcl: NAME 			{strcpy(name, $1);}
	| '(' dcl ')' 
	| dirdcl PARENS		{strcat(out, " funcion que regresa");}
	| dirdcl BRACKETS	{
						strcat(out, " arreglo");
						strcat(out, $2);
						strcat(out, " de ");}
	;
%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}

