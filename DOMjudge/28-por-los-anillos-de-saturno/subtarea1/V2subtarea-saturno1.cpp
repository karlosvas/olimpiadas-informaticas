#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using info = pair<int,int>;
using Grafo = vector<vector<info>>; // Grados, Anillos.
Grafo grafo;

int INF = 1000000000;
int N, K;

void solve(){
    // Anillos N, Túneles K
    // Subtarea N=1 K=0.
    cin>>N>>K;
    
    // Tiempo en recorrer un grado de distancia angular, en el i-esimo angulo, como N=1 , solo hay un anillo.
    int T; cin>>T;
    
    // // Indice de al anillo(d) y grado en el que empieza(g)
    // // Indice del anillo(e) y grado en el que termina(h)
    int d, g, e, h;
    cin>>d>>g>>e>>h;

    int sol = max(g,h) - min(g,h);
    if(sol > 180) sol = 180 - (sol % 180);

    if(sol >= INF) cout<<"IMPOSIBLE\n";
    else cout<<sol * T<<"\n";
}

int main(){
    int C; cin >> C;
    while(C > 0){
        C--;
        solve();
    }
    return 0;
}