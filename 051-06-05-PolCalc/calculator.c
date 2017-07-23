 /* calculator.c
  * CALCULADORA POLACA
  * Equipo 06
  * 22/07/2017
  */
#include <stdio.h>
#include "scanner.h"
#include "stackOfDoublesModule.h"

int main(void){

	double op2;
	Token dato;
	Token *t;
	t = &dato; 

	while ((GetNextToken(t)) != EOF) {
	 	switch (t->type) {
			 case Number:
			 	push(t->val);
			 	break;			
			 case Addition:
			 	push(pop() + pop());
			 	break;
			 case Multiplication:
			 	push(pop() * pop());
			 	break;
			 case Substraction:
				 op2 = pop();
				 push(pop() - op2);
			 	break;
			 case Division:
				 op2 = pop();
				 if (op2 != 0.0)
				 	push(pop() / op2);
				 else
				 	printf("error: zero divisor\n");
				 break;
			 case PopResult:
			 	printf("Resultado: %.2f \n", pop());
			 	break;		
			 default:
			 	printf("Invalido lexema %c \n",t->errorLexema);
			 	break;
		}
	}

	return 0;
}