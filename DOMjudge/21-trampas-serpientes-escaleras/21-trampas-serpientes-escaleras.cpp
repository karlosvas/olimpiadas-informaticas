#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> table;
int N, K, S, E;

// Función bfs para buscar el camino mas corto desde el origen a el N*N.
int bfs(int O, int D){
    // Vector de N*N casilas, sin descubir.
    vector<int> dist(N*N, -1);
    dist[O] = 0;
    queue<int> q;
    q.push(O);

    while (!q.empty()){
        int v = q.front(); q.pop();
        // Por cada adyacente no descubierta, se le suma la distancia del nodo atual (v).
        for(int i = 0; i <= K && v <= N*N; ++i){
            // Lo recorremos, si es el objetivo lo devuelbe, si no lo guardamos en la cola para ser el nuevo (v).
            int w = table[v+i];
            if(dist[w] == -1){
                // Si no esta visitado se le añade a la distanmcia acumulada a dist[w].
                dist[w] = dist[v] + 1;
                if(w == D - 1) return dist[w];
                else q.push(w);                
            }
        }
    }
    // Retornamos -1 si no ese encontro ningún camino.
    return -1;
}


bool solve(){
    cin>>N>>K>>S>>E;

    if(N == 0) return false;

    // Grafo dirijido que permite ir del inicio al final, pero no viceversa, (S) Serpientes, (E) Escaleras.
    table.assign(N * N, 0);
    for(int i= 0; i < N*N; i++){
        table[i] = i;
    }

    for(int i = 0; i < S+E; ++i){
        int in,fn; cin>>in>>fn;
        --in; --fn;
        table[in] = fn;
    }

    cout<<bfs(0, N*N)<<"\n";

    return true;
}

int main(){
    while(solve());
    return 0;
}