## Detecion de mancha negras
Dado un bitmap de pixeles blancos y negros, queremos, saber el número de manchas negras que contiene y el tamañio (numero de pixeles) de la mayor.

## Las componentes conexas
Son conjuntos de vértices en un grafo que están conectados entre sí por caminos, lo que significa que puedes llegar de cualquier vértice de una componente a cualquier otro vértice de la misma componente siguiendo aristas.

## auto &
El operador "auto &" se utiliza en C++ para declarar una variable usando la inferencia de tipo y una referencia. Por ejemplo, si tienes una variable "x" de tipo int y quieres declarar una variable "y" que sea una referencia a "x" con la inferencia de tipo, puedes hacerlo de la siguiente manera:
auto &y = x;

## Grafos bipartitos
Definición: Un grafo se considera bipartito si sus vértices pueden dividirse en dos conjuntos (llamémoslos A y B) de tal manera que todas las aristas del grafo conectan un vértice de A con un vértice de B.

Representación gráfica: En un grafo bipartito, puedes representar los vértices de un conjunto, por ejemplo A, en un lado y los vértices del otro conjunto, B, en el otro lado. Las aristas siempre cruzarán de un lado al otro.

Propiedad clave: En un grafo bipartito, no puede haber un ciclo de longitud impar. Esto significa que si sigues un camino a lo largo de las aristas, el número de aristas que recorres siempre será par.

Ejemplos comunes: Los ejemplos clásicos de grafos bipartitos son los grafo de asignación (matching), en los que puedes emparejar elementos de un conjunto con elementos de otro (por ejemplo, emparejar estudiantes con proyectos en un programa de asignación de proyectos).

Aplicaciones: Los grafos bipartitos se utilizan en muchas aplicaciones del mundo real, como la asignación de recursos, la representación de redes de flujo, la modelización de relaciones entre dos conjuntos de entidades, entre otros.

Para determinar si un grafo es bipartito, puedes utilizar algoritmos como el "Algoritmo de Búsqueda en Anchura (BFS)" para colorear los vértices de dos colores diferentes y asegurarte de que no haya dos vértices adyacentes con el mismo color.