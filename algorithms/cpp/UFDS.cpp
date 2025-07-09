#include <bits/stdc++.h>
using namespace std;

struct ufds {
    int numSets;
    vector<int> p;

    ufds(int N) : numSets(N), p(N, -1) {}

    // Devuelve el padre de ir recursivamente hasta encontrar la raíz.
    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }

    // Comprueba si dos V están entre sí en el mismo árbol.
    bool related(int i, int j) { return find(i) == find(j); }

    void join(int i, int j) {
        int x = find(i), y = find(j);
        // Si son iguales ya estaban en el mismo árbol.
        if (x == y) return;
        // Pone como hijo al árbol más pequeño.
        if (p[x] < p[y]) swap(x, y);
        // Sumamos el tamaño del árbol más pequeño al más grande y ponemos como
        // padre al más grande.
        p[y] += p[x];
        p[x] = y;
        --numSets;
    }

    int size(int i) { return -p[find(i)]; }
};

struct ufdsRollback {
    struct Operation {
        int type;  // 0 = join, 1 = other operations if needed
        int x, y;
        int oldPx, oldPy, oldNumSets;
    };

    int numSets;
    vector<int> p;
    vector<Operation> history;

    ufdsRollback(int N) : numSets(N), p(N, -1) {}

    // Devuelve el padre sin path compression para rollback
    int find(int i) {
        while (p[i] >= 0) i = p[i];
        return i;
    }

    // Comprueba si dos V están entre sí en el mismo árbol.
    bool related(int i, int j) { return find(i) == find(j); }

    void join(int i, int j) {
        int x = find(i), y = find(j);
        // Si son iguales ya estaban en el mismo árbol.
        if (x == y) {
            history.push_back({0, x, y, p[x], p[y], numSets});
            return;
        }

        // Guardar estado para rollback
        history.push_back({0, x, y, p[x], p[y], numSets});

        // Pone como hijo al árbol más pequeño.
        if (p[x] < p[y]) swap(x, y);
        // Sumamos el tamaño del árbol más pequeño al más grande y ponemos como
        // padre al más grande.
        p[y] += p[x];
        p[x] = y;
        --numSets;
    }

    void rollback() {
        if (history.empty()) return;
        Operation op = history.back();
        history.pop_back();

        p[op.x] = op.oldPx;
        p[op.y] = op.oldPy;
        numSets = op.oldNumSets;
    }

    int getOperationsCount() { return history.size(); }

    int size(int i) { return -p[find(i)]; }
};

// UFDS con rank optimization
struct ufdsRank {
    int numSets;
    vector<int> parent, rank;

    ufdsRank(int N) : numSets(N), parent(N), rank(N, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);  // Path compression
        }
        return parent[i];
    }

    bool related(int i, int j) { return find(i) == find(j); }

    bool join(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return false;

        // Union by rank
        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            rank[x]++;
        }
        --numSets;
        return true;
    }

    int getNumSets() { return numSets; }
};

// UFDS con información adicional (suma, mínimo, máximo por componente)
struct ufdsExtended {
    int numSets;
    vector<int> parent, size;
    vector<long long> sum;
    vector<int> minVal, maxVal;

    ufdsExtended(vector<int>& values) : numSets(values.size()) {
        int n = values.size();
        parent.resize(n);
        size.assign(n, 1);
        sum.resize(n);
        minVal.resize(n);
        maxVal.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sum[i] = values[i];
            minVal[i] = maxVal[i] = values[i];
        }
    }

    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }

    bool related(int i, int j) { return find(i) == find(j); }

    bool join(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return false;

        // Unir componentes y actualizar información
        if (size[x] < size[y]) swap(x, y);

        parent[y] = x;
        size[x] += size[y];
        sum[x] += sum[y];
        minVal[x] = min(minVal[x], minVal[y]);
        maxVal[x] = max(maxVal[x], maxVal[y]);
        --numSets;
        return true;
    }

    int getSize(int i) { return size[find(i)]; }
    long long getSum(int i) { return sum[find(i)]; }
    int getMin(int i) { return minVal[find(i)]; }
    int getMax(int i) { return maxVal[find(i)]; }
    int getNumSets() { return numSets; }
};

// UFDS con distancia/peso entre nodos
struct ufdsWeighted {
    vector<int> parent;
    vector<long long> weight;  // Peso relativo al padre
    int numSets;

