# Unidad Curiosa de Monitorización

La Unidad Curiosa de Monitorización (UCM) se encarga de leer los datos proporcionados por una serie de sensores y enviar con cierta periodicidad los datos obtenidos y procesados a los usuarios que se han
registrado previamente.
La UCM admite que los usuarios se registren proporcionando un Identi-
ficador, un número entre 103 y 109 que identifica de forma única al usuario, y un Periodo, el intervalo de tiempo que transcurrirá entre dos envíos
consecutivos de información a ese usuario (entre 1 y 5.000). Es decir, cuando hayan pasado
Periodo segundos desde que el usuario se registró, este recibirá la información de la UCM
por primera vez; y después recibirá la información cada Periodo segundos.
Acaban de registrarse varios usuarios, todos con identificadores dintintos. ¿Podrías decir a
quiénes irán dirigidos los K primeros envíos de información? Si dos o más usuarios tienen
que recibir la información al mismo tiempo, los envíos se realizan en orden creciente de
sus identificadores de usuario.

## Entrada

La entrada consta de una serie de casos de prueba. Para cada uno, primero aparece el número de usuarios que se acaban de registrar (no más de 25.000). A continuación, aparecen
los datos de las órdenes de registro de cada uno de ellos (el identificador de usuario y la
periodicidad con la que desea recibir información). Y por último aparece el número K de
envíos cuyo destinatario se desea conocer (1 ≤ K ≤ 100.000). La entrada termina cuando
el número de usuarios sea 0.

## Salida

Para cada caso se escribirán los identificadores de los usuarios que recibirán los K primeros
envíos, uno por línea.
Después de cada caso se escribirá ---.

### Entrada de ejemplo

2  
1234 200  
9000 300  
5  
0

### alida de ejemplo

1234  
9000  
1234  
1234  
9000

---
