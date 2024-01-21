# Árbol de recubrimientio mínimo.

Dado un Grafo no dirijido G, un árbol de recubrimiento de G es un sugrafo de T tal que:

- T es un árbol: Es conexo y acíclico.
- T es de recubrimeinto: alcanza todos los vértices de G.

Si T es u árbol de revubrimeinto de un grafo G con V vértices:

- T contiene V-1 aristas.
- Al eliminar cualquier areista de T deja de ser conexo.
- Añadir cualquiero arista a T crea un ciclo.

### ARM

Dado un grafo valorado no dirigido G, encontrar un árbol de recubrimiento de coste mínimo (ARM).

### Aplicaciones en las que se usa el ARM

Verificación facial a tiempor real.
Búsqueda de redes de carreteras en imágenes de satélites o aéras.
Reduccion del almacenamiento de datos en la secuyenciación de aminoácidos de una proteína.
Modelar la localidad de interacciones entre películas en flojos de fluidos turbulentos.
Algoritmos de añproximacionpara problemas NP-dificiles (por ejemplo, TSP árbol de Steiner).
Deiseño de redes (comunicaciones, électricas, hidráulicas, informáticas, viales).

## Algoritmo de Kruskal

Considera las aristas en orden creciente de coste, y cada arista se seleciona si no crea ciclos.

## Algoritmo de Prim

Comienza en un vértice y contruye el árbol a partir de él, añadiendo cada vez la arista de menor coste que extiende el árbol.

## Varianes del problema del ARM

Árbol de recubrimiento máximo.
Subgrafo de recubrimiento "mínimo". Algunas aristas del grafo original ya están seleccionadas.
Bosque de recubrimiento mínimo. El grafo no es conexo.
Problema del camino MiniMax o MaxMin. El coste de un camino es el máximo o el mínimo de las aristas que lo forman.
Segundo árbol de recubrimiento mínimo. Entre todos los árboles de recubrimiento que no tienen el coste del árbol de recubrimiento mínimo queremos entreontrar el de menor coste.
