#include <iostream>
#include <vector>
#include <string>

using namespace std;
using Grafo = vector<vector<int>>;
Grafo g;
vector<bool> visit;

int dfs(int v){
    // Cuenta los adyacentes.
    visit[v] = true;
    int ad = 1;
    for(int arista : g[v]){
        if(!visit[arista]) {
            ad += dfs(arista);
        }
    }
    return ad;
}

bool solve(){
    // Usuaurios en al red(n)
    // Numero de grupos(m)
    int n,m;
    cin>>n>>m;

    if(!cin) return false;
    g.assign(n, {} );

    for (int i = 0; i < m; i++) {
        int num = 0;
        int a = 0;

        bool first = false;
        int event; cin>>event;
        while(event--){
            // Hacemos las relaciones entre vectores.
            cin>>a; a--;
            
            if(!first){
                // Si es la primera vuelta lo guarda en num, para que en la siguiente haga la reclacion con el siguiente valor de a.
                num = a;
                first = true;
            } else{
                g[num].push_back(a);
                g[a].push_back(num);
                num = a;
            }
        }
        first = false;
    }
    
    // Cremos un grafo de boleanos inicializamos en false con n (Vectores), para estrablecer las relaciones.

    for (int v= 0; v < n; v++){
        // Recorre todos los vértices, y se reincician las visitas en cada vuelta para contyar las adyacentes de cada verice.
        visit.assign(n, false);
        int sol = dfs(v);

        if(v == n -1) cout<<sol<<"\n";
        else cout<<sol<<" ";
        // Cantidad de usuarios (ADyacentes de v) que termiann sabiendo la noticia, si empieza a distribuirla v.
    }

    return true;
}

int main(){
    while(solve());
    return 0;
}