# Reescribiendo fracciones

Es bien sabido que una misma fracción se puede reescribir manteniendo su valor sin más que
multiplicar el numerador y el denominador por el mismo número.
Aunque es menos intuitivo, también es posible reescribir fracciones como la suma de otras dos
fracciones. Por ejemplo:

1/2 = 1/6 + 1/3 = 1/4 + 1/4

De hecho, para cualquier número natural k > 0, la fracción 1/k puede reescribirse de la forma:

1/k = 1/x + 1/y

con x e y enteros positivos.
Para un mismo k, ¿cuántas de estas parejas (x, y) existen?
Entrada
El programa recibirá múltiples casos de prueba por la entrada estándar. Cada uno estará compuesto por un número 1 ≤ k ≤ 2
31 – 1.

## Salida

Para cada caso de prueba, el programa escribirá, en la salida estándar, una línea con un número
indicando cuántas parejas diferentes de números enteros positivos (x, y) existen tales que:

1/k = 1/x + 1/y

Debido a la propiedad conmutativa, las parejas (x, y) e (y, x) se considerarán iguales y deberán
contarse una única vez.

## Entrada de ejemplo

2  
12  
90

## Salida de ejemplo

2  
8  
23
