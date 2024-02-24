# Desarrollos en las bicicletas

En ciclismo, el desarrollo es la distancia que una bicicleta particular recorre por cada pedalada completa dada. El valor depende del
diámetro de la rueda trasera, y de la relación de marchas (o razón de
cambio), es decir, de los tamaños relativos entre el plato (lado de los
pedales) y la corona o piñón (lado de la rueda).
Por ejemplo, si se da una pedalada completa en una bicicleta con
un plato de 52 dientes, la rueda dará cuatro vueltas completas si se
tiene una corona de 13 dientes, existiendo una relación 4:1 (parte superior de la imagen). Si, por el contrario, el plato tiene 24 y la corona 34,
la rueda dará menos de una vuelta por pedalada (parte inferior).
La configuración 52-13 es alta (la rueda da muchas vueltas), por lo
que proporciona velocidad a cambio de necesitar mucho esfuerzo. Por
su parte, la configuración 24-34 es baja, y proporciona fuerza pues dar
una pedalada cuesta menos trabajo, a costa de recorrer menos espacio. Para poder mantener una cadencia de pedaleo más o menos constante, las relaciones altas se
utilizan en llanos o cuestas abajo y las bajas cuando se realizan ascensos.
Las bicicletas tienen varios platos y varias coronas, y el ciclista debe decidir en cada momento
qué combinación utiliza. Cuando se comienza una cuesta arriba, por ejemplo, normalmente se
va haciendo descender la relación, lo que da la sensación de que la bicicleta “pesa menos”. El
problema es que el cambio de plato y de corona es independiente, y no siempre es fácil conseguir
una disminución secuencial de la relación. Por ejemplo, si una hipotética (e inexistente) bicicleta
tiene dos platos, uno con 34 dientes y otro con 48, y tres coronas de tamaños 20, 26 y 34 dientes,
el orden de menor a mayor desarrollo es:
Plato 34 34 48 34 48 48
Corona 34 26 34 20 26 20
Relación 1:1 17:13 24:17 17:10 24:13 12:5
Fíjate que para recorrerlos por orden, es necesario entrelazar diferentes tamaños en el plato.
Conocer este orden es importante para minimizar el esfuerzo montando en bici. ¿Eres capaz de
calcularlo?
Entrada
La entrada consiste en un conjunto de casos de prueba, cada uno compuesto de tres líneas. La
primera contiene dos números indicando respectivamente el número de platos (P) y de coronas (C)
de la bici, ambos menores que 20. La segunda línea contiene P números positivos con el número
de dientes de cada plato. La tercera línea lista la cantidad de dientes de cada una de las C coronas.
Todos los platos y coronas tendrán al menos 1 diente y nunca tendrán más de 1.000. Además, no
habrá dos desarrollos iguales.
El último caso de prueba es seguido por una línea con dos ceros.
Salida
Por cada caso de prueba se escribirán, de menor a mayor desarrollo, todas las combinaciones
posibles de platos y coronas. Para cada una se indicará primero el número de dientes del plato y
luego de la corona, separándolos por un guión. Dos combinaciones consecutivas se separarán por
un espacio.
1

## Entrada de ejemplo

2 3  
34 48  
20 26 34  
1 4  
44  
28 24 20 16  
0 0

## Salida de ejemplo

34-34 34-26 48-34 34-20 48-26 48-20  
44-28 44-24 44-20 44-16  
2
