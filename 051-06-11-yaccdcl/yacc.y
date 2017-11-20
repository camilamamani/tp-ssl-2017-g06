/*dcl yacc
 *Equipo 06
 *20/11/17
*/

%{
#include <stdio.h>
#define MAXTOKEN 100
#define YYSTYPE const char*

char name[MAXTOKEN];
char out[1000];
%}

%token END
%token PARENS
%token BRACKETS
%token NAME

%%
loop: statement
    | loop statement
    ;
    
statement: NAME dcl END	{printf("%s: %s %s", name, out, $1); out[0] = '\0';}
	;
	
dcl: asterisco dirdcl
    ;

asterisco: 
	| '*'			{strcat(out, " apuntador a");}
	| asterisco '*'		{strcat(out, " apuntador a");}
	;

dirdcl: NAME 			{strcpy(name, $1);}
	| '(' dcl ')' 
	| dirdcl PARENS		{strcat(out, " funcion que regresa");}
	| dirdcl BRACKETS	{strcat(out, " arreglo");
				 strcat(out, $2);
				 strcat(out, " de ");}
	;
%%

int main(){
	yyparse();
	return 0;
}
