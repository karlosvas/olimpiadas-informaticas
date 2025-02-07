#include <bits/stdc++.h>
using namespace std;

struct ufds {
    int numSets;
    vector<int> p;

    ufds(int N) : numSets(N), p(N, -1) {}

    // Devuelbe el padre de ir ecursivamente hasta encontrar la raiz.
    int find(int i) { return p[i] < 0 ? i : p[i] = find(p[i]); }

    bool related(int i, int j) { return find(i) == find(j); }

    void join(int i, int j) {
        int x = find(i), y = find(j);
        // SI son iguales ya estaban en el mismo árbol.
        if (x == y)
            return;
        // Pone como hijo al arbol mas pequeño.
        if (p[x] < p[y])
            swap(x, y);
        // Sumamos el tamaño del arbol mas pequeño al mas grande. y ponemos como
        // padre al mas grande.
        p[y] += p[x];
        p[x] = y;
        --numSets;
    }

    int size(int i) { return -p[find(i)]; }
};

// Verifica si se puede saltar desde (x1, y1) a (x2, y2) con un radio de k
bool canJump(int x1, int y1, int x2, int y2, int k) {
    int dx = x2 - x1;  // Diferencia en x
    int dy = y2 - y1;  // Diferencia en y
    // Verifica si la distancia euclidiana está dentro del radio k
    return (dx * dx + dy * dy) <= k * k;
}

bool solve() {
    // n columnas, m filas, k distancia a la que puede saltar la ardilla, t
    // arboles que se talan.
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    int end = (n + 1) * (m + 1);

    if (!cin)
        return false;

    // Arboles en las posiciones (x, y).
    vector<pair<int, int>> trees(t);
    for (int i = 0; i < t; i++)
        cin >> trees[i].first >> trees[i].second;

    // Creamos el grafo de uniones.
    ufds UFDS((n + 1) * (m + 1));
    // Arboles que estan vivos.
    vector<vector<bool>> alive(n + 1, vector<bool>(m + 1, false));
    alive[0][0] = alive[n][m] = true;

    vector<pair<int, int>> directions = {{-k, 0}, {k, 0}, {0, -k}, {0, k}};
    // Vamos talando los arboles en orden inverso.
    for (int i = t - 1; i >= 0; i--) {
        int x = trees[i].first;
        int y = trees[i].second;
        alive[x][y] = true;

        for (auto [dx, dy] : directions) {
            int nx = x + dx;
            int ny = y + dy;
            if (nx >= 0 && nx <= n && ny >= 0 && ny <= m && alive[nx][ny] && canJump(x, y, nx, ny, k)) {
                // Une las posiciones (x, y) y (nx, ny) en la estructura de conjuntos
                // disjuntos
                UFDS.join(x * (m + 1) + y, nx * (m + 1) + ny);
            }
        }

        // Verifica si la posición (0, 0) y (n, m) están conectadas
        if (UFDS.related(0, n * (m + 1) + m)) {
            if (i == t - 1)
                cout << "NUNCA SE PUDO\n";
            else
                cout << trees[i].first << " " << trees[i].second << "\n";
            return true;
        }
    }

    cout << "NUNCA SE PUDO\n";

    return true;
}

int main() {
    while (solve());
    return 0;
}