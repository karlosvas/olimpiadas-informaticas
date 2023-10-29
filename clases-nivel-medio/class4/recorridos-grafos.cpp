#include <iostream>
#include <string>
#include <vector>
using namespace std;

using Grafo = vector<vector<int>>;

Grafo g;
vector<bool> visit;

void dfs(int v) {
    visit[v] = true;
    for(int w: g[v]) {
        if(!visit[w]) {
            dfs(w);
        }
    }
}

int main (){
    int V, A;
    cin>>V>>A;
    g.assign(V,{});

    for(int i = 0; i < A; ++i){
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int componentes = 0;
    visit.assign(V, false);
    for(int v = 0;v<V;++v) {
        if(!visit[v]) {
            dfs(v);
            ++componentes;
        }
    }

    cout<<componentes<<"\n";
    return 0;
}