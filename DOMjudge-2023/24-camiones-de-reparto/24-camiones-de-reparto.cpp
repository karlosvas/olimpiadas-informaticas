#include <iostream>
#include <vector>

using namespace std;
vector<vector<pair<int, int>>> g; // anchura,calle
vector<bool> visit;

// Origen (o), Destino(d), Anchura del camión(a).
bool dfs(int o, int d, int a){
    visit[o] = true;
    // Buscamos en las calles adyacentes a las que puede acceder.
    // Achura de la nueva calle (c), nueva calle (w). 
    for(auto [c, w] : g[o]){
        
        // w no ha sido visitado.
        if(!visit[w]){
            // Si la anchura camión (a) no cabe por la nueva calle c, busca por otra ruta.
            if(c < a) continue;

            // Si devuelbe true quiere decir que ha encontrado el destino (d).
            if (dfs(w, d, a)) return true;
            else if (w == d) return true;
        }
    }

    return false;
}

bool solve(){
    int V,E;
    cin>>V; // Intersecciones de la cuiudad (V).
    cin>>E; // Calles entre intersecciones (E).

    if(!cin) return false;

    // Creamos un grafo dirijido con V vertices desde 1. 
    g.assign(V+1, {});

    for(int e = 0; e < E; ++e){
        // Conexiones de calles.
        int u, v, c; // Para ir desde u a v tiene que pasar por una calle con anchura c.
        cin>>u>>v>>c;
        g[u].push_back({c, v});
        g[v].push_back({c, u});
    }

    int K; cin>>K; // Consultas (K).
    
    for(int k = 0; k < K; ++k){
        // Por cada nueva consulta el grafo se inicializa con todos los vértices en false.
        visit.assign(V+1, false);
        int o,d,a; // Origen(o), Destino(d), Anchura(a).
        cin>>o>>d>>a;

        // Si dfs devuelbe fasle signific que ha podido encontrar un camino.
        if(dfs(o,d,a)) cout<<"SI\n";
        else cout<<"NO\n";
    }

    return true;
}
int main(){
    while(solve());
    return 0;
}