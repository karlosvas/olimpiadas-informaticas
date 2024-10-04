#include <iostream>
#include <queue>
using namespace std;

struct Inst{
    int mus;
    int part;
};

bool operator<(Inst a, Inst b) {
    // Declaramos el grupo mayor de a y b.
    int max_a = a.mus / a.part + (a.mus % a.part > 0);
    int max_b = b.mus / b.part + (b.mus % b.part > 0);
    return max_b > max_a;
};

bool solve(){
    // Partituras que se pueden compar (p)
    // Números de instrumenstos distintos (n)
    int p,n;
    cin>>p>>n;

    if (!cin) return false;

    priority_queue<Inst> pq;
    int musicos;

    for(int i = 0; i< n; i++){
        // Cantidad de músicos que hay para cada uno de los instrumentos.
        cin>>musicos;
        pq.push({musicos, 1});
    }

    // Las veces que hay que repartir una partitura nueva ya que cada instrumento tiene una partitura son las que se pueden comprar(p) menos los numeros de instrumentos(n) ya que ya an sido entrgados.
    p-=n;
    while (p--){
        // Destructuramos el struct Instruumento com mayor prioridad.
        auto [mus,par] = pq.top();
        pq.pop();
        ++par;
        // Le pasamos como objeto los músicos y partituras extraidos de la pq.
        pq.push({mus, par});
    }
    
    auto [mus, par] = pq.top();
    // Musicos entre las partituras mas el resto si al dividirlo entre las partituras es mayor a 0.
    int max_gruup = mus/par + (mus % par > 0);
    cout<<max_gruup<<"\n";

    return true;
};

int main(){
    while(solve());
    return 0;
};