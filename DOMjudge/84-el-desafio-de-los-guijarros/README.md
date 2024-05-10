# El desafío de los guijarros

Roberto es un aventurero al que le gusta viajar a paises lejanos con gran tradición cultural
e histórica. Y siempre intenta buscar algún objeto peculiar que se use en esa zona y que no
conociera antes.
El pasado verano estuvo en la recóndita zona de Tetrafengcheng, donde sus gentes suelen
matar el tiempo con un simple, en apariencia, juego que se juega sobre un tablero con
cuatro filas y un número variable de columnas, como el de la siguiente figura:
Cada celda del tablero tiene un número entero positivo tallado sobre la madera. Cuando
son dos los jugadores, se alternan para colocar unos pequeños guijarros sobre celdas sin
ocupar hasta que ya no se pueden colocar más guijarros. Al acabar, cada jugador suma los
números de las casillas donde ha puesto sus guijarros y gana aquel que consigue un valor
mayor. Pero hay una regla adicional: dos guijarros no pueden estar en celdas adyacentes
horizonal o verticalmente. La adyacencia en diagonal sí está permitida.
Los pastores de Tetrafengcheng pasan mucho tiempo solos llevando en su mochila un tablero de este juego y un saquito de guijarros, con la esperanza de cruzarse con algún paisano y echar unas partidas. Si no es el caso, juegan en solitario intentando conseguir cada
vez una suma más alta con las celdas donde colocan los guijarros respetando las reglas de
separación en vertical u horizontal.
Roberto se trajo uno de estos tableros y ahora solo en su casa, recordando a aquella hospitalaria gente, se pregunta cuál será la suma máxima que se puede conseguir con su tablero.

## Entrada

La entrada está formada por una serie de casos de prueba. Cada caso consiste en la descripción de un tablero en cinco líneas. En la primera aparece el número N de columnas del
tablero (un número entre 1 y 100.000). En las cuatro siguientes aparecen N números (valores
entre 1 y 1.000) en cada una de ellas; son los números de las cuatro filas del tablero.

## Salida

Para cada caso de prueba se escribirá la suma máxima que se puede obtener colocando
guijarros en las celdas del tablero de forma que no haya dos adyacentes en horizontal o
vertical.

### Entrada de ejemplo

6  
100 20 70 40 10 60  
90 50 30 10 15 30  
30 15 10 30 50 90  
60 10 40 70 20 100  
2  
1 5  
2 6  
3 7  
4 8

### Salida de ejemplo

580  
18
