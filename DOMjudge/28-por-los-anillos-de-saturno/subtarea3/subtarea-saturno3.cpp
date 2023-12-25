#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 1000000000;

void solve(){
    // Anillos N, Túneles K
    int N, K; cin>>N>>K;

    vector<int> rings(N+1, 0);
    // Guardamos la distancia recorrida en cada anillo para llegar al tunel.
    for(int k = 1; k <= K; ++k){
        int a,b; cin>>a>>b;
        rings[a] = b;
    }
    
    // res almacena el cost del recorrido.
    // costeE almacena el peso en el ultimo anillo para moverse hacia h.
    // v almacena los grados recorridos hasta el ultimo anillo.
    vector<int> peso_anillos(N+1, 0);
    int costeE = 0;
    for(int n = 1; n < N +1; ++n){
        // Timepo que tarda un alienígena en recorrer un grado de distancia angular, en el i-esimo anillo.
        int T; cin>>T;
        peso_anillos[n] = T;
    }

    // Índice de al anillo en el que empieza(D);
    // Grado en el que empieza(G);
    // Índice del anillo en el que termina(e);
    // Grado en el que termina(h);
    int d,g,e,h;
    cin>>d>>g>>e>>h;

    if(d > e){
        swap(d,e);
        swap(g,h);
    }

    // Distancia conocida recorrida.(w), coste del recorrido.(cost), distancia desde la distancia conicida hasta la distancia almacenada en el anillo(u)
    int cost = 0, w = g, dist = 0;
    for(int n = d; n < e; ++n){
        // Se ha recorrido en el anillo n la cantidad de u grados.
        // Grados recorridos conocidos y coste del recorrido.
        // Distancia entre el origen y el tunel(w)
        dist = min(abs(w - rings[n]), 360 - abs(w - rings[n]));
        cost += dist * peso_anillos[n];
        w = rings[n];
    }
    // Sumamos el coste de la distancia conocida hasta h.
    cost += min(abs(w-h), 360 - abs(w-h)) * peso_anillos[e];

    if(cost >= INF) cout<<"IMPOSIBLE\n";
    else cout<<cost<<"\n";
}

int main(){
    int C; cin >> C;
    while(C > 0){
        solve();
        C--;
    }
    return 0;
}