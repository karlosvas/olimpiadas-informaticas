#include <iostream>
#include <set>
#include <vector>

using namespace std;
using Grafo = vector<set<int>>;
Grafo g;
vector<bool> visit;

int B, N;

// Grafo bipartito.
int dfs(int v, int color) {
    visit[v] = true;

    if(color == 1){
        N++;
    } else {
        B++;
    }

    for(int w: g[v]){
        if(!visit[w]){
            // Viistamos las adyacentes y le damos a color su negativo para que pase de negras a blancas en el siguiente bucle.
            visit[w] = true;
            dfs(w, -color);
        } else if ((color == 1 && visit[w] && N % 2 == 0) || (color == -1 && visit[w] && B % 2 == 0)) {
            // Si son negras y esta viistada y es divisible entre dos O si son blancas y esta visitada y el es divisible entre dos, el bucle termina aqui ya que no es bipartito. 
            return 0;
        }
    }

    return min(B,N);
}

bool solve(){
    // Cruces (n)
    // Calles entre cruces (c)
    int n; cin>>n;
    int c; cin>>c;
    if(!cin) return false;

    g.assign(n,{});
    visit.assign (n, {false});

    for (int i = 0; i< c;i++){
        // Agregamos las conexioines entre los vértices.
        int a,b; cin>>a>>b;
        --a; --b;
        g[a].insert(b);
        g[b].insert(a);
    }
    
    int guardias = 0;

    for(int v = 0; v < n; ++v){
        if(!visit[v]){
            // Agregamos el menor número de guardias por cada componente conexa, con color le indicamos el estado en el que se encuentra si B = blancas o si N = negras.
            int color = 1;
            B = 0; N = 0;
            guardias += dfs(v, color);
        }
    }

    if(guardias == 0) cout<<"IMPOSIBLE\n";
    else cout<<guardias<<"\n";
    return true;    
}

int main(){
    while(solve());
    return 0;
}