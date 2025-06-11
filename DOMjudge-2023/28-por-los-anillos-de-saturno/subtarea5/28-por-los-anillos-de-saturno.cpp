#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
using estado = pair<int, pair<int, int>>;

vector<vector<pair<int, int>>> rings;
vector<int> tiempos;

// necesitas los tuneles entre anillos con distancia 0 cero, eso se mantiene.
// lo que cambia es el como conectas nodos dentro de un mismo nivel
// los unicos nodos interesantes dentro de un mismo anillo son los que bien son de tunel, o bien si es el nodo inicial o final. luego esos son los que estan marcados en verde
// y ahora estos nodos interesantes, en vez de conectarlos todos con todos, conectas cada uno con el que esté a la izquierda o a la derecha suya en el circulo del anillo

const int INF = 1'000'000'000;

int dijkstra(int d, int g, int e, int h, int N) {
    vector<vector<int>> dist(N, vector<int>(360, INF));
    dist[d][g] = 0;

    priority_queue<estado, vector<estado>, greater<estado>> pq;
    pq.push({0, {d, g}});

    while (!pq.empty()) {
        auto [distv, infov] = pq.top();  // Distancia hasta v (distv)
        auto [v, gv] = infov;            // Informacion del anillo v (anillo actual, grado actual)
        pq.pop();

        if (distv > dist[v][gv]) continue;  // Si la distancia conocida es mayor, no lo procesamos

        for (auto [gw, w] : rings[v]) {  // Grado destino
            // Distancia desde el grado del anillo v hasta el grado del anillo w
            int distancia = min(abs(gv - gw), 360 - abs(gv - gw)) * tiempos[v];

            if (dist[v][gv] + distancia < dist[w][gw]) {
                // Si la distancia conocida es menor actualizamos
                dist[w][gw] = dist[v][gv] + distancia;
                pq.push({dist[w][gw], {w, gw}});
            }
        }
    }

    // Verificamos si se a dado el caso de que el anillo de origen y de llegada es el mismo
    // por lo que devemos calcular lo que cuesta moverse de donde estamos al grado en cuestion
    return dist[e][h];
}

void solve() {
    // Anillos(N), Túneles(K), Tiempo de recorrido por anillo(T)
    int N, K, T;
    // Anillo y grado de inicio {d,g}, anillo y grado de fin {e,h}
    int d, g, e, h;

    cin >> N >> K;
    // Tenemos N rings +  el final
    rings.assign(N, {});
    for (int k = 0; k < K; ++k) {
        int a, b;
        cin >> a >> b;
        a--;

        rings[a].push_back({b, a + 1});
        rings[a + 1].push_back({b, a});
    }

    tiempos.assign(N, 0);
    // Coste de moverse en el anillo
    for (int n = 0; n < N; ++n)
        cin >> tiempos[n];

    cin >> d >> g >> e >> h;
    d--;
    e--;

    // Conetacmos la salida y la entrada como si fuera un tunel ya que una vez llegemos a e deveremos llegara hasta h
    rings[e].push_back({h, e});
    rings[d].push_back({g, d});

    int cost = dijkstra(d, g, e, h, N);

    if (cost == INF)
        cout << "IMPOSIBLE\n";
    else
        cout << cost << "\n";
}

#define ONLINE_JUDGE
int main() {
#ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
#endif
    int C;
    cin >> C;
    while (C--)
        solve();
    return 0;
}
