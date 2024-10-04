#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Grafo = vector<vector<int>>;
Grafo g;
int N, C;

vector<int> bfs(int O){

    // Vector de N nodos en al red.
    vector<int> dist(N, -1);
    dist[O] = 0;
    queue<int> q;
    q.push(O);

    while (!q.empty()){
        int v = q.front(); q.pop();
        // Por cada adyacente no descubierta es la suma de la distancia del nodo atual + 1, la guardamos en la cola.
        for(int w: g[v]){
            if(dist[w] == -1){
                dist[w] = dist[v] + 1;
                q.push(w);                
            }

        }
    }

    // Retornamos la distancia almacenada.
    return dist;
}

bool solve(){
    // Número de nodos en la red (N).
    // Número de conexiones en la red (C).
    cin>>N;
    cin>>C;
    if(!cin) return false;

    g.assign(N, {});

    for (int i = 0; i < C; i++){
        // Relaciones entre vértices no dirijidos.
        int a, b; cin>>a>>b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int K; cin>>K;

    for (int k = 0; k < K; k++){
        // Vertice de origen por el que buscar (O).
        // Máximo del recorrido (TTL).
        int O,TTL; cin>>O>>TTL;
        O--;

        // Recorrido en anchura.
        vector<int> dist = bfs(O);
        int in = 0;

        for(int v = 0; v < N; ++v){
            // Si su recorrido es mayor a el TTL o no estan en la misma componente conexa inalcanzable (in) suma 1.
            if(dist[v] > TTL || dist[v] == -1) in++;
        }

        cout<<in<<"\n";
        if(k == K -1) cout<<"---\n";
    }

    return true;
}

int main(){
    while(solve());
    return 0;
}