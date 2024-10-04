#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using info = pair<int,int>;
using Grafo = vector<vector<info>>; // Grados, Anillos.

Grafo rings;

int N, K;
// Índice de al anillo en el que empieza(D);
// Grado en el que empieza(G);
// Índice del anillo en el que termina(e);
// Grado en el que termina(h);
int INF = 1000000000;

void solve(){
    // Anillos N, Túneles K
    cin>>N>>K;

    // Al haber 360 conexiones, hay tunel en todos los grados, por lo que la mejor opción será irse al grado que menos cueste recorrer y dirijirse a la salida.
    for(int k = 0; k < K; ++k){
        int a,b; cin>>a>>b;
        // No hace falta siquiera hacer las conexiones.
    }
    
    // Priroidad de los anillos, para ver cual es el que menos cuesta recorrer.
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int n = 1; n < N +1; ++n){
        // Timepo que tarda un alienígena en recorrer un grado de distancia angular, en el i-esimo anillo.
        int T; cin>>T;
        pq.push(T);
    }
    
    int e, h, d, g;
    cin>>d>>g>>e>>h;

    // Distancia entre el grado de salida y el grado de entrada moviendonos en el anillo menor coste.    
    int sol = min(abs(g-h), 360 - abs(g-h)) * pq.top();
    // Mostrar la solución.
    cout<<sol<<"\n";
}

int main(){
    int C; cin >> C;
    while(C > 0){
        solve();
        C--;
    }
    return 0;
}

