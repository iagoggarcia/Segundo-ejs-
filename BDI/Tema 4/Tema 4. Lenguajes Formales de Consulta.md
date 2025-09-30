### 2.5 Lenguajes de consulta relacional

> *Lenguaje de consulta:*
Lenguaje en el que los usuarios solicitan información de la base de datos. Pueden ser procedimentales o no procedimentales.

>*Lenguajes procedimentales:*
>En ellos el usuario indica al sistema que lleve a cabo una serie de operaciones en la base de datos para calcular el resultado deseado.

>*Lenguajes no procedimentales:*
>El usuario describe la información deseada pero no establece un procedimiento concreto para conseguirla.

Hay varios lenguajes de consultas "puros":
- **Álgebra relacional**: procedimental
- **Cálculo relacional de tuplas**: no procedimental
- **Cálculo relacional de dominios**: no procedimental

Estos son lenguajes rígidos y formales, pero ilustran las técnicas fundamentales para la extracción de datos de las bases de datos.

- ¿Cómo funciona cada lenguaje de los anteriores? (a grandes rasgos)
	- Álgebra relacional &rarr; consta de un conjunto de operaciones que toma una o dos relaciones como entrada y genera una nueva como salida.
	- Cálculo relacional (de tuplas y de dominios) &rarr; usa la lógica de predicados para definir el resultado buscado, sin ningún procedimiento concreto para llegar a él.

### 2.6 Operaciones relacionales
Todo lenguaje procedimental de consulta proporciona un conjunto de operaciones que se pueden aplicar a una o un par de relaciones. El resultado es siempre *una única relación* y gracias a ello, las operaciones pueden encadenarse entre sí.

La más frecuente es la **selección de tuplas concretas de una única relación** (profesor) que satisfaga algún predicado particular (sueldo > 85.000€). El resultado será una nueva relación, subconjunto de la relación original (profesor).

**Selección de ciertos atributos** de una relación: el resultado es una nueva relación que *solo* tiene los atributos seleccionados. Por ejemplo: teniendo la relación profesor compuesta por los atributos "ID", "nombre", "sueldo" y "nombre_dept", deseamos una lista que *únicamente* contenga los id y los sueldos de los profesores. Entonces, la nueva relación, tan solo poseerá esos dos atributos: "ID" y "sueldo".

**Join (reunión)**: permite combinar dos relaciones mezclando pares de tuplas (una de cada relación) en una única tupla. Por ejemplo, teniendo la relación profesor descrita antes y otra llamada departamento, compuesta por los atributos "nombre_dept", "edificio" y "presupuesto". El resultado de la reunión de estas dos relaciones daría lugar a otra compuesta por los atributos "ID", "nombre", "sueldo", "nombre_dept", "edificio" y "presupuesto", si los valores del atributo "nombre_dept "son iguales en ambas relaciones.

**Producto cartesiano**: combina tuplas de dos relaciones, pero su resultado contiene todos los pares de tuplas de las dos relaciones, independientemente de sus atributos coinciden o no.

**Unión de conjuntos**: realiza la unión de dos tablas "de estructura similar". Por ejemplo "alumnos_graduados" y "alumnos_sin_graduar" y a partir de ellas obtener todos los estudiantes de un departamento.

Como se ha explicado anteriormente, se pueden aplicar operaciones sobre los resultados de las consultas. Por ejemplo, para obtener el *"ID" y "sueldo"* de los profesores con sueldo mayor a 85.000 €, primero se seleccionan las tuplas que cumplen la condición y luego se eligen los atributos deseados. En este caso sería posible elegir primero los atributos deseados, y sobre ese resultado realizar la selección de aquellos con sueldo > 85.000€. El resultado es el mismo que si se realizaran las operaciones en orden inverso. No obstante, esto no sucede siempre.

También puede suceder que el resultado de una consulta contenga tuplas duplicadas, por ejemplo seleccionando "nombre_dept" en la relación profesor podría suceder que varios profesores estén en el mismo departamento (p.e: Informática). Algunos lenguajes relacionales eliminan los duplicados para cumplir con la definición de conjunto matemático, mientras que otros los mantienen para mejorar la eficiencia.

*Álgebra relacional*: define un conjunto de operaciones sobre relaciones (una o dos) que se toman como entrada y devuelven una relación como salida. Las 5 operaciones básicas del Álgebra relacional son: *selección*, *proyección*, *producto cartesiano*, *unión de conjuntos* y *diferencia de conjuntos*.

