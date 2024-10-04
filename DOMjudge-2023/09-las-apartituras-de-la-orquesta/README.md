# Las partituras de la orquesta

Para una orquesta modesta, gran parte del presupuesto
se va en la compra de las partituras. Si cada músico tiene
su propia copia, el número puede ascender a más de 100.
Afortunadamente, los músicos que tocan el mismo instrumento se sientan juntos y pueden compartir atril. Eso supone un ahorro considerable, aunque si se abusa demasiado puede provocar un efecto feo en la sala de conciertos. Al fin y al cabo ver a muchos músicos agolpándose
alrededor del mismo atril no es muy estético.
La sección de asuntos económicos de la orquesta nos ha informado del número de partituras que podremos comprar para la próxima obra que se tocará. Teniendo en cuenta el
número de músicos de cada instrumento, ¿cuál será el atril más concurrido?
Por ejemplo, si tenemos 8 violines, 5 violas, 5 violonchelos y 2 contrabajos y hay presupuesto para 6 partituras, podemos comprar dos copias de violines, dos de violas, una de
violonchelos y otra de contrabajos. En ese caso el atril más compartido será el de los violonchelos, con 5 músicos.

# Entrada
La entrada está compuesta de distintos casos de prueba, cada uno formado por dos líneas.
La primera contiene dos enteros, p y n, con el número de partituras que podremos comprar (hasta 200.000) y el número de instrumentos distintos que hay en la orquesta (hasta
100.000). Se garantiza que se podrá comprar al menos una partitura para cada tipo de
instrumento.
La segunda línea contiene n números positivos que indican la cantidad de músicos que hay
en la orquesta para cada uno de los instrumentos (como mucho 1.000).

# Salida
Por cada caso de prueba aparecerá un único entero indicando el número de músicos que
se agolparán en el atril más compartido cumpliendo las restricciones de la orquesta y presupuesto. Recuerda que el objetivo es minimizar la cantidad de gente en el atril más concurrido.

## Entrada de ejemplo
4 4  
8 5 5 2  
6 4  
8 5 5 2  
7 4  
8 5 5 2  

## Salida de ejemplo
8  
5  
4  