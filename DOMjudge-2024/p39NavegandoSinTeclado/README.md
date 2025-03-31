# Navegandosin teclado

Lo de ayer fue un drama. Con los años que llevas criticando a todos los que abusan del ratón en lugar de utilizar las teclas rápidas, te tuvo quepasarati. Maldito teclado, que se tuvo que romper. Y encima endía festivo, imposible comprar otro. Todo el día utilizando el ordenador a través del lento e incómodo ratón. Menos mal que lo único que hiciste fue navegar por internet y pudiste ir de una página a otra utilizando los enlaces entre ellas. Una persona normal con el orgullo herido compraría un teclado de reserva. Pero tú no. Con un flamante teclado nuevo vas a hacer un programa que te ayude a decidir la manera más rápida de navegar si te vuelves a ver en la misma situación. Para eso has recopilado todas las páginas web que visitas y has hecho una lista de los enlaces que tiene cada una de ellas. Teniendo en cuenta la página de inicio que tienes en el navegadorquieressabercuáleslaformamásrápidadellegaraunapáginadeterminada utilizando únicamente esos enlaces. Como estás obsesionado por la velocidad, el programa tendrá en cuenta que el tiempo de carga de cadapágina puede ser distinto y que una vez cargada, encontrar y pinchar en cadaenlacedependedelolejosqueestédelprincipiodelapáginaydeloocultoqueesté. Venga, ¡manos a la obra!

## Entrada

La entrada estará compuesta por distintos casos de prueba terminados por una línea con un 0. Cada caso de prueba representa un escenario de navegación distinto, que incluye el conjunto de páginas a visitar, sus tiempos de carga y los enlaces que hay entre ellos. La primera línea de cada caso contiene el número Ndepáginasmanejadas(1<N≤1.000).
La página de inicio del navegador es la 1 y la página que queremos visitar la N. Acontinuación viene una línea con N números quecontiene el tiempo de carga (en milisegundos) de cada una de las páginas. AparecedespuésunalíneaconunnúmeroMindicandoelnúmerodeenlacesentrepáginas quesehanidentificado,trasloqueaparecenMlíneascadaunadescribiendounenlacecon la página en la que está, la página a la que va y el tiempo (en milisegundos) que se tarda desde que la página carga hasta que el usuario encuentra el enlace y lo pulsa. Se garantiza que todos los tiempos serán menores a 10 segundos y que en caso de que una página tenga más de un enlace a la misma página, únicamente se proporciona aquel que puede utilizarse antes.

## Salida

Para cada caso de prueba se escribirá el número mínimo de milisegundos que se tardará enpodernavegardesdelapágina1hastalapáginaNcontandoeltiempodecargadetodas las páginas (incluídas la 1 y la N) y el tiempo de localización y pulsación de cada enlace. Si no se puede alcanzar la página, se escribirá IMPOSIBLE.

### Entrada de ejemplo

4  
10 5 15 8  
5  
1 2 10  
1 3 20  
1 4 100  
2 4 20  
3 4 20  
4  
10 5 15 8  
4  
1 2 10  
1 3 20  
2 3 40  
4 2 10  
0

### Salida de ejemplo

53  
IMPOSIBLE
