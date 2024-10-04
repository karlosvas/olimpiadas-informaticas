# La máquina calculadora
A Javier le gusta la electrónica y cacharrear para construir máquinas
que tengan cierto propósito. Ahora que su hijo Luis está aprendiendo a calcular le ha construido una máquina con un marcador, en el
que aparecen cuatro dígitos y tres botones marcados con etiquetas
+1, *2 y ÷3, que al ser pulsados actualizan el marcador realizando
la operación correspondiente (sumar uno, multiplicar por dos o dividir entre tres). Como el marcador solamente tiene cuatro dígitos, las
operaciones se realizan módulo 10.000 y la división es entera.
Luis ha entendido perfectamente el funcionamiento de la máquina y la utiliza para comprobar
que los cálculos que hace mentalmente antes de pulsar un botón son correctos. Ahora Javier le
ha retado con un juego: él configura el marcador para que aparezca un número concreto y le pide
a Luis que consiga llegar a otro número pulsando los botones el menor número de veces.
¿Puedes ayudarles calculando cuál es el menor número de pulsaciones que hay que realizar para
conseguir que aparezca el número final a partir del original?
Entrada
El programa dará respuesta a una serie de casos de prueba. Cada caso consiste en una única
línea con dos números (entre 0 y 9.999), el que aparece originalmente en el marcador y el que
Luis debe conseguir pulsando los botones de la máquina calculadora.
Salida
Para cada caso de prueba, se escribirá en una línea el menor número de pulsaciones necesarias
para conseguir el número final a partir del original.

## Entrada de ejemplo
0 1024
5000 0
9999 6666
## Salida de ejemplo
11
1
2