Jugando al Buscaminas
Hoy vamos a jugar al Buscaminas. Seguro que lo conoces. En un
tablero dividido en celdas se esconde cierto número de bombas.
El objetivo es encontrarlas todas. Para ello hay que destapar todas
las celdas que no esconden bombas. Como ayuda, cuando se descubre una celda sin bombas, aparece en ella el número de bombas
en las (como mucho) 8 celdas colindantes. Así, si al descubrir una
celda aparece un 3 eso significa que de las 8 celdas que hay alrededor 3 de ellas esconden una bomba y 5 no. Cuando se descubre
una celda que no tiene bombas alrededor, en vez de un 0 la celda se deja vacía y se descubren de forma automática las 8 celdas
colindantes (ahorrando al jugador tener que descubrirlas por sí mismo sin ningún riesgo).
Esto provoca que en ocasiones se descubran muchas celdas de golpe. Si se descubre una
celda con una bomba, se pierde la partida.
La figura muestra el estado del juego después de haber descubierto consecutivamente las
cuatro esquinas del tablero.
Lo que queremos es conocer el estado del juego después de que el jugador haya descubierto una serie de celdas.
Entrada
La entrada constará de una serie de casos de prueba. Cada caso comienza con una línea
con los números de filas F y columnas C del tablero (1 ≤ F, C ≤ 50). A continuación aparecen F líneas, cada una con C caracteres: un * significa que en la celda correspondiente se
esconde una bomba; las casillas vacías se indican con -. Después aparece el número K de
celdas a descubrir, seguido de K líneas que indican las coordenadas de cada celda descubierta: una fila entre 1 y F y una columna entre 1 y C. Pueden intentarse descubrir celdas
ya descubiertas anteriormente (quizás de forma automática), en cuyo caso el estado del
tablero no cambia. Si al descubrir una celda aparece una bomba, esa será la última celda
a descubrir que aparezca en la entrada para ese caso.
Salida
Para cada caso de prueba, se escribirá el tablero después de haber descubierto todas las
celdas indicadas en la entrada (y las que lo hayan hecho de forma automática). Por cada
celda descubierta se escribirá un número indicando el número de bombas que hay alrededor, salvo que este sea 0, que se escribirá -. Las celdas sin descubrir se indicarán con X.
Si durante el juego se ha descubierto una bomba, se escribirá GAME OVER en vez del tablero
final.

## Entrada de ejemplo
8 8  
-*---*--  
--------  
**------  
---*----  
---*---*  
-*--*---  
----*---  
--------  
4  
1 1  
1 8  
8 8  
8 1  

## Salida de ejemplo
1XXXXX1-  
XXXX111-  
XXXX1---  
XXXX2-11  
XXXX311X  
XXXXX211  
1112X2--  
---1X1--  