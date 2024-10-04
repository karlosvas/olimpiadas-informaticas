#include <iostream>
#include <set>
#include <vector>

using namespace std;
int white, black;

using Grafo = vector<set<int>>;
Grafo g;
vector<pair<bool, char>> visit;

// Grafo bipartito en un recorrido en profundidad.
bool dfs(int v, bool color) {
    visit[v].first = true;

    // Le damos el color correspondiente a cada uno de los vértices.
    if(color){
        ++white;
        visit[v].second = 'w';
    }
    else{ 
        ++black;
        visit[v].second = 'b';
    }

    for(int w: g[v]){
        // Alternamos el color al explorar nodos adyacentes, si el ciolor actual es igual a alguno de sus adyacentes, no es bipartito y devolbemos a dfs false para que el control pase a la llamda anterior.
        if (visit[v].second == visit[w].second) return false;
        if(!visit[w].first){
            // Si no esta visitado llamamos a dfs para sus adyacentes, y le damos el color opuesto a el de la llamada actual.
            // Si dfs es false, es porque no es bipartiro por lo que también retorna false para devolberle el control a la anterior, de esa manera terminar de forma recursiva.
            if (!dfs(w, !color)) return false;
        }
    }
    
    return true;
}

bool solve(){
    // Calles o vertices (N), Cruces o aristas (C).
    int N, C; cin>>N>>C;

    if(!cin) return false;

    // Grafo de N calles o vérices.
    // Grafo de N vértices con pares de bool para saber si están visitados, y char para guardar de que color son.
    g.assign(N,{});
    visit.assign (N, {false, {}});

    for (int k = 0; k< C;k++){
        // Casos de prueba, con las conexiones entre calles.
        int a,b; cin>>a>>b;
        --a; --b;
        g[a].insert(b);
        g[b].insert(a);
    }
    
    // El valor minimo será la suma de el valor minimo de los colores en las componentes conexas.
    bool gameover = false;
    int min_conex = 0;
    bool color = true;

    for(int v= 0; v < N; v++){
        if(!visit[v].first){
            // Reiniciamos el contador de colores en cada componente conexa.
            black = 0, white = 0;
            if(!dfs(v, color)){
                // Si dfs es false significa que no es bipartito, por lo que paramos de buscar. 
                cout<<"IMPOSIBLE\n";
                gameover = true;
                break;
            }else{
                // Sumamos el color mínimo entre los colores en cada componente conexa.
                min_conex += min(white, black);
            }
        }
    }

    // Si no es game_over mostramos la suma de todos los minimos de las componentes conexas.
    if(!gameover) cout<<min_conex<<"\n";
    return true;
}

int main(){
    while(solve());
    return 0;
}