### 6.1 El álgebra relacional

Esta ya fue definida anteriormente y sus operaciones fundamentales también han sido citadas. Además de dichas operaciones hay otras derivadas de ellas: *intersección de conjuntos*, *reunión natural* y *asignación*.

#### 6.1.1 Operaciones fundamentales

- **Selección**: como su nombre indica selecciona tuplas que cumplen un predicado dado y se usa la letra griega sigma para denotarla &rarr; σ. Se permiten las comparaciones que usan =, ≠, >,<, ≥ o ≤. Para combinar varios predicados en uno se pueden usar la disyunción, la conjunción y la negación lógica.
- **Proyección**: devuelve una relación de argumentos, excluyendo algunos atributos. Además, como las relaciones son conjuntos, se eliminan todas las filas duplicadas. Ejemplo: se quiere conseguir una relación formada por los "ID", "nombre" y "sueldo" de los profesores, pero sin los "nombre_dept". Se usa la letra pi para denotarla.
- **Composición de operaciones relacionales**: el resultado de una operación relacional debe ser también una relación. Gracias a que las operaciones siempre devuelven relaciones, es posible componer operaciones, es decir, aplicar unas sobre otras o "encadenarlas". Así se da lugar a expresiones más complejas del álgebra relacional.
- **Unión de conjuntos**: para que sea más fácil entenderlo utilizaremos el siguiente ejemplo: se necesita el conjunto de todos los "asignatura_id" de las asignaturas que se impartieron en otoño de 2009, en primavera de 2010 o en ambas épocas. Dicho conjunto estará formado por la unión de ambos subconjuntos individuales. Como las relaciones resultantes son un conjunto, los valores duplicados aparecen una sola vez. Para poder realizarse la unión entre las relaciones estas deben:
	- Ser *compatibles*.
	- Ser de la *misma cardinalidad* &rarr; tener el mismo número de atributos.
	- Los dominios de los atributos i-ésimos de r y s *deben ser iguales* para todo i.

- **Diferencia de conjuntos**: es indicada por "-" y permite encontrar las tuplas que están en una relación pero no en la otra. Ejemplo: r - s &rarr; el resultado contendrá las tuplas que están en r pero no en s. Al igual que en la unión, hay que asegurarse de que:
	-  Sean *compatibles*.
	- Tengan la *misma cardinalidad* &rarr; mismo número de atributos.
	- Los dominios de los atributos i-ésimos de r y s *sean iguales* para todo i.
  
- **Producto cartesiano**: indicado mediante "x". Permite combinar información de dos relaciones cualesquiera. Ejemplo: r<sub>1</sub> x r<sub>2</sub>. Para distinguir atributos que pueden aparecer tanto en r<sub>1</sub> como en r<sub>2</sub> con el mismo nombre, se le adjunta al nombre del atributo el nombre de la relación de la que proviene (profesor.ID o enseña.ID). Para los atributos que solo aparecen en una de las relaciones se puede omitir el prefijo con el nombre de la relación. Sin embargo puede haber problemas de nombramiento cuando se realiza un producto cartesiano de una relación consigo misma, por ejemplo. Esto se evita mediante la operación renombramiento, que se explica más abajo.
- **Renombramiento**: los resultados de las expresiones del álgebra relacional no tienen un nombre que se pueda usar para referirse a ellas. Es por ello que esta operación permite hacerlo. Ejemplo: para hacer profesor x profesor &rarr; ρd (profesor), donde la d sería el nuevo nombre de profesor y ahora los atributos serían d.nombre, d.ID, etc.

#### 6.1.2 Definición formal del álgebra relacional

Expresiones del álgebra relacional:
- E<sub>1</sub> ∪ E2 &rarr; *Unión*
- E1 − E2 &rarr; *Diferencia*
- E<sub>1</sub> × E<sub>2</sub> &rarr; *Producto cartesiano*
- σ<sub>P</sub>(E1), donde P es un predicado sobre los atributos de E1 &rarr; *Selección*
- Π<sub>S</sub>(E<sub>1</sub>), donde S es una lista que se compone de algunos de los atributos de E1 &rarr; *Proyección*
- ρ<sub>x</sub>(E<sub>1</sub>), donde x es el nuevo nombre del resultado de E1 &rarr; *Renombramiento*

#### 6.1.3 Otras operaciones del álgebra relacional

