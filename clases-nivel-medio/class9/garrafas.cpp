#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1000000000;

using estado = pair<int,int>; // cantidad de agua en la primera garafa, cantidad de agua en la segunda garrafa.
using info = pair<int,estado>; // <agua movida, estado>

void solve(){
    vector<int> cap(3);
    int D;
    // Capacidad de las garrafas (A, B, C) y cantidad de agua deseada (D)
    cin>>cap[0]>>cap[1]>>cap[2]>>D;
    if(cap[0] == D){
        cout<<"0\n";
        return;
    }

    // Dijkstra
    vector<vector<int>> dist(3, vector<int>(cap[0]+1, INF));
    priority_queue<info, vector<info>, greater<info>> cola;

    estado origen = {cap[0], 0};
    cola.push({0, origen});
    dist[origen.first][origen.second] = 0;

    while(!cola.empty()){
        auto [t, u] = cola.top(); cola.pop();
        auto [a, b] = u;

        if(t > dist[a][b]) continue; // Información antigua.

        int c = cap[0] - a - b; // Cantidad de agua en la tercera garrafa.
        vector<int> act = {a, b, c};

        // Vemos si tenemos solución
        for(int x: act){
            if(x == D){
                cout<<t<<"\n";
                return;
            }
        }

        // Transvases
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                // i -> j
                if(i == j) continue;
                // Movemos de i a j todo lo que podamos
                vector<int> nuevo = act;
                int muevo = min(nuevo[i], cap[j] - nuevo[j]);
                nuevo[i] = act[i] - muevo;
                nuevo[j] = act[j] + muevo;
                if(t + muevo < dist[nuevo[0]][nuevo[1]]){ // Puedo mejeorar.
                    dist[nuevo[0]][nuevo[1]] = t + muevo;
                    cola.push({t + muevo, {nuevo[0], nuevo[1]}});
                }
            }
        }
    }
    // Si llegamos aquí no hay solución.
    cout<<"BOOM\n";
}

int main(){
    solve();
    return 0;
}