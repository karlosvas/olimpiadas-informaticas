# include <iostream>
# include <string>

using namespace std;
using Grafo = vector<vector<int>>;

bool solve() {
    int v,a;
    cin>>v>>a;
    Grafo g(v);

    for(int i = 0; i < a;i++){
        g[a-1].push_back(v-1);
        g[v-1].push_back(a-1);
    }
}

int main (){
    while (solve())
    return 0;
}