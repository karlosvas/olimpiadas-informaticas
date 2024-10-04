Haciendo trampas en Serpientes y Escaleras
Serpientes y Escaleras es un juego clásico, originario de la India, donde ya se jugaba en el
siglo XVI. El tablero está formado por una cuadrícula de N×N casillas numeradas de forma
consecutiva desde 1 hasta N2
, comenzando por la esquina inferior izquierda y continuando
fila por fila de abajo arriba, alternando en cada fila el ir hacia la izquierda o hacia la derecha,
como aparece en el dibujo. Algunos pares de casillas, siempre en filas diferentes, pueden estar
conectados mediante serpientes (que bajan, naranjas en el dibujo) o escaleras (que suben, azules
en el dibujo). Cada casilla puede ser extremo de como mucho una serpiente o una escalera. La
primera y la última casilla nunca son extremos de una serpiente o escalera.
100 99 98 97 96 95 94 93 92 91
81 82 83 84 85 86 87 88 89 90
80 79 78 77 76 75 74 73 72 71
61 62 63 64 65 66 67 68 69 70
60 59 58 57 56 55 54 53 52 51
41 42 43 44 45 46 47 48 49 50
40 39 38 37 36 35 34 33 32 31
21 22 23 24 25 26 27 28 29 30
20 19 18 17 16 15 14 13 12 11
1 2 3 4 5 6 7 8 9 10
A Serpientes y Escaleras pueden jugar cualquier número de jugadores correspondiéndole a
cada uno una ficha. Todas las fichas comienzan en la casilla número 1. Los jugadores van alternándose para mover su ficha. Para ello, tiran un dado con K caras numeradas desde 1 hasta K,
y avanzan su ficha siguiendo la numeración del tablero tantas casillas como indique el dado.
Si la ficha termina en el extremo superior de una serpiente, se deslizará hasta su extremo inferior. En cambio, si termina en el extremo inferior de una escalera, ascenderá hasta su extremo
superior. Gana la partida el jugador que antes alcance la última casilla.
El juego así planteado no requiere ninguna destreza. Pero supongamos que has trucado
el dado y tienes el poder de elegir la cara que saldrá cada vez que lo tiras. ¿Sabes cuántos
movimientos tendrías que hacer para ganar la partida si comienzas moviendo tú?
Entrada
La entrada consta de una serie de casos de prueba. En la primera línea de cada caso aparecen
cuatro números: la dimensión N del tablero, el número K de caras del dado (K ≤ N), el número
S de serpientes y el número E de escaleras. Las siguientes S + E líneas contienen cada una dos
números, indicando la casilla inicial y la casilla final de una serpiente (las S primeras) o una
escalera (las E siguientes). Tanto N como K son números entre 1 y 100.
La entrada termina con 0 0 0 0.
Salida
Para cada caso de prueba se escribirá el menor número de movimientos necesarios para
ganar la partida. Está garantizado que la casilla final es alcanzable desde la inicial en todos los
casos.

## Entrada de ejemplo
10 6 5 6  
50 13  
68 55  
81 16  
93 43  
98 36  
3 60  
6 47  
32 53  
45 86  
51 94  
61 83  
0 0 0 0  

## Salida de ejemplo
3  