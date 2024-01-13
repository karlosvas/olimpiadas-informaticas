# Estructura UFDS
Estructuras de equivalencia. (a,b) eR de alguna manera a esta relacionado con b.
Relacion de equivalencia:
Reflexiba a R a. (cada elemento esta relacionado con si mismo)
Simétrica a R b. (Si a == b y b == a)
Transitiva: a R b y b R c entonces a R c.

Una partición es un conjunto de subconjuntos disjuntos cuya unión es el conjunto original.

## Relación de equivalencia dinámica
### Unión rapida
vector de p elementos, para cada uno guardamos cual es su padre, cuando no tiern padre le indicamos que como padre es el mismo.
Para buscar la raiz podemos decir que mientras el padre de i sea distinto de i hacemos i = Pi

### Unión por tamaños
Vamos a mantener los tamaños de los arboles(número de elementos)
Al unir el arbol mas pequeño pasa a ser hijo del árbol mayor.
LA búsqueda es proporcinal a la profundidad del elemento buscado.
Al hacer la unión por tamaños, la profundidad está cotada por O(log N)

### Unión por tamaños y compresión de caminos
Despues de buscar la raíz del árbol donde se encuentra x, cambiamos su padre para que sea esa raíz.

## Implementación de compresión de caminos
```cpp
struct ufds {
    int numSets;
    vector<int> p;

    ufds(int N) : numSets(N), p(N, -1) {}

    // Devuelbe el padre de ir ecursivamente hasta encontrar la raiz.
    int find(int i) {
        return p[i] < 0 ? i : p[i] = find(p[i]);
    }

    bool related(int i, int j) {
        return find(i) == find(j);
    }

    void join(int i, int j) {
        int x = find(i), y = find(j);
        // SI son iguales ya estaban en el mismo árbol.
        if(x == y) return;
        // Pone como hijo al arbol mas pequeño.
        if(p[x] < p[y]) swap(x, y);
        // Sumamos el tamaño del arbol mas pequeño al mas grande. y ponemos como padre al mas grande.
        p[y] += p[x]; p[x] = y;
        --numSets;
    }

    int size(int i) {
        return -p[find(i)];
    }
}
```
