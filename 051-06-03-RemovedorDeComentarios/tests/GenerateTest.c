/* Generador de archivos de prueba de volumen para removedor de comentarios
 * Se generan 3 archivos:  testKilo.c de 1Kb., testMega.c de 1Mb. y testGiga.c de 1Gb.
 *Equipo 06
 *20170603
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void crearArchivo(char * nombreArchivo, char volumen){
	FILE *fp;
	int i, lim, randomCaracter, randomOperador;
	srand(time(NULL)); 
    
	switch(volumen){
		case 'k':
			lim = pow(2,10-3);
			break;
		case 'm':
			lim = pow(2,20-1);
			break;
		case 'g':
			lim = pow(2,30-1);
			break;
		default:
			lim = 0;
			break;
	}

	fp = fopen(nombreArchivo,"w");
	
	if (fp != NULL){
		for (i = 0 ; i < lim ; i++) {
			randomCaracter = (rand() % 78) + 48;
			randomOperador = (rand() % 16) + 32;
			fputc(randomCaracter, fp);
			fputc(randomOperador, fp);
		}
	}

	fclose(fp);
}
	
int main(){

	crearArchivo("testKilo.c",'k');
	crearArchivo("testMega.c",'m');
	crearArchivo("testGiga.c",'g');
	return 0;
}
