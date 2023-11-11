#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Grafo = vector<vector<int>>;
Grafo g;
int V,A;

vector<int> bfs(int origen){
    vector<int> dist(V,-1);
    dsit[origen] = 0;
    queue<int> q;
    q.push(origen);

    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int w: g[v]){
            if(dist[w] == -1){
                dist[w] = dist[v] + 1;
                q.push(w);
            }
        }
        
    }

    return dist;
}

int main(){
    cin>>V>>A;

    g.assing(V, {});
    for(int i= 0; i < A; ++i){
        int u,v; cin>>u>>v;
        g[u].push_back(v)
        g[v].push_back(u)
    }

    vector<int> dist = bfs(0);
    for(int v = 1; v < V; ++v){
        if(dits[v] < 0){
            cout<<v<<" inalcanzabe\n"
        }else{
            cout<<v<<" a distancia "<<dist[v]<<"\n";
        }
    }
    return 0;
}

/*
7 9
0 1
0 2
0 5
1 2
2 3
2 4
3 4
3 5
4 6
*/