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
