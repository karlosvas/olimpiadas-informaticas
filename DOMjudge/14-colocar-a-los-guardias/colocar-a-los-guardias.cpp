#include <iostream>
#include <vector>
#include <string>

using namespace std;
using Grafo = vector<vector<int>>;
Grafo g;
vector<bool> visit;

// Grafo bipartito.
using namespace std;

bool solve(){
    // Cruces (n)
    // Calles entre cruces (c)
    int n; cin>>n;
    int c; cin>>c;
    if(!cin) false;
    
    for(int i = 0; i < c; ++i){
        // Añadismos las aristas a los vértices.
        int c1, c2; cin>>c1>>c2;
        c1--; c2--;
        g[c1].push_back(c2);
        g[c2].push_back(c1);
    }

    return true;    
}

int main(){
    while(solve())
    return 0;
}