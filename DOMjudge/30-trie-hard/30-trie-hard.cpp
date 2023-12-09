#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

using estado = pair<int, int>; // Agua movida, estado.
using info = pair<int, estado>; // Cantidad en la pirmera, cantidad en la segunda.
int INF = 1000000000;

void solve(){
    vector<int> cap(3); // Capacidadades de cada jarra.
    // Primera(a), Segunda(b), Tercera(c), Objetivo(0)
    int O; cin>>cap[0]>>cap[1]>>cap[2]>>O;

    // Si empezamos con la cantidad objetivo, no se puede.
    if(cap[0] == O){
        cout<<"0\n";
        return;
    }

    // Distancia minima para llegar a cada estado.
    vector<vector<int>> dist(cap[0]+1, vector<int>(cap[1]+1, INF));
    priority_queue<info,vector<info>,greater<info>> pq;

    // Estado inicial.
    estado origen = {cap[0], 0};
    pq.push({0, origen}); // Agua movida, estado(Cantidad de la primera garrafa, cantidad a la que se mueve).
    dist[origen.first][origen.second] = 0;

    // Dijkstra.
    while(!pq.empty()){
        auto[t, u] = pq.top(); pq.pop(); // Agua transvasada conocida, estado.
        auto[a, b] = u; // Cantidad de agua en la primera, cantidad de agua en la segunda.

        if(t > dist[a][b]) continue; // Info antigua.

        int c = cap[0] - a - b; // Cantidad de agua en la tercera, inicial menos el agua en las demas.
        vector<int> terna_act = {a, b, c}; // terna actual.

        for(int objetivo: terna_act){
            // Si algun elemeento de la terna es igual al objetivo, mostramos la cantidad de agua transvasada para llegar a el.
            if(objetivo == O){
                cout<<t<<"\n";
                return;
            }
        }

        // Transvasar agua de una garrafa a otra.
        for(int i = 0; i < 3; i++){
            for(int j= 0; j < 3; j++){
                // Si tienen la misma cantidad de agua, pasa al siguiente caso.
                if(i == j) continue;

                vector<int>new_terna = terna_act; // Creamos otro vector para no cambiar el estado actual.

                // Nos aseguramos que no se desborde la garrafa.
                // Primera garrafa en el estado actual, y la capacidad de la segunda garrafa menos lo movido en esa iteración j.
                int move = min(terna_act[i], cap[j] - terna_act[j]);
                // Se vacia la priemra garrafa y se llena la segunda.
                new_terna[i] = terna_act[i] - move;
                new_terna[j] = terna_act[j] + move;

                if(t + move < dist[new_terna[0]][new_terna[1]]){
                    // Si la cantidad de agua trasvasada conocida mas el coste de moverla, es menor que la distancia de la nueva terna.
                    // Actualizamos la distancia de la nueva terna y la añadimos a la cola de prioridad.
                    dist[new_terna[0]][new_terna[1]] = t + move;
                    pq.push({t + move, {new_terna[0], new_terna[1]}});
                }
            }
        }
    }
    // No se ha encontrado solución, se acabo el tiempo.
    cout<<"BOOM\n";
}

int main() {
    int C; cin>>C;
    while(C > 0){
        solve();
        C--;
    }
    return 0;
}
