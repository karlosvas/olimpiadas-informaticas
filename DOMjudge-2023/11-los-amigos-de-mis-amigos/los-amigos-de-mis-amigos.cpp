#include <iostream>
#include <vector>
using namespace std;

using Grafo = vector<vector<int>>;

Grafo g;
vector<bool> visit;

int dfs(int v) {
    // Llamada recursiva para ver si el vertice y sus adyacentes estan visitados.
    visit[v] = true;
    int tam = 1;
    for(int ad: g[v]) {
        // Recorre todas las adyacentes.
        if(!visit[ad]) {
            tam += dfs(ad);
        }
    }
    return tam;
}

bool solve(){
    // Vectores y aristas, grafo de vectores de v.
    int V, A; cin>>V>>A;
    g.assign(V,{});

    for(int i = 0; i < A; ++i){
        // Añadismos los dios vértices de cada arista.
        int v1, v2; cin>>v1>>v2;
        --v1; --v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }

    // Creamos un grafo de voleanos inicializados en false con V (Vectores).
    int maximo = 0;
    visit.assign(V, false);

    for(int v = 0;v<V;++v) {
        // Si no esta visitado el verice llama a dfs.
        if(!visit[v]) {
            int tam = dfs(v);
            if(maximo < tam){
                // Verifica si el tamaño del actual es mayor que el anteririor.
                maximo = tam;
            }
        }
    }
    cout<<maximo<<"\n";
    return true;
}

int main (){
    int cases; cin>>cases;
    while (solve()){
        cases--;
        if (cases== 0) return false;
    };
    
    return 0;
}