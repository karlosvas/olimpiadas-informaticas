#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using info = pair<int,int>; // minutos, vértice
using Grafo = vector<vector<info>>;
Grafo g;

const int INF = 1000000000;
int N, S, T, P;

// Dijkstra para encontrar la ruta más corta desde cada ratón hasta la salida, origen(O).
vector<int> dijkstra(int S){
    // Creamos un vector de distancias, inicializadas a infinito, y le damos distancia 0 al origen.
    vector<int> dist(N+1, INF);
    dist[S] = 0;
    // Creamos una cola de prioridad inversa, para que el tiempo menor sea el de mayor prioridad, y le agregamos el origen.
    priority_queue<info, vector<info>, greater<info>> pq;
    pq.push({0, S});

    while(!pq.empty()){
        // Sacamos el vértice con menor tiempo de la cola.
        // Minutos(m), Vértice(v)
        auto[m, v] = pq.top(); pq.pop();
        if(m > dist[v]) continue; // Información obsoleta.

        for(auto[ma, w] : g[v]){
            // Minutos de la adyacente(ma), Vértice adyacente(w).
            // Si el tiempo de la celda actual más el tiempo en dirijirse a la siguiente es menor que el tiempo de la adyacente.
            if(dist[v] + ma < dist[w]){
                // Actualizamos el tiempo en llegar, y la agregamos a la cola.
                dist[w] = dist[v] + ma;
                // Si el vértice adyacente es la salida, devolvemos el tiempo que tarda.
                pq.push({dist[w], w});
            }
        }

    }
    // Si no se puede llegar a la salida, devolvemos infinito.
    return dist;
}

bool solve(){
    // Número de celdas del laberinto(N), salida(S), segundos(T), y pasdizos(P)
    cin>>N>>S>>T>>P;
    
    if(!cin) return false;

    g.assign(N+1, {});
    
    // Pasadizos en en laberinto de grafos dirigidos.
    for(int p = 0; p < P; ++p){
        // Pasadizo desde B hasta A.
        // Tiempo que tarda en recorrer cada pasadizo (C)
        int A, B, C; cin>>A>>B>>C;
        g[B].push_back({C, A});
    }

    int sol = 0;
    // Buscamos el tiempo mínimo que se tarde de la salida a cada ratón.
    vector<int> mice = dijkstra(S);
    for(int elm :mice){
        // Si el tiempo no es el origen(0), y es menor o igual que el tiempo que tenemos, podria salir del laberinto.
        if(elm <= T && elm != 0) sol++;
    }
    // Ratones que pueden salir del laberinto.
    cout<<sol<<"\n";

    return true;
}   

int main(){
    while(solve());
    return 0;
}