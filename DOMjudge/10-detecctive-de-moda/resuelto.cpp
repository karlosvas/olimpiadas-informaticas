#include <iostream>
#include <queue>
#include <set>
#include <map>

using namespace std;

bool solve() {
    // numero de camisetas
    int n; cin >> n;
    int i = 0, d = 0;

    // Percha(dq)
    deque<int> dq;
    // Diccioanrio de pares que no se repite.
    map<int, set<int>> dicc;
    // Para verificar si es unica.
    set<int> unique;

    // Se ejecuta n veces.
    while (n--) {
        int id; cin >> id;
        dq.push_back(id);
        auto & pos = dicc[id];
        if (pos.empty()) unique.insert(d);
            // Si el conjunto esta vacio le agrega el valor.
        else if (pos.size() == 1) unique.erase(*pos.begin());
            // Si el conjunto no esta vacio lo borramos apora que no sea único.
        pos.insert(d);
        ++d;
    }

    int e, num; cin >> e;

    while (e--) {
        char c; cin >> c;

        if (c == 'P'){
            if (unique.empty()) cout<<"NADA INTERESANTE\n";
            else {
                // Cojemos las ditancias de izuierda y derecha.
                int numI = (*unique.begin() - i + 1);
                int numD = d - (*unique.rbegin());

                if (numI < numD) cout<<numI<<" IZQUIERDA\n";
                else if (numD < numI) cout<<numD<< " DERECHA\n";
                else cout<<numI<<" CUALQUIERA\n";
            }
        }else if( c== 'I' || c == 'D'){
            cin >> num;
            int newPosition = (c == 'I') ? --i : d++;

            if(c == 'I') dq.push_front(num);
            else dq.push_back(num);

            auto & pos = dicc[num];
            if (pos.empty()) unique.insert(newPosition);
            else if (pos.size() == 1) unique.erase(*pos.begin());

            pos.insert(newPosition);
        }else if( c == 'i' || c == 'd'){
            int newPosition = (c == 'i') ? i++ : --d; 
            int v;

            if (c == 'i') { v = dq.front(); dq.pop_front();}
            else { v = dq.back(); dq.pop_back();}

            auto & pos = dicc[v];
            pos.erase(newPosition);

            if (pos.size() == 1) unique.insert(*pos.begin());
            else if (pos.empty()) pos.erase(newPosition);
        }
    }
    cout<<"---\n";
    return true;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }
    return 0;
}
