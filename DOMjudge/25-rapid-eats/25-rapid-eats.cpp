#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Grafo = vector<vector<pair<int,int>>>; // minutos, vértice.
using info = pair<int,int>;
Grafo g;
const int INF = 1000000000;
int N, C;

bool dikstra(int P, int Q){
    priority_queue<info, vector<info>, greater<info>> pq;
    vector<int> dist(N +1, INF);
    pq.push({0, P});
    while(!pq.empty()){
        // Minutos (m), Vertice(v)
        auto[m,v] = pq.top(); pq.pop();
        if(m > dist[v]) continue;

        // Minuto de adyacentes(ma)
        for(auto[ma, w] : g[v]){
            if(dist[v] + ma < dist[w]){
                dist[w] = dist[v] + ma;
                pq.push({dist[w], w});
                if(w == Q){
                    cout<<"el menor tiempo hasta el destino es "<<ma<<"Y el es vértice es "<<v<<"\n";
                    return false;
                }
            }
        }
    }
    return false;
}

bool solve(){
    // Número de puntos de recojida (N), Numero de tramos o calles entre puntos (C).
    cin>>N>>C;

    if(!cin) return false;

    g.assign(N + 1, {});
    for(int c = 0; c < C; ++c){
        int u,v,t; cin>>u>>v>>t;
        g[u].push_back({c,v});
        g[v].push_back({c,v});
    }

    int K; cin>>K;
    for(int k = 0; k < K; ++k){
        int P,Q; cin>>P>>Q;
        if(!dikstra(P,Q)) cout<<"NO LLEGA\n";
    }
    cout<<"---\n";
    return false;
}

int main(){
    while(solve());
    return 0;
}