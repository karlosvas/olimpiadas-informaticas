#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using info = pair<int, int>;     // {Anillo, grado}
using estado = pair<int, info>;  // Distancia, {Anillo, Grado}

#define DOMJ

vector<vector<estado>> rings;

const int INF = 1'000'000'000;

int dijkstra(int d, int g, int e, int h, int N) {
    vector<vector<int>> dist(N + 1, vector<int>(360, INF));
    dist[d][g] = 0;

    priority_queue<estado, vector<estado>, greater<estado>> pq;
    pq.push({0, {d, g}});

    while (!pq.empty()) {
        auto [distv, infov] = pq.top();  // Distancia hasta v (distv)
        auto [v, gv] = infov;            // Informacion del anillo v (anillo actual, grado actual)
        pq.pop();

        for (auto [distw, infow] : rings[v]) {  // Distancia hasta w conocida(distw)
            auto [w, gw] = infow;               // (Anillo destino, grado destino)
            // Distancia desde el grado del anillo v hasta el grado del anillo w
            int distancia = min(abs(gv - gw), 360 - abs(gv - gw));
            if (w == e) {
                distancia += min(abs(gw - h), 360 - abs(gw - h));
                gw = h;
            }

            // Si la distancia conocida es menor actualizamos
            if (dist[v][gv] + distancia < dist[w][gw]) {
                dist[w][gw] = dist[v][gv] + distancia;
                pq.push({dist[w][gw], {w, gw}});
            }
        }
    }
    return (d == e) ? dist[e][h] = min(abs(g - h), 360 - abs(g - h)) : dist[e][h];
}

void solve() {
    // Anillos(N), Túneles(K), Tiempo de recorrido por anillo(T)
    int N, K, T;
    // Anillo y grado de inicio {d,g}, anillo y grado de fin {e,h}
    int d, g, e, h;

#ifdef DOMJ
    cin >> N >> K;
    rings.assign(N + 1, {});
    for (int k = 1; k <= K; ++k) {
        int a, b;
        cin >> a >> b;
        // Puede ir en las dos direciones
        rings[a].push_back({a, {a + 1, b}});
        rings[a + 1].push_back({a + 1, {a, b}});
    }
    // Coste de moverse en el ianillo
    for (int n = 1; n < N + 1; ++n)
        cin >> T;

    cin >> d >> g >> e >> h;
#else
    N = 3, K = 4;
    rings.assign(N + 1, vector<info>(N + 1));
    // 1
    rings[1].push_back({2, 20});
    rings[2].push_back({1, 20});
    rings[1].push_back({2, 350});
    rings[2].push_back({1, 350});
    // 2
    rings[2].push_back({3, 170});
    rings[3].push_back({2, 170});
    rings[2].push_back({3, 185});
    rings[3].push_back({2, 185});
    T = 10;
    // d = 1, g = 0, e = 3, h = 170;
    d = 3, g = 170, e = 1, h = 0;
    rings[e].push_back({e, h});
    rings[d].push_back({d, g});
#endif

    // Como puede ir en las dos direciones no hace falta empezar desde el anillo interno
    int cost = dijkstra(d, g, e, h, N);

    // Coste de llegar al {anillo grado final} * coste de moverse, todo(Ti es el mismo)
    if (cost == INF)
        cout << "IMPOSIBLE\n";
    else
        cout << cost * T << "\n";
}

int main() {
    int C;
#ifdef DOMJ
    cin >> C;
#else
    C = 1;
#endif
    while (C--)
        solve();
    return 0;
}