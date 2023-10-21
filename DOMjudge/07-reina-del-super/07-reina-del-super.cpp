#include <iostream>
#include <string>
#include <queue>
using namespace std;
using Caja = pair<int, int>;

bool resolve(){
    int n, c;
    cin>>n>>c;
    cin.ignore();
    
    if (n == 0) return false;

    priority_queue<Caja, vector<Caja>, greater<Caja>> cajas;
    for (int i = 1; i <= n ; i++){
        cajas.push({0,i});
    }

    for (int i = 0; i < c; i++) {
        int tiempo; cin>>tiempo;
        auto caja = cajas.top(); cajas.pop();
        caja.first += tiempo;
        cajas.push(caja);
    }

    cout<<cajas.top().second<<"\n";
    return true;
}


int main() {   
    while (resolve()); 
    return 0;
}