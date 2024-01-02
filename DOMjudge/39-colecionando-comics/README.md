# Coleccionando cómics
El nuevo fascículo de tu serie de cómics favorita está a punto
de salir a la venta y todos quieren hacerse con una versión en
papel del mismo. Además, los ejemplares vendidos por esta
editorial vienen con un número identificador único, por lo que
cuanto más bajo sea el número, más codiciado es el ejemplar.
En la tienda de cómics en la que sueles comprar tienen una
manera muy peculiar de venderlos: colocan todos los ejemplares del nuevo lanzamiento en
varias pilas, los clientes se colocan en fila para entrar en la tienda por turno, y el cliente al que
le toca el turno solamente puede elegir comprar uno de los ejemplares que se encuentran
en la cima de alguna de las pilas.
Como no quieres un ejemplar cualquiera, has decidido hacer un poco de trampa y tienes
en tu poder los identificadores de todos los ejemplares y sus posiciones dentro de las pilas.
Teniendo en cuenta que cada cliente va a comprar el mejor ejemplar que tenga disponible
en el momento de entrar a la tienda, tienes que calcular el puesto de la cola de espera que
debes ocupar el día del lanzamiento para hacerte con el mejor ejemplar de la tienda (el que
tiene un identificador menor de entre todos los disponibles).
Entrada
La entrada consta de una serie de casos de prueba. Cada caso comienza con una línea que
contiene el número N de pilas de cómics. A continuación, aparecerán N líneas con la descripción de cada pila: un número K que indica la cantidad de cómics en esa pila, seguido de
K números positivos (entre 1 y 108
), los identificadores de los ejemplares, ordenados desde
el fondo de esa pila hasta su cima (que aparece a la derecha del todo en la descripción).
Para cada caso de prueba, todos los identificadores de ejemplar son distintos, pero no tienen por qué ser consecutivos o comenzar en 1.
Salida
Para cada caso de prueba se escribirá una línea con la posición (numeradas desde 1) que
tienes que ocupar en la cola de espera de la tienda para llevarte el mejor ejemplar.

## Entrada de ejemplo
2
5 5 2 3 1 20
7 9 12 44 13 4 7 8
3
3 4 5 6
2 3 2
4 11 8 9 7

## Salida de ejemplo
6
1