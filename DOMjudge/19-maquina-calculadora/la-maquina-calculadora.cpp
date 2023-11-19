#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using Grafo = vector<vector<int>>;
Grafo g;

// Función que devuelve los nodos adyacentes según la operación definida por i.
int adyacentes(int v, int i){
    return (i == 0) ? ((v + 1) % 10000) 
    : ((i == 1) ? ((v * 2) % 10000) 
    : (v / 3));
}

// Función de busqueda en anchura.
int bfs(int O, int D){
    // Si el origen es igual al destino devolbemos los nodos recorridos.
    if(O == D) return 0;

    // Inicializamos los 10000 vertices con un valor de -1 para indicar que no se ha llegadoa a ellos.
    vector<int> dist(10000, -1);
    // Empezamos desde el 0 y añadimos el origen a una cola.
    dist[O] = 0;
    queue<int> q;
    q.push(O);

    while (!q.empty()){
        int v = q.front(); q.pop();

        for (int i = 0; i < 3; ++i){
            // Buscamos en los adyacentes.
            int w = adyacentes(v, i);
            if(dist[w] ==  -1){
                // Si el nodo no ha sido visitado, lo marcamos con la distancia actual + 1 para guardar el recorrido.
                dist[w] = dist[v] + 1;
                // Si el nuevo adyacente es igual a el destino retorna la distancia recorrida, si no, guarda en la cola el siguiente nodo para analizar.
                if (w == D) return dist[w];
                else q.push(w);
            }
        }
    }

    // No se ha encontrrado un camino
    return -1;
}

bool solve(){
    // Origen (O)
    // Destino (D)
    int O, D; cin>>O>>D;

    if(!cin) return false;
    
    int dist = bfs(O, D);
    cout<<dist<<"\n";

    return true;
}

int main(){
    while(solve());
    return 0;
}