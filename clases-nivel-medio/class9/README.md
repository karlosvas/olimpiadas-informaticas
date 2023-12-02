# Aplicaciones del algoritmo de Dijkstra
Como construirlo sin tener un grafo explícito (ejercicio garrafas.cpp).
Utilizamos estados.
```cpp
using estado = pair<int,int>; // cantidad de agua en la primera garafa, cantidad de agua en la segunda garrafa.
using info = pair<int,estado>; // <agua movida, estado>
```
Se define el tipo `estado` como un par de enteros que representa la cantidad de agua en la primera garrafa y la cantidad de agua en la segunda garrafa. Por ejemplo, un estado podría ser `(3, 5)`, lo que significa que hay 3 unidades de agua en la primera garrafa y 5 unidades de agua en la segunda garrafa.

La estructura `info` se define como un par de enteros, donde el primer elemento representa la cantidad de agua movida y el segundo elemento es un estado. Por ejemplo, un `info` podría ser `(2, (3, 5))`, lo que significa que se movieron 2 unidades de agua y el estado resultante es `(3, 5)`.

Lógica para tener el cuenta el siguiente.
```cpp
if(t + muevo < dist[nuevo[0]][nuevo[1]]){ // Puedo mejeorar.
    dist[nuevo[0]][nuevo[1]] = t + muevo;
    cola.push({t + muevo, {nuevo[0], nuevo[1]}});
}
```
Aquí, `t` representa el agua movida, `muevo` es una variable que ayuda a rastrear la cantidad de agua que se está transfiriendo entre las garrafas en cada paso del algoritmo. `nuevo` es el nuevo estado resultante después de mover el agua. Si la suma es menor que la distancia almacenada en `dist`, se actualiza la distancia y se agrega el nuevo estado a la cola de prioridad `cola`.

# Caminos mínimo con un número par de aristas
Haze falta saber con que paridad se llega a cada vétice.
Lo buscamos en un sistema de transiciones mediante estados.
Formando un grafo implícito, sobre la marcha.
Podemos alternar entre en estado <x,0> o <x,1>.
