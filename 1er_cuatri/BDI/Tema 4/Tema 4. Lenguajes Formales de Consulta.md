### 2.5 Lenguajes de consulta relacional

> **Lenguaje de consulta:**
Lenguaje en el que los usuarios solicitan información de la base de datos. Pueden ser procedimentales o no procedimentales.

>**Lenguajes procedimentales:**
>En ellos el usuario indica al sistema que lleve a cabo una serie de operaciones en la base de datos para calcular el resultado deseado.

>**Lenguajes no procedimentales:**
>El usuario describe la información deseada pero no establece un procedimiento concreto para conseguirla.

Hay varios lenguajes de consultas "puros":
	- <u>Álgebra relacional</u>: procedimental
	- <u>Cálculo relacional de tuplas</u>: no procedimental
	- <u>Cálculo relacional de dominios</u>: no procedimental

Estos son lenguajes rígidos y formales, pero ilustran las técnicas fundamentales para la extracción de datos de las bases de datos.

- ¿Cómo funciona cada lenguaje de los anteriores? (a grandes rasgos)
	- Álgebra relacional &rarr; consta de un conjunto de operaciones que toma una o dos relaciones como entrada y genera una nueva como salida.
	- Cálculo relacional (de tuplas y de dominios) &rarr; usa la lógica de predicados para definir el resultado buscado, sin ningún procedimiento concreto para llegar a él.
### 2.6 Operaciones relacionales
Todo lenguaje procedimental de consulta proporciona un conjunto de operaciones que se pueden aplicar a una o un par de relaciones. El resultado es siempre **una única relación** y gracias a ello, las operaciones pueden encadenarse entre sí.

La más frecuente es la <u>selección de tuplas concretas de una única relación</u> (profesor) que satisfaga algún predicado particular (sueldo > 85.000€). El resultado será una nueva relación, subconjunto de la relación original (profesor).

<u>Selección de ciertos atributos</u> de una relación: el resultado es una nueva relación que **solo** tiene los atributos seleccionados. Por ejemplo: teniendo la relación profesor compuesta por los atributos "ID", "nombre", "sueldo" y "nombre_dept", deseamos una lista que **únicamente** contenga los id y los sueldos de los profesores. Entonces, la nueva relación, tan solo poseerá esos dos atributos: "ID" y "sueldo".

<u>Join (reunión)</u>: permite combinar dos relaciones mezclando pares de tuplas (una de cada relación) en una única tupla. Por ejemplo, teniendo la relación profesor descrita antes y otra llamada departamento, compuesta por los atributos "nombre_dept", "edificio" y "presupuesto". El resultado de la reunión de estas dos relaciones daría lugar a otra compuesta por los atributos "ID", "nombre", "sueldo", "nombre_dept", "edificio" y "presupuesto", si los valores del atributo "nombre_dept "son iguales en ambas relaciones.

<u>Producto cartesiano</u>: combina tuplas de dos relaciones, pero su resultado contiene todos los pares de tuplas de las dos relaciones, independientemente de sus atributos coinciden o no.

<u>Unión de conjuntos</u>: realiza la unión de dos tablas "de estructura similar". Por ejemplo "alumnos_graduados" y "alumnos_sin_graduar" y a partir de ellas obtener todos los estudiantes de un departamento.

Como se ha explicado anteriormente, se pueden aplicar operaciones sobre los resultados de las consultas. Por ejemplo, para obtener el **"ID" y "sueldo"** de los profesores con sueldo mayor a 85.000 €, primero se seleccionan las tuplas que cumplen la condición y luego se eligen los atributos deseados. En este caso sería posible elegir primero los atributos deseados, y sobre ese resultado realizar la selección de aquellos con sueldo > 85.000€. El resultado es el mismo que si se realizaran las operaciones en orden inverso. No obstante, esto no sucede siempre.

También puede suceder que el resultado de una consulta contenga tuplas duplicadas, por ejemplo seleccionando "nombre_dept" en la relación profesor podría suceder que varios profesores estén en el mismo departamento (p.e: Informática). Algunos lenguajes relacionales eliminan los duplicados para cumplir con la definición de conjunto matemático, mientras que otros los mantienen para mejorar la eficiencia.

**Álgebra relacional**: define un conjunto de operaciones sobre relaciones (una o dos) que se toman como entrada y devuelven una relación como salida. Las 5 operaciones básicas del Álgebra relacional son: **selección**, **proyección**, **producto cartesiano**, **unión de conjuntos** y **diferencia de conjuntos**.