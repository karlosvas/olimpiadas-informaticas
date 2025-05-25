# Difundiendo un rumor

Víctor se prometió a sí mismo que nunca más jugaría a videojuegos...
Pero hace poco Firestorm, una conocida empresa de desarrollo de
videojuegos, ha publicado su nuevo juego, World of Farcraft, y se ha
hecho muy popular. Por supuesto, Víctor ha empezado a jugarlo.
Ahora intenta resolver una misión. La tarea consiste en llegar a un
asentamiento llamado Overcity y conseguir difundir allí un rumor.
Víctor sabe que en Overcity viven una serie de personajes. Algunos
personajes son amigos entre sí y comparten la información que obtienen. Además, Víctor sabe que puede sobornar a cualquier personaje para que empiece a difundir el rumor; eso sí, el iésimo personaje quiere una cantidad ci de oro a cambio de empezar a difundir el rumor. Cuando
un personaje oye el rumor, se lo cuenta a todos sus amigos, y estos empiezan a difundir el rumor a sus amigos (ya de forma gratuita para Víctor), y así sucesivamente.  
La misión termina cuando todos los personajes de Overcity conocen el rumor. ¿Cuál es la cantidad mínima de oro que Víctor debe gastar para superar la misión?

## Entrada

La entrada consistirá en una serie de casos de prueba. Cada caso comienza con una línea con el
número N de personajes en Overcity (1 ≤ N ≤ 25.000) y el número M de pares de amigos (0 ≤ M
≤ 200.000).
La segunda línea contiene N enteros ci
, la cantidad de oro que quiere el personaje i-ésimo para
comenzar a difundir el rumor (1 ≤ ci ≤ 10.000).
A continuación, aparecerán M líneas, cada una con dos números (entre 1 y N), describiendo que
esos dos personajes son amigos.

## Salida

Para cada caso de prueba se escribirá una línea con la menor cantidad de oro que Víctor tiene
que gastar para conseguir la misión (que el rumor llegue a todos los personajes de Overcity).

### Entrada de ejemplo

5 2  
8 5 3 2 4  
1 4  
4 5  
10 5  
1 6 2 7 3 8 4 9 5 10  
1 2  
3 4  
5 6  
7 8  
9 10

### Salida de ejemplo

10  
15
