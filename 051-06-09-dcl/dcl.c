 /* dcl.c
  * Equipo 06
  * 02/09/2017
  */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dcl.h"

int main(){
	while(gettoken() != EOF){
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();

		if(tokentype != '\n')
			printf("error de sintaxis\n");
		
		printf("%s: %s %s\n", name, out, datatype);
	}
	return 0;
}

int GetToken(){
	int c;
	char *p = token;

	while((c = getchar()) == ' ' || c == '\t')
		;

	if(c == '('){
		if((c = getchar()) == ')'){
			strcpy(token, "()");
			return tokentype = PARENS;
		}else{
			ungetc(c, stdin);
			return tokentype ='(';
		}
	}else if (c=='['){
		for(*p++ = c;(*p++ = getchar()) != ']';)
			;
		
		*p='\0';
		return tokentype = BRACKETS; 

	} else if (isalpha(c)){
		for(*p++ = c; isalnum(c = getchar());)
			*p++ = c;
		
		*p='\0';
		ungetc(c, stdin);
		return tokentype = NAME;
	} else
		return tokentype = c;
}	

/* dcl: reconoce una declaración */
void dcl(){
	int ns;
	for(ns = 0; gettoken() == '*';)
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
	}else if(tokentype == NAME)
		strcpy(name, token);
	else
		printf("error: nombre o (dcl) esperado\n");

	while((type=gettoken()) == PARENS || type == BRACKETS){
		if(type == PARENS)
			strcat(out, "funcion que regresa");
		else{
			strcat(out, " arreglo");
			strcat(out, token);
			strcat(out, "de");
		}
	}
}