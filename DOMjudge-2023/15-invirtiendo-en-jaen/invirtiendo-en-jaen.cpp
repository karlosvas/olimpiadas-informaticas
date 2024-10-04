#include <iostream>
#include <vector>
#include <string>
using namespace std;

using Mapa = vector<string>;
Mapa img;
vector<vector<bool>> visit;

int incF[] ={-1,0,1,0};
int incC[] ={0,1,0,-1};
int F,C;

int dfs(int f, int c){
    visit[f][c] = true;
    int tam= 1;
    for(int d= 0; d < 4; ++d){
        int nf = f + incF[d], nc= c + incC[d];
        if (0 <= nf && nf < F && 0 <= nc && nc < C && img[nf][nc] == '#' && !visit[nf][nc]) {
                tam += dfs(nf,nc);
        }
    }
    return tam;
}

bool solve(){
    cin>>F>>C;
    if(!cin) return false;

    img = Mapa(F);
    cin.ignore();

    for(int i = 0; i < F; ++i){
        getline(cin, img[i]);
    }

    int best_tam= 0;
    int olivos = 0;
    visit.assign(F, vector<bool>(C,false));
    // Recorrido en produndidad del grafo inplícito.

    for(int f = 0; f < F; ++f){
        for(int c = 0; c < C; ++c){
            if(!visit[f][c] && img[f][c] == '#') {
               ++olivos;
               int tam = dfs(f,c);
               if(tam > best_tam){
                    best_tam = tam;
               }
            }
        }
    }
    cout<<best_tam<<"\n";

    return true;
}

int main (){
    while(solve());
    return 0;
}
