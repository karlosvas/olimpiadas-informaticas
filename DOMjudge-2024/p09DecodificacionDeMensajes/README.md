# Decodificación de mensajes

El agente 0069 ha inventado un nuevo método de codificación de mensajes secretos. El
mensaje original X se codifica en dos etapas: en primer lugar, X se transforma en X0
reemplazando cada sucesión de caracteres consecutivos que no sean vocales por su inversa;
en segundo lugar, X0
se transforma en la sucesión de caracteres X
00 obtenida al ir tomando sucesivamente el primer carácter de X
0, luego el último, luego el segundo, luego el
penúltimo, etc.
Por ejemplo, si X es Anacleto, agente secreto, X0
sería Analceto ,agetnes erceto y X00 (elmensaje cifrado) sería Aontaelccreet os e,natge.
¿Sabrías recuperar el mensaje original a partir de un mensaje cifrado?

## Entrada

La entrada está formada por una serie de casos de prueba. Cada caso ocupa una línea y
representa un mensaje cifrado con el método del agente 0069.

## Salida

Para cada caso se escribirá en una línea el mensaje descodificado.

### Entrada de ejemplo

Aontaelccreet os e,natge  
Moeihr aed eacrepbeadln ied o  
AuE ItOoUmbo ,coortriiuq

### Salida de ejemplo

Anacleto, agente secreto  
Me he aprendido el abecedario  
AEIOU, borriquito como tu
