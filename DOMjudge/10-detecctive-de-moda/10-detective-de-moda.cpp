#include <iostream>
#include <string>
#include <queue>

using namespace std;

void quest(deque<int> dq){
    priority_queue<int> pq;
    for(int num: dq){
        pq.push(num);
    }

    // Guardar los que no se repitan.
    int test= 0, count = 0;
    deque<int> unic;

    while (!pq.empty()) {
        int current = pq.top();
        pq.pop();

        if (current == test) {
            unic.pop_back();
            count++;
        } else {
            unic.push_back(current);
            test = current;
        }
    }

    // Buscando cuando es la primera vez que un número no repetido coinciode para cada uno de los lados.
    int solI = -1, solD = -1, numD, numI;

    for(deque<int>::size_type i = 0; i < dq.size(); i++){
        if(solI == -1){
            numI = dq[i];
            for(int numE: unic){
                if(numI == numE){
                    solI = i + 1;
                    break;
                }
            }
        }
        
        if(solD == -1){
            numD = dq[dq.size() - 1 - i];
            for(int numE: unic){
                if(numD == numE){
                    solD = i + 1;
                    break;
                }
            }
        }
    }

    // Mostrando si se a encontrado y si es asi cual se encontro antes.
    string res;
    if(solI == -1 && solD == -1) cout<<"NADA INTERESANTE\n";
    else if (solI == solD) cout<<solD<<" "<<"CUALQUIERA\n";
    else if(solI < solD)  cout<<solI<<" "<<"IZQUIERDA\n";
    else cout<<solD<<" "<<"DERECHA\n";

    
}

bool solve(){
    int n, id;
    // Numero de camisetas que la tienda tiene actualmente (n) en venta;
    cin>>n;
    
    deque<int> dq;
    for(int i = 0; i < n; i++){
        // Identificadores de los estilos de las camisetas, mismo estilo = mismo identificador (id).
        cin>>id;
        dq.push_back(id);
    }

    // Numero de eventos(e)
    int e,num;
    cin>>e;

    char c;
    for(int i = 0; i < e; i++){
        cin>>c;
        switch (c){
        case('I'):
            cin>>num;
            dq.push_front(num);
            break;
        case('D'):
            cin>>num;
            dq.push_back(num);
            break;
        case('i'):
            dq.pop_front();
            break;   
        case('d'):
            dq.pop_back();
            break;
        case('P'):
            quest(dq);
            break;
        }
    }

    cout<<"---\n";
    return true;
}
int main(){
    int cases;
    cin>>cases;
    while(cases > 0){
        solve();
        cases--;
    }
    return 0;
}