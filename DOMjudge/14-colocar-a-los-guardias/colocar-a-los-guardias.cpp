#include <iostream>
#include <set>
#include <vector>

using namespace std;
using Grafo = vector<set<int>>;
Grafo g;
vector<pair<bool, bool>> visit;

// Grafo bipartito.
using namespace std;

int dfs(int v) {
    visit[v].first = true;
    int guardias = 0;

    for(int w: g[v]){
        // Empezando desde el 1, si el actual es igual que el anterior los dos son false.
        if(!visit[w].first){

            if(!visit[v].second && !visit[w].second){
                visit[w].second = true;
                ++guardias;
            }
            guardias += dfs(w);
        }
    }

    return guardias;
}

bool solve(){
    // Cruces (n)
    // Calles entre cruces (c)
    int n; cin>>n;
    int c; cin>>c;
    if(!cin) return false;

    g.assign(n,{});
    visit.assign (n, {false, false});

    for (int i = 0; i< c;i++){
        int a,b; cin>>a>>b;
        --a; --b;
        g[a].insert(b);
        g[b].insert(a);
    }
    
    int total_g = 0;
    for(int v= 0; v < n; v++){
        if(!visit[v].first){
            total_g += dfs(v);
        }
    }
    
    if(n == c) cout<<"IMPOSIBLE\n";
    else cout<<total_g<<"\n";
    return true;    
}

int main(){
    while(solve());
    return 0;
}