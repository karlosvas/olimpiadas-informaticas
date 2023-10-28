#include <iostream>
#include <queue>
using namespace std;

struct Instrumento {
    int musicos;
    int partituras;
};

bool operator<(Instrumento a, Instrumento b) {
    int max_gruupo_a = a.musicos / a.partituras + (a.musicos % a.partituras > 0);
    int max_gruupo_b = b.musicos / b.partituras + (b.musicos % b.partituras > 0);
    return max_gruupo_b > max_gruupo_a;
};

bool solve(){
    int p,n;
    cin>>p>>n;

    if(!cin) return false;

    priority_queue<Instrumento> cola;

    int musicos;
    for(int i = 0; i < n; i++){
        cin>>musicos;
        cola.push({musicos, 1});
    }

    p -= n;
    while (p--){
        auto [mus, par] = cola.top();
        cola.pop();
        ++par;
        cola.push({mus, par});
    }

    auto [mus, par] = cola.top();
    int grupo_mayor = mus/par + (mus % par > 0);
    cout<<grupo_mayor<<"\n";
    
    return true;
}

int main(){
    while(solve());
    return 0;
}