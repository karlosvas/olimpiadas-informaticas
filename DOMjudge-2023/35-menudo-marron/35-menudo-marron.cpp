#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

const int INF = 1000000000;
vector<vector<int>> g;
vector<bool> visit;
vector<int> solution;

// Visitamos todos los supermercados a los que podemos llegar desde v.
int dfs(int v, vector<int>& supermarket_prices, int best_option,  int index) {
    visit[v] = true;
    solution[v] = index;

    if(supermarket_prices[v] != INF) best_option = min(best_option, supermarket_prices[v]);

    for (int w : g[v]) {
        if (!visit[w]) {
            best_option = dfs(w, supermarket_prices, best_option, index);
        }
    }

    return best_option;
}

bool solve(){
    int N, C; cin>>N>>C;
    // Numero de puntos en la ciudad(N) y calles(C)

    if(!cin) return false;

    g.assign(N+1, {});

    for(int c= 0; c < C; c++){
        int a,b; cin>>a>>b;
        // Conexion de calles de doble sentido.
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // Supermercados(S) (S<N<C) No hay dos en la misma localización.
    int S; cin>>S;
    vector<int> supermarket_prices;
    supermarket_prices.assign(N+1, INF);

    for(int s = 0; s < S; s++){
        // Guarda en la clave del vertice super el precio.
        int super, price; cin>>super>>price;
        supermarket_prices[super] = price;
    }

    // Consultas(K), map de visitados.
    int K; cin>>K;

    solution.assign(N+1, INF);
    visit.assign(N+1, false);
    vector<int> conexas;

    int index = 0;
    for(int k= 0; k < K; k++){
        // Origen de la consulta(o);
        int o; cin>>o;

        if(!visit[o]){
            // Buscamos por cada componente conexa con un priority_queue cual es el supermercado mas barato.
            int best_option = dfs(o, supermarket_prices, INF, index);
            conexas.push_back(best_option);
            index++;
        }

        if(conexas[solution[o]] == INF) cout<<"MENUDO MARRON\n";
        else cout<<conexas[solution[o]]<<"\n";
    }

    cout<<"---\n";
    return true;
}

int main(){
    while(solve());
    return 0;
}