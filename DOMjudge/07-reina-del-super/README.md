# Reina del súper

Hace tiempo, Ismael se enamoró perdidamente de una cajera
del supermercado. No se cansa de espiarla entre la sección
de ofertas y menaje del hogar. Tiene la tarjeta echando humo,
porque aunque tenga la nevera llena, todas las tardes baja a
comprar cualquier cosa con tal de volver a verla. Y da igual
cuánta gente haya; él siempre se pone a esperar en la fila de
su caja.
Pero al llegar hoy al súper se ha llevado una desagradable sorpresa. Al cerebrito de turno
que gestiona el supermercado le ha dado por instaurar la “fila única”.  
Ahora en lugar de
haber filas independientes para cada caja, hay una única fila para todas y cuando una caja
se queda vacía, el primero que ocupa la filla va a ella.
El gerente del súper seguramente piense que ahora los clientes quedarán más satisfechos
con el servicio proporcionado porque saben que nunca esperarán de más, pero a Ismael le
han destrozado la vida. Ya no tiene la garantía de que le atienda su reina del súper particular
cuando le toca pagar.
Solo le queda una alternativa. Cuando se aproxima a la fila única, puede estimar cuánto
tardará cada cliente en pasar por la caja en base a la cantidad de productos en el carrito y
averiguar entonces en qué caja le tocará para ver si es la de su amada o no.

## Entrada
La entrada estará compuesta por distintos casos de prueba, cada uno de ellos representando el estado del supermercado uno de los días en los que Ismael va a comprar.
Cada caso de prueba consta de dos líneas. La primera contiene el número N de cajas abiertas en ese momento y el número C de clientes esperando. A continuación viene una línea
con C números positivos que indican el número de segundos que tardará cada cliente en
ser atendido. El primer número se corresponde con el tiempo de la primera persona de la
filla única.
Al último caso de prueba le sigue uno con 0 cajas y 0 clientes que no debe procesarse.

## Salida
Para cada caso de prueba se escribirá una línea con el número de la caja en la que será
atendido Ismael si se coloca detrás de los C clientes esperando.
Ten en cuenta que las cajas están numeradas de la 1 a la N y que en caso de quedar dos
cajas libres a la vez, el primer cliente irá a la caja con menor número.

### Entrada de ejemplo
2 2  
10 5  
2 2  
5 10  
3 2  
5 10  
0 0  

### Salida de ejemplo
2  
1  
3