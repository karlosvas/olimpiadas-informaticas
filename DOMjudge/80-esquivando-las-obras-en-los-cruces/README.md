# Esquivando las obras en los cruces

Cuadracity es un lugar muy agradable para pasear. O lo era…En esta ciudad las calles van
de norte a sur o de este a oeste, dividiendo la ciudad en manzanas cuadradas regulares. En
todas las intersecciones hay pasos de peatones que los vehículos respetan escrupulosamente. Pero las próximas elecciones están a la vuelta de la esquina y el Ayuntamiento ha
decidido arreglar de repente muchas de estas intersecciones, por lo que hay engorrosas
obras en muchas de ellas.
Supón que te encuentras en la esquina noroeste de la ciudad y quieres ir a la estación de
tren, que se encuentra en la esquina sureste, sin caminar más de lo imprescindible y evitando las intersecciones donde se están realizando obras, ya que hay polvo, mucho ruido
y suponen un retraso extra. ¿De cuántas formas distintas puedes realizar este recorrido satisfaciendo ambas restricciones?
Por ejemplo, la siguiente figura ilustra el caso de una ciudad con cuatro calles este-oeste
y cinco calles norte-sur. Hay tres intersecciones marcadas con obras. El recorrido desde la
esquina noroeste a la estación de tren requiere atravesar 3 + 4 = 7 manzanas, y hay cuatro
formas distintas de hacerlo que evitan las obras.

## Entrada

La entrada está formada por una serie de casos de prueba. Cada caso comienza con una
línea con dos números: el número N de calles este-oeste y el número M de calles norte-sur
(1 ≤ N, M ≤ 50). Las siguientes N líneas contienen cada una M caracteres, que describen
lo que ocurre en cada intersección. El carácter ‘.’ significa que la intersección está libre de
obras mientras que el carácter ‘X’ indica que la intersección está siendo remodelada. Las
esquinas noroeste y sureste no tienen nunca obras.

## Salida

Para cada caso de prueba se escribirá una línea con el número de caminos distintos que
van de la esquina noroeste a la esquina sureste sin ser más largos de lo imprescindible (si
hay N×M calles, el camino más corto recorre (𝑁 −1)+ (𝑀−1) manzanas) y sin pasar por obras.
Ese número será siempre menor que 109.

## Entrada de ejemplo

4 5  
.....  
.X...  
..X.X  
.....  
3 5  
.X...  
...X.  
XXX..

## Salida de ejemplo

4  
0
