#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
using namespace std;

// DFS básico - versión recursiva
void dfsRecursive(vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    // Explorar todos los vecinos del nodo actual
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfsRecursive(graph, neighbor, visited);
        }
    }
}

// DFS - versión iterativa usando stack
void dfsIterative(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;

    s.push(start);
    cout << "DFS iterativo desde nodo " << start << ": ";

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            cout << current << " ";

            // Agregar vecinos al stack (en orden inverso para mantener orden)
            for (int i = graph[current].size() - 1; i >= 0; i--) {
                int neighbor = graph[current][i];
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}

// DFS para encontrar un camino entre dos nodos
vector<int> dfsPath(vector<vector<int>>& graph, int start, int target,
                    vector<bool>& visited, vector<int>& path) {
    visited[start] = true;
    path.push_back(start);

    if (start == target) {
        return path;  // Camino encontrado
    }

    for (int neighbor : graph[start]) {
        if (!visited[neighbor]) {
            vector<int> result = dfsPath(graph, neighbor, target, visited, path);
            if (!result.empty()) {
                return result;
            }
        }
    }

    path.pop_back();       // Backtrack
    return vector<int>();  // No se encontró camino
}

// DFS para detectar ciclos en grafo dirigido
bool hasCycleDFS(vector<vector<int>>& graph, int node, vector<int>& color) {
    // 0 = blanco (no visitado), 1 = gris (en proceso), 2 = negro (terminado)
    color[node] = 1;  // Marcar como gris

    for (int neighbor : graph[node]) {
        if (color[neighbor] == 1) {
            return true;  // Back edge encontrado - hay ciclo
        }
        if (color[neighbor] == 0 && hasCycleDFS(graph, neighbor, color)) {
            return true;
        }
    }

    color[node] = 2;  // Marcar como negro
    return false;
}

// DFS para ordenamiento topológico
void topologicalSortDFS(vector<vector<int>>& graph, int node,
                        vector<bool>& visited, stack<int>& topoStack) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            topologicalSortDFS(graph, neighbor, visited, topoStack);
        }
    }

    topoStack.push(node);  // Agregar al stack después de procesar vecinos
}

// DFS en matriz (para laberintos, islas, etc.)
void dfsMatrix(vector<vector<int>>& matrix, int row, int col,
               vector<vector<bool>>& visited) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Verificar límites y validez
    if (row < 0 || row >= rows || col < 0 || col >= cols ||
        visited[row][col] || matrix[row][col] == 0) {
        return;
    }

    visited[row][col] = true;
    cout << "(" << row << "," << col << ") ";

    // Explorar las 4 direcciones
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];
        dfsMatrix(matrix, newRow, newCol, visited);
    }
}

// DFS para contar componentes conexas
int countComponents(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);
    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            components++;
            cout << "Componente " << components << ": ";
            dfsRecursive(graph, i, visited);
            cout << endl;
        }
    }

    return components;
}

// DFS para verificar si un grafo es bipartito
bool isBipartiteDFS(vector<vector<int>>& graph, int node, vector<int>& color, int c) {
    color[node] = c;

    for (int neighbor : graph[node]) {
        if (color[neighbor] == -1) {
            // Colorear con color opuesto
            if (!isBipartiteDFS(graph, neighbor, color, 1 - c)) {
                return false;
            }
        } else if (color[neighbor] == color[node]) {
            return false;  // Mismo color en nodos adyacentes
        }
    }

    return true;
}

// DFS para encontrar puentes (aristas críticas)
void bridgesDFS(vector<vector<int>>& graph, int node, vector<bool>& visited,
                vector<int>& disc, vector<int>& low, vector<int>& parent,
                vector<pair<int, int>>& bridges, int& time) {
    visited[node] = true;
    disc[node] = low[node] = ++time;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            parent[neighbor] = node;
            bridgesDFS(graph, neighbor, visited, disc, low, parent, bridges, time);

            low[node] = min(low[node], low[neighbor]);

            // Si low[neighbor] > disc[node], entonces (node, neighbor) es un puente
            if (low[neighbor] > disc[node]) {
                bridges.push_back({node, neighbor});
            }
        } else if (neighbor != parent[node]) {
            low[node] = min(low[node], disc[neighbor]);
        }
    }
}

// DFS para encontrar puntos de articulación
void articulationPointsDFS(vector<vector<int>>& graph, int node, vector<bool>& visited,
                           vector<int>& disc, vector<int>& low, vector<int>& parent,
                           vector<bool>& ap, int& time) {
    int children = 0;
    visited[node] = true;
    disc[node] = low[node] = ++time;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            children++;
            parent[neighbor] = node;
            articulationPointsDFS(graph, neighbor, visited, disc, low, parent, ap, time);

            low[node] = min(low[node], low[neighbor]);

            // node es punto de articulación en los siguientes casos:
            // 1) node es raíz y tiene más de un hijo
            if (parent[node] == -1 && children > 1) {
                ap[node] = true;
            }

            // 2) node no es raíz y low[neighbor] >= disc[node]
            if (parent[node] != -1 && low[neighbor] >= disc[node]) {
                ap[node] = true;
            }
        } else if (neighbor != parent[node]) {
            low[node] = min(low[node], disc[neighbor]);
        }
    }
}

// Wrapper para inicializar DFS recursivo
void dfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    cout << "DFS recursivo desde nodo " << start << ": ";
    dfsRecursive(graph, start, visited);
    cout << endl;
}

