# Los parasoles

Nuestro tranquilo pueblo lleva siglos dedicado a la explotación agrícola con plantaciones
de girasoles. De hecho, cuenta la leyenda que fuimos unos de los primeros en cultivarlos
tras su llegada a Europa.
Desgraciadamente, en los últimos tiempos nuestras tierras están siendo afectadas por unos
pequeños gusanos, los parasoles, que mordisquean los tallos de nuestras plantas e impiden
que estas giren para mirar al Sol.
El ataque de los parasoles es siempre el mismo. Los gusanos entran en un cultivo por la
esquina inferior derecha (mirando el cultivo desde arriba) y se van extendiendo formando un
rectángulo. El resultado es que cuando se hace una foto del terreno se ve que una sección
rectangular en la parte inferior derecha está llena de plantas que no miran al Sol.
Para poder evaluar los daños, el ayuntamiento ha comprado un dron que podemos enviar
a un punto concreto de la plantación para saber si en esa zona las plantas han girado o no.
Lo que necesitamos ahora es decidir a qué puntos mandamos al dron para saber cómo de
afectada está un área determinada.
Como ejemplo, si tenemos un cultivo de tamaño 8×6 y mandamos al dron a las coordenadas
(3,4), (7,3) y (2,5) y solo en la primera detecta parasoles, entonces sabremos con certeza
que la zona afectada va desde la posición (3,4) hasta la esquina inferior derecha. La figura
siguiente ilustra este ejemplo mostrando en amarillo las zonas sanas y en negro las zonas
afectadas por los parasoles:
1 2 3 4 5 6 7 8  
1  
2  
3  
4  
5  
6  
1 2 3 4 5 6 7 8  
1  
2  
3  
4  
5  
6  
Nuestra tarea consiste en crear una aplicación que ayude al técnico del ayuntamiento a
decidir dónde enviar el dron para poder averiguar rápidamente la posición de la esquina
superior izquierda del rectángulo afectado de varios cultivos. La aplicación recibirá el tamaño de la parcela e irá solicitando al operario que envíe al dron a distintas coordenadas.
En base a lo que vea el dron en cada posición, la aplicación decidirá dónde le envía a continuación.
El funcionamiento exacto es el siguiente. Al arrancar, la aplicación se quedará esperando
a que el operario introduzca por teclado el tamaño de la parcela a analizar (dos números,
TamX y TamY). A continuación irá pidiendo al operario que mande al dron a los sitios que
estime convenientes para ver la situación en esa zona. Para eso, escribirá en líneas independientes comandos de la forma: “? posX posY”. El técnico del ayuntamiento irá mandandando al dron a cada una de esas posiciones y a su vuelta escribirá en el teclado un 0 si
la zona está intacta y un 1 si la zona ha sido afectada por los parasoles. Cuando la aplicación
conozca el resultado, escribirá una línea con “=> posX posY” con la esquina solicitada; en
ese momento el operario escribirá un nuevo tamaño de parcela comenzando de nuevo el
ciclo o bien escribirá un tamaño vacío (“0 0”) lo que hará que nuestra aplicación termine.
A continuación aparece un ejemplo de ejecución. En cursiva aparecen los datos introducidos por el operario y en negrita los escritos por la aplicación.
2 3  
? 1 1  
1  
=> 1 1  
8 6  
? 3 4  
1  
? 7 3  
0  
? 2 5  
0  
=> 3 4  
0 0

### Restricciones

1 ≤ TamX, TamY ≤ 105

### Subtareas

1. (2 puntos) TamY ≤ 10, TamX ≤ 10 y la respuesta es (TamX,TamY)
2. (10 puntos) TamY = 1, TamX ≤ 10
3. (4 puntos) TamY = 2, TamX ≤ 10
4. (40 puntos) TamY = 1, TamX ≤ 105
5. (4 puntos) TamY = 2, TamX ≤ 105
6. (40 puntos) sin restricciones adicionales
   Nota
   Al tratarse de un problema interactivo es importante que cada vez que tu solución escriba
   algo que el juez deba leer se asegure de volcar la salida (usando terminología inglesa, haga
   “flush”). La forma de hacerlo varía entre lenguajes. En los admitidos en la competición puede
   hacerse con:
   • C++: cout << endl; o cout << flush;.
   • C: fflush(stdout);.
   • Java: System.out.flush();.
   • Python: print(..., flush=True) o sys.stdout.flush()
