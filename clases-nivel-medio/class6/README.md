## Recorrido de anchura
En ocasiones estamos interesados enn encontrar el camino más corto desde un origen s a otro vértice v (o a todos los vertices conectados a s).

El recorrido en anchura (En inglés, breadth-first search, BFS) logra eso a primera vista todoss los vértices alcanzavles siguiendo una arista (a distancia 1); luego visita todos los vértices alcanzables utilzando dos aristas (a distancia 2) y asi sucesivamente.

Para lograrlo utilza una cola donde guaradar los vértivces alcanzados peero que aun no se an explorado sus adyacentes.

De esta manera podremos econtarar el camino mas corto que va desde el origen a cualquier vétice.

## Repaso extra
La complejidad del dfs y bfs es O(V+E).
Videos BettaTech.
Algoritmos BFS y DFS:https://youtu.be/_Yf8tneauJ8?si=vaTCDBw6rTd2bqgA
