#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define DOMJ

// Definición de las direcciones posibles: arriba, abajo, izquierda, derecha y diagonales
const int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

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

void dfs(vector<vector<char>>& sea, int x, int y, vector<vector<bool>>& visited, ufds& UF, int F, int C) {
    // Verificamos si las coordenadas están dentro de los límites de la matriz y si la celda no ha sido visitada
    if (x < 0 || x >= F || y < 0 || y >= C || visited[x][y] || sea[x][y] != '#') return;
    // Marcamos la celda como visitada
    visited[x][y] = true;

    // Convertimos la posición en la matriz a un índice lineal
    // Exploramos en todas las direcciones posibles
    int cellIndex = x * C + y;

    // Buscamos en las 8 direciones
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < F && ny >= 0 && ny < C && sea[nx][ny] == '#') {
            // Indice lineal x*Y+y
            int newIndex = nx * C + ny;
            if (!UF.related(cellIndex, newIndex)) {
                // Si no estan relacionados y los dos estan contaminados los unimos
                UF.join(cellIndex, newIndex);
                dfs(sea, nx, ny, visited, UF, F, C);
            }
        }
    }
}

#ifndef DOMJ
void mostrar(vector<vector<char>>& v, int F, int C) {
    cout << "\n";
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            cout << v[i][j];
        }
        cout << "\n";
    }
    cout << "----\n";
}
#endif

bool solve() {
    // Filas(F)
    // Columnas(C)
    int F, C;
    cin >> F >> C;

    if (!cin)
        return false;

    // Ignora el salto de linea 'flush de entrada' para leer la siguiente linea con getline
    cin.ignore();

#ifdef DOMJ
    // Añadimos los valores del mar y sus manchas
    vector<vector<char>> sea(F, vector<char>(C));
    for (int i = 0; i < F; i++) {
        string line;
        getline(cin, line);
        for (int j = 0; j < C; j++) {
            sea[i][j] = line[j];
        }
    }
#else
    vector<vector<char>> sea = {
        {' ', '#', ' ', '#', ' ', ' ', ' ', '#'},
        {' ', '#', '#', '#', ' ', ' ', '#', '#'},
        {' ', ' ', ' ', ' ', ' ', '#', '#', '#'},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '#', ' ', '#', ' ', ' ', ' ', ' '},
        {' ', '#', '#', '#', ' ', '#', '#', ' '},
        {'#', '#', '#', ' ', ' ', '#', '#', ' '},
        {' ', ' ', '#', ' ', ' ', ' ', ' ', ' '}};
#endif

    // Vector de visitados, e inicializamos la instalcia de Union Find Data Structure UFDS
    vector<vector<bool>> visited(F, vector<bool>(C, false));
    ufds UF(F * C);
    int maxSize = 0;

    // Buscamos la componente conexa mas grande en ufds, y lo recorremos con dfs, para unirlos
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++) {
            if (sea[i][j] == '#' && !visited[i][j]) {
                dfs(sea, i, j, visited, UF, F, C);
                maxSize = max(UF.size(i * C + j), maxSize);
            }
        }
    }

#ifndef DOMJ
    mostrar(sea, F, C);
#endif

    // Imágenes adicionales(Q)
    int Q;
    cin >> Q;

    // Mostramos el valor máximo
    (Q == 0) ? cout << maxSize << '\n' : cout << maxSize << ' ';
    while (Q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        // Si no estaba contaminada, y esta dentro de los límites la contaminamos(#) con petróleo
        if (x >= 0 && x < F && y >= 0 && y < C && sea[x][y] != '#') {
            sea[x][y] = '#';
            int cellIndex = x * C + y;
            for (int i = 0; i < 8; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                // Si tiene algun vecino contaminado(#) lo unimos a la componente conexa, y actualizamos el mayor valor encontrado
                if (nx >= 0 && nx < F && ny >= 0 && ny < C && sea[nx][ny] == '#') {
                    UF.join(cellIndex, nx * C + ny);
                }
            }
            maxSize = max(UF.size(cellIndex), maxSize);
        }
// Mostramos la solución y si es el último el salto de linea
#ifndef DOMJ
        mostrar(sea, F, C);
#endif
        (Q == 0) ? cout << maxSize << '\n' : cout << maxSize << ' ';
    }
    return true;
}

int main() {
    while (solve());
    return 0;
}