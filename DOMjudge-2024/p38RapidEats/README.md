# RapidEats

Rocky Rutanator trabaja como planificador de rutas para la empresa RapidEats, un servicio de entrega dealimentos adomicilio que opera en la bulliciosa ciudad de Deliciaville. RapidEats utiliza para el reparto unas motillos eléctricas con poca autonomía, por lo que cuenta con una red de puntos de recarga/recogida/entrega conectados por una intrincada red de tramos decalles, cada unoconunaduraciónestimadaenminutos para llegar de un punto a otro. Además, para garantizar la frescura de los alimentos, se ha establecido que los riders vayan siempre por el camino más rápido. ¿Cuál es el tiempo mínimo requerido para llevar un pedido desde el punto de partida P hasta el punto de entrega final Q a través de una secuencia de tramos? Supónquenohayretrasosenningúnpuntodeentregayquetodoslosrepartidoressiguen las rutas sugeridas de manera eficiente.

## Entrada

La entrada consta de varios casos de prueba, ocupando cada uno de ellos varias líneas. Enla primera aparecen, separados por un espacio, el número N (entre 2 y 20.000) de puntos derecarga/recogida/entregaenlaciudadyelnúmeroC(entre0y100.000)detramos decalles (entre puntos). A continuación, aparece unalíneaporcadatramocontresenteros, que indican los números de los puntos que une ese tramo (números entre 1 y N) y el tiempoestimado para recorrerlo (un valor entre 1 y 500). Todas las calles pueden recorrerse en ambos sentidos. A continuación aparece el número K (entre 1 y 10) de pedidos a repartir seguido de la información de esos pedidos: dos números distintos que representan el punto de origen y el de destino de cada pedido.

## Salida

Para cada caso de prueba se escribirá una línea por cada pedido que contendrá el tiempo mínimo para ir desde el origen al destino. Si para un pedido no existiera camino que conectara el origen con el destino, entonces se escribiría NO LLEGA. Después de la salida de cada caso se escribirá una línea con---.

### Entrada de ejemplo

4 4  
1 2 15  
1 3 30  
2 3 20  
4 3 10  
2  
1 3  
4 1  
4 2  
1 3 10  
2 4 20  
2  
1 2  
3 1

### Salida de ejempl

30  
40  
\---
NO LLEGA  
10  
\---