Las operaciones fundamentales son suficientes para expresar cualquier consulta, pero algunas sería complicado expresarlas. Para ello se definen otras operaciones; para cada operación nueva se crea una expresión equivalente usando solo las operaciones fundamentales.

- **Intersección de conjuntos**: suponiendo un ejemplo en el que se quieren encontrar el conjunto de las asignaturas impartidas en otoño de 2009 que hayan sido también impartidas en primavera de 2010, se utilizará esta operación. Se puede reescribir de la siguiente forma:
r ∩ s = r − (r − s)
- **Reunión natural**: simplifica consultas que normalmente requieren producto cartesiano + selección. Une dos relaciones forzando que los atributo comunes tengan el mismo valor y elimina duplicados de atributos repetidos. Si no hay atributos en común, simplemente se reduce a un producto cartesiano. Un ejemplo sería la consulta de "Obtener el nombre de cada profesor con las asignaturas que enseña", aquí lo que haría la reunión natural sería buscar los ID iguales en profesor y en enseña y coger los valores nombre de profesor y su correspondiente id_asignatura en enseña para formar una nueva tabla con estos dos datos.
- **Asignación**: se indica con "&larr;" y actúa de manera parecida a la asignación de los lenguajes de programación. Es algo similar a un =, pero de formato temporal. Es decir, guarda el resultado de una expresión en una variable temporal que se puede usar posteriormente, pero no se muestra nada al usuario. Ejemplo: temp1 &larr; R x S
- **Reunión externa**: extensión de la operación reunión para trabajar con información ausente. Funciona de forma similar a la reunión natural pero conserva las tuplas que se perderían al realizar la reunión creando tuplas en el resultado con valores nulos. Tiene tres formas:
	- Reunión externa *por la izquierda*: toma todas las tuplas de la relación de la izquierda que no coinciden con ninguna tupla de la relación de la derecha, las rellena con valores nulos en los demás atributos de la relación de la derecha y las añade al resultado de la reunión natural.
	- Reunión externa *por la derecha*: simétrica a la reunión externa por la izquierda.
	- Reunión externa *completa*: realiza ambas operaciones.

#### 6.1.4 Operaciones del álgebra relacional extendida

Estas son operaciones del álgebra relacional con la capacidad de escribir consultas que no se pueden expresar con las operaciones básicas explicadas anteriormente.

- **Proyección generalizada**: extiende la proyección permitiendo que se utilicen operaciones aritméticas o de cadenas de caracteres en la lista de proyección. Por ejemplo coger el sueldo de profesor y dividirlo entre 12 para conseguir el sueldo mensual.
- **Agregación**: permite el uso de funciones como mínimo o el promedio sobre conjuntos de valores. Estas toman una colección de valores y devuelven como resultado un único valor. Ejemplo: función sum para el conjunto {1,5,7}, hay 3 valores pero el resultado es la suma de ellos, 13 (un único valor). Las colecciones pueden tener valores repetidos y el orden en el que aparecen no importa &rarr; *Multiconjuntos*. Los conjuntos son un caso especial de multiconjuntos en los que no se pueden repetir elementos.

### 6.2 El cálculo relacional de tuplas

Este es un lenguaje de consultas no procedimental, es decir, describe la información deseada sin establecer un procedimiento concreto para llegar a ella.

- {*t* | *P (t)*} &rarr; conjunto de todas las tuplas t tales que el predicado *P* es cierto para *t*.

#### 6.2.1 Ejemplos de consultas

- {*t* | *t* ∈ *profesor* ∧ *t*[*sueldo*] > 80000} &rarr; encontrar el ID, nombre, nombre_dept y sueldo de los profesores con un sueldo mayor a 80.000€.

- {*t* | ∃ *s* ∈ *profesor* (*t*[*ID*] = *s*[*ID*] ∧ *s*[*sueldo*] > 80000)} &rarr; encontrar el ID de los profesores cuyo sueldo sea superior a 80.000€

- {*t* | ∃ *s* ∈ *profesor* (*t*[*nombre*] = *s*[*nombre*] ∧ ∃ *u* ∈ *departamento *(*u*[*nombre_dept*] =[*nombre_dept*] ∧ *u*[*edificio*] = «Watson»))} &rarr; encontrar el nombre de todos los profesores cuyo departamento está en el edificio Watson.

