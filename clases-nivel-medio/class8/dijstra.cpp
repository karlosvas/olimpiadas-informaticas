#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Digrafo = vector<vector<pair<int,int>>>;
using info = pair<int,int>; // distancia,vertice

const int INF = 1000000000;
int origen = 0;
vector<int> ant;

void camino(int v) {
    if (v == origen) cout<<origen;
    else {
        camino(ant[v]);
        cout<<"-->"<<v;
    }
}

int main(){
    int V,A;
    cin>>V>>A;

    Digrafo g(V);

    for(int i = 0; i < A; ++i){
        int u, v, c; cin>>u>>v>>c;
        g[u].push_back({c,v});
    }

    vector<int> dist(V, INF);
    ant.assign(V, 0);

    priority_queue<info, vector<info>, greater<info>> pq;
    dist[origen] = 0;
    pq.push({0, origen});

    while(!pq.empty()){
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue; // info antigua

        for(auto [c, v] : g[u]){
            if(dist[u] + c < dist[v]){
                dist[v] = dist[u] + c;
                ant[v] = u;
                pq.push({dist[v], v});
            }
        } 

    }
    
    for(int v = 0; v < V; ++v){
        cout<<"Distancia de 0 a "<<v<<":"<<dist[v]<<"\n";
        camino(v); cout<<"\n";
    }
    return 0;
}