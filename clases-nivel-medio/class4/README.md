# Grafos

Los grafos sirven par representar elementos y conexiones uno a uno entre ellos.
Conjunto de vertices y un conjunto de aristas que conectan pares de vertices.
Autoarista => Es una arista que va desde un vertize a si mismo,
Paralelas => Aristas que conectan el mismo par de vertices. 

### Matriz de adyacencia.
```cpp
using Grafo = vector<vector<bool>>;
int V = 13;
Grafo g(V, vector<bool>(V, false));

// Arista 7-8
g[7][8] = true;
g[8][7] = true;
```
### Listas de adyacentes
```cpp
using Grafo = vector<vector<int>>;
int V = 13;
Grafo g(V);

// Arista 7-8
g[7].push_back(8) = true;
g[8].push_back(7) = true;
```

### Ejemplo
```cpp
using Grafo = vector<vector<int>>;
int V, A;
cin>>V>>A;

Grafo g(V); // 0-indexed.
// Da tantas vuelyas como aristas.
for(int i = 0; i < A; ++i){
    int u, v;
    cin>>u>>v;
    g[u-1].push_back(v-1);
    g[v-1].push_back(u-1);
}
```
## Recorrido en profundiad
En ingles "depth-fist-search", DFS imita la resolución de un laberinto.
Para recorrer un grafo utilizamos un algoritmo recursivo que va visitando vertices.
Visitar un vertice consiste en:
    Hacer algo con el;
    Marcarlo ocomo visitado;
    Vivistar (recursivamente todos los verrtices adacentyes si aun no viistados)