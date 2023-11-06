# include <iostream>
# include <vector>
# include <string>
using namespace std;

using Map = vector<vector<char>>;
vector<vector<bool>> visit;
Map table;
Map solution;

int incF[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int incC[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int F, C;

int dfs(int x, int y) {
    visit[x][y] = true;
    int bomba = 0;

    for (int pos = 0; pos < 8; ++pos) {
        int nf = x + incF[pos], nc = y + incC[pos];
        if (0 <= nf && nf < F && 0 <= nc && nc < C && table[nf][nc] == '*' && !visit[nf][nc]) {
            bomba++;
        }
    }
    
    // Ahora asigna el valor en solution[x][y] después de contar las minas adyacentes.
    if (bomba > 0) {
        solution[x][y] = static_cast<char>('0' + bomba);
    } else {
        solution[x][y] = '-';
    }

    // Continúa la DFS para las celdas adyacentes.
    for (int pos = 0; pos < 8; ++pos) {
        int nf = x + incF[pos], nc = y + incC[pos];
        if (0 <= nf && nf < F && 0 <= nc && nc < C && table[nf][nc] != '*' && !visit[nf][nc]) {
            if (solution[x][y] != 'X') dfs(nf, nc);
        }
    }
    return bomba;
}



bool solve(){
    // Filas (F), Columnas (C)
    cin>>F>>C;
    if(!cin) return false;

    table.assign(F, vector<char>(C));
    string line;

    for(int i = 0; i < F; ++i){
        cin.ignore();
        getline(cin, line);
        for(int j = 0; j < C; j++){
            table[i][j] = line[j]; 
        }
    }

    solution.assign(F, vector<char>(C, 'X'));
    visit.assign(F, vector<bool>(C, false));
    cout<<"inserta k: ";
    int k; cin>>k;
    for(int i = 0; i < k; ++i){
        int x,y;cin>>x>>y;
        x--; y--;
        dfs(x, y);
    }

    for (int f = 0; f < F; ++f) {
        for (int c = 0; c < C; ++c) {
            cout<<solution[f][c];
        }
        cout<<"\n";
    }

    return true;
}

int main(){
    while(solve())
    return 0;
}

/*
Entrada de ejemplo
8 8  
-*---*--  
--------  
**------  
---*----  
---*---*  
-*--*---  
----*---  
--------  
4  
1 1  
1 8  
8 8  
8 1  

## Salida de ejemplo
1XXXXX1-  
XXXX111-  
XXXX1---  
XXXX2-11  
XXXX311X  
XXXXX211  
1112X2--  
---1X1--  
*/