/*Parser Simple
 *Equipo 06
 *20172108
 */
#include <stdio.h>
#include <StackModule.h>

int c, cAnterior;
enum caracteres {
	LLAVEa = 123,
	LLAVEc = 125,
	PARENTESISa = 40,
	PARENTESISc = 41,
	CORCHETEa = 91,
	CORCHETEc = 93,
	APOSTROFE = 39,
	COMILLAS = 34,
	LF = 10,
	CONTRABARRA=92
};

int main(){
	
	goto estadoInicial;
	
	estadoInicial: {
		PushString("$");
		goto codigo;
	}
	
	codigo: {
		switch(c=getchar()){
			case LLAVEa:
				putchar(c);
				Push('l');
				goto codigo;
			case PARENTESISa:
				putchar(c);
				Push('p');
				goto codigo;
			case CORCHETEa:
				putchar(c);
				Push('c');
				goto codigo;
			case LLAVEc:
				if(Pop()!='l'){
					printf("error llave");
					return;
					}
				else
					putchar(c);
					goto codigo;
			case PARENTESISc:
				if(Pop()!='p'){
					printf("error parentesis");
					return;
					}
				else
					putchar(c);
					goto codigo;
			case CORCHETEc:
				if(Pop()!='c'){
					printf("error corchete");
					return;
					}
				else
					putchar(c);
					goto codigo;
			case COMILLAS:
				putchar(c);
				goto cadena;
			case APOSTROFE:
				putchar(c);
				goto caracter;
			case EOF:
				goto estadoFinal;
			default:
				putchar(c);
				goto codigo;
			}
		}
	estadoFinal:{
		if (Pop()!='$')
			printf("error en pila");
		else
			return;
	}
	caracter: {
	c = getchar();
	switch(c){
		case CONTRABARRA:
			putchar(c);
			goto escapeCaracter;
		case APOSTROFE:
			putchar(c);
			goto codigo;
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
				goto codigo;
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
				goto cadena;
		}
	}

}
