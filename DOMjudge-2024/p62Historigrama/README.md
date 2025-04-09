# Histograma

Hay una imagen de n × n p´ıxeles que representa un histograma, es decir, un gr´afico de columnas en la
que hay n columnas que est´an marcadas con p´ıxeles negros hasta una cierta altura y con p´ıxeles blancos
m´as arriba.
Por ejemplo, esta imagen 6 × 6 representa un histograma con alturas 3, 1, 0, 5, 2, 3. La altura m´axima de
las columnas en este histograma es 5.
El objetivo es encontrar la altura m´axima de las columnas del histograma consultando como m´aximo
10 000 p´ıxeles de la imagen.

## Entrada y salida

Este es un problema interactivo. Debes refrescar la salida cada vez que imprimas datos (cout <<
endl o cout << flush en C++, System.out.flush() en Java, stdout.flush() en Python).
La primera l´ınea de la entrada contiene un entero n, la dimensi´on de la imagen. Debes leer este valor
antes de hacer ninguna pregunta.
Para consultar un p´ıxel debes escribir una l´ınea con el formato ? x y, donde x, y son las coordenadas del
p´ıxel que quieres consultar (0 ≤ x, y ≤ n − 1, x es la coordenada horizontal en el sentido de izquierda a
derecha e y es la coordenada vertical en el sentido de abajo a arriba ((0, 0) es la esquina inferior izquierda
y (n−1, n−1) la esquina superior derecha)). A continuaci´on debes leer una l´ınea con el resultado, que ser´a
un 1 si el p´ıxel es negro o un 0 si es blanco. En caso de que hayas superado el l´ımite de consultas o hayas
hecho una consulta inv´alida, leer´as un -1. Si tu programa lee un -1, debe terminar inmediatamente.
Para dar la respuesta debes escribir una l´ınea con el formato ! h, donde h es la altura m´axima de las
columnas del histograma (el m´aximo valor de h tal que existe un p´ıxel negro con coordenada y igual a
h − 1; si no hay ning´un p´ıxel negro, la respuesta es 0). Despu´es de escribir la respuesta tu programa
deber´ıa terminar.

XXVI Olimpiada Inform´atica Espa˜nola
Concurso de prueba
histograma

## Ejemplo

### Entrada:

6  
0  
0  
0  
0  
0  
0  
0  
0  
0  
1

### Salida:

? 0 5  
? 1 5  
? 2 5  
? 3 5  
? 4 5  
? 5 5  
? 0 4  
? 1 4  
? 2 4  
? 3 4  
! 5

Esta interacción se podría corresponder con la imagen de ejemplo.

### Restricciones

1 ≤ n ≤ 5 000.
Puedes hacer como mucho 10 000 consultas.

### Subtareas

1. (25 puntos) n ≤ 100.
2. (25 puntos) n ≤ 1000.
3. (25 puntos) n ≤ 2500.
4. (25 puntos) Sin restricciones adicionales.