// Función principal con ejemplos
int main() {
    cout << "=== Algoritmo DFS (Depth-First Search) ===" << endl;

    // Ejemplo 1: DFS básico
    cout << "\n1. DFS básico (recursivo e iterativo):" << endl;
    vector<vector<int>> graph = {
        {1, 2},     // Nodo 0 conectado a 1 y 2
        {0, 3, 4},  // Nodo 1 conectado a 0, 3 y 4
        {0, 5},     // Nodo 2 conectado a 0 y 5
        {1},        // Nodo 3 conectado a 1
        {1, 5},     // Nodo 4 conectado a 1 y 5
        {2, 4}      // Nodo 5 conectado a 2 y 4
    };

    dfs(graph, 0);
    dfsIterative(graph, 0);

    // Ejemplo 2: Encontrar camino
    cout << "\n2. Encontrar camino de 0 a 5:" << endl;
    vector<bool> visited(graph.size(), false);
    vector<int> path;
    vector<int> result = dfsPath(graph, 0, 5, visited, path);

    if (!result.empty()) {
        cout << "Camino encontrado: ";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i < result.size() - 1) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "No se encontró camino" << endl;
    }

    // Ejemplo 3: Detectar ciclos
    cout << "\n3. Detección de ciclos:" << endl;
    vector<vector<int>> cyclicGraph = {
        {1},     // 0 -> 1
        {2},     // 1 -> 2
        {0, 3},  // 2 -> 0, 3 (ciclo: 0->1->2->0)
        {}       // 3 (sin salidas)
    };

    vector<int> color(cyclicGraph.size(), 0);
    bool hasCycle = false;
    for (int i = 0; i < cyclicGraph.size(); i++) {
        if (color[i] == 0) {
            if (hasCycleDFS(cyclicGraph, i, color)) {
                hasCycle = true;
                break;
            }
        }
    }

    cout << "El grafo dirigido " << (hasCycle ? "tiene" : "no tiene") << " ciclos" << endl;

    // Ejemplo 4: Ordenamiento topológico
    cout << "\n4. Ordenamiento topológico:" << endl;
    vector<vector<int>> dagGraph = {
        {1, 2},  // 0 -> 1, 2
        {3},     // 1 -> 3
        {3},     // 2 -> 3
        {}       // 3 (sin salidas)
    };

    vector<bool> visitedTopo(dagGraph.size(), false);
    stack<int> topoStack;

    for (int i = 0; i < dagGraph.size(); i++) {
        if (!visitedTopo[i]) {
            topologicalSortDFS(dagGraph, i, visitedTopo, topoStack);
        }
    }

    cout << "Orden topológico: ";
    while (!topoStack.empty()) {
        cout << topoStack.top() << " ";
        topoStack.pop();
    }
    cout << endl;

    // Ejemplo 5: DFS en matriz
    cout << "\n5. DFS en matriz (buscar islas):" << endl;
    vector<vector<int>> matrix = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}};

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<bool>> visitedMatrix(rows, vector<bool>(cols, false));
    int islands = 0;

    cout << "Matriz original:" << endl;
    for (auto& row : matrix) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 1 && !visitedMatrix[i][j]) {
                islands++;
                cout << "Isla " << islands << ": ";
                dfsMatrix(matrix, i, j, visitedMatrix);
                cout << endl;
            }
        }
    }

    cout << "Total de islas: " << islands << endl;

    // Ejemplo 6: Componentes conexas
    cout << "\n6. Componentes conexas:" << endl;
    vector<vector<int>> disconnectedGraph = {
        {1},  // Componente 1: 0-1
        {0},
        {3},  // Componente 2: 2-3
        {2},
        {5},  // Componente 3: 4-5
        {4}};

    int components = countComponents(disconnectedGraph);
    cout << "Total de componentes conexas: " << components << endl;

    // Ejemplo 7: Verificar si es bipartito
    cout << "\n7. Verificar si el grafo es bipartito:" << endl;
    vector<int> colorBipartite(graph.size(), -1);
    bool bipartite = true;

    for (int i = 0; i < graph.size(); i++) {
        if (colorBipartite[i] == -1) {
            if (!isBipartiteDFS(graph, i, colorBipartite, 0)) {
                bipartite = false;
                break;
            }
        }
    }

    cout << "El grafo " << (bipartite ? "es" : "no es") << " bipartito" << endl;

    return 0;
}

/*
Complejidad del algoritmo DFS:
- Tiempo: O(V + E) donde V es el número de vértices y E el número de aristas
- Espacio: O(V) para el stack de recursión y estructuras auxiliares

Características principales:
- Explora tan profundo como sea posible antes de retroceder
- Usa un stack (implícito en recursión o explícito en iteración)
- Muy útil para problemas de conectividad y búsqueda exhaustiva

Aplicaciones comunes:
1. Búsqueda de caminos
2. Detección de ciclos
3. Ordenamiento topológico
4. Componentes conexas
5. Verificación de bipartición
6. Encontrar puentes y puntos de articulación
7. Resolver laberintos
8. Contar islas en una matriz

Ventajas:
- Eficiente en memoria para grafos profundos
- Útil para problemas de backtracking
- Encuentra caminos rápidamente (aunque no necesariamente el más corto)

Desventajas:
- Puede usar mucha memoria del stack en grafos muy profundos
- No garantiza el camino más corto
- Puede quedarse "atrapado" en ramas largas

Variantes:
- DFS iterativo (usa stack explícito)
- DFS con backtracking
- DFS para detección de componentes fuertemente conexas (Tarjan, Kosaraju)
*/