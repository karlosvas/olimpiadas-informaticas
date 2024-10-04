# Petroleros hundidos
Desgraciadamente, las asociaciones ecologistas se ven obli-
gadas a hacer frente, periódicamente, a las llamadas “ma-
reas negras”. En ellas, grandes cantidades de crudo son ver-
tidas al mar, dejando enormes superficies de agua con pe-
tróleo flotando a la deriva.
Para estimar los daños medioambientales, se realizan foto-
grafías de las zonas afectadas utilizando satélites geoesta-
cionarios. La superficie del mar queda dividida en una reji-
lla de celdas, cada una marcada como zona contaminada
o como zona limpia (al menos de momento). Las imágenes obtenidas son también usadas para
organizar los trabajos de limpieza, para los que no es importante la superficie total contaminada,
sino la superficie contigua más grande (mancha más grande). Dada una fotografía del satélite, dos
celdas contaminadas de petróleo (negras) se consideran pertenecientes a la misma mancha si se
puede llegar de una a otra atravesando solo celdas contaminadas realizando desplazamientos
en cualquiera de las 8 direcciones (horizontal, vertical, y dos diagonales).
Cuando el petrolero se hunde, muchas veces sigue derramando crudo que, al emerger, aumenta
la zona contaminada y puede hacer que cambie cual es la mayor mancha. Por ejemplo, en el
siguiente esquema se muestra la primera imagen que se tomó, y la evolución horaria al ir subien-
do más crudo desde las profundidades del mar. En cada una, se marca con puntos blancos las
celdas de la mancha más grande (con su tamaño en el pie de la imagen), y con una cruz la última
celda que ha pasado a estar contaminada.

## Entrada
La entrada estará compuesta por diversos casos de prueba. Para cada caso, la primera línea
contendrá el número F de filas y el número C de columnas de la rejilla (números entre 1 y 1.000).
A continuación aparecerán F líneas, cada una con C caracteres. El espacio en blanco representa
una celda azul (mar) y el carácter # representa una celda contaminada de negro petróleo. En la
siguiente línea aparecerá un número no negativo N (no mayor de 100.000) indicando el número
de imágenes adicionales tomadas (en cada una aparece una nueva celda de petróleo), seguido
de N líneas cada una con dos enteros que indicarán la fila (entre 1 y F) y columna (entre 1 y C)
donde aparecerá esa celda contaminada.
## Salida
Para cada caso de prueba se escribirá una línea con el tamaño de la mancha de petróleo más
grande inicialmente, seguido de los tamaños tras añadir cada una de las nuevas celdas contami-
nadas, separados por espacios. Las superficies se miden en número de celdas.
### Entrada de ejemplo

8 8  
```
 # #   #  
 ###  ##  
     ###  
 #  
 # #  
 ###  ##  
###   ##  
  #  
```
3  
6 8  
2 5  
6 5  

### Salida de ejemplo
10 10 12 16