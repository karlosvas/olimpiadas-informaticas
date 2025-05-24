# Girar o no girar

Sergey y Dmitry, dos viejos veteranos, han estado horas recordando
viejas batallas vividas cuando las guerras se libraban entre barro, trincheras y silvidos de mortero, y no pilotando drones asesinos a miles
de kilómetros de distancia. El vodka siempre ayuda para traer a la
memoria a los camaradas muertos hechos pedazos en escaramuzas
por conquistar colinas perdidas en mitad de ningún sitio que ya a nadie
le importan.  
El vodka y, por qué no decirlo, una vieja rencilla por culpa de una
antigua novia demasiado alegre que dejó a uno para caer en los brazos
del otro, ha caldeado el ambiente más allá de lo prudente. No ayuda a que los ánimos se serenen
que encima de la mesa, acompañando a los vasos de vodka vacíos, haya un revólver que alguno
ha decidido llevar para ambientar la reunión.
Los vapores del alcohol han llevado a Sergey a cargar el tambor del revólver con unas cuantas
balas, cerrarlo y hacerlo girar. Con ojos vidriosos ha propuesto a su camarada jugar a la ruleta rusa
y sin esperar respuesta se ha acercado el cañón a la sien y ha disparado.  
¡CLICK!  
El percutor no ha encontrado proyectil y Sergey ha salvado la vida. El tambor ha avanzado una
posición y ahora es el turno de Dmitry que, sin haber tenido tiempo de rechazar participar en el
macabro juego, se ve ahora obligado a dispararse para no mancillar su honor. No sabe si en la nueva
posición habrá o no una bala que acabe con su vida, pero mientras su antiguo camarada colocaba
las balas aleatoriamente, él se ha fijado en sus posiciones. Sabiendo que en la posición anterior a
la que ahora está delante del percutor no había una bala, se pregunta si tiene más posibilidades de
sobrevivir si dispara o si antes de hacerlo hace girar aleatoriamente el tambor para que se recoloque
en algún sitio desconocido.

## Entrada

Cada caso de prueba es una línea con una cadena formada únicamente por ceros y unos de al
menos 2 y no más de 1000 caracteres. La cadena representa el estado del tambor del arma, donde
un 0 indica una posición sin bala y un 1 indica una posición con bala. Tras disparar, el tambor gira de
modo que el percutor pasa a estar sobre la posición situada a la derecha en la cadena de entrada.
La última posición simbolizada por la cadena tiene a su derecha a la primera.

## Salida

A partir de las posiciones de las balas en el tambor, el programa debe analizar qué alternativa
maximiza las posibilidades de sobrevivir. Si es mejor girar el tambor para que se sitúe en una posición aleatoria se escribirá Girar. Si es preferible disparar directamente se escribirá No girar. Si las
probabilidades de sobrevivir son indiferentes a lo que se haga se escribirá Da igual.

### Entrada de ejemplo

010101  
000111  
0011

### Salida de ejemplo

Girar  
No girar  
Da igual
