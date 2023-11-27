#include <iostream>
#include <vector>
#include <string>

using namespace std;
using Grafo = vector<vector<int>>;
Grafo g;
vector<bool> visit;


int dfs(int v, vector<int>& v_conexas, int conexas){
    // Cuenta los adyacentes y guarda el nuumero en ese indice de componentes conexas.
    v_conexas[v] = conexas;
    visit[v] = true;
    int tam = 1;
    for(int arista : g[v]){
        if(!visit[arista]) {
            tam += dfs(arista, v_conexas, conexas);
        }
    }
    return tam;
}

bool solve(){
    // Usuaurios en al red(n)
    // Número de grupos(m)
    int n,m;
    cin>>n>>m;

    if(!cin) return false;
    
    g.assign(n, {} );

    while (m--) {
        // Elemento actual(a) elemento anterior(b)
        int a = 0, b = 0;

        bool first = false;
        int event; cin>>event;

        while(event--){
            // Hacemos las relaciones entre vertices.
            cin>>a; a--;
            // Si no es la primera vuelta hace las relaciones entre el actual y el anterior.
            if(!first) first = true;
            else{
                g[b].push_back(a);
                g[a].push_back(b);
            }
            b = a;
        }
    }
    
    // visit se utiliza para saber quien ya ha sido visitado.
    visit.assign(n, false);
    // Creamos un vector de conexas que representa a que componete conexa pertenece cada usuario,size que guarda la longitd de cada una. 
    vector<int> v_conexas(n, {}); vector<int> size;
    int conexas= 0;

    for (int v= 0; v < n; v++){
        if(!visit[v]){
            // Busca el tamaño de las conexas y las guiarda en size.
            // Empieza a distribuir la noticia v.
            int tam = dfs(v, v_conexas, conexas);
            size.push_back(tam);
            conexas++;
        }
    }

    for(int v= 0; v < n; v++){
        // Se muestran los resultados de los datos.
        if (v == n - 1) cout<<size[v_conexas[v]]<<"\n";
        else cout<<size[v_conexas[v]]<< " ";
    }

    return true;
}

int main(){
    while(solve());
    return 0;
}