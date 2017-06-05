/*Remueve Comentarios
 *Implementación A
 *Equipo 06
 *20170604
 */
#include <stdio.h>
int c, cAnterior;
enum caracteres {
	APOSTROFE = 39,
	COMILLAS = 34,
	LF = 10,
	CONTRABARRA=92
};

void codigoSinComentarios(void);
void barra1(void);
void barra2(void);
void cadena(void);
void escapeCadena(void);
void asterisco(void);
void asteriscosPalabras(void);
void caracter(void);
void escapeCaracter(void);

void codigoSinComentarios(){

	switch(c = getchar()){
		case '/':
			barra1();
			return;
		case COMILLAS:
			putchar(c);
			cadena();
			return;
		case APOSTROFE:
			putchar(c);
			caracter();
			return;
		case EOF:
			return;
		default:
			putchar(c);
			codigoSinComentarios();
			return;
	}
}

void barra1(){
	c = getchar();
	switch(c){
		case '/':
			barra2();
			return;
		case '*':
			asterisco();
			return;
		default:
			putchar(c);
			codigoSinComentarios();
			return;
	}
}

void barra2(){
	c = getchar();
	switch(c){
		case LF:
			putchar(c);
			codigoSinComentarios();
			return;
		case EOF:
			return;
		default:
			barra2();
			return;
	}
}

void asterisco(){
	c = getchar();
	switch(c){
		case '*':
			asteriscosPalabras();
			return;
		case EOF:
			return;
		default:
			asterisco();
			return;
	}
}

void asteriscosPalabras(){
	cAnterior = c;
	c = getchar();
	switch(c){
		case '/':
			if(cAnterior == '*'){
				putchar(' ');
				codigoSinComentarios();
				return;
			}
			else{
				asteriscosPalabras();
				return;
			}
		case EOF:
			return;
		default:
			asteriscosPalabras();
			return;
	}
}

void caracter(){
	c = getchar();
	switch(c){
		case CONTRABARRA:
			putchar(c);
			escapeCaracter();
			return;
		case APOSTROFE:
			putchar(c);
			codigoSinComentarios();
			return;
		case EOF:
			return;
		default:
			putchar(c);
			caracter();
			return;
	}
}

void escapeCaracter(){
	c= getchar();
	switch(c){
		case EOF:
			return;
		default: 
			putchar(c);
			caracter();
			return;
	}
}

void cadena(){
	c = getchar();
	switch(c){
		case CONTRABARRA:
			putchar(c);
			escapeCadena();
			return;
		case COMILLAS:
			putchar(c);
			codigoSinComentarios();
			return;
		case EOF:
			return;
		default:
			putchar(c);
			cadena();
			return;
	}
}
void escapeCadena(){
	c= getchar();
	switch(c){
		case EOF:
			return;
		default: 
			putchar(c);
			cadena();
			return;
	}
}

int main(){
	codigoSinComentarios();
	return 0;
}
