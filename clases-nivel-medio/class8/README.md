# Algoritmo de Dijsktra

## Digrafos valorados
Son grafos con aristas orientadas que tienen asociados un valor (peso, coste).
Digarfo es una forma abrebiada de decir grafo dirijido.

Para representar el infinito podemos darle un numero muy grande ya que int no dispone del numero infinito comoo tal, sin pasarse porque podriamos provocar desboradamiento un numero común para definir infinmito es 10 elevado a la 9 ya que dos mil millones con algo es el numero mas gradnde que se pude representar.

Para representar un digrafo mediante matriz de adyacencia podemos hacerlo de la siguiente manera =>
```cpp
using Digrafo vector<vector<int>>;
int INF = 1000000000; // Infinito.

int C = 13;
Digrafo.assign(V, vector<int>(V, INF));

// Conexión o arista entre el 7 a l 8.
g[7][8] = 14;
```

Para hacer esto mismo pero con listas de adyacentes =>
```cpp
using Digrafo = vector<vectores<pair<int,int>>>; // Coste, vecino.

int V = 13;
Digrafo g(V,{});

// Arista del 7 al 8
g[7].push_back({14,8});
```

Construcción del digrafo valorado =>
```cpp
int V,A;
cin>>V>>A;

Digrafo g(V, {});

for(int i = 0; i < A; ++i){
    int u, v, c;
    cin>>u>>v>>c;
    g[u].push_back({c, v});
    /* Si fuera no dirijido hariamos
    g[v].push_back({c,u});
    */
}
```
### Caminos minimos
Dado un digrafo valorado, encontrar el camino mínimo del s a t.
Los ciclos no ayudan a encontrar el camino mínimo, todo camíno minimo va a ser simple, osea que no repite vértices.

El coste de un camino es la suma de los costes de las aristas
El camino minimo es el que tiene menos coste entre todos los caminos posibles entre un vertice y otro.

Si el camino minimo que va desde s a t