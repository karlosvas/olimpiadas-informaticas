#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

bool solve(){
    int N; cin>>N;

    if(N == 0) return false;

    // Creamos un map para que cada jugador tenga su set de cartón con números sin repetir.
    map<string, set<int>> players;
    
    for(int n = 0; n < N; n++){
        // Nombre del jugador(name)
        string name; cin>>name;
        // Números del cartón del jugador(x), cartón de cada jugador(carton).
        int x;
        set<int> cardboard;
        while (cin>>x){
            // Siempre que x, sea diferente de 0, se inserta en el cartón del jugador.
            if(x == 0) break;
            cardboard.insert(x);
        }
        players[name] = cardboard;
    }

    // Número de bombos(Q).
    int Q; cin>>Q;
    for(int q = 0; q < Q; q++){
        int n_bomb; cin>>n_bomb;
        // Cada vez que se saca una bola, se comprueba si algún jugador tiene esa bola en su cartón.
        for(auto[name, cardboard] : players){
            // Si la bola está en el cartón del jugador en la iteración, se elimina del cartón.
            if(players[name].find(n_bomb) != players[name].end()){
                // Si el cartón del jugador se queda vacío, se muestra el nombre del jugador ganador.
                if(players[name].size() == 1) cout<<name<<" ";
                players[name].erase(n_bomb);
            }
        }
    }
    cout<<"\n";
    
    return true;
}
int main(){
    while(solve());
    return 0;
}