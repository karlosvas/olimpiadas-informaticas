# Exposición de arte

Doc ha recibido ya las piezas de arte para la exposición, pero
aún la tiene a medio montar. Su principal problema es que indicó a los artistas que le enviaran a su casa las obras y ahora
tiene que trasladarlas al lugar de la exposición.
En teoría, esa labor de mudanza es fácil: se alquila un camión,
se carga y se llevan. En la práctica, sin embargo, la situación es
un poco más difícil. Aunque las obras son pequeñas (en un único camión entrarían todas),
pesan mucho. Eso significa que debe tener cuidado a la hora de escoger el camión que
alquile y fijarse en cuál es el peso máximo que es capaz de transportar.
La tarea se complica un poco porque:
• El precio del alquiler del camión es proporcional a la carga máxima que soporta, por
lo que quiere reducirla al máximo incluso aunque eso implique hacer más de un viaje.
• Aunque teniendo en cuenta el tiempo de que dispone Doc para realizar la mudanza,
tiene limitado el número de viajes que puede hacer con el camión.
• Además, para evitar tener que mover mucho las obras dentro de casa de Doc, las
piezas las cargará en el camión en el mismo orden en el que están colocadas en el
pasillo de la entrada.
Tenemos que ayudar a Doc a elegir el camión que debe alquilar.

### Entrada

La entrada estará compuesta de varios casos de prueba.
Cada caso de prueba ocupa dos líneas. La primera tiene el número de obras de arte que
se agolpan en el pasillo de Doc (como mucho 100.000) y el número máximo de viajes que
Doc tiene tiempo de hacer con el camión (como mucho 100). Ambos números son mayores
que cero.
La segunda línea contiene los pesos de las distintas obras que hay que transportar en el
orden en el que deben ser trasladadas. Se garantiza que la suma de los pesos de todas las
obras es inferior a 109
.
La entrada termina con una línea con dos ceros que no debe procesarse.

### Salida

Por cada caso de prueba se escribirá una única línea con el tope de carga más pequeño
que debe tener el camión alquilado para poder hacer la mudanza de todas las obras sin
pasarse del número de viajes máximo establecido ni superar la carga máxima del camión.

## Entrada de ejemplo

3 1  
3 4 5  
3 2  
3 4 5  
3 2  
3 5 4  
3 3  
3 4 5  
0 0

## Salida de ejemplo

12  
7  
8  
5
