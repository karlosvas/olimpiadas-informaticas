#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using info = pair<int,int>;
using Grafo = vector<vector<info>>; // Grados, Anillos.
Grafo grafo;

int INF = 1000000000;
int N, K;

void solve(){
    // Anillos N, Túneles K
    // Subtarea N=1 K=0.
    cin>>N>>K;
    
    // Tiempo en recorrer un grado de distancia angular, en el i-esimo angulo, como N=1 , solo hay un anillo.
    int T; cin>>T;

    // grafo de N+1 anillos, 360 grados, con lo que atrda por moverse de grado.
    grafo.assign(N+1, vector<info>(360));
    for (int n = 1; n < N+1; ++n) {
        for (int grado = 0; grado <= 360; ++grado) {
            grafo[n][grado] = {T, grado};
        }
    }
    // Indice de al anillo(d) y grado en el que empieza(g)
    // Indice del anillo(e) y grado en el que termina(h)
    int d, g, e, h;
    cin>>d>>g>>e>>h;

    // Distancias entre anillos en el eje positivo.
    vector<int>pos(360, INF);
    // Desde el origen hay distancia 0 y lo añadimos a la cola de prioridad inversa.
    pos[g] = 0;
    priority_queue<info, vector<info>, greater<info>> pq;
    pq.push({0, g});
    while(!pq.empty()){
        // Tiempo en llegar(t), grado(v).
        auto [t, v] = pq.top(); pq.pop();
        if(t > pos[v]) continue; // Info antigua
        // Tiempo del adyacente ta, grado adyacente w.
        // Si el tiempo conocido mas el camino hasta el siguiente es manor que el grado sigiente, lo actualizamos.
        if(pos[v] + T < pos[v+1]){
            pos[v+1] = pos[v] + T;
            pq.push({pos[v+1], v+1});
        }
    }

    // Lo mismo pero a la inversa, para ver si es mejor ir hacia atras.
    // Eje negativo(neg)
    vector<int>neg(360, INF);
    neg[g] = 0;
    pq.push({0, g});
    while(!pq.empty()){
        auto [t, v] = pq.top(); pq.pop();
        if(t > neg[v]) continue;
        int before = (v-1+360) % 360;
        if(neg[v] + T < neg[before]){
            neg[before] = neg[v] + T;
            pq.push({neg[before], before});
        }
    }

    // El minimo entre el tiempo de ir hacia adelante o hacia atras.
    cout<<min(pos[h], neg[h])<<"\n";
}

int main(){
    int C; cin >> C;
    while(C > 0){
        C--;
        solve();
    }
    return 0;
}