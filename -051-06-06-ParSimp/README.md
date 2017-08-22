# Sintaxis y Semántica de los Lenguajes
- Curso: k2051.
- Año 2017.
- Grupo 06.
- Integrantes:
  - Federico Hazama
  - Agustin Pérez
  - Camila Mamani
  - Luciano Lisachi
  - Nicolás Pérez
  
 **TP N6 Parser Simple**
<p>El objetivo es diseñar e implementar un autómata de pila (APD) que verifique el
balanceo de los paréntesis, corchetes, y llaves.</p>

**Definición del APD**
<p> M=({codigo, caracter, escapeCaracter, cadena, escapeCadena,estadoInicial}, ASCII, {c,p,l,$},estadoInicial,$,estadoFinal)
  
**Autómata de Pila**
``` [dot]
digraph automataSimpleParser {
	a->b [label= "&#949, &#949/$"];
	b->b [label= "l/&#949"];
	b->b [label= "(/p"];
	b->b [label= "[/c"];
	b->b [label= "{/ll"];
	b->b [label= "), p/&#949"];
	b->b [label= "], c/&#949"];
	b->b [label= "}, ll/&#949"];
	b->c [label= "$/&#949"];
	b->d [label= "\"/&#949"];
	b->e [label= "\'/&#949"];
	d->f [label= "\\/&#949"];
	e->g [label= "\\/&#949"];
	f->d [label= "l/&#949"];
	d->d [label= "l/&#949"];
	g->e [label= "l/&#949"];
	e->e [label= "l/&#949];
	d->b [label= "\"/&#949"];
	e->b [label= "\'/&#949"];

	
	a [label= "EstadoInicial -"];
	b [label= "Simple Parser -"];
	c [label= "EstadoFinal +"];
	d [label= "Cadena -"];
	e [label= "Caracter -"];
	f [label= "Escape Cadena -"];
	g [label= "Escape Caracter -"];
}
```
