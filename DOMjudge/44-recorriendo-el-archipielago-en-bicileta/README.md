Recorriendo el archipiélago en bicicleta
Al archipiélago Milislotes han llegado las bicicletas. Sus habitantes están estusiasmados y no se bajan de la bici en todo el día,
yendo de un lado para otro sin descanso. Pero las islas son tan
pequeñas que terminan todos mareados de dar vueltas sin parar,
por lo que se están planteando crear una red de puentes rectos
que les permita ir en bici de cualquier isla a cualquier otra.
Han pedido presupuesto al arquitecto, que ha confeccionado una
lista con todos los puentes que podrían construirse entre islas del archipiélago y cuánto costaría construir cada uno de esos puentes. ¿Podrías ayudarles a decidir qué puentes construir
de tal forma que se pueda ir en bici desde cualquier isla a cualquier otra y el coste total de
la obra sea lo mínimo posible?
Entrada
La entrada está formada por varios casos de prueba. Cada uno ocupa varias líneas: en la
primera aparece el número I de islas en el archipiélago (entre 1 y 1.000); en la siguiente aparece el número P de puentes presupuestados (entre 0 y 10.000); y a continuación aparece
una línea por cada uno de estos puentes con tres enteros, las islas que une (numeradas
entre 1 e I) y el coste de construir ese puente (un valor entre 1 y 100.000). Los puentes siempre van de una isla a otra distinta, son transitables en bici en ambos sentidos, y no se ha
presupuestado más de un puente entre un mismo par de islas.
Salida
Para cada caso de prueba se escribirá, en una línea, el coste mínimo de construir los puentes
necesarios para unir todas las islas por bici. Si no hubiera suficientes puentes presupuestados para lograrlo, se escribirá No hay puentes suficientes.

## Entrada de ejemplo

4  
5  
1 2 5  
1 3 10  
2 4 7  
1 4 8  
3 4 2  
4  
3  
1 2 3  
2 4 5  
4 1 8

## Salida de ejemplo

14  
No hay puentes suficientes