- {*t* | ∃ *s* ∈ *sección* (*t*[*asignatura_id*] = *s*[*asignatura_id*]) ∧ *s*[*semestre*] = «Otoño» ∧ *s*[*año*] = 2009)} ∨ ∃ *u* ∈ *sección* (*u*[*asignatura_id*] = *t*[*asignatura_id*])} ∧ *u*[*semestre*] = «Primavera» ∧ *u*[*año*] = 2010)} &rarr; encontrar el conjunto de todas las asignaturas que se enseñaron en otoño de 2009 y en primavera de 2010 o ambos.

- {*t* | ∃ *s* ∈ *sección* (*t*[*asignatura_id*] = *s*[*asignatura_id*]) ∧ *s*[*semestre*] = «Otoño» ∧ *s*[*año*] = 2009)} ∧ ∃ *u* ∈ *sección* (*u*[*asignatura_id*] = *t*[*asignatura_id*])} ∧ *u*[*semestre*] = «Primavera» ∧ *u*[*año*] = 2010)} &rarr; encontrar el conjunto de todas las asignaturas que se enseñaron en otoño de 2009 y en primavera de 2010.

- {*t* | ∃ *s* ∈ *sección* (*t*[*asignatura_id*] = *s*[*asignatura_id*]) ∧ *s*[*semestre*] = «Otoño» ∧ *s*[*año*] = 2009)} ∧ ¬ ∃ *u* ∈ *sección* (*u*[*asignatura_id*] = *t*[*asignatura_id*])} ∧ *u*[*semestre*] = «Primavera» ∧ *u*[*año*] = 2010)} &rarr; encontrar el conjunto de todas las asignaturas que se enseñaron en otoño de 2009 pero no en primavera de 2010.

### 6.3 Cálculo relacional de dominios

Esta forma de cálculo relacional usa variables de dominio que toman sus valores del dominio de un atributo, en vez de hacerlo para una tupla completa. No obstante, está muy relacionado con el cálculo relacional de tuplas.

#### 6.3.1 Definición formal

Las expresiones son de la forma:

- {<*x*<sub>1</sub>, *x*<sub>2</sub>, … *x*<sub>n</sub>> | P (*x*<sub>1</sub>, *x*<sub>2</sub>,… *x*<sub>n</sub>)} &rarr; *x*<sub>n</sub> representan las variables del dominio.

A su vez <*x*<sub>1</sub>, *x*<sub>2</sub>, … *x*<sub>n</sub>> es una relación con n atributos y las correspondientes *x*<sub>1</sub>, *x*<sub>2</sub>, … *x*<sub>n</sub> son variables de dominio o constantes de dominio. Además, P representa una fórmula compuesta por "átomos". Para construir las fórmulas hay una serie de reglas:
- Los átomos son fórmulas
- Si *P*<sub>1</sub> es una fórmula, también lo son *P*<sub>1</sub> y (*P*<sub>1</sub>)
- Si *P*<sub>1</sub> y *P*<sub>2</sub> son fórmulas, también lo son *P*<sub>1</sub>∨*P*<sub>2</sub>, *P*<sub>1</sub>∧*P*<sub>1</sub> y *P*<sub>2</sub>→*P*<sub>2</sub>

#### 6.3.2 Ejemplos de consultas

- {<*i*, *n*, *d*, *s*> | <*i*, *n*, *d*, *s*> ∈ *profesor* ∧ *s* > 80000}  &rarr; econtrar el ID, nombre, nombre_dept y sueldo de los profesores cuyo sueldo sea superior a 80.000€
- {<*n*> | ∃ *i*, *d* , *s* (<*i*, *n*, *d*, *s*> ∈ *profesor* ∧ > 80000)} &rarr; encontrar los ID de profesor de los profesores cuyo sueldo sea superior a 80.000€
- {<*n*, *c*> | ∃ *i*, *a* (<*i*, *c*, *a*, *s*, *y*> ∈ *enseña* ∧ ∃ *d*, *s* (<*i*, *n*, *d*, *s*> ∈ *profesor* ∧ *d* = «Física»))} &rarr; encontrar los nombres de todos los profesores del departamento de Física junto con los asignatura_id de todas las asignaturas que enseñan
- {<*c*> | ∃ *s* (<*c*, *a*, *s*, *y*, *b*, *r*, *t*> ∈ *sección* ∧ *s* = «Otoño» ∧ *y* = «2009» ∨ ∃ *u* (<*c*, *a*, *s*, *y*, *b*, *r*, *t*> ∈ *sección* ∧ *s* = «Primavera» ∧ *y* = «2010» &rarr; encontrar el conjunto de todas las asignaturas que se enseñaron en otoño de 2009, primavera de 2010 o en ambos