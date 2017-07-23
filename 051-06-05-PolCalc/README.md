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
 
 ``` [dot]
digraph maquinaDeEstados{
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
 
 

