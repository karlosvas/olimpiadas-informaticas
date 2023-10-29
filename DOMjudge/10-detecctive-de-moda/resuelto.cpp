#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

bool solve() {
    // crea las camisetas y sus identificadores.
    int n, id;
    cin >> n;
    int i = 0, d = 0;

    // Diccioanrio de pares que no se repite.
    map<int, set<int>> dicc;
    deque<int> dq;
    set<int> unique;

    for (int j = 0; j < n; j++) {
        cin >> id;
        dq.push_back(id);
        auto &conj = dicc[id];
        if (conj.empty()) unique.insert(d);
        else if (conj.size() == 1) {
            unique.erase(*conj.begin());
            conj.insert(d);
            d++;
        }
    }

    int e, num;
    cin >> e;
    char c;
    int newPosition, newShirt;

    for (int j = 0; j < e; j++) {
        cin >> c;
        auto &conj = dicc[num];

        switch (c) {
            case 'I':
                cin >> num;
                newPosition = --i;
                dq.push_front(num);
                if (conj.empty()) unique.insert(newPosition);
                else if (conj.size() == 1) {
                    unique.erase(*conj.begin());
                    conj.insert(newPosition);
                }
                break;
            case 'D':
                newPosition = d++;
                cin >> num;
                dq.push_back(num);
                if (conj.empty()) unique.insert(newPosition);
                else if (conj.size() == 1) {
                    unique.erase(*conj.begin());
                    conj.insert(newPosition);
                }
                break;
            case 'i':
                newPosition = i++;
                newShirt = dq.front();
                dq.pop_front();
                break;
            case 'd':
                newPosition = --d;
                newShirt = dq.front();
                dq.pop_back();
                conj = dicc[newShirt];
                conj.erase(newPosition);

                if (conj.size() == 1) unique.insert(*conj.begin());
                else if (conj.empty()) conj.erase(newPosition);
                break;
            case 'P':
                if (unique.empty()) cout << "NADA INTERESANTE\n";
                else {
                    int numD = d - (*unique.rbegin()) - 1;
                    int numI = (*unique.begin() - i - 1);

                    if (numI < numD) cout<<numI<<" IZQUIERDA\n";
                    else if (numD < numI) cout<<numD<< " DERECHA\n";
                    else cout<<numD<<" CUALQUIERA\n";
                }
                break;
        }
    }
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
