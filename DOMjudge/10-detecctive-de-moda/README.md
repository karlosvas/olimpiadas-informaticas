# Dectective de moda
Rocío tiene una tienda un tanto peculiar enfrente de su casa. La tienda solo vende camisetas, y cada camiseta tiene
un estilo propio que se identica por un número, aunque
se puede dar el caso de que varias camisetas a la venta
tengan el mismo estilo.
La tienda tiene todas las camisetas dispuestas en una barra horizontal, y tiene una política de compras un tanto restrictiva: solamente se permiten comprar las camisetas que
se encuentren en los extremos de la barra, para que no se desordenen mucho.
Para vestir de exclusiva, Rocío quiere comprar una camiseta que sea única, es decir que
no haya otra con su mismo estilo en la tienda en el momento de adquirirla. Está dispuesta
a comprar camisetas que no sean únicas con tal de llevarse una que sí lo sea. Pero como
tampoco le sobra el dinero, no quiere que sean demasiadas.

## Entrada
La entrada comienza con el número de casos de prueba que vendrán a continuación, cada
uno describiendo, a lo largo de varias líneas, la situación de la tienda y los eventos que
tienen lugar a lo largo del tiempo.
La primera línea de cada caso contiene un número N, el número de camisetas que la tienda
tiene a la venta actualmente.
En la siguiente línea aparecen N enteros xi
, los identicadores de los estilos de las camisetas. Dos camisetas con el mismo estilo tendrán el mismo identificador. En la entrada,
las camisetas siguen el mismo orden en el que se encuentran en la tienda, de izquierda a
derecha.
A continuación aparece un número E, indicando el número de eventos que tienen lugar.
Las si-guien-tes E líneas del caso de prueba describen cada una un evento en orden cronológico. Cada evento puede ser de 3 tipos:
Las letras I y D seguidas de un número yj
indican que se añade una camiseta a la venta
con identificador de estilo yj en el extremo Izquierdo o Derecho, respectivamente.
Las letras i y d indican que se ha vendido la camiseta que se encontraba en el extremo
izquierdo o derecho, respectivamente. Se garantiza que cuando se realiza una venta
la tienda tiene camisetas.
La letra P indica que Rocío se pregunta en ese momento cuántas camisetas consecutivas de uno de los extremos debería comprar como mínimo para garantizar que
se lleva a casa una camiseta con un estilo único en la tienda en ese momento. Rocío
nunca compra las camisetas, solo se hace la pregunta.

## Restricciones
1 ≤ N ≤ 105
1 ≤ E ≤ 105
1 ≤ xi
, yj ≤ 109

## Subtareas
1. (5 puntos) Todos los números xi e yj son distintos.
2. (10 puntos) N ≤ 100, E ≤ 100, y el número de camisetas no excede 100 en ningún
momento.
3. (15 puntos) Nunca se venden camisetas y para todo yj existe xi
tal que xi = yj
.
4. (25 puntos) Nunca se venden camisetas.
5. (45 puntos) Sin restricciones adicionales.

## Salida
Por cada caso de prueba el programa deberá responder a todas las preguntas que se haga
Rocío, en orden cronológico. Cada respuesta ocupará una línea independiente.
Para responder a una pregunta, se indicará el número mínimo de camisetas consecutivas
que es necesario comprar, empezando por uno de los extremos, para llevarse a casa una
camiseta que sea única en la tienda. Al número le seguirá, separado por un espacio, el
nombre del extremo en cuestión: IZQUIERDA o DERECHA. Si pudiesen ser ambos, el nombre
del extremo se sustituirá por la palabra CUALQUIERA.
Si en el momento de hacer una pregunta no hay ninguna camiseta con un estilo único en
la tienda (o simplemente no hay camisetas), se escribirán las palabras NADA INTERESANTE.
Al final de cada caso de prueba se escribirán tres guiones ---.

Entrada de ejemplo
2  
5  
8 5 9 23 8  
9  
P  
I 22  
P  
I 23  
D 5  
D 22  
P  
I 9  
P  
5  
2 1 3 1 2  
5  
P  
i  
P  
D 2  
P  

## Salida de ejemplo
2 CUALQUIERA  
1 IZQUIERDA  
5 CUALQUIERA  
NADA INTERESANTE  
---
3 CUALQUIERA  
1 DERECHA  
2 IZQUIERDA  
---