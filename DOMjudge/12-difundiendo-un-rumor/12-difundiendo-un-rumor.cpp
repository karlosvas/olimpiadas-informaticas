#include <iostream>
#include <vector>
using namespace std;

using Grafo = vector<vector<int>>;
Grafo g;
vector<bool> visit;

// Depth-First Search (DFS).
int dfs(int v, vector<int> &cash) {
    visit[v] = true;
    int actual = cash[v];

    for(int arista : g[v]) {
        if(!visit[arista]) {
            int tam = dfs(arista, cash);
            actual = std::min(actual, tam);
        }
    }
    // Devuelbe el valor del cash en las adyacentes en cada componente conexa.
    return actual;
}

bool solve() {
    // Personajes(n), Pares de amigos(m).
    int n, m; cin >> n >> m;
    if (n == 0 || m == 0) return false;

    vector<int> cash;
    g.assign(n, {});

    for(int i = 0; i < n; ++i){
        // Dinero que cobraría cada personaje para ser sobornado.
        int ci; cin>>ci;
        cash.push_back(ci);
    }

    for(int i = 0; i < m; ++i){
        // Añadismos las aristas a los vértices.
        int p1, p2; cin>>p1>>p2;
        --p1; --p2;
        g[p1].push_back(p2);
        g[p2].push_back(p1);
    }

    // Creamos un grafo de boleanos inicializados en false con V (Vectores).
    int min = 0;
    visit.assign(n, false);
    // Recorre todas los vertices.
    for(int v = 0; v < n ; ++v) {
        if (!visit[v]) {
            // Si no esta visitado el verice llama a dfs.
            int component_min = dfs(v, cash);
            min += component_min;  
        }
    }
    cout<<min<<"\n";
    return true;
}

int main(){
    while (solve());    
    return 0;
}