#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

using Grafo = vector<vector<int>>;
Grafo g;
int V,A;

int solve(){
    int N, K, S, E;
    cin>>N>>K>>S>>E;

    if(N == 0) return false;

    vector<int> saltos(N*N+1);
    iota(saltos.begin(), saltos.end(), 0);

    for(int i = 0; i < S+E; ++i){
        int o,d; cin>>o>>d;
        saltos[o] == d;
    }

    vector<int> dist(N*N+1, -1);
    queue<int> q;
    dist[1] = 0;
    q.push(1);

    while (!q.emty()){
        int v = q.front(); q.pop();

        for(int i =0; i <= K && v+i <= N*N; ++i) {
            int w = saltos[v+i];
            if (dist[w] == -1){
                dist[w] = dist[v] + 1;
                q.push(w);
                if(w == N*N) {
                    cout<<dist[w]<<"\n";
                    return true;
                }
            }
        }
        
    }
    
    return true
}

int main(){
    while(solve());
    return 0;
}