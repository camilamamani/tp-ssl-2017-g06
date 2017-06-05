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
  
 **TP N3 Removedor de Comentarios**
<p>El objetivo es diseñar una máquina de estado que remueva comentarios, implementar dos versiones, e 
informar cual es la más eficiente mediante un benchmark</p>

**Implementación A**
<p> Estados como Funciones</p>
<p>Transición con llamadas a las funciones, recursivamente.</p>

**Implementación B**
<p> Estados como Etiquetas</p>
<p>Transición con goto.</p>

**Tabla Comparativa**

|Tamaño de Archivo|Implementación A|Implementación B|
|--------|----------------|----------------|
|1KB|0.061 s|0.154 s|
|1MB|No soporta|0.164 s|
|1GB|No soporta|108.007 s|

**Autómatas**
``` [dot]
digraph automataLiteralCadenas {
	o->a [label= " \"/putchar(\")"];
	a->a [label= "x/putchar(x)"];
	a->b [label=" '\\' /putchar(\\)"]
	b->a [label= "x/putchar(x)"];
	a->c [label= " \"/putchar(\")"];
	o [label= "codigo"];
	a [label= "cadena"];
	b [label= "escape cadena"];
	c [label= "codigosub2"];
}

digraph automataConstanteCaracteres {
	o->a [label= " '/putchar(')"];
	a->a [label= "x/putchar(x)"];
	a->b [label="  '\\' /putchar(\\)"]
	b->a [label= "x/putchar(x)"];
	a->c [label= " '/putchar(')"];
	o [label= "codigo"];
	a [label= "caracter"];
	b [label= "escape caracter"];
	c [label= "codigosub2"];
}

digraph automataCaracteresSueltos {
	o->a[label= " x/putchar(x)"];
	o [label= "codigo"];
	a [label= "codigosub2"];
	
}

digraph automataComentarios {
	o->a [label= " '\\'/&#949;"];
	a->b [label= " '\\'/&#949;"];
	b->b [label="x/&#949;"];
	a->c [label= "'*'/&#949;"];
	c->c [label="x/&#949;"];
	c->d [label="x/&#949;"];
	d->d [label="x/&#949;"];
	d->d [label="'*'/&#949;"];
	d->e [label= " '\\'/putchar(' ')"];
	b->e [label="'\\n'/putchar('\\n')"];
	o [label= "codigo"];
	a [label= "barra1"];
	b [label= "barra2"];
	c [label= "asterisco"];	
	d [label="asteriscos palabras"];
	e [label="codigo sin comentarios"];
}
```
**Expresiones regulares para los autómatas**  
<p>x:cualquier otro caracter <p>
<p> <p>

L1={"}U{x^n \^m x^k / n>=0, 0<=m<=1, k>=0}U{"} 
<p><p>

L2= {'}U{x^n \^m x^k / 0<=n<=1, 0<=m<=1, k>=0}U{'} 
<p><p>
L3= {x}
<p><p>
L4= {/}U{/ x^m '\n' / m>=0}U{* x^m * / m>=0} U {/}

**Definiciones formales para los autómatas**
<p>automata1=({codigo, cadena, escape cadena, codigosub2}, {'"',x ,'\'}, Tsub1, codigo,{codigosub2} )<p>
<p>automata2=({codigo, caracter, escape caracter, codigosub2},{''',x ,'\' },Tsub2, codigo, {codigosub2})<p>
<p>automata3=({codigo, codigosub2}, {x}, Tsub3, codigo, {codigosub2})<p>
<p>automata4=({codigo,barra1,barra2,asterisco,asteriscos palabras,codigo sin comentarios}, {'\n', '/', x,'*' }, codigo, {codigo sin comentarios} )<p>

**Máquina de estados**
``` [dot]
digraph maquinaDeEstados{
	o->a [label= " \"/putchar(\")"];
	a->a [label= "x/putchar(x)"];
	a->b [label=" '\\' /putchar(\\)"]
	b->a [label= "x/putchar(x)"];
	a->a [label= " \"/putchar(\")"];
	o->c [label= " '/putchar(')"];
	c->c [label= "x/putchar(x)"];
	c->d [label="  '\\' /putchar(\\)"]
	d->c [label= "x/putchar(x)"];
	c->o [label= " '/putchar(')"];
	o->o[label= " x/putchar(x)"];
	o->e [label= " '\\'/&#949;"];
	e->f [label= " '\\'/&#949;"];
	f->f [label="x/&#949;"];
	e->g [label= "'*'/&#949;"];
	g->g [label="x/&#949;"];
	g->h [label="x/&#949;"];
	h->h [label="x/&#949;"];
	h->h [label="'*'/&#949;"];
	h->o [label= " '\\'/putchar(' ')"];
	b->o [label="'\\n'/putchar('\\n')"];

	o [label= "codigo sin comentarios"];
	a [label= "cadena"];
	b [label= "escape cadena"];
	c [label= "caracter"];
	d [label= "escape caracter"];
	e [label= "barra1"];
	f [label= "barra2"];
	g [label= "asterisco"];	
	h [label="asteriscos palabras"];

}
```
