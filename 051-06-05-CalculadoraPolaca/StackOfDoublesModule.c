#include "StackOfDoublesModule.h"
#define MAXVAL 50 ///* maximum depth of val stack */

 static StackItem stack[MAXVAL]; 

 int sp=0;

//sacar if y establecer precondicion pila no nula?
StackItem pop(void){
	if(!isEmpty())
	    {
	    	sp--;
	    	return printf("%f\n",*(stack+sp)); 
	    }
		else
	    {
	     printf("\nStack Empty\n");
		}
	return 0;
}

void push(StackItem oneItem){
	*(stack + sp) = oneItem;
	 sp++;
}


int isEmpty(void){
	return (sp == 0);
}


int isFull(void){
	return (sp >= MAXVAL);
}
