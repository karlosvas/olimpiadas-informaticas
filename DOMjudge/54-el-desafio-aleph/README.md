# El desafío de Aleph

Hace mucho tiempo, en una misteriosa tierra llamada Númerica,
existía una antigua orden secreta de programadores conocida como los Sabios del Código. Estos sabios eran famosos por su increíble habilidad para descifrar los secretos más ocultos del universo
digital.
Un día, el Gran Maestro de los Sabios, conocido como Aleph, reveló la existencia de un número supremo, cuyo valor estaba oculto
entre las sombras del misterio. Este número encerraba un poder
inimaginable y solo aquel que pudiera desentrañar su enigma sería merecedor de tanta
sabiduría.
Desafiados por el enigma, los programadores más valientes y astutos de todos los rincones
del reino se reunieron en el Gran Concurso de Adivinanza Numérica. Su objetivo era crear
un programa capaz de adivinar el número secreto de Aleph.
Tu misión, valiente programador, es crear un programa que pueda desvelar el número supremo haciendo propuestas de números a Aleph (sin agotarle). Pero antes de enfrentarte
al Gran Maestro, puedes practicar con el juez de este concurso, que te propone adivinar
varios números (uno a continuación de otro). Para eso deberás entablar una conversación
con él. Podrás hacer preguntas escribiéndolas a través de la salida estándar y leerás sus
respuestas a través de la entrada estándar.
La conversación se inicia cuando la máquina te proporciona dos números que indican el
rango en el cual se encuentra el número que ha seleccionado (entre 0 y 109
). A partir de ese
momento, la máquina estará esperando tus preguntas. Para realizar una pregunta, deberás
escribir una línea que contenga un signo de interrogación ‘?’ seguido del número por el cual
estás preguntando. La máquina responderá con ‘<=’ si el número que ha seleccionado es
menor o igual al que has propuesto, o ‘>’ si es mayor. Cuando hayas deducido el número
oculto, escribe en una línea independiente “Respuesta:” seguido del número que crees
que ha sido seleccionado. Esto terminará la conversación sobre este caso de prueba, y la
máquina te proporcionará otros dos números, un nuevo intervalo donde se encuentra el
número oculto.
La conversación llega a su fin cuando la máquina te proporciona un intervalo de 0 0.
A continuación aparece un ejemplo de ejecución. En cursiva aparece lo escrito por la máquina y en negrita lo escrito por un posible programa tuyo.
0 10
? 8

> ? 10  
> <=  
> ? 9  
> <=  
> Respuesta: 9  
> 0 0

### Nota

> Al tratarse de un problema interactivo es importante que cada vez que tu solución escriba
> algo que el juez deba leer se asegure de volcar la salida (usando terminología inglesa, haga
> “flush”). La forma de hacerlo varía entre lenguajes. En los admitidos en la competición puede
> hacerse con:
> • C++: cout << endl; o cout << flush;.
> • C: fflush(stdout);.
> • Java: System.out.flush();.
> • Python: print(..., flush=True) o sys.stdout.flush()
