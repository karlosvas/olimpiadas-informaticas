#include <iostream>
#include <string>
#include <queue>

using namespace std;

void quest(deque<int> dq){
    priority_queue<int> pq;
    for(int num: dq){
        pq.push(num);
    }

    // Buscar cuando los numeros se repiten.
    int test= 0, count = 0;
    deque<int> exa;

    while (!pq.empty()) {
        int current = pq.top();
        pq.pop();

        if (current == test) {
            exa.pop_back();
            count++;
        } else {
            exa.push_back(current);
            test = current;
        }
    }

    for(int num: exa){
        cout<<num<<" ";
    }
    cout<<"\n";

    for(int num: dq){
        cout<<num<<" ";
    }
    cout<<"\n";

    int solI = -1, solD = -1, numD, numI;

    for(auto i = 0; i < dq.size(); i++){
        if(solI == -1){
            numI = dq[i];
            cout<<"NumeroI: "<<numI<<"\n";
            for(int numE: exa){
                if(numI == numE){
                    solI = i + 1;
                    cout<<"SolI: "<<solI<<"\n";
                    break;
                }
            }
        }
        
        if(solD == -1){
            numD = dq[dq.size() - 1 - i];
            cout<<"NumeroD: "<<numD<<"\n";
            for(int numE: exa){
                if(numD == numE){
                    solD = i + 1;
                    cout<<"SolD: "<<solD<<"\n";
                    break;
                }
            }
        }
    }

    string res;
    if(solI == -1 && solD == -1) cout<<"NADA INTERESANTE";
    else if (solI == solD) cout<<solD<<" "<<"CUALQUIERA";
    else if(solI < solD)  cout<<solI<<" "<<"IZQUIERDA";
    else cout<<solD<<" "<<"DERECHA";

    
}

bool solve(){
    int n, id;
    // Numero de camisetas que la tienda tiene actualmente (n) en venta;
    cin>>n;
    
    deque<int> dq;
    for(int i = 0; i < n; i++){
        // Identificadores de los estilos de las camisetas, mismo estilo = mismo identificador (xi).
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
            cout<<"PREGUNTA\n";
            quest(dq);
            break;
        }
    }

    cout<<"\n---\n";
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