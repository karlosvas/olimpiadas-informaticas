# Trie Hard

Al igual que John McClane y Zeus Carver en La Jungla de Cristal III,
te encuentras en una situación extremadamente delicada. Estás
atrapado en una habitación con tres garrafas de agua dispuestas
frente a ti. La primera está completamente llena, la segunda está
vacía y la tercera también se encuentra sin agua. Cada una de estas
garrafas tiene una capacidad diferente y, lo que es más importante,
no hay otra fuente de agua disponible.
La gravedad de la situación se vuelve evidente cuando notas un cronómetro que marca el
tiempo restante. Un dispositivo de alto riesgo, una bomba, está conectado a estas garrafas.
Si no logras transferir una cantidad exacta de agua a una cualquiera de las garrafas antes
de que el cronómetro llegue a cero, la bomba explotará.
No tienes nada para medir el agua, salvo las propias garrafas, por lo que la única forma de
manipular el agua es verterla de una garrafa a otra, pero con mucho cuidado: solo puedes
verter agua de una garrafa a otra hasta que la primera se vacíe completamente o la segunda
se llene al límite. Así sabrás en cada momento cuánta cantidad de agua tiene cada garrafa.
Esto significa que cada movimiento debe ser calculado con precisión. Cada segundo eres
capaz de mover un litro de agua y debes alcanzar el objetivo en el menor tiempo posible,
o dicho de otra manera, con la menor cantidad de agua trasvasada de una garrafa a otra.
El tic-tac del cronómetro parece resonar más fuerte con cada segundo que pasa. ¿Podrás
resolver este enigma y evitar la inminente explosión? ¡El tiempo corre inexorablemente!
Entrada
La entrada comienza con el número de casos de prueba que vendrán a continuación.
Cada caso de prueba ocupa una línea de la entrada y consta de cuatro números (entre 1 y
1.000). Los tres primeros son las capacidades de las tres garrafas (la primera es la que inicialmente está llena y las otras dos vacías). El cuarto número es la cantidad que queremos
conseguir en alguna de las tres garrafas, no importa en cuál.
Salida
Por cada caso de prueba se escribirá una línea con la cantidad mínima total de agua que es
necesario trasvasar entre las garrafas para conseguir el objetivo. Si no es posible conseguir
dicha cantidad, se escribirá BOOM en su lugar.

## Entrada de ejemplo
3
8 5 3 4
4 3 2 2
6 3 1 8

## Salida de ejemplo
19
2
BOOM