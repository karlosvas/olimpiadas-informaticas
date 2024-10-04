# Posiciones en el ranking ICPC En los concursos de programación de la

ICPC(International Collegiate Programming Contest),
talentosos equipos de estudiantes
universitarios de todo el mundo compiten para resolver diversos problemas
algorítmicos en un tiempo limitado.Cada problema presenta un desafío que
explora diferentes aspectos de la informática,
como estructuras de datos,
algoritmos y conceptos matemáticos.Estos equipos deben demostrar sus
capacidades en la resolución de problemas,
diseño de algoritmos eficientes y habilidades de
programación.En este ambiente competitivo,
los equipos buscan destacar resolviendo la mayor cantidad posible de
problemas en el menor tiempo posible.El ranking de los equipos se establece
según el número de problemas resueltos,
antes los que han resuelto más, y en caso de empate,
se utiliza el tiempo
total(suma de los minutos transcurridos desde el inicio del concurso hasta
la resolución de cada problema) como factor de desempate.Es decir,
si dos equipos han resuelto la misma cantidad de problemas,
el equipo que haya logrado
resolverlos en un tiempo menor ocupará una posición más alta en el ranking
.Esta medida no solo destaca la capacidad de resolución,
sino también la eficiencia temporal de los equipos y agrega un elemento
estratégico al concurso,
ya que los equipos deben tomar decisiones rápidas y precisas para maximizar
su puntuación en un tiempo limitado
.Ahora te toca a ti resolver un problema de forma eficiente y en el
menor tiempo posible.Dado el ranking final de un concurso de
programación ICPC,
y una cantidad de problemas C,
tienes que contestar cuál es la posición en el
ranking(numeradas desde 1) del primer equipo que resolvió
exactamente C problemas y cuál es la posición en el ranking del último
equipo que resolvió C problemas. ¿Sabrás estar a la altura
?

### Entrada

La entrada consta de una serie de casos de prueba .Cada caso comienza con una línea con el número de equipos N que aparecen en el ranking(entre 1 y 250.000)
.En la siguiente línea aparecen N números,
que corresponden a los números de problemas resueltos por cada equipo en el
ranking,
desde el primero hasta el
último(por lo que esta secuencia está ordenada de mayor a menor)
.Un concurso nunca tiene más de 250.000 problemas.A
continuación aparece el número P de preguntas que habrá que
contestar(entre 1 y 250.000),
y en la siguiente línea aparecen P números,
representando las P preguntas.Un número C
representa la pregunta “¿Cuáles son la primera y la última posición en el
ranking que ocupan los equipos que han resuelto exactamente C problemas
?”.

### Salida

Por cada caso de prueba seescribirán tantas líneas como preguntas tenga el caso,
con las respuestas a esas preguntas.La respuesta a cada pregunta
consistirá en dos números,
la primera y la última posición en el
ranking(numeradas desde el 1) que ocupan los equipos que han resuelto
exactamente el número de problemas de la pregunta
.Si no existieran equipos que hayan resuelto ese número de problemas
se contestaría NO HAY.Detrás de las respuestas de cada caso se
escribirá una línea más con-- -

## Entrada de ejemplo

10 8 8 8 7 7 6 6 5 4 2  
2  
8 6  
5  
10 8 8 3 0  
3 1 8 7

## Salida de ejemplo

1 3 6 7  
--  
NO HAY  
2 3  
NO HAY  
--
