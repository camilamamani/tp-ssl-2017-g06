/*dcl yacc
 *Equipo 06
 *15/11/17
*/

%{
#include <stdio.h>
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

%%
loop: statement
    | loop statement
    ;
    
statement: NAME dcl END
	;
	
dcl: asterisco dirdcl
    ;

asterisco: 
	| '*'	
	| asterisco '*'
	;

dirdcl: NAME 	
	| '(' dcl ')' 
	| dirdcl PARENS		
	| dirdcl BRACKETS	
	;
%%

int main(){
	out[0] = '\0';
	yyparse();
	return 0;
}
