# Ratones en un laberinto

Un grupo de ratones de laboratorio está siendo entrenado para escapar de un laberinto. El laberinto está compuesto por una
serie de celdas, donde cada celda está conectada a otras a través de pasadizos donde hay obstáculos, por lo que los ratones
tardan un tiempo conocido en superar cada uno de estos tramos. Además, algunos pasajes permiten a los ratones ir en un
solo sentido, pero no al revés.
Todos los ratones han sido muy bien entrenados y, cuando son
colocados en una celda arbitraria del laberinto, siguen un camino que los lleva a la celda de salida en un tiempo mínimo.
Vamos a realizar el siguiente experimento: se coloca un ratón en cada celda del laberinto (excepto en la celda de salida) y se inicia un temporizador de cuenta atrás. Cuando el cronómetro se
detiene, contamos la cantidad de ratones que han salido del laberinto.
¿Puedes escribir un programa que, dada la descripción del laberinto y el límite de tiempo, prediga
la cantidad de ratones que saldrán del laberinto? Puedes suponer que no hay cuellos de botella
en el laberinto, es decir, que todas las celdas tienen espacio para un número arbitrario de ratones.
Entrada
La entrada está compuesta por diversos casos de prueba. La primera línea de cada caso contiene
4 números: el número N (entre 1 a 10.000) de celdas del laberinto (numeradas de 1 a N), el número
S de la celda donde se encuentra la salida, el número T de segundos con el que se inicia el
cronómetro para la cuenta atrás (entre 1 y 106
), y el número P de pasadizos (entre 1 y 100.000).
Las siguientes P líneas describen cada una de ellas un pasadizo, dando 3 números: dos números
de celda A y B y los segundos (entre 1 a 10.000) que tarda un ratón en llegar de A a B.
Obsérvese que cada conexión es unidireccional, es decir, los ratones no pueden viajar de B a A
a menos que haya otra línea que especifique ese pasadizo. Además, el tiempo requerido para
viajar en cada dirección puede ser diferente.
Salida
Para cada caso de prueba el programa debe escribir una línea con el número de ratones que
alcanzarán la celda de salida S en como mucho T segundos.

## Entrada de ejemplo
5 5 20 5
1 2 5
1 4 10
2 4 7
3 4 15
4 5 10
3 1 10 2
2 3 5
3 2 6

## Salida de ejemplo
3
0