    ufdsWeighted(int n) : parent(n), weight(n, 0), numSets(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    pair<int, long long> find(int x) {
        if (parent[x] == x) return {x, 0};
        auto p = find(parent[x]);
        weight[x] += p.second;
        parent[x] = p.first;
        return {parent[x], weight[x]};
    }

    int getRoot(int x) { return find(x).first; }
    long long getWeight(int x) { return find(x).second; }

    bool related(int x, int y) { return getRoot(x) == getRoot(y); }

    // Une x e y con peso w (weight[y] - weight[x] = w)
    bool join(int x, int y, long long w) {
        auto px = find(x), py = find(y);
        if (px.first == py.first) {
            // Verificar consistencia
            return (py.second - px.second == w);
        }

        parent[py.first] = px.first;
        weight[py.first] = px.second - py.second + w;
        --numSets;
        return true;
    }

    // Obtiene la diferencia de peso entre x e y
    long long getDifference(int x, int y) {
        if (!related(x, y)) return LLONG_MAX;  // No están conectados
        return getWeight(y) - getWeight(x);
    }
};

// Funciones de utilidad para problemas comunes
class UFDSProblems {
   public:
    // Detectar ciclos en grafo no dirigido
    static bool hasCycle(int n, vector<pair<int, int>>& edges) {
        ufds dsu(n);
        for (auto& edge : edges) {
            if (dsu.related(edge.first, edge.second)) {
                return true;  // Ciclo encontrado
            }
            dsu.join(edge.first, edge.second);
        }
        return false;
    }

    // Algoritmo de Kruskal para MST
    static long long kruskal(int n, vector<tuple<int, int, int>>& edges) {
        sort(edges.begin(), edges.end());
        ufds dsu(n);
        long long mstCost = 0;
        int edgesUsed = 0;

        for (auto& [weight, u, v] : edges) {
            if (!dsu.related(u, v)) {
                dsu.join(u, v);
                mstCost += weight;
                edgesUsed++;
                if (edgesUsed == n - 1) break;
            }
        }

        return edgesUsed == n - 1 ? mstCost : -1;  // -1 si no hay MST
    }

    // Contar componentes conexas
    static int countComponents(int n, vector<pair<int, int>>& edges) {
        ufds dsu(n);
        for (auto& edge : edges) {
            dsu.join(edge.first, edge.second);
        }
        return dsu.numSets;
    }

