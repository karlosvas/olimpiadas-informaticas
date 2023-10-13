#include <iostream>
#include <queue>
using namespace std;

struct registro {
    int id;
    int periodo;
    int momento;
};

bool operator<(registro a, registro b){
    return b.momento < a.momento || (b.momento == a.momento && b.id < a.id);
};

bool solve(){
    int n; cin>>n;
    if(n==0) return false;

    priority_queue<registro> pq; // Como por defecto tiene less, el compilador ya lo estamos comparando = "<".
    for(int i=0; i<n;i++){
        int id,per;
        cin>>id>>per;
        pq.push({id, per, per});
    }

    int envios;
    cin>> envios;
    while(envios--){
        registro r = pq.top();
        pq.pop();
        cout<<r.id<<"\n";
        pq.push({r.id, r.periodo, r.periodo + r.momento});
    }
    cout<<"\n";
    return true;
};


int main(){
    while (solve());
    return 0;
};