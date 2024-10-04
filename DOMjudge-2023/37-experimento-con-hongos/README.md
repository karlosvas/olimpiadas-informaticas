# Experimento con hongos

Virginia es una experta microbióloga que disfruta estudiando distintos
tipos de levaduras. Las levaduras son, generalmente, hongos unicelulares que se reproducen de manera asexual. Es decir, cada hongo tiene un
único progenitor, que es genéticamente idéntico a él.
El último descubrimiento de Virginia parece ser un gran hallazgo. Ha conseguido un nuevo tipo de hongo que se reproduce a intervalos de tiempo
completamente regulares. Es como si cada hongo tuviese un «contador
biológico» que determina cuándo debe reproducirse. Este contador se
decrementa cada hora, y cuando llega a cero, el hongo se reproduce y
reinicia su contador. Cuando un hongo se reproduce da lugar a una yema, que tiene que crecer
y separarse de su progenitor antes de convertirse en un hongo «adulto». Por este motivo, una
yema tarda más que un hongo adulto en reproducirse por primera vez, pero una vez que lo ha
hecho, su ciclo de reproducción pasa a ser el mismo que el del resto de hongos adultos.
Por ejemplo, supongamos que el ciclo de reproducción de un hongo es de 5 horas, y que una yema tarda 7 horas en reproducirse por primera vez. Comencemos con un hongo (al que llamamos
H1
) cuyo contador interno tiene el valor 5.
t = 0 h
Hongo H1
Contador 5
El contador de H1
se decrementa a cada hora, por lo que, transcurridas cuatro horas, su contador
alcanza el valor 1.
t = 4 h
Hongo H1
Contador 1
Una hora después, el hongo H1
da lugar a una nueva yema H2
, y reinicia su contador a 5. La yema
recién nacida tiene el contador a 7 porque no se reproducirá por primera vez hasta pasadas siete
horas.
t = 5 h
Hongo H1 H2
Contador 5 7
Transcurridas cuatro horas desde la situación anterior, tenemos lo siguiente:
t = 9 h
Hongo H1 H2
Contador 1 3
Una hora después, H1
vuelve a reproducirse, creando otra yema H3
. El contador de H1
vuelve a
reiniciarse a 5.
t = 10 h
Hongo H1 H2 H3
Contador 5 2 7
Transcurridas dos horas más, H2
se reproduce, dando lugar a H4
:
t = 12 h
Hongo H1 H2 H3 H4
Contador 3 5 5 7
Tres horas después, H1
se reproduce y nace H5
:
t = 15 h
Hongo H1 H2 H3 H4 H5
Contador 5 2 2 4 7
Dos horas después, tenemos la siguiente situación:
t = 17 h
Hongo H1 H2 H3 H4 H5 H6 H7
Contador 3 5 5 2 5 7 7
Tres horas después, tenemos la siguiente situación:
t = 20 h
Hongo H1 H2 H3 H4 H5 H6 H7 H8 H9
Contador 5 2 2 4 2 4 4 6 7
Es decir, transcurridas 20 horas desde el inicio del experimento, la colonia llega a tener 9 hongos.
Manipulando las condiciones de humedad y temperatura, Virginia puede alterar a voluntad el
tiempo de reproducción de los hongos adultos y el tiempo de crecimiento de las yemas. Por
desgracia, como la colonia de hongos se reproduce de manera exponencial, enseguida pierde la
cuenta del número de hongos que hay en cada momento. ¿Puedes ayudarla?
Entrada
La entrada consta de una serie de casos de prueba. Cada uno de ellos ocupa una línea que
contiene tres números enteros N, M y T. El número N indica cada cuántas horas se reproduce un
hongo adulto. El número M indica cuántas horas pasan desde que nace una yema hasta que se
reproduce por primera vez. El número T indica la duración total (en horas) del experimento. Se
cumple que 0 < N < M < 1.500 y que 0 ≤ T ≤ 3.000.
Salida
Para cada caso de prueba debe imprimirse una línea con el número de hongos que existen en
la colonia transcurridas T horas desde el inicio del experimento, suponiendo que comienza con
un único hongo adulto cuyo contador biológico tiene el valor N. Se garantiza que el número de
hongos siempre es inferior a 109
.

## Entrada de ejemplo
5 7 10  
5 7 15  
5 7 20  
3 4 0  
3 4 50  

## Salida de ejemplo
3
5
9
1
18884