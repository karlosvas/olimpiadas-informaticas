#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Grafo = vector<vector<int>>;
Grafo g;
int N,C,A,L,T;

vector<int> bfs(int O){
    // Creamos un recorrido en anchura con N interseciones (vertices), inicializado en -1 para indicar si ha sido descubierto.
    vector<int> dist(N, -1);
    // Empezamos desde el origen y lo añadimos a la cola.
    dist[O] = 0;
    queue<int> q;
    q.push(O);

    while(!q.empty()){
        // Si la cola no esta vacia guardamos el ultimo elemento en v y lo eliminamos.
        int v = q.front(); q.pop();
        for(int w: g[v]){
            // Recorremos los adyacentes a v.
            if(dist[w] == -1){
                // Si no esta visitado, agregamos la distancia que a recorrido a dist[w], de esta manera guardaremos en dist la distancia recorrida.
                dist[w] = dist[v] + 1;
                // Lo agregamos a la cola para el siguiente caso de prueba.
                q.push(w);
            }
        }
    }

    // Una vez descubierta todas las posibilidades devolvemos el vector con las distancias.
    return dist;
}

bool solve(){
    cin>>N>>C>>A>>L>>T;

    if(!cin) return false;
    
    // Creamos el grafo con N vétices y lo inicializamos vacio.
    g.assign(N, {});

    for(int c = 0; c < C; ++c){
        // Por cada tramo de calle (C) hay una  nueva conexión.
        int a,b; cin>>a>>b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Hacemos un vector de distancias para todos los vértices desde Alex(A), Lucas(L) y desde el Trabajo(T).
    vector<int> routeAlex = bfs(A - 1);
    vector<int> routeLucas = bfs(L - 1);
    vector<int> routeJob = bfs(T - 1);

    int min_sum = 1000000;
    // min_sum sera el valor minimo de la suma de todas la rutas en cada vertice.
    for(int v = 0; v < N; ++v){
        // LA suma indica cuanto costaría llegar al trabajo si v fuera el punto de unión entre A, L y T.
        // Ya que si por ejemplo, v = 3, el coste seria lo que cuesta llegar A hasta 4 + lo que tarde L hasta 4 + lo que tarde T hasta 4.
        int current_sum = routeAlex[v] + routeLucas[v] + routeJob[v];
        min_sum = min(min_sum, current_sum);
    }

    cout<<min_sum<<"\n";

    return true;
}

int main(){
    while(solve());
    return 0;
}