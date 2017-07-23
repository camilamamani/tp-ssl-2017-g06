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
  
 **TP N5 Lexico de la Calculadora Polaca**
 • Estudiar los fundamentos de los scanner aplicados a una calculadora con notación polaca inversa que utiliza un stack.
 • Implementar modularización mediante los módulos Calculator, StackOfDoublesModule, y Scanner.
 
 **Preguntas y Respuestas**
 <p> a) ¿Es necesario modificar StackModule.h? ¿Por qué? </p>
 <p>Si, porque agregamos las funciones isEmpty() e isFull(). </p>
 <p> b) ¿Es necesario recompilar la implementación de Stack? ¿Por qué? </p>
 <p> c) ¿Es necesario que Calculator muestre el lexema que originó el error léxico? Justifique su decisión </p>
 <p>Si porque creemos que es necesario ver los datos que toma como error. </p>
 <p> i. Si decide hacerlo, ¿de qué forma debería exponerse el lexema?</p>
 <p>Agregamos una tercer componente del tipo char que se llama errorLexema </p>


``` [dot]
digraph scanner{
   o->o [label= " '', '\t' / &#949;"];
   o->a [label= " + / type = Addition"];
   o->b [label= " - / type = Substraction"];
   o->c [label= " / / type = Division"]
   o->d [label= " * / type = Multiplication"];
   o->e [label= " '\n' / type = PopResult"];
   o->f [label= " o / type = LexError; t->errorLexema = o"];
   o->g [label= " n / type = Number; lexema[++i]=n"];
   g->g [label= " n / type = Number; lexema[++i]=n"]
   g->h [label= " . / &#949;"];
   h->g [label= " n / type = Number; lexema[++i]=n"];

   o [label= "getNextToken -"];
   a [label= "Addition +"];
   b [label= "Substraction +"];
   c [label= "Division +"];
   d [label= "Multiplication +"];
   e [label= "PopResult +"];
   f [label= "LexError +"];
   g [label= "Number +"];	
   h [label= "ParteFraccionaria"];

}
```
``` [dot]
digraph dependencias{
   o->b [label= "push(t->val), pop()"];
   o->d [label= "getNextToken(t)"];
   a->b [label= "pop(), push(StackItem), isEmpty(), isFull()"];
   c->d [label= "int getNextToken(Token *t)"];

   o [label= "calculator.c"];
   a [label= "stackOfDoublesModule.c"];
   b [label= "stackOfDoublesModule.h"];
   c [label= "scanner.c"];
   d [label= "scanner.h"];
}
```
 

