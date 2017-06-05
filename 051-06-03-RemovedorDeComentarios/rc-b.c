/*Remueve Comentarios
 *Implementación B
 *Equipo 06
 *20170506
 */
#include <stdio.h>
int c, cAnterior;
enum caracteres {
	APOSTROFE = 39,
	COMILLAS = 34,
	LF = 10,
	CONTRABARRA=92
};

int main(){
	
	goto codigoSinComentarios;
	
	codigoSinComentarios: {

		switch(c = getchar()){
			case '/':
				goto barra1;
			case COMILLAS:
				putchar(c);
				goto cadena;
			case APOSTROFE:
				putchar(c);
				goto caracter;
			case EOF:
				return 0;
			default:
				putchar(c);
				goto codigoSinComentarios;
		}
	}

	barra1: {
		c = getchar();
		switch(c){
			case '/':
				goto barra2;
			case '*':
				goto asterisco;
			case EOF:
				return;
			default:
				putchar(c);
				goto codigoSinComentarios;
		}
		
	}

	barra2: {
		c = getchar();
		switch(c){
			case LF:
				putchar(c);
				goto codigoSinComentarios;
			case EOF:
				break;
			default:
				goto barra2;
		}
	}

	asterisco: {
		c = getchar();
		switch(c){
			case '*':
				goto asteriscosPalabras;
			case EOF:
				break;
			default:
				goto asterisco;
		}
	}

	asteriscosPalabras: {
		cAnterior = c;
		c = getchar();
		switch(c){
			case '/':
				if(cAnterior == '*'){
					putchar(' ');
					goto codigoSinComentarios;
				}
				else{
					goto asteriscosPalabras;
				}
			case EOF:
				break;
			default:
				goto asteriscosPalabras;
		}
	}
	caracter: {
		c = getchar();
		switch(c){
			case CONTRABARRA:
				putchar(c);
				goto escapeCaracter;
			case APOSTROFE:
				putchar(c);
				goto codigoSinComentarios;
			case EOF:
				break;
			default:
				putchar(c);
				goto caracter;
		}
	}
	escapeCaracter: {
		c= getchar();
		switch(c){
			case EOF:
				break;
			default: 
				putchar(c);
				goto caracter;
		}
	}
	cadena: {
		c = getchar();
		switch(c){
			case CONTRABARRA:
				putchar(c);
				goto escapeCadena;
			case COMILLAS:
				putchar(c);
				goto codigoSinComentarios;
			case EOF:
				break;
			default:
				putchar(c);
				goto cadena;
		}
	}
	escapeCadena: {
		c= getchar();
		switch(c){
			case EOF:
				break;
			default: 
				putchar(c);
				goto caracter;
		}
	}

	return 0;
	
}