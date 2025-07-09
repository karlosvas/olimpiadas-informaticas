#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
using namespace std;

// BFS para grafo representado con lista de adyacencia
void bfs(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;

    // Comenzar desde el nodo inicial
    q.push(start);
    visited[start] = true;

    cout << "BFS traversal starting from node " << start << ": ";

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Explorar todos los vecinos del nodo actual
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// BFS para encontrar el camino más corto (número de aristas)
vector<int> bfsShortestPath(vector<vector<int>>& graph, int start, int target) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    vector<int> distance(n, -1);
    queue<int> q;

    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == target) {
            break;
        }

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);
            }
        }
    }

    // Reconstruir el camino
    vector<int> path;
    if (distance[target] == -1) {
        return path;  // No hay camino
    }

    int current = target;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());
    return path;
}

// BFS para matriz de adyacencia (útil para problemas de laberintos)
void bfsMatrix(vector<vector<int>>& matrix, int startRow, int startCol) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    queue<pair<int, int>> q;

    // Direcciones: arriba, abajo, izquierda, derecha
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    q.push({startRow, startCol});
    visited[startRow][startCol] = true;

    cout << "BFS traversal in matrix starting from (" << startRow << ", " << startCol << "): ";

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        cout << "(" << x << "," << y << ") ";

        // Explorar las 4 direcciones
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // Verificar límites y si la celda es válida (1) y no visitada
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
                matrix[newX][newY] == 1 && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
    cout << endl;
}

// BFS para encontrar todos los nodos alcanzables desde un nodo
vector<int> bfsReachable(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> reachable;
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        reachable.push_back(current);

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return reachable;
}

// Función de ejemplo y pruebas
int main() {
    cout << "=== Algoritmo BFS (Breadth-First Search) ===" << endl;

    // Ejemplo 1: Grafo simple
    cout << "\n1. BFS en grafo simple:" << endl;
    vector<vector<int>> graph = {
        {1, 2},     // Nodo 0 conectado a 1 y 2
        {0, 3, 4},  // Nodo 1 conectado a 0, 3 y 4
        {0, 5},     // Nodo 2 conectado a 0 y 5
        {1},        // Nodo 3 conectado a 1
        {1, 5},     // Nodo 4 conectado a 1 y 5
        {2, 4}      // Nodo 5 conectado a 2 y 4
    };

    bfs(graph, 0);

    // Ejemplo 2: Camino más corto
    cout << "\n2. Camino más corto de 0 a 5:" << endl;
    vector<int> path = bfsShortestPath(graph, 0, 5);
    if (!path.empty()) {
        cout << "Camino: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i];
            if (i < path.size() - 1) cout << " -> ";
        }
        cout << " (distancia: " << path.size() - 1 << ")" << endl;
    } else {
        cout << "No hay camino" << endl;
    }

    // Ejemplo 3: BFS en matriz (laberinto)
    cout << "\n3. BFS en matriz (1 = camino libre, 0 = obstáculo):" << endl;
    vector<vector<int>> matrix = {
        {1, 1, 0, 1},
        {1, 1, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 1}};

    bfsMatrix(matrix, 0, 0);

    // Ejemplo 4: Nodos alcanzables
    cout << "\n4. Nodos alcanzables desde el nodo 0:" << endl;
    vector<int> reachable = bfsReachable(graph, 0);
    cout << "Nodos alcanzables: ";
    for (int node : reachable) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

/*
Complejidad del algoritmo BFS:
- Tiempo: O(V + E) donde V es el número de vértices y E el número de aristas
- Espacio: O(V) para la cola y el arreglo de visitados

Casos de uso comunes:
1. Encontrar el camino más corto en grafos no ponderados
2. Explorar niveles de un árbol
3. Resolver problemas de laberintos
4. Detectar componentes conexas
5. Verificar si un grafo es bipartito
6. Encontrar todos los nodos a una distancia específica

Ventajas:
- Garantiza encontrar el camino más corto en grafos no ponderados
- Explora sistemáticamente por niveles
- Útil para problemas que requieren exploración exhaustiva

Desventajas:
- Usa más memoria que DFS debido a la cola
- No es óptimo para grafos muy anchos
*/