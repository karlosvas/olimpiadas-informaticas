# Eligiendo vagones

Como viaje de fin de curso, se han juntado varias clases y se
han ido de viaje por Europa aprovechando los descuentos del Interrail. Cada vez que tienen que coger billetes para un trayecto
ocurre lo mismo: quieren ir todos juntos, pero, siendo tantos, resulta misión imposible.
Como solución de compromiso, se conforman con estar todos en vagones contiguos, siempre que sea la menor cantidad de
vagones posible, para que si alguien en un extremo quiere hablar
con otra persona que está sentada en el extremo contrario tenga
que andar poco por los pasillos del tren.
Después de haber visitado la Torre Eiffel y los Campos Eliseos están comprando los billetes para
ir a Berlín. Saben cuántos son, y cuántos huecos libres hay en cada vagón, y tienen que decidir qué
asientos coger.

## Entrada

Cada caso de prueba comienza con una primera línea con dos números. El primero, 1 ≤ p ≤ 108, indica la cantidad de personas que viajan juntas en el grupo. El segundo, 1 ≤ n ≤ 500.000, indica
el número de vagones del tren.
La segunda línea contiene n números separados por espacio con la cantidad de asientos libres
de cada vagón, empezando por el vagón más cercano a la locomotora y terminando por el más
alejado. Ningún número es mayor que 10.000 y la suma total de huecos libres no supera 2×109.
La entrada termina con dos ceros, que no deben procesarse.

## Salida

Por cada caso de prueba el programa escribirá el mínimo número de vagones adyacentes necesarios para que todos los estudiantes del grupo puedan viajar, junto con la posición en el tren del
primer vagón que ocuparán. Los vagones se numeran empezando por el 1, el situado junto a la
locomotora, hasta el n.
Si hay más de una posible solución, se elegirá aquella más cercana a la locomotora. Si no hay
solución se escribirá NO ENTRAN.

### Entrada de ejemplo

5 4  
1 1 3 3  
3 5  
0 1 1 1 1  
8 3  
5 0 2  
0 0

### Salida de ejemplo

2 3  
3 2  
NO ENTRAN
