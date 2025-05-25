# Teclado estropeado

Ya no se fabrican los teclados como antes. Después de unos pocos meses, a Jacobo el suyo
le ha empezado a hacer cosas raras. En concreto, cuando pulsa ciertas teclas el teclado
parece interpretar que se han pulsado otras.
Después de un rato de análisis ha llegado a la conclusión de que la pulsación de la tecla
del guion (-) tiene el mismo resultado que si pulsa la tecla Inicio, y el cursor se le va al
principio de la línea. Algo parecido le ocurre con el +, que se lleva el cursor al final igual
que la tecla Fin. Y al pulsar "\*" se consigue el mismo efecto que con la tecla de la fiecha
derecha. Pero lo peor de todo es lo que ocurre con el 3: ¡hace lo mismo que la tecla Supr,
que borra la letra que hay a la derecha del cursor!
El resultado es que cuando Jacobo se pone a copiar un texto sin mirar la pantalla, el resultado final de lo que ha escrito puede terminar siendo muy distinto de lo que quería escribir.
¿Qué texto saldrá como resultado de la pulsación de una serie de teclas?

## Entrada

La entrada consta de un número indeterminado de líneas que deben ser consideradas
independientes. Cada una contiene la secuencia de pulsaciones de Jacobo.

## Salida

Para cada caso de prueba se mostrará en una línea el texto final que obtendrá Jacobo tras
pulsar las teclas indicadas en el orden dado.

### Entrada de ejemplo

OIE
OIE-333
dI-3\*E-O+
OIE-3O\*3E

### Salida de ejemplo

OIE  
OIE

OIE
