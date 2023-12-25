# El bingo de Azahara

El bingo es un juego de azar en el que cada jugador dispone de
una o varias tarjetas, llamadas cartones. Cada cartón tiene impresa
una serie aleatoria de números. Por otro lado, un locutor extrae sucesivamente varias bolas numeradas de un bombo, anunciando los
números extraidos. Cada vez que el locutor anuncia un número, los
jugadores lo tachan de sus cartones, en caso de tenerlo. El primer
jugador que consigue tachar todos los números de alguno de sus cartones grita “¡Bingo!”
y gana el juego. Si varios jugadores completan el cartón al mismo tiempo, todos ganan la
partida.
Azahara Fortunata ha decidido montar un salón con una variante de este juego, llamada
Bingo Injusto. En esta variante, cada jugador dispone de un único cartón, pero la cantidad
de números que contiene el cartón es aleatoria. De este modo, puede haber jugadores que
tengan más números que tachar que otros. Como Azahara no dispone de mucho presupuesto, ha decidido ella misma tomar el papel de locutora del juego. El problema es que le
aburre tener que comprobar cuáles de los cartones son los premiados, y ha decidido hacer
un programa que realice esta ingrata tarea por ella. ¿Puedes ayudarla?
Entrada
La entrada consta de una serie de casos de prueba, cada uno de ellos describiendo una
partida de bingo. Cada caso de prueba comienza con el número N de jugadores participantes (1 ≤ N ≤ 50.000). A continuación aparecen N líneas, cada una describiendo el cartón
de cada jugador. Cada una de estas líneas comienza con el nombre del jugador (secuencia
de como mucho 40 letras minúsculas del alfabeto inglés) y va seguida por la secuencia de
números contenidos en el cartón de dicho jugador (números entre 1 y 106
, todos distintos).
Esta secuencia finaliza con el número 0, que no forma parte del cartón. Ningún cartón tiene
más de 1.000 números.
A continuación aparece la descripción de la secuencia de números que salen del bombo,
todos distintos, que son los que Azahara irá leyendo hasta que algún/algunos de los jugadores grite ¡Bingo!. En la primera línea aparece la cantidad de números y en la siguiente
aparecen esos números, separados por espacios. Suponemos que no hay ningún jugador
despistado que se olvide de tachar un número de su cartón, o que se olvide gritar ¡Bingo!
cuando consigue tachar todos los números de su cartón. Pero en la secuencia sí puede haber más números de los necesarios para encontrar un ganador, que salieron del bombo y
estaban preparados por si hicieran falta.
La entrada finaliza con una partida de 0 jugadores, que no se procesa.
Salida
Para cada caso de prueba se escribirá una línea con los nombres de los jugadores que han
ganado la partida. La lista de ganadores ha de estar ordenada alfabéticamente de manera
ascendente. Si una partida tiene varios ganadores, sus nombres deben estar separados por
un espacio.

## Entrada de ejemplo
2  
diana 30 21 23 32 0  
martin 20 21 31 46 78 23 0  
6  
20 23 21 32 46 30  
3  
felipe 15 9 21 0  
ricardo 10 2 9 0  
gerardo 7 9 0  
7  
15 21 10 2 7 9 3  
0  

## Salida de ejemplo
diana  
felipe gerardo ricardo  