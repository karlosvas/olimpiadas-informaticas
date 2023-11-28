#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Grafo = vector<vector<pair<int,int>>>; // minutos, vértice.
using info = pair<int,int>;
Grafo g;
const int INF = 1000000000;
int N, C;
vector<int> ant;

// Muestra el camino de manera recursiva he inversa.
// Origen (P), Destino (Q).
void camino(int P, int Q) {
    if (P == Q) cout<<Q;
    else {
        camino(ant[P]);
        cout<<"->"<<P;
    }
}

// Dijkstra encuentra los caminimos con el coste mínimo de un vértice a otro.
int Dijsktra(int P, int Q){
    // Creamos una cola de prioridad inversa prioridad al menor.
    // Por cada caso de prueba se reinician los vertices a INF.
    vector<int> dist(N +1, INF);
    // Guarda olos vertices anteriores al encontrar un camino con menor coste.
    ant.assign(N + 1, 0);
    priority_queue<info, vector<info>, greater<info>> pq;
    // La distancia tiene que calcularse desde P, y agregamos el par a la cola con el tiempo y el origen.
    dist[P] = 0;
    pq.push({0, P});

    while(!pq.empty()){
        // Minutos(m), Vertice(v) extraemos los valores del par.
        auto[m,v] = pq.top(); pq.pop();
        // Si los minutos > tiempo minimo conodido hsata ahora, pasa al siguiente elemento para no tener en cuenta vértices en pq antiguos o que ya han sido descartados.
        if(m > dist[v]) continue;

        // Minutos de adyacentes(ma), vértice de adyacentes(w).
        for(auto[ma, w] : g[v]){
            // Tiempo actual + minutos a recorrer son < que el tiempo a recorer, si no ha sido explorado antes, es INF, si no se encarga de verificar si tiene un camino con menor coste.
            if(dist[v] + ma < dist[w]){
                // Guarda en dist[w] el tiempo desde el vértice desde el que se busca + los minutos a recorrer hasta su adyacebte, y se guarda como siguiente caso.
                dist[w] = dist[v] + ma;
                ant[w] = v;
                pq.push({dist[w], w});
            }
        }
    }

    // Una vez se ha explorado todo el grafo, devolvemos el tiempo mínimo que se tarda en llegar al destino.
    return dist[Q];
}

bool solve(){
    // Número de puntos de recojida (N), Numero de tramos o calles entre puntos (C).
    cin>>N>>C;

    if(!cin) return false;

    // Creamos un grafo de 1 a N de vértices.
    g.assign(N + 1, {});
    // Conexiones de calles entre puntos de recojida bidereccionales.
    for(int c = 0; c < C; ++c){
        // Punto1(u), Punto2(v), Tiemo(t).
        int u,v,t; cin>>u>>v>>t;
        g[u].push_back({t,v});
        g[v].push_back({t,u});
    }

    // Cantidad de casos de prueba (K).
    int K; cin>>K;
    for(int k = 0; k < K; ++k){
        // Punto de partida o origen (P), Punto de entrega final o destino(Q).
        int P,Q; cin>>P>>Q;
        // Si devuelbe INF es que no ha enontrado un camino que conecte el origen con el destino por lo que no a lleagdo a ese vertice.
        int sol = Dijsktra(P,Q);

        if(sol == INF) cout<<"NO LLEGA\n";
        else cout<<sol<<": "<<camino(P, Q)<<"\n";
    }
    cout<<"---\n";

    return true;
}

int main(){
    while(solve());
    return 0;
}