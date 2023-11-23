La ronda de la noche
En Ciudad Decoro les preocupa que los jóvenes se reúnan con sus parejas en la noche, a
espaldas de sus padres. Por ello en la última Ordenanza Municipal se ha obligado a que
todas las casas tengan un jardín-laberinto para acceder a su puerta principal y que (opcionalmente) se instalen sensores de movimiento en los mismos. Conscientes de la posible
dificultad de implantación de la Ordenanza, se ha decidido que todos los jardines-laberinto
estén organizados en cuadrículas donde cada casilla está libre, tiene un muro o alberga un
sensor de movimiento.
Como no podría ser de otra forma, la plataforma activista #FreeLove va a hacer todo lo
posible para evitar que estas nuevas medidas supongan un obstáculo real para el amor.
Durante las últimas semanas ha ido investigando y realizando mapas de todos los jardineslaberinto, anotando la posición de los sensores de movimiento. #FreeLove ha detectado
que únicamente hay 10 tipos diferentes de sensores de movimiento, etiquetados como
CAT-k donde k es un número natural entre 0 y 9. Los sensores captan movimiento en línea
recta en las 4 direcciones (norte, sur, este y oeste) y la k de su categoría indica el número
de casillas que cubren en cada dirección. De esta manera, un sensor CAT-0 únicamente
capta movimiento en la casilla en la que está instalado, mientras que un sensor CAT-2 capta
movimiento en su casilla y en 2 casillas en cada una de las 4 direcciones (en total cubre 9
casillas). Sin embargo, lo más interesante que ha descubierto #FreeLove es que los sensores
no pueden traspasar los muros del laberinto, así que en ocasiones su alcance en alguna
dirección se ve limitado.
#FreeLove necesita descubrir cuáles de los jardines-laberinto permiten que un amante vaya de la entrada del jardín a la puerta principal de la casa sin ser descubierto por ningún
sensor. ¿Podrías ayudarles a diferenciar los jardines-laberinto impenetrables de aquellos
favorables al amor, y en esos casos calcular el mínimo número de casillas que hay que
atravesar para llegar de la entrada del jardín a la puerta principal?
Entrada
La entrada comienza con una línea conteniendo el número de jardínes a analizar. Cada
jardín comienza con dos números 0 < ancho,alto ≤ 1000 con el ancho y alto del jardínlaberinto en una línea. Le sigue la descripción del jardín en alto líneas de ancho caracteres
cada una. Estos caracteres son:
‘#’: Una pared.
‘.’: Una casilla libre.
‘E’: La casilla donde está la entrada al jardín-laberinto.
‘P’: La casilla donde está la puerta principal de la casa.
k, con 0 ≤ k ≤ 9: Casilla que alberga un sensor CAT-k.
La entrada al jardín y la puerta principal de la casa pueden estar en cualquier parte del
jardín, incluidas casillas interiores. Además, nada impide que algún sensor vigile la casilla
donde está la entrada al jardín o la puerta principal de la casa, por lo que en esos casos no
será posible recorrer el jardín sin ser descubiertos.
Salida
Por cada jardín-laberinto la salida será una línea con el mínimo número de casillas del jardín
que hay que atravesar para llegar de la entrada a la puerta principal de la casa sin ser
descubierto, o la palabra NO en caso de que sea imposible.

# Entrada de ejemplo
3
9 4
........P
..2#.....
E.##..1..
.........
6 4
....#P
..#...
.####.
E....1
10 5
E.........
..........
....2.....
..........
.........P

# cSalida de ejemplo
12
10
NO