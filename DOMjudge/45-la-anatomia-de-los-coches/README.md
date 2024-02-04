# La autonomía de los coches

En la actualidad, muchos fabricantes de automóviles están desarrollando coches que funcionan con electricidad en lugar de
gasolina. Las baterías utilizadas en estos coches suelen ser muy
pesadas y caras, por lo que los diseñadores deben adoptar un
importante compromiso a la hora de determinar la capacidad de
la batería, y por tanto la autonomía, de estos vehículos. Tu tarea
consiste en ayudar a determinar la autonomía mínima necesaria
para que un coche pueda viajar entre dos ciudades cualesquiera
del territorio.
La red de carreteras está formada por ciudades conectadas por
carreteras bidireccionales de diferente longitud. En cada ciudad hay una estación de recarga. A lo largo de una ruta entre dos ciudades, el coche puede pasar por cualquier número
de ciudades, pero la distancia entre cada par de ciudades consecutivas a lo largo de la ruta
no debe ser mayor que la autonomía del coche. ¿Cuál es la autonomía mínima del coche
que, si es posible, permita viajar entre cada par de ciudades del territorio?
Entrada
La entrada consiste en una secuencia de redes de carreteras. La primera línea de cada red
contiene dos números enteros N (entre 1 y 10.000) y M (entre 0 y 100.000), el número de
ciudades y carreteras. Las ciudades están numeradas de 1 a N. A la primera línea le siguen
otras M, cada una de las cuales describe una carretera mediante tres enteros positivos: los
dos primeros son los números de las dos ciudades conectadas por la carretera y el tercero
es la longitud de la carretera. Las longitudes nunca son mayores que 1.000.000.
Salida
Para cada red de carreteras se escribirá una línea que contenga un número entero, la autonomía mínima del coche que le permite viajar libremente por la red, yendo de cualquier
ciudad a cualquier otra. Si no es posible viajar de una ciudad a otra, independientemente
de la autonomía del coche, se mostrará una línea con la palabra Imposible.

## Entrada de ejemplo

4 4  
1 2 5  
2 3 10  
3 1 7  
2 4 8  
1 0  
4 2  
1 2 3  
4 3 5

## Salida de ejemplo

8  
0  
Imposible
