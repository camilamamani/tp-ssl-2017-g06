#include "StackOfDoublesModule.h"
#include <stdio.h>
#define MAXVAL 50 


static StackItem stack[MAXVAL]; 

 int sp=0;


StackItem pop(void){
	if(!isEmpty())
	    {
	    	sp--;
	    	return *(stack+sp); 
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
