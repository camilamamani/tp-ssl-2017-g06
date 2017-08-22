 /* StackOfCharsModule.c
  * Equipo 06
  * 02/07/2017
  */

#include "StackOfCharsModule.h"
#define MAXVAL 50 ///* maximum depth of val stack */

 static StackItem stack[MAXVAL]; 

 int sp=0;

//sacar if y establecer precondicion pila no nula?
StackItem pop(void){
	if( !isEmpty() ){
	    	sp--;
	    	return *(stack+sp); 
	}
	return 0;//desapareceria si establecemos precondicion
}

void push(StackItem oneItem){
	//if ( sp = 0 ) { *(stack + sp) = '$'; sp++}  
	*(stack + sp) = oneItem;
	 sp++;
}

void pushString(char* s){
	for( ; *s; ++s)
		push(*s);
}

//reemplazar int por "bool"? c99 lo posee (stdbool.h), no aparece como bibliotecas a usar en el enunciado.
int isEmpty(void){
	return (sp == 0);
	//return (sp == '$');
}


int isFull(void){
	return (sp >= MAXVAL);
}
