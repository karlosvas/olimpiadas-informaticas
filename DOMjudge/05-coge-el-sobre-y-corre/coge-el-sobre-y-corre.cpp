#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;


bool solve(){
    int n, k;
    // Numero de sobres que guarda (n)
    // Numero de sobrees que tiene que cojer(k)
    cin>>n>>k;
    
    if (!cin) return false;

    priority_queue<int> pq;
    vector<int> envelopes(n);

    for (int & cash : envelopes) {
        cin >> cash;
    }

    int x = 0, it = 0;
    // Las posibilidades son las veces que puede elejir entre los k sobres.

    int posibilitis = n - k + 1;

    while(posibilitis > 0){
        // EL dinero a lejir cada k casos.
        int cash = envelopes[it];

        if (static_cast<int>(pq.size()) == k) {
            x++;
            it = x;
            // Elije el numero mas alto entre las k opciones, y busca desde el siguiente número.
            if(posibilitis == 1) cout<<pq.top()<<"\n";
            else cout<<pq.top()<<" ";
            while (!pq.empty()){
                pq.pop();
            }
            posibilitis--;
            continue;
        }

        pq.push(cash);
        it++;
    }
    return true;
}

int main(){
    while(solve());
    return 0;
}