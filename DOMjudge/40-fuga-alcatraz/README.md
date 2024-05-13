# Fuga de Alcatraz

Vito y Corleone, dos famosos mafiosos, han decido escaparse de la
cárcel de Alcatraz aprovechando que se ha estropeado el sistema
de iluminación, que en un descuido la puerta del patio de la prisión
se ha quedado abierta y que sobre la isla hay una fuerte niebla.
Para lograr escapar deben atravesar de arriba a abajo un patio rectangular lleno de vigilantes. Al ser la niebla muy cerrada, cada vigilante puede percibir solamente personas que están a una distancia
de, como mucho, 10 metros.
Los mafiosos deben decidir si, sabiendo las dimensiones del patio de la prisión, el número de vigilantes que hay y dónde están colocados, podrán pasar por el patio sin ser detectados por algún
vigilante. Pueden comenzar en cualquier punto del muro Norte y podrán escaparse si consiguen
alcanzar cualquier punto del muro Sur.

## Entrada

La entrada está formada por distintos casos de prueba.
Cada caso de prueba consiste en una única línea con números, todos ellos enteros. Los dos primeros indican el ancho y alto del patio (ambos entre 100 y 1.000). El tercer número, N, entre 1 y
1.000, representa la cantidad de vigilantes que hay en el patio. A continuación la línea contendrá
N parejas de números enteros. Cada pareja indica la posición (x, y) de un vigilante. La coordenada
(0, 0) corresponde a la esquina inferior izquierda del patio de la prisión.
El final de la entrada se indica con una línea con un único 0 que no se debe procesar.

## Salida

Para cada caso de prueba se escribirá una línea con la palabra SI si los dos mafiosos pueden
escapar de la prisión sin ser vistos por los vigilantes, o la palabra NO si no hay forma de que los
mafiosos puedan cruzar el patio sin ser detectados por algún vigilante.

## Entrada de ejemplo

100 100 1 50 50  
100 500 4 80 100 10 10 30 30 60 60  
100 100 5 10 50 30 50 50 50 70 50 90 50  
0

## Salida de ejemplo

SI  
SI  
NO
