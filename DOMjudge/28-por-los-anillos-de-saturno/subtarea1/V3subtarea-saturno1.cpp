#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using info = pair<int,int>;
using Grafo = vector<vector<info>>; // Grados, Anillos.

int INF = 1000000000;

void solve(){
    int N, K;
    // Anillos N, Túneles K
    // Subtarea N=1 K=0.
    cin>>N>>K;
    
    // Tiempo en recorrer un grado de distancia angular, en el i-esimo angulo, como N=1 , solo hay un anillo.
    int T; cin>>T;

    // grafo de N+1 anillos, 360 grados, con lo que atrda por moverse de grado.
    Grafo grafo;
    grafo.assign(360, vector<info>({}));
    for (int n = 1; n < N+1; ++n) {
        // Rangos positivos, conecta los angulos, el 0 con el 1, y asi hasta 179 con 180.
        for (int grado = 0; grado < 180; ++grado) {
            grafo[grado].push_back({T, grado + 1});
            if(grado > 0) grafo[grado].push_back({T, grado - 1});
        }
        // Números negativos, conecta el 0 con el 359, y asi hasta 181 con 180.
        for (int grado = 360; grado > 180; --grado) {
            grafo[grado % 360].push_back({T, grado - 1});
        }
    }
    // Indice de al anillo(d) y grado en el que empieza(g)
    // Indice del anillo(e) y grado en el que termina(h)
    int d, g, e, h;
    cin>>d>>g>>e>>h;

    // Distancias entre anillos
    vector<int>dist(360, INF);
    // Desde el origen hay distancia 0 y lo añadimos a la cola de prioridad inversa.
    dist[g] = 0;
    priority_queue<info, vector<info>, greater<info>> pq;
    pq.push({0, g});
    while(!pq.empty()){
        // Tiempo en llegar conocido(t), grado actual(v).
        auto [t, v] = pq.top(); pq.pop();
        
        if(t > dist[v]) continue; // Info antigua

        // Tiempo en lleagar al grado adyacaente(ta), grado adyacente(w).
        // Si el tiempo conocido mas el camino hasta el siguiente grado, es manor que la distancia conocida al grado sigiente, lo actualizamos.
        for(auto [ta, w] : grafo[v]){
            if(dist[v] + T < dist[w]){
                dist[w] = dist[v] + T;
                pq.push({dist[w], w});
            }
        }
    }
    // Mostramos el tiempo menor en lleagar al grado buscado.
    cout<<dist[h]<<"\n";
}

int main(){
    int C; cin>>C;
    while(C > 0){
        solve();
        C--;
    }
    return 0;
}