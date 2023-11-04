#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;
using Grafo = vector<vector<int>>;
Grafo g;
vector<bool> visit;

int dfs(int v){
    visit[v] = true;
    int res = 1;

    for(int arista : g[v]){
        if(!visit[arista]) {
            res += dfs(arista);
        }
    }
    return res;
}

bool solve(){
    // Usuaurios en al red(n)
    // Numero de grupos(m)
    int n,m;
    cin>>n>>m;

    if(!cin) false;
    string lineId;
    g.assign(n, {} );

    for (int i = 0; i < m; i++){
        int first; cin>>first;

        for(int k = 0; k < first; k++){
            // Añadimos cada entrada a g en ese índice.
           int num; cin>>num;
            g[i].push_back(num);
        }

    }

    
    // Cremos un grafo de boleanos inicializamos en false con n (Vectores), para estrablecer las relaciones.
    visit.assign(n, false);

    for (int v= 0; v < n; v++){
    // Recorre todos los vértices.
        if (!visit[v]) {
            int res = dfs(v);
            cout<<res<<"\n";
        }
        // Cantidad de usuarios que termiann sabiendo la noticia.
    }

    return true;
}

int main(){
    while(solve());
    return 0;
}

/*
## Entrada de ejemplo
7 5  
3 2 5 4  
0  
2 1 2  
1 1  
2 6 7  

4 2  
1 1  
1 3  

## Salida de ejemplo
4 4 1 4 4 2 2  
1 1 1 1  
*/