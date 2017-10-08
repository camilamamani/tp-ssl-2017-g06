 /* dcl.c
  * Equipo 06
  * 02/09/2017
  */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h" 

extern int yylex(void);
extern char *yytext;

int main(){
	while(GetToken() != EOF){
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();

		if(tokentype != END)
			printf("Error de sintaxis\n");
		
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

int GetToken(){
	int c;
	char *p = token;

	if((tokentype = yylex()) == 0){
		return EOF;
	}
	else{
		strcpy(token, yytext);
		return tokentype;
	}
}	

/* dcl: reconoce una declaración */
void dcl(){
	int ns;
	for(ns = 0; GetToken() == '*';)
		ns++;
	dirdcl();
	while(ns-- > 0)
		strcat(out, "apuntador a ");
}

/* dirdcl: reconoce un declarador directo */
void dirdcl(){
	int type;

	if(tokentype == '('){
		dcl();
		if(tokentype != ')')			
			printf("error: falta )\n");
		
	}else if(tokentype == NAME){
		strcpy(name, token);
	}else
		printf("error: nombre o (dcl) esperado\n");
		

	//if(GetToken() != END){//Para que no pida de más
		while((type= GetToken()) == PARENS || type == BRACKETS){
			if(type == PARENS)
				strcat(out, "funcion que regresa");
			else{
				strcat(out, " arreglo");
				strcat(out, token);
				strcat(out, "de");
			}
		}
	//}
}



















