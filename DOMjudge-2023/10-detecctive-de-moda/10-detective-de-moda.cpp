#include <iostream>
#include <queue>
#include <set>
#include <map>
using namespace std;


bool solve(){
    // Numero de camisetas actualmente (N) en venta, iterador que a punta al primero (i) iterador que apunta al ultimo (d)
    int N; cin>>N;
    int i = 0, d = 0;

    if(!cin) return false;

    // Verificamos si es única (Map de frecuencias), Mapa de valores con sus posiciones, Identificadores de los estilos de las camisetas.
    deque<int> hanger;
    map<int, set<int>> values;
    set<int> unique;

    while (N--) {
        int new_id; cin>>new_id;
        // Se añade una nueva camiseta a la derecha.
        hanger.push_back(new_id);

        // Hacemos referencia a la posicion de value con esa id, a el set de values, si esta vacío es unico, si no lo borramos únicos.
        auto& pos = values[new_id];
        if (pos.empty()) unique.insert(d);
        else if (pos.size() == 1) unique.erase(*pos.begin());
        // Actualizamos la nueva posicion.
        pos.insert(d);
        ++d;
    }

    // Nuevos de eventos(E)
    int E; cin>>E;

    while (E--){
        
        char c; cin>>c;

        if( c == 'P'){
            // Si no hay camisetas en la percha no hay nada itnteresante.
            if(unique.empty()){
                cout<<"NADA INTERESANTE\n";
            } else {
                // Distancia desde el unico menor hasta la izquierda(distI) y lo mismo hacia la derecha(distD)
                int distI = (*unique.begin()) - i + 1;
                int distD = d - (*unique.rbegin());

                // Mostramos la distancia menor.
                if (distI < distD) cout<<distI<<" IZQUIERDA\n";
                else if(distD < distI) cout<<distD<<" DERECHA\n";
                else cout<<distI<<" CUALQUIERA\n"; 
            }

        } else if (c == 'I' || c == 'D'){
            // Nueva id de la comiseta(new_id), nueva posicion de i o d(new_position)
            int new_id, new_position;
            cin>>new_id;

            // Si es I, lo agregamos por la izquierda a la percha y actualizamos la posicion, si es D por la derecha.
            if (c == 'I') new_position = --i, hanger.push_front(new_id);
            else new_position = d++, hanger.push_back(new_id);
            
            auto& pos = values[new_id];
            if (pos.empty()) unique.insert(new_position);
            else if (pos.size() == 1) unique.erase(*pos.begin());
            pos.insert(new_position);

        } else if (c == 'i' || c == 'd'){
            // Nueva id de la comiseta(new_id), nueva posicion de i o d(new_position)
            int new_id, new_position;
            
            // Si es i, lo borramos por la izquierda de la percha y actualizamos la posicion, si es d por la derecha.
            if (c == 'i') new_position = i++, new_id = hanger.front(), hanger.pop_front();
            else new_position = --d, new_id = hanger.back(), hanger.pop_back();

            auto& pos = values[new_id];
            pos.erase(new_position);
            if (pos.empty()) unique.erase(new_position);
            else if(pos.size() == 1) unique.insert(*pos.begin());
        }
    }

    cout<<"---\n";

    return true;
}

int main(){
    int cases; cin>>cases;
    while(cases--){
        solve();
    }
    return 0;
}