# Camiones de reparto

Somos una empresa de transporte y hemos decidido renovar parte de nuestra flota de camiones de reparto. A nosotros nos conviene que los camiones
sean anchos, porque así se puede repartir y colocar mejor la mercancia. Pero
claro, hay ciudades con calles muy estrechas, por donde no todos los camiones pueden pasar.
Tenemos mapas actualizados de las ciudades donde trabajamos, donde hemos señalado para cada calle cuál es la anchura máxima que puede tener
un camión para poder transitar por ella.
¿Nos ayudas a decidir si un camión de una anchura determinada puede circular por una ciudad
para llegar desde un punto concreto a otro?
Entrada
La entrada está formada por una serie de casos de prueba. En cada caso, primero se describe
una ciudad. La primera línea contiene el número V de intersecciones de la ciudad (numeradas de
1 a V) y la segunda el número E de calles entre intersecciones. A continuación aparecen E líneas,
cada una con tres números: las intersecciones que une esa calle, y la anchura máxima que puede
tener un camión que transite por ella. Todas las calles son de doble sentido.
Tras la descripción de la ciudad, aparece un número K de consultas, seguido de K líneas, cada una
con tres números: dos intersecciones distintas, el origen y el destino, y la anchura de un camión,
del que estamos interesados en saber si podría viajar desde el origen hasta el destino.
Todos los casos cumplen que 2 ≤ V ≤ 10.000, 0 ≤ E ≤ 100.000 y 1 ≤ K ≤ 10. Todas las anchuras
son números entre 1 y 1.000.000.
Salida
Para cada caso de prueba se escribirán K líneas, una por consulta. La respuesta a una consulta
será SI si un camión de la anchura correspondiente podría recorrer un camino que le llevara del
origen al destino, y NO en caso contrario.

## Entrada de ejemplo
5  
5  
1 2 10  
1 3 30  
2 4 20  
3 4 15  
4 5 12  
3  
1 5 8  
1 4 12  
2 5 15  

## Salida de ejemplo
SI  
SI  
NO  