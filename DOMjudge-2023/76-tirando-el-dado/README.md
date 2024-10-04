# Tirando el dado

Marta tiene un dado y se divierte tirándolo varias veces seguidas y calculando la suma de los valores que le van saliendo (1 5 + 2 + 3 + 2 + …). Esta tarde llegó hasta 100, y al ser un número
tan exacto, se preguntó de cuántas formas distintas podría haber llegado a esa misma suma. Cogió lápiz y papel y se puso
a escribir las formas de conseguir 10 (quería empezar por algo
más sencillo). Además, hace poco ha aprendido que la suma
es conmutativa, por lo que no le interesa contar dos formas que solamente se diferencian en el orden en que han salido los números. Para ella, que le salga primero un 4 y luego un 6, es lo mismo que primero le salga el 6 y después el 4. Lleva un buen rato y ha contado 35.
formas de conseguir la suma 10. ¿Serán todas?  
Iba a ponerse con la difícil tarea de calcular las formas de conseguir 100, pero antes ha empezado a pensar qué ocurriría si el dado en vez de 6 caras tuviera k, numeradas del 1 al k. Eso parece aún más difícil. Necesita ayuda.

## Entrada

La entrada comienza con el número de casos de prueba que vendrán a continuación. Cada caso ocupa una línea con dos números: el número k de caras del dado (entre 1 y 20) y la suma s que se quiere conseguir (entre 1 y 100).

## Salida

Para cada caso de prueba se escribirá una línea con el número de formas distintas (sin
importar el orden en el que salgan los dados) de conseguir la cantidad s con un dado que
tiene k caras, numeradas del 1 al k. El número de formas nunca será mayor que 109.

## Entrada de ejemplo

3  
6 10  
6 100  
10 100

## Salida de ejemplo

35  
189509  
6292069
