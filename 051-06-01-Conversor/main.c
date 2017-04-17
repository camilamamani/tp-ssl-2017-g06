 /* main.c
  * Conversor de Temperaturas
  * Equipo 06
  * 16/04/2017
  */
#include <stdio.h>
#include "conversor.h"

int main(void){
	const int LOWER =	0; /* lower limit of table */
	const int UPPER =	300; /* upper limit */
	const int STEP 	=	20;
	int fahr;
	
	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, fahrToCels(fahr));
	return 0;
}
