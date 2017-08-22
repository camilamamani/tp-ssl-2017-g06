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
<p> M=({codigo, caracter, escapeCaracter, cadena, escapeCadena,estadoInicial}, ASCII, {c,p,l,$},estadoInicial,$,estadoFinal)</p>
  
**Especificación PushString**
<p>PushString:Σ*->Ø / PushString(cadena)=Ø,<br/>
PushString(cadena)={cadena=subCadena.(caracter); subCadena € Σ*, c € Σ,<br/>
&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp;&emsp; Push(c)+PushString(ubCadena)
</p>
