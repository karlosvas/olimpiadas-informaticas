#include <iostream>
#include <unordered_map>
#include <string>
#include <set>
#include <limits>
using namespace std;

bool solve(){
    // Numero de jugadores(N)
    int N; cin>>N; 

    if(N == 0) return false;

    // Map de cartones, y de cuantas veces aparece cada jugador es la longitud de su cartón.
    // Utilizamos set para que se ordenen alfabeticamente los nombres de los jugadores.
    unordered_map<int, set<string>> cardboard;
    unordered_map<string, int> counts;

    for(int n = 0; n < N; n++){
        string name; cin>>name;
        int x;
        while (cin>>x){
            if(x == 0) break;
            // Añadimos a que número pertenece cada nombre, y cuanta es la longitud de su cartón.
            cardboard[x].emplace(name);
            counts[name]++;
        }
    }
    // Bombos(Q)
    int Q; cin>>Q;

    // Utilizamos un set para que se ordenen alfabeticamente los nombres de los ganadores.
    bool end = false;

    for(int q = 0; q < Q; q++){
        // Numero de la bola(num_bol)
        int num_bol; cin>>num_bol;

        // Iterador que apunta a el numero que esta en los cartones.
        auto it = cardboard.find(num_bol);
        if(it != cardboard.end()) {

            // Iterador que recorre los nombres de los jugadores que tienen ese número en su cartón.
            for(auto names_it = it->second.begin(); names_it != it->second.end(); ++names_it){
                auto name = *names_it; // Nombre del jugador en cada iteración.
                auto next_it = next(names_it); // Iterador que apunta al siguiente nombre del jugador, para verificar si es el ultimo.

                // Restamos 1 a la longitud del cartón, del jugador que disponga de ese numero, si es 0 es que ha cantado bingo.
                if(--counts[name] == 0) {
                    // Se amacena las personas que han cantado bingo en esa tirada de la bola.
                    // Si su contador es 1 es posible que en la siguiente iteracion cante bingo tambien.
                    if (next_it == it->second.end() || counts[*next_it] > 1) cout<<name<<"\n";
                    else cout<<name<<" ";
                    // Si alguien cantó bingo termina el juego.
                    end = true;
                }

            }

            if(end) break;
        }
    }

    // Limpiamos el búfer de entrada antes de retornar de la función.
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return true;
}

int main(){
    while(solve());
    return 0;
}

