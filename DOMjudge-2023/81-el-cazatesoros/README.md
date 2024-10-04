# El cazatesoros

Marcos es cazatesoros. Acaba de localizar un barco pirata que se hundió
hace siglos y repartió a su alrededor cofres llenos de monedas de oro. Un
sofisticado sistema de sonar le ha permitido identificar la posición, la profundidad y la cantidad de oro de cada uno de estos cofres. Por desgracia,
Marcos solamente dispone de una botella de aire comprimido para realizar las inmersiones de recuperación. Para más inri, olvidó traer su GPS
por lo que no puede volver a puerto a por más botellas porque las posibilidades de volver
a encontrar el pecio serían casi nulas.
Marcos quiere bucear y recuperar todo el oro que sea posible. Sabe que la botella le permitirá estar debajo del agua T segundos; que en cada inmersión solamente podrá subir uno
de los cofres; y que el tiempo de descenso a una profundidad p es de p segundos mientras
que el tiempo de ascenso es de 2p segundos.
¿Puedes ayudarle a decidir cuáles son los cofres que debe recoger para maximizar la cantidad de oro recuperada?

## Entrada

La entrada está compuesta por diversos casos de prueba. Para cada uno, la primera línea
contiene el valor T, los segundos que permite la botella estar debajo del agua (un entero
entre 1 y 10.000). La segunda línea contiene el número N de cofres encontrados (un entero
entre 1 y 100). A continuación, aparecen N líneas cada una con dos enteros, que representan
la profundidad a la que se encuentra (un entero entre 1 y 500) y la cantidad de oro que
contiene (un entero entre 1 y 10.000) cada uno de los cofres.

## Salida

Para cada caso de prueba, primero se escribirá una línea con la máxima cantidad de oro
que se puede recuperar. Después se escribirá otra línea con el número de cofres a recoger,
seguida de una línea por cada uno de ellos con la información de cada uno: profundidad
y cantidad de oro. Los cofres deben presentarse en el mismo orden que aparecen en la
entrada. Se garantiza que la solución óptima es única.
Después de la salida de cada caso se escribirá ---.

### Entrada de ejemplo

210  
3  
40 5  
40 1  
25 2  
200  
5  
25 4  
50 5  
40 4  
10 2  
70 10  
29  
1  
10 20

### Salida de ejemplo

7  
2  
40 5  
25 2  
\---  
8  
2  
25 4  
40 4  
\---  
0  
0  
\---
