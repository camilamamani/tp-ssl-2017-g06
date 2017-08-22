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
				PushString("ll");
				goto codigo;
			case PARENTESISa:
				putchar(c);
				PushString("p");
				goto codigo;
			case CORCHETEa:
				putchar(c);
				PushString("c");
				goto codigo;
			case LLAVEc:
				if((strcmp(PopString(),"ll"))!=0){
					printf("error llave");
					return;
					}
				else
					putchar(c);
					goto codigo;
			case PARENTESISc:
				if((strcmp(PopString(),"p"))!=0){
					printf("error parentesis");
					return;
					}
				else
					putchar(c);
					goto codigo;
			case CORCHETEc:
				if((strcmp(PopString(),"c"))!=0){
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
				if ((strcmp(PopString(),"$"))!=0)
					printf("error en pila");
			default:
				putchar(c);
				goto codigo;
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
