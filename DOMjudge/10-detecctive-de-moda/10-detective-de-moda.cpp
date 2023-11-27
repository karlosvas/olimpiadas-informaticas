#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

bool solve(){
    // Numero de camisetas actualmente (n) en venta, iterador que a punta al primero (i) iterador que apunta al ultimo (d)
    int n, id; cin>>n;
    int i = 0, d = 0;

    if(!cin) return false;

    // Verificamos si es única (Map de frecuencias).
    deque<int> percha;
    map<int, set<int>> valores;
    // Conjuntos unicos.
    set<int> unique;

    // Identificadores de los estilos de las camisetas.
    while (n--) {
        int id; cin >> id;
        // Se añade una nueva camiseta a la derecha.
        percha.push_back(id);
        auto &pos = valores[id];

        // Si pos esta vacío le agrega el valor, si no apuntamos al, unico mas pequeño y lo eliminamos.
        if (pos.empty()) unique.insert(d);
        else if (pos.size() == 1) unique.erase(*pos.begin());
    
        pos.insert(d);
        ++d;
    }

    // Nuevos eventos(e)
    int e,num; cin>>e;
    while (e--){
        char c; cin>>c;
        if( c == 'P'){
            if(unique.empty()){
            cout<<"NADA INTERESANTE\n";
            } else {
                int distI = (*unique.begin()) -i + 1;
                int distD = d - (*unique.rbegin());

                if(distI < distD) cout<<distI<<" "<<"IZQUIERDA\n";
                else if(distD < distI) cout<<distD<<" "<<"DERECHA\n";
                else cout<<distI<<" "<<"CUALQUIERA\n"; 
            }
        } else if (c == 'I'){
            int p = --i;
            cin>>num;
            percha.push_front(num);
            auto & pos = valores[num];

            if (pos.empty()) unique.insert(num);
            else if (pos.size() == 1) unique.erase(*pos.begin());

            pos.insert(p);
        } else if(c == 'D'){
            int p = ++d;
            cin>>num;
            percha.push_back(num);
            auto & pos = valores[num];

            if (pos.empty()) unique.insert(num);
            else if (pos.size() == 1) unique.erase(*pos.begin());

            pos.insert(p);
            break;
        } else if (c =='i'){
            int p = i++;
            percha.pop_front();
            int v = percha.front(); percha.pop_front();

            auto & pos = valores[v];
            pos.erase(p);
            if (pos.size() == 1) unique.insert(*pos.begin());
            else if (pos.empty()) unique.erase(p);
            break;   
        } else if (c == 'd'){
            // Posicion de d o ultmimo elemento popr la derecha (p)
            int p = --d;
            // Guardamos el ultimo elemento y lo borramos.
            int v = percha.back(); percha.pop_back();
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