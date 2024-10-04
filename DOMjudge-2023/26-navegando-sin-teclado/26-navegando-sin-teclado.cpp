#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using info = pair<int,int>;
using Grafo = vector<vector<info>>; // Minutos, Vértices.

Grafo g;
vector<int> pages;
int N;
int INF = 1000000000;

// Dijkstra para encontrar el camino más corto entre O y D páginas.
int dijkstra(int O, int D){
    // Distancia de cada uno de los vértices, inicializado en INF, la distancia desde el origen es 0.
    vector<int> dist(N+1, INF);
    dist[O] = 0;
    // Cola de prioridad inversa, para que el menor elemento sea el primero, y le añaddimos el origen.
    priority_queue<info, vector<info>, greater<info>> pq;
    pq.push({0, O});

    while(!pq.empty()){
        auto d = pq.top().first; // Distancia(d)
        auto u = pq.top().second; // Vertice(u)
        pq.pop();

        // Si la distancia actual es mayor que el valor acumulado, pasamos al siguiente, para info antigua.
        if(d > dist[u]) continue;

        for(auto [w, v] : g[u]){
            // El coste del vértice actual mas el timpo a recorrer mas  el tiemo de carga de la pagina.
            if(dist[u] + w + pages[u] < dist[v]){
                // Lo guardanmos en dist y lo pasamos a la cola de prioridad.
                dist[v] = dist[u] + w + pages[u];
                pq.push({dist[v], v});
            }
        }
    }

    // Si la distancia es infinita, no se puede llegar al destino, si no sera la distancia mas el tiempo mas lo que tarda esta en cargar.
    if(dist[D] == INF) return -1;
    return dist[D] + pages[D];
}

bool solve(){
    // Páginas manejadas (N)
    cin>>N;
    
    if(N == 0) return false;

    pages.assign(N+1, 0);
    for(int n = 1; n < N+1; ++n){
        // Tiempo de carga en milisegundos de cada una de las páginas(N)
        int K; cin>>K;
        pages[n] = K;
    }

    // Origen y destino (O, D)
    int O = 1, D = N;
    g.assign(N + 1, {}); 

    // Número de enlaces entre páginas (M)
    int M; cin>>M;
    for(int m = 0; m < M; ++m){
        // Página origen, página destino y tiempo de navegación en segundos (u, v, t)
        int u, v, t; cin>>u>>v>>t;
        g[u].push_back({t, v});
    }

    // Si es -1 no se puede llegar al destino.
    int sol = dijkstra(O, D);
    if(sol == -1) cout<<"IMPOSIBLE\n";
    else cout<<sol<<"\n";

    return true;
}

int main(){
    while(solve());
    return 0;
}