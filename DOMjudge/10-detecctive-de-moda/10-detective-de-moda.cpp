#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

bool solve(){
    int n, id; cin>>n;
    int d = 0, i = 0;
    // Numero de camisetas que la tienda tiene actualmente (n) en venta;

    if(!cin) return false;
    map<int, set<int>> valores;
    // Para verificar si es única.
    set<int> unique;
    deque<int> dq;
    // Identificadores de los estilos de las camisetas, mismo estilo = mismo identificador (id).
    while (n--) {
        int id; cin >> id;
        // Se añade una nueva camiseta a la derecha.
        dq.push_back(id);
        // Añade las ids y guarda el valor de el convunti en pos.
        auto & pos = valores[id];
        if (pos.empty()) unique.insert(d);
            // Si el conjunto esta vacio le agrega el valor.
        else if (pos.size() == 1) unique.erase(*pos.begin());
    
        pos.insert(d);
        ++d;
    }

    // Numero de eventos(e)
    int e,num;
    cin>>e;

    while (e--){
        char c; cin>>c;
        if( c == 'P'){
            if(unique.empty()){
            cout<<"NADA INTERESANTE\n";
            } else {
                int solI = (*unique.begin()) -i + 1;
                int solD = (*unique.rbegin());

                if(solI < solD) cout<<solI<<" "<<"IZQUIERDA\n";
                else if(solD < solI) cout<<solD<<" "<<"DERECHA\n";
                else cout<<solD<<" "<<"CUALQUIERA\n"; 
            }
        } else if (c == 'I'){
            int p = --i;
            cin>>num;
            dq.push_front(num);
            auto & pos = valores[num];

            if (pos.empty()) unique.insert(num);
            else if (pos.size() == 1) unique.erase(*pos.begin());

            pos.insert(p);
        } else if(c == 'D'){
            int p = ++d;
            cin>>num;
            dq.push_back(num);
            auto & pos = valores[num];

            if (pos.empty()) unique.insert(num);
            else if (pos.size() == 1) unique.erase(*pos.begin());

            pos.insert(p);
            break;
        } else if (c =='i'){
            int p = i++;
            dq.pop_front();
            int v = dq.front(); dq.pop_front();

            auto & pos = valores[v];
            pos.erase(p);
            if (pos.size() == 1) unique.insert(*pos.begin());
            else if (pos.empty()) unique.erase(p);
            break;   
        } else if (c == 'd'){
            int p = --d;
            int v = dq.back(); dq.pop_back();
            
            auto & pos = valores[v];
            pos.erase(p);
            if (pos.size() == 1) unique.insert(*pos.begin());
            else if (pos.empty()) unique.erase(p);
            break;
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