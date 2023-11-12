# Ovejas negras

Parece ser que en cierta ocasión estaban de viaje por Escocia un abogado, un
físico y un matemático. Por la ventanilla del tren en el que viajaban vieron un
campo con ovejas negras. Ninguno de los tres había visto ovejas negras nunca,
por lo que se estableció un curioso diálogo entre ellos:
— ¡Vaya! ¡En Escocia las ovejas son negras! —dijo el abogado.
— Querrás decir que en Escocia algunas ovejas son negras... —corrigió el físico.
— Bueno, —no pudo evitar decir el matemático— con lo que hemos visto lo único que podemos
decir es que en Escocia algunas ovejas son negras... ¡por un lado!
Para comprobar si el abogado tenía razón o no, se han tomado fotografías a todas las ovejas de
Escocia, y ahora hay que analizarlas para ver si aparecen ovejas blancas (al menos por un lado).
Entrada
La entrada estará compuesta por distintos casos de prueba, cada uno siendo una instantánea de
una o más ovejas escocesas. Cada foto comienza con una línea con dos números indicando el
ancho y el alto (en píxeles) de la imagen (números entre 1 y 100). A continuación viene la imagen
en blanco y negro en donde el carácter ‘.’ representa el color blanco y ‘X’ el negro.
Se puede asumir que:
El fondo de la imagen es siempre blanco.
Todas las ovejas tienen la silueta negra. Las ovejas blancas tienen todo blanco en su interior.
Las ovejas nunca se solapan (es decir, en las fotos las ovejas nunca se tocan).
Ninguna oveja entra en contacto con los bordes de la foto (es decir, en todas las fotos la
primera y última fila y la primera y última columna son ‘.’).
En la foto solo aparecen ovejas.
Salida
Para cada caso de prueba se escribirá el número de ovejas blancas que aparecen en la foto.

## Entrada de ejemplo
16 8
................
..........XXX...
.....XXXXXXXX...
....XXXXXXX.....
.....XXXXX......
.....X...X......
.....X...X......
................
30 8
..............................
.......XXX..XXX...............
..XXXXXXXX..XXXXXXXX.....XX...
.X.....X......XXXXXXX...XXXX..
..XXXXX........XXXXX....X..X..
..X...X........X...X....XXXX..
..X...X........X...X....X..X..
..............................

## Salida de ejemplo
0
2