    // Verificar si el grafo es bipartito usando UFDS
    static bool isBipartite(int n, vector<pair<int, int>>& edges) {
        ufds dsu(2 * n);  // Cada nodo tiene dos copias

        for (auto& [u, v] : edges) {
            // u y v no pueden estar en el mismo conjunto
            if (dsu.related(u, v) || dsu.related(u + n, v + n)) {
                return false;
            }
            // u va con ~v, v va con ~u
            dsu.join(u, v + n);
            dsu.join(v, u + n);
        }
        return true;
    }
};

// Función principal con ejemplos
int main() {
    cout << "=== Union-Find Disjoint Set (UFDS) ===" << endl;

    // Ejemplo 1: UFDS básico
    cout << "\n1. UFDS básico:" << endl;
    ufds basicUfds(6);

    cout << "Componentes iniciales: " << basicUfds.numSets << endl;

    basicUfds.join(0, 1);
    basicUfds.join(2, 3);
    basicUfds.join(1, 2);

    cout << "Después de unir (0,1), (2,3), (1,2):" << endl;
    cout << "Componentes: " << basicUfds.numSets << endl;
    cout << "¿0 y 3 están relacionados? " << (basicUfds.related(0, 3) ? "Sí" : "No") << endl;
    cout << "¿4 y 5 están relacionados? " << (basicUfds.related(4, 5) ? "Sí" : "No") << endl;
    cout << "Tamaño del componente de 0: " << basicUfds.size(0) << endl;

    // Ejemplo 2: UFDS con rollback
    cout << "\n2. UFDS con rollback:" << endl;
    ufdsRollback rollbackUfds(5);

    cout << "Componentes iniciales: " << rollbackUfds.numSets << endl;
    rollbackUfds.join(0, 1);
    rollbackUfds.join(2, 3);
    cout << "Después de (0,1) y (2,3): " << rollbackUfds.numSets << " componentes" << endl;

    rollbackUfds.join(1, 2);
    cout << "Después de (1,2): " << rollbackUfds.numSets << " componentes" << endl;

    cout << "Haciendo rollback..." << endl;
    rollbackUfds.rollback();
    cout << "Después del rollback: " << rollbackUfds.numSets << " componentes" << endl;

    // Ejemplo 3: UFDS con información extendida
    cout << "\n3. UFDS con información extendida:" << endl;
    vector<int> values = {10, 20, 5, 15, 8, 12};
    ufdsExtended extUfds(values);

    cout << "Valores iniciales: ";
    for (int v : values) cout << v << " ";
    cout << endl;

    extUfds.join(0, 1);  // Une 10 y 20
    extUfds.join(2, 3);  // Une 5 y 15

    cout << "Componente de 0 - Suma: " << extUfds.getSum(0)
         << ", Min: " << extUfds.getMin(0)
         << ", Max: " << extUfds.getMax(0) << endl;

    cout << "Componente de 2 - Suma: " << extUfds.getSum(2)
         << ", Min: " << extUfds.getMin(2)
         << ", Max: " << extUfds.getMax(2) << endl;

    // Ejemplo 4: UFDS con pesos
    cout << "\n4. UFDS con pesos:" << endl;
    ufdsWeighted weightedUfds(4);

    // Crear relaciones: weight[1] - weight[0] = 5
    weightedUfds.join(0, 1, 5);
    // weight[2] - weight[1] = 3, entonces weight[2] - weight[0] = 8
    weightedUfds.join(1, 2, 3);

    cout << "Diferencia entre 0 y 1: " << weightedUfds.getDifference(0, 1) << endl;
    cout << "Diferencia entre 0 y 2: " << weightedUfds.getDifference(0, 2) << endl;
    cout << "Diferencia entre 1 y 2: " << weightedUfds.getDifference(1, 2) << endl;

    // Ejemplo 5: Problemas comunes
    cout << "\n5. Problemas comunes con UFDS:" << endl;

    // Detección de ciclos
    vector<pair<int, int>> graphEdges = {{0, 1}, {1, 2}, {2, 3}, {3, 1}};
    bool hasCycle = UFDSProblems::hasCycle(4, graphEdges);
    cout << "¿El grafo tiene ciclos? " << (hasCycle ? "Sí" : "No") << endl;

    // Algoritmo de Kruskal
    vector<tuple<int, int, int>> mstEdges = {
        {1, 0, 1}, {3, 0, 2}, {2, 1, 2}, {4, 1, 3}, {5, 2, 3}};
    long long mstCost = UFDSProblems::kruskal(4, mstEdges);
    cout << "Costo del MST: " << mstCost << endl;

    // Contar componentes
    vector<pair<int, int>> compEdges = {{0, 1}, {2, 3}, {4, 5}};
    int components = UFDSProblems::countComponents(6, compEdges);
    cout << "Número de componentes conexas: " << components << endl;

    // Verificar bipartición
    vector<pair<int, int>> bipartiteEdges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    bool isBipartite = UFDSProblems::isBipartite(4, bipartiteEdges);
    cout << "¿Es bipartito? " << (isBipartite ? "Sí" : "No") << endl;

    return 0;
}

/*
Complejidad de UFDS:
- Find: O(α(n)) ≈ O(1) amortizado con path compression
- Union: O(α(n)) ≈ O(1) amortizado
- Espacio: O(n)

α(n) es la función inversa de Ackermann, prácticamente constante para valores reales.

Optimizaciones implementadas:
1. Path Compression - en find(), comprime el camino al root
2. Union by Size - une el árbol pequeño al grande
3. Union by Rank - alternativa a union by size

Variantes incluidas:
1. UFDS básico - implementación estándar
2. UFDS con rollback - permite deshacer operaciones
3. UFDS con rank - optimización por ranking
4. UFDS extendido - mantiene suma, min, max por componente
5. UFDS con pesos - maneja distancias/diferencias entre nodos

Problemas típicos:
- Detección de ciclos en grafos
- Algoritmo de Kruskal (MST)
- Componentes conexas
- Verificación de bipartición
- Problemas de conectividad dinámica
- Percolation
- Equivalencia de elementos

Aplicaciones:
- Algoritmos de grafos (MST, conectividad)
- Problemas de agrupación
- Análisis de redes
- Verificación de propiedades de grafos
- Optimización de consultas de conectividad

La implementación con rollback es útil para:
- Algoritmos offline
- Problemas con consultas temporales
- Backtracking con estado de unión

UFDS con pesos es útil para:
- Problemas de diferencias/distancias
- Verificación de consistencia
- Problemas de scheduling con restricciones